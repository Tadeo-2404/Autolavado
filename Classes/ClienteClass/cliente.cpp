#include <iostream>
#include <iomanip>
#include <fstream>
#include "Cliente.hpp"
using namespace std;

string Encryptar(string valor)
{
    int i;
    string resultado;
    for (i = 0; i < valor.size(); i++)
    {
        resultado += (valor[i] + 3);
    }
    return resultado;
}

string Desencryptar(string valor)
{
    int i;
    string resultado;
    for (i = 0; i < valor.size(); i++)
    {
        resultado += (valor[i] - 3);
    }
    return resultado;
}

Cliente::Cliente()
{
}

Cliente::Cliente(string ID, string nombre, string apellido, string correo, string numeroCelular, string IDVehiculo)
{
    this->ID = ID;
    this->nombre = nombre;
    this->apellido = apellido;
    this->correo = correo;
    this->numeroCelular = numeroCelular;
    this->IDVehiculo = IDVehiculo;
}

void Cliente::CrearEncriptacion()
{
    ofstream archivoClientes("ClientesEncryptation.txt", ios::app);

    if (archivoClientes.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    cout << "Bienvenido a crear Cliente Encryptado" << endl;
    cout << "Ingrese el ID del Cliente" << endl;
    getline(cin, ID);
    ID = Encryptar(ID);
    cout << "ID: " << ID << endl;

    cout << "Ingresa el Nombre del Cliente" << endl;
    getline(cin, nombre);
    nombre = Encryptar(nombre);
    cout << "Nombre: " << nombre << endl;

    cout << "Ingresa el Apellido del Cliente" << endl;
    getline(cin, apellido);
    apellido = Encryptar(apellido);
    cout << "Apellido: " << apellido << endl;

    cout << "Ingrese el Correo del Cliente" << endl;
    getline(cin, correo);
    correo = Encryptar(correo);
    cout << "Correo: " << correo << endl;

    cout << "Ingrese el Celular del Cliente" << endl;
    getline(cin, numeroCelular);
    numeroCelular = Encryptar(numeroCelular);
    cout << "Numero: " << numeroCelular << endl;

    cout << "Ingrese el ID del Vehiculo" << endl;
    getline(cin, IDVehiculo);
    IDVehiculo = Encryptar(IDVehiculo);
    cout << "IDVehiculo: " << IDVehiculo << endl;

    int IDsize = ID.size(), nombreSize = nombre.size(), apellidoSize = apellido.size(), correoSize = correo.size(), numeroCelularSize = numeroCelular.size(), IDVehiculoSize = IDVehiculo.size();

    archivoClientes.write((char *)&IDsize, sizeof(int));
    archivoClientes.write(ID.c_str(), IDsize);

    archivoClientes.write((char *)&nombreSize, sizeof(int));
    archivoClientes.write(nombre.c_str(), nombreSize);

    archivoClientes.write((char *)&apellidoSize, sizeof(int));
    archivoClientes.write(apellido.c_str(), apellidoSize);

    archivoClientes.write((char *)&correoSize, sizeof(int));
    archivoClientes.write(correo.c_str(), correoSize);

    archivoClientes.write((char *)&numeroCelularSize, sizeof(int));
    archivoClientes.write(numeroCelular.c_str(), numeroCelularSize);

    archivoClientes.write((char *)&IDVehiculoSize, sizeof(int));
    archivoClientes.write(IDVehiculo.c_str(), IDVehiculoSize);

    archivoClientes.close();
};

void Cliente::MostrarEncriptacion()
{
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    ifstream archivo("ClientesEncryptation.txt", ios::app);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);
        cout << left << endl;
        cout << "ENCRYPTADO" << endl;
        cout << setw(15) << "ID";
        cout << setw(20) << "Nombre";
        cout << setw(15) << "Apellido";
        cout << setw(15) << "Correo";
        cout << setw(15) << "Celular";
        cout << setw(15) << "IDVehiculo" << endl;
        cout << setw(15) << ID;
        cout << setw(20) << nombre;
        cout << setw(15) << apellido;
        cout << setw(15) << correo;
        cout << setw(15) << numeroCelular;
        cout << setw(15) << IDVehiculo << endl;
        cout << "------------------------" << endl;

        cout << "DESENCRYPTADO" << endl;
        cout << setw(15) << "ID";
        cout << setw(20) << "Nombre";
        cout << setw(15) << "Apellido";
        cout << setw(15) << "Correo";
        cout << setw(15) << "Celular";
        cout << setw(15) << "IDVehiculo" << endl;
        cout << setw(15) << Desencryptar(ID);
        cout << setw(20) << Desencryptar(nombre);
        cout << setw(15) << Desencryptar(apellido);
        cout << setw(15) << Desencryptar(correo);
        cout << setw(15) << Desencryptar(numeroCelular);
        cout << setw(15) << Desencryptar(IDVehiculo) << endl;
    }

    archivo.close();
}

void Cliente::BuscarEncriptacion(string ClienteBuscado)
{
    ClienteBuscado = Encryptar(ClienteBuscado);
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    ifstream archivo("ClientesEncryptation.txt");
    int cont = 0;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    Cliente Cliente;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado << endl;

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);
        if (ID == ClienteBuscado)
        {
            cont++;
            cout << left << endl;
            cout << "ENCRYPTADO" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << ID;
            cout << setw(20) << nombre;
            cout << setw(15) << apellido;
            cout << setw(15) << correo;
            cout << setw(15) << numeroCelular;
            cout << setw(15) << IDVehiculo << endl;
            cout << "------------------------" << endl;

            cout << "DESENCRYPTADO" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << Desencryptar(ID);
            cout << setw(20) << Desencryptar(nombre);
            cout << setw(15) << Desencryptar(apellido);
            cout << setw(15) << Desencryptar(correo);
            cout << setw(15) << Desencryptar(numeroCelular);
            cout << setw(15) << Desencryptar(IDVehiculo) << endl;
        }
    }
    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
}

void Cliente::ModificarEncriptacion(string ClienteBuscado)
{
    ClienteBuscado = Encryptar(ClienteBuscado);
    ifstream archivo("ClientesEncryptation.txt");
    ofstream archivoTemporal("ClientesEncryptationTemp.txt", ios::app);
    int cont = 0;
    int opc;
    string newValue;
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    Cliente Cliente;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado;

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);

        if (ID == ClienteBuscado)
        {
            cont++;
            cout << left << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << "ENCRYPTADO" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << ID;
            cout << setw(20) << nombre;
            cout << setw(15) << apellido;
            cout << setw(15) << correo;
            cout << setw(15) << numeroCelular;
            cout << setw(15) << IDVehiculo << endl;
            cout << "------------------------" << endl;

            cout << "DESENCRYPTADO" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << Desencryptar(ID);
            cout << setw(20) << Desencryptar(nombre);
            cout << setw(15) << Desencryptar(apellido);
            cout << setw(15) << Desencryptar(correo);
            cout << setw(15) << Desencryptar(numeroCelular);
            cout << setw(15) << Desencryptar(IDVehiculo) << endl;
            cout << "====================================================================" << endl;
            cout << "1) ID" << endl;
            cout << "2) Nombre" << endl;
            cout << "3) Apellido" << endl;
            cout << "4) Correo" << endl;
            cout << "5) Celular" << endl;
            cout << "6) IDVehiculo" << endl;
            cout << "Selecciona el atributo que deseas modificar" << endl;
            cin >> opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
                cout << "ID" << endl;
                cout << "Introduce el nuevo ID del Cliente" << endl;
                getline(cin, ID);
                ID = Encryptar(ID);
                IDsize = ID.size();
                break;

            case 2:
                cout << "Nombre" << endl;
                cout << "Introduce el nuevo Nombre del Cliente" << endl;
                getline(cin, nombre);
                nombre = Encryptar(nombre);
                nombreSize = nombre.size();
                break;

            case 3:
                cout << "Apellido" << endl;
                cout << "Introduce el nuevo Apellido del Cliente" << endl;
                getline(cin, apellido);
                apellido = Encryptar(apellido);
                apellidoSize = apellido.size();
                break;

            case 4:
                cout << "Correo" << endl;
                cout << "Introduce el nuevo Correo del Cliente" << endl;
                getline(cin, correo);
                correo = Encryptar(correo);
                correoSize = correo.size();
                break;

            case 5:
                cout << "Celular" << endl;
                cout << "Introduce el nuevo Celular del Cliente" << endl;
                getline(cin, numeroCelular);
                numeroCelular = Encryptar(numeroCelular);
                numeroCelularSize = numeroCelular.size();
                break;

            case 6:
                cout << "IDVehiculo" << endl;
                cout << "Introduce el nuevo ID del Vehiculo" << endl;
                getline(cin, IDVehiculo);
                IDVehiculo = Encryptar(IDVehiculo);
                IDVehiculoSize = IDVehiculo.size();
                break;

            default:
                cout << "Error: opcion invalida" << endl;
                break;
            }
        }
        archivoTemporal.write((char *)&IDsize, sizeof(int));
        archivoTemporal.write(ID.c_str(), IDsize);

        archivoTemporal.write((char *)&nombreSize, sizeof(int));
        archivoTemporal.write(nombre.c_str(), nombreSize);

        archivoTemporal.write((char *)&apellidoSize, sizeof(int));
        archivoTemporal.write(apellido.c_str(), apellidoSize);

        archivoTemporal.write((char *)&correoSize, sizeof(int));
        archivoTemporal.write(correo.c_str(), correoSize);

        archivoTemporal.write((char *)&numeroCelularSize, sizeof(int));
        archivoTemporal.write(numeroCelular.c_str(), numeroCelularSize);

        archivoTemporal.write((char *)&IDVehiculoSize, sizeof(int));
        archivoTemporal.write(IDVehiculo.c_str(), IDVehiculoSize);
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("ClientesEncryptation.txt");
    rename("ClientesEncryptationTemp.txt", "ClientesEncryptation.txt");
    cout << "Se ha actualizado la informacion" << endl;
}

void Cliente::EliminarEncriptacion(string ClienteBuscado)
{
    ClienteBuscado = Encryptar(ClienteBuscado);
    ifstream archivo("ClientesEncryptation.txt");
    ofstream archivoTemporal("ClientesEncryptationTemp.txt", ios::app);
    int cont = 0;
    int opc;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado;

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);

        if (ID == ClienteBuscado)
        {
            cont++;
            cout << left << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << "ENCRYPTADO" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << ID;
            cout << setw(20) << nombre;
            cout << setw(15) << apellido;
            cout << setw(15) << correo;
            cout << setw(15) << numeroCelular;
            cout << setw(15) << IDVehiculo << endl;
            cout << "------------------------" << endl;

            cout << "DESENCRYPTADO" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << Desencryptar(ID);
            cout << setw(20) << Desencryptar(nombre);
            cout << setw(15) << Desencryptar(apellido);
            cout << setw(15) << Desencryptar(correo);
            cout << setw(15) << Desencryptar(numeroCelular);
            cout << setw(15) << Desencryptar(IDVehiculo) << endl;
            cout << "====================================================================" << endl;
            cout << "Desear eliminar este Cliente?" << endl;
            cout << "1) SI" << endl;
            cout << "2) N0" << endl;
            cout << "Selecciona una opcion" << endl;
            cin >> opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
                cout << "Cliente eliminado correctamente" << endl;
                break;

            case 2:
                cout << "Regresando al menu principal" << endl;
                return;
                break;

            default:
                cout << "Error: opcion invalida" << endl;
                break;
            }
        }

        if (ID != ClienteBuscado)
        {
            archivoTemporal.write((char *)&IDsize, sizeof(int));
            archivoTemporal.write(ID.c_str(), IDsize);

            archivoTemporal.write((char *)&nombreSize, sizeof(int));
            archivoTemporal.write(nombre.c_str(), nombreSize);

            archivoTemporal.write((char *)&apellidoSize, sizeof(int));
            archivoTemporal.write(apellido.c_str(), apellidoSize);

            archivoTemporal.write((char *)&correoSize, sizeof(int));
            archivoTemporal.write(correo.c_str(), correoSize);

            archivoTemporal.write((char *)&numeroCelularSize, sizeof(int));
            archivoTemporal.write(numeroCelular.c_str(), numeroCelularSize);

            archivoTemporal.write((char *)&IDVehiculoSize, sizeof(int));
            archivoTemporal.write(IDVehiculo.c_str(), IDVehiculoSize);
        }
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("ClientesEncryptation.txt");
    rename("ClientesEncryptationTemp.txt", "ClientesEncryptation.txt");
}

void Cliente::Crear()
{
    ofstream archivoClientes("Clientes.txt", ios::app);

    if (archivoClientes.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    cout << "Bienvenido a crear Cliente" << endl;
    cout << "Ingrese el ID del Cliente" << endl;
    getline(cin, ID);

    cout << "Ingresa el Nombre del Cliente" << endl;
    getline(cin, nombre);

    cout << "Ingresa el Apellido del Cliente" << endl;
    getline(cin, apellido);

    cout << "Ingrese el Correo del Cliente" << endl;
    getline(cin, correo);

    cout << "Ingrese el Celular del Cliente" << endl;
    getline(cin, numeroCelular);

    cout << "Ingrese el ID del Vehiculo" << endl;
    getline(cin, IDVehiculo);
    int IDsize = ID.size(), nombreSize = nombre.size(), apellidoSize = apellido.size(), correoSize = correo.size(), numeroCelularSize = numeroCelular.size(), IDVehiculoSize = IDVehiculo.size();

    archivoClientes.write((char *)&IDsize, sizeof(int));
    archivoClientes.write(ID.c_str(), IDsize);

    archivoClientes.write((char *)&nombreSize, sizeof(int));
    archivoClientes.write(nombre.c_str(), nombreSize);

    archivoClientes.write((char *)&apellidoSize, sizeof(int));
    archivoClientes.write(apellido.c_str(), apellidoSize);

    archivoClientes.write((char *)&correoSize, sizeof(int));
    archivoClientes.write(correo.c_str(), correoSize);

    archivoClientes.write((char *)&numeroCelularSize, sizeof(int));
    archivoClientes.write(numeroCelular.c_str(), numeroCelularSize);

    archivoClientes.write((char *)&IDVehiculoSize, sizeof(int));
    archivoClientes.write(IDVehiculo.c_str(), IDVehiculoSize);

    archivoClientes.close();
};

void Cliente::Mostrar()
{
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    ifstream archivo("Clientes.txt", ios::app);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);
        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "Nombre";
        cout << setw(10) << "Apellido";
        cout << setw(15) << "Correo";
        cout << setw(15) << "Celular";
        cout << setw(10) << "IDVehiculo" << endl;
        cout << setw(10) << ID;
        cout << setw(10) << nombre;
        cout << setw(10) << apellido;
        cout << setw(15) << correo;
        cout << setw(15) << numeroCelular;
        cout << setw(10) << IDVehiculo << endl;
        cout << "------------------------" << endl;
    }

    archivo.close();
}

void Cliente::Buscar(string ClienteBuscado)
{
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    ifstream archivo("Clientes.txt");
    int cont = 0;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    Cliente Cliente;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado << endl;

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);
        if (ID == ClienteBuscado)
        {
            cont++;
            cout << left << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << ID;
            cout << setw(20) << nombre;
            cout << setw(15) << apellido;
            cout << setw(15) << correo;
            cout << setw(15) << numeroCelular;
            cout << setw(15) << IDVehiculo << endl;
            cout << "------------------------" << endl;
        }
    }
    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
}

void Cliente::Modificar(string ClienteBuscado)
{
    ifstream archivo("Clientes.txt");
    ofstream archivoTemporal("ClientesTemp.txt", ios::app);
    int cont = 0;
    int opc;
    string newValue;
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    Cliente Cliente;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado;

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);

        if (ID == ClienteBuscado)
        {
            cont++;
            cout << left << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << ID;
            cout << setw(20) << nombre;
            cout << setw(15) << apellido;
            cout << setw(15) << correo;
            cout << setw(15) << numeroCelular;
            cout << setw(15) << IDVehiculo << endl;
            cout << "====================================================================" << endl;
            cout << "1) ID" << endl;
            cout << "2) Nombre" << endl;
            cout << "3) Apellido" << endl;
            cout << "4) Correo" << endl;
            cout << "5) Celular" << endl;
            cout << "6) IDVehiculo" << endl;
            cout << "Selecciona el atributo que deseas modificar" << endl;
            cin >> opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
                cout << "ID" << endl;
                cout << "Introduce el nuevo ID del Cliente" << endl;
                getline(cin, ID);
                IDsize = ID.size();
                break;

            case 2:
                cout << "Nombre" << endl;
                cout << "Introduce el nuevo Nombre del Cliente" << endl;
                getline(cin, nombre);
                nombreSize = nombre.size();
                break;

            case 3:
                cout << "Apellido" << endl;
                cout << "Introduce el nuevo Apellido del Cliente" << endl;
                getline(cin, apellido);
                apellidoSize = apellido.size();
                break;

            case 4:
                cout << "Correo" << endl;
                cout << "Introduce el nuevo Correo del Cliente" << endl;
                getline(cin, correo);
                correoSize = correo.size();
                break;

            case 5:
                cout << "Celular" << endl;
                cout << "Introduce el nuevo Celular del Cliente" << endl;
                getline(cin, numeroCelular);
                numeroCelularSize = numeroCelular.size();
                break;

            case 6:
                cout << "IDVehiculo" << endl;
                cout << "Introduce el nuevo ID del Vehiculo" << endl;
                getline(cin, IDVehiculo);
                IDVehiculoSize = IDVehiculo.size();
                break;

            default:
                cout << "Error: opcion invalida" << endl;
                break;
            }
        }
        archivoTemporal.write((char *)&IDsize, sizeof(int));
        archivoTemporal.write(ID.c_str(), IDsize);

        archivoTemporal.write((char *)&nombreSize, sizeof(int));
        archivoTemporal.write(nombre.c_str(), nombreSize);

        archivoTemporal.write((char *)&apellidoSize, sizeof(int));
        archivoTemporal.write(apellido.c_str(), apellidoSize);

        archivoTemporal.write((char *)&correoSize, sizeof(int));
        archivoTemporal.write(correo.c_str(), correoSize);

        archivoTemporal.write((char *)&numeroCelularSize, sizeof(int));
        archivoTemporal.write(numeroCelular.c_str(), numeroCelularSize);

        archivoTemporal.write((char *)&IDVehiculoSize, sizeof(int));
        archivoTemporal.write(IDVehiculo.c_str(), IDVehiculoSize);
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("Clientes.txt");
    rename("ClientesTemp.txt", "Clientes.txt");
    cout << "Se ha actualizado la informacion" << endl;
}

void Cliente::Eliminar(string ClienteBuscado)
{
    ifstream archivo("Clientes.txt");
    ofstream archivoTemporal("ClientesTemp.txt", ios::app);
    int cont = 0;
    int opc;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado;

    while (true)
    {
        archivo.read((char *)&IDsize, sizeof(int));
        ID.resize(IDsize);
        archivo.read((char *)&ID[0], IDsize);

        if (archivo.eof())
            break;

        archivo.read((char *)&nombreSize, sizeof(int));
        nombre.resize(nombreSize);
        archivo.read((char *)&nombre[0], nombreSize);

        archivo.read((char *)&apellidoSize, sizeof(int));
        apellido.resize(apellidoSize);
        archivo.read((char *)&apellido[0], apellidoSize);

        archivo.read((char *)&correoSize, sizeof(int));
        correo.resize(correoSize);
        archivo.read((char *)&correo[0], correoSize);

        archivo.read((char *)&numeroCelularSize, sizeof(int));
        numeroCelular.resize(numeroCelularSize);
        archivo.read((char *)&numeroCelular[0], numeroCelularSize);

        archivo.read((char *)&IDVehiculoSize, sizeof(int));
        IDVehiculo.resize(IDVehiculoSize);
        archivo.read((char *)&IDVehiculo[0], IDVehiculoSize);

        if (ID == ClienteBuscado)
        {
            cont++;
            cout << left << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << setw(15) << "ID";
            cout << setw(20) << "Nombre";
            cout << setw(15) << "Apellido";
            cout << setw(15) << "Correo";
            cout << setw(15) << "Celular";
            cout << setw(15) << "IDVehiculo" << endl;
            cout << setw(15) << ID;
            cout << setw(20) << nombre;
            cout << setw(15) << apellido;
            cout << setw(15) << correo;
            cout << setw(15) << numeroCelular;
            cout << setw(15) << IDVehiculo << endl;
            cout << "====================================================================" << endl;
            cout << "Desear eliminar este Cliente?" << endl;
            cout << "1) SI" << endl;
            cout << "2) N0" << endl;
            cout << "Selecciona una opcion" << endl;
            cin >> opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
                cout << "Cliente eliminado correctamente" << endl;
                break;

            case 2:
                cout << "Regresando al menu principal" << endl;
                return;
                break;

            default:
                cout << "Error: opcion invalida" << endl;
                break;
            }
        }

        if (ID != ClienteBuscado)
        {
            archivoTemporal.write((char *)&IDsize, sizeof(int));
            archivoTemporal.write(ID.c_str(), IDsize);

            archivoTemporal.write((char *)&nombreSize, sizeof(int));
            archivoTemporal.write(nombre.c_str(), nombreSize);

            archivoTemporal.write((char *)&apellidoSize, sizeof(int));
            archivoTemporal.write(apellido.c_str(), apellidoSize);

            archivoTemporal.write((char *)&correoSize, sizeof(int));
            archivoTemporal.write(correo.c_str(), correoSize);

            archivoTemporal.write((char *)&numeroCelularSize, sizeof(int));
            archivoTemporal.write(numeroCelular.c_str(), numeroCelularSize);

            archivoTemporal.write((char *)&IDVehiculoSize, sizeof(int));
            archivoTemporal.write(IDVehiculo.c_str(), IDVehiculoSize);
        }
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("Clientes.txt");
    rename("ClientesTemp.txt", "Clientes.txt");
}

string Cliente::getID()
{
    return this->ID;
}

string Cliente::getNombre()
{
    return this->nombre;
}

string Cliente::getApellido()
{
    return this->apellido;
}

string Cliente::getCorreo()
{
    return this->correo;
}

string Cliente::getnumeroCelular()
{
    return this->numeroCelular;
}

string Cliente::getIDVehiculo()
{
    return this->IDVehiculo;
}

void Cliente::setID(string IDvalor)
{
    this->ID = IDvalor;
}

void Cliente::setNombre(string nombreValor)
{
    this->nombre = nombreValor;
}

void Cliente::setApellido(string apellidoValor)
{
    this->apellido = apellidoValor;
}

void Cliente::setCorreo(string correoValor)
{
    this->correo = correoValor;
}

void Cliente::setNumeroCelular(string numeroValor)
{
    this->numeroCelular = numeroValor;
}

void Cliente::setIDVehiculo(string IDvalor)
{
    this->IDVehiculo = IDvalor;
}