#include <iostream>
#include <iomanip>
#include <fstream>
#include "Cliente.hpp"
using namespace std;

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

    archivoClientes.write(ID.data(), ID.size());
    archivoClientes.write("\0", sizeof(char));

    archivoClientes.write(nombre.data(), nombre.size());
    archivoClientes.write("\0", sizeof(char));

    archivoClientes.write(apellido.data(), apellido.size());
    archivoClientes.write("\0", sizeof(char));

    archivoClientes.write(correo.data(), correo.size());
    archivoClientes.write("\0", sizeof(char));

    archivoClientes.write(numeroCelular.data(), numeroCelular.size());
    archivoClientes.write("\0", sizeof(char));

    archivoClientes.write(IDVehiculo.data(), IDVehiculo.size());
    archivoClientes.write("\0", sizeof(char));

    archivoClientes.close();
};

void Cliente::Mostrar()
{
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    ifstream archivo("Clientes.txt");

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (true)
    {
        getline(archivo, ID, '\0');
        getline(archivo, nombre, '\0');
        if (archivo.eof())
            break;
        getline(archivo, apellido, '\0');
        getline(archivo, correo, '\0');
        getline(archivo, numeroCelular, '\0');
        getline(archivo, IDVehiculo, '\0');
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
    Cliente Cliente;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado << endl;

    while (true)
    {
        getline(archivo, ID, '\0');
        getline(archivo, nombre, '\0');
        if (archivo.eof())
            break;
        getline(archivo, apellido, '\0');
        getline(archivo, correo, '\0');
        getline(archivo, numeroCelular, '\0');
        getline(archivo, IDVehiculo, '\0');
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
    Cliente Cliente;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado;

    while (true)
    {
        getline(archivo, ID, '\0');
        getline(archivo, nombre, '\0');
        if (archivo.eof())
            break;
        getline(archivo, apellido, '\0');
        getline(archivo, correo, '\0');
        getline(archivo, numeroCelular, '\0');
        getline(archivo, IDVehiculo, '\0');
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
                break;

            case 2:
                cout << "Nombre" << endl;
                cout << "Introduce el nuevo Nombre del Cliente" << endl;
                getline(cin, nombre);
                break;

            case 3:
                cout << "Apellido" << endl;
                cout << "Introduce el nuevo Apellido del Cliente" << endl;
                getline(cin, apellido);
                break;

            case 4:
                cout << "Correo" << endl;
                cout << "Introduce el nuevo Correo del Cliente" << endl;
                getline(cin, correo);
                break;

            case 5:
                cout << "Celular" << endl;
                cout << "Introduce el nuevo Celular del Cliente" << endl;
                getline(cin, numeroCelular);
                break;

            case 6:
                cout << "IDVehiculo" << endl;
                cout << "Introduce el nuevo ID del Vehiculo" << endl;
                getline(cin, IDVehiculo);
                break;

            default:
                cout << "Error: opcion invalida" << endl;
                break;
            }
        }
        archivoTemporal.write(ID.data(), ID.size());
        archivoTemporal.write("\0", sizeof(char));

        archivoTemporal.write(nombre.data(), nombre.size());
        archivoTemporal.write("\0", sizeof(char));

        archivoTemporal.write(apellido.data(), apellido.size());
        archivoTemporal.write("\0", sizeof(char));

        archivoTemporal.write(correo.data(), correo.size());
        archivoTemporal.write("\0", sizeof(char));

        archivoTemporal.write(numeroCelular.data(), numeroCelular.size());
        archivoTemporal.write("\0", sizeof(char));

        archivoTemporal.write(IDVehiculo.data(), IDVehiculo.size());
        archivoTemporal.write("\0", sizeof(char));
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
    string newValue;
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ClienteBuscado;

    while (true)
    {
        getline(archivo, ID, '\0');
        getline(archivo, nombre, '\0');
        if (archivo.eof())
            break;
        getline(archivo, apellido, '\0');
        getline(archivo, correo, '\0');
        getline(archivo, numeroCelular, '\0');
        getline(archivo, IDVehiculo, '\0');

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
            archivoTemporal.write(ID.data(), ID.size());
            archivoTemporal.write("\0", sizeof(char));

            archivoTemporal.write(nombre.data(), nombre.size());
            archivoTemporal.write("\0", sizeof(char));

            archivoTemporal.write(apellido.data(), apellido.size());
            archivoTemporal.write("\0", sizeof(char));

            archivoTemporal.write(correo.data(), correo.size());
            archivoTemporal.write("\0", sizeof(char));

            archivoTemporal.write(numeroCelular.data(), numeroCelular.size());
            archivoTemporal.write("\0", sizeof(char));

            archivoTemporal.write(IDVehiculo.data(), IDVehiculo.size());
            archivoTemporal.write("\0", sizeof(char));
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