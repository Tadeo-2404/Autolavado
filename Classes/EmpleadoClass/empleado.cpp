#include <iostream>
#include "Empleado.hpp"
#include "Indice.hpp"
#include <iomanip>
#include <fstream>
using namespace std;

Empleado::Empleado()
{

}

Empleado::Empleado(string ID, string nombre, string apellido, string ciudadOrigen, string estadoOrigen, string colonia, string calle, string numeroCasa, int CP)
{
    this->ID = ID;
    this->nombre = nombre;
    this->apellido = apellido;
    this->ciudadOrigen = ciudadOrigen;
    this->estadoOrigen = estadoOrigen;
    this->colonia = colonia;
    this->calle = calle;
    this->numeroCasa = numeroCasa;
    this->direccion = ciudadOrigen + "," + estadoOrigen + "," + calle + "," + "#" + numeroCasa, "," + colonia + "," + to_string(CP);
    this->CP = CP;
}

Empleado::~Empleado()
{

}

void Empleado::Crear(Empleado &empleado, Indice &indice)
{
    string ID, nombre, apellido, ciudadOrigen, estadoOrigen, colonia, calle, numeroCasa;
    int CP;

    ofstream archivoEmpleados, archivoIndices;
    archivoEmpleados.open("Empleados.txt", ios::app);

    if(archivoEmpleados.fail()) {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit(1);
    }

    cout << "Introduce el ID del empleado" <<endl;
    getline(cin, ID);
    empleado.setID(ID);

    cout << "Introduce el Nombre del empleado" <<endl;
    getline(cin, nombre);
    empleado.setNombre(nombre);

    cout << "Introduce el Apellido del empleado" <<endl;
    getline(cin, apellido);
    empleado.setApellido(apellido);

    cout << "Introduce la Ciudad de Origen del empleado" <<endl;
    getline(cin, ciudadOrigen);
    empleado.setCiudadOrigen(ciudadOrigen);

    cout << "Introduce el Estado de Origen del empleado" <<endl;
    getline(cin, estadoOrigen);
    empleado.setEstadoOrigen(estadoOrigen);

    cout << "Introduce la Colonia del empleado" <<endl;
    getline(cin, colonia);
    empleado.setColonia(colonia);

    cout << "Introduce la Calle del empleado" <<endl;
    getline(cin, calle);
    empleado.setCalle(calle);

    cout << "Introduce el CP del empleado" <<endl;
    cin>>CP;
    empleado.setCP(CP);

    int pos = (stoi(empleado.getID())-1)*sizeof(empleado);
    archivoEmpleados.seekp(pos, ios::beg);
    archivoEmpleados.write((char*)&empleado, sizeof(empleado));
    archivoEmpleados.close();
    indice.setPos(pos);
    indice.setID(empleado.getID());
    archivoIndices.open("Indices.txt", ios::app);
    archivoIndices.write((char*)(&indice), sizeof(indice));
    archivoIndices.close();
    cout << "Registro almacenado correctamente" <<endl;
}

void Empleado::Mostrar(Empleado &empleado, Indice &indice)
{
    ifstream archivoEmpleados("Empleados.txt", ios::app);
    ifstream archivoIndices("Indices.txt", ios::app);

    if (archivoEmpleados.fail() || archivoIndices.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Empleados" <<endl;

    while (true)
    {
        archivoEmpleados.read((char*)&empleado,sizeof(empleado));
        if(archivoEmpleados.eof()) break;

        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "Nombre";
        cout << setw(10) << "Apellido";
        cout << setw(15) << "Ciudad";
        cout << setw(15) << "Estado";
        cout << setw(15) << "Colonia";
        cout << setw(15) << "Calle";
        cout << setw(10) << "CP" << endl;
        cout << setw(10) << empleado.getID();
        cout << setw(10) << empleado.getNombre();
        cout << setw(10) << empleado.getApellido();
        cout << setw(15) << empleado.getCiudadOrigen();
        cout << setw(15) << empleado.getEstadoOrigen();
        cout << setw(15) << empleado.getColonia();
        cout << setw(15) << empleado.getCalle();
        cout << setw(10) << empleado.getCP() <<endl;
        cout << "------------------------" << endl;
    }

    cout << "Indices" <<endl;

    while (true)
    {
        archivoIndices.read((char*)&indice,sizeof(indice));
        if(archivoIndices.eof()) break;

        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "POS" << endl;
        cout << setw(10) << indice.getID();
        cout << setw(10) << indice.getPos() <<endl;
        cout << "------------------------" << endl;
    }

    archivoIndices.close();
    archivoEmpleados.close();
}

void Empleado::Buscar(Empleado &empleado ,string ID, Indice &indice) 
{
    ifstream archivoEmpleados("Empleados.txt", ios::app);
    ifstream  archivoIndices("Indices.txt", ios::app);
    int cont = 0;

    if (archivoIndices.fail() || archivoEmpleados.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ID << endl;

    while (true)
    {
        archivoIndices.read((char*)(&indice), sizeof(indice));
        if(archivoIndices.eof()) break;

        if (indice.getID() == ID)
        {
            archivoEmpleados.seekg((stoi(indice.getID())-1)*sizeof(empleado), ios::beg);
            archivoEmpleados.read((char*)&empleado,sizeof(empleado));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "Nombre";
            cout << setw(10) << "Apellido";
            cout << setw(10) << "Ciudad";
            cout << setw(10) << "Estado";
            cout << setw(10) << "Colonia";
            cout << setw(10) << "Calle";
            cout << setw(10) << "CP" << endl;
            cout << setw(10) << empleado.getID();
            cout << setw(10) << empleado.getNombre();
            cout << setw(10) << empleado.getApellido();
            cout << setw(10) << empleado.getCiudadOrigen();
            cout << setw(10) << empleado.getEstadoOrigen();
            cout << setw(10) << empleado.getColonia();
            cout << setw(10) << empleado.getCalle();
            cout << setw(10) << empleado.getCP() << endl;
            cout << "------------------------" << endl;
        }
    }
    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    cont = 0;
    archivoIndices.close();
    archivoEmpleados.close();
}
    
void Empleado::Eliminar(Empleado &empleado ,string ID, Indice &indice)
{
    ifstream archivoEmpleados("Empleados.txt", ios::app);
    ifstream  archivoIndices("Indices.txt", ios::app);
    ofstream archivoEmpleadosTemp("EmpleadosTemp.txt", ios::app);
    ofstream archivoIndicesTemp("IndicesTemp.txt", ios::app);
    int cont = 0, opc;


    if (archivoIndices.fail() || archivoEmpleados.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ID << endl;

    while (true)
    {
        archivoIndices.read((char*)(&indice), sizeof(indice));
        if(archivoIndices.eof()) break;

        if (indice.getID() == ID)
        {
            archivoEmpleados.seekg((stoi(indice.getID())-1)*sizeof(empleado), ios::beg);
            archivoEmpleados.read((char*)&empleado,sizeof(empleado));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "Nombre";
            cout << setw(10) << "Apellido";
            cout << setw(10) << "Ciudad";
            cout << setw(10) << "Estado";
            cout << setw(10) << "Colonia";
            cout << setw(10) << "Calle";
            cout << setw(10) << "CP" << endl;
            cout << setw(10) << empleado.getID();
            cout << setw(10) << empleado.getNombre();
            cout << setw(10) << empleado.getApellido();
            cout << setw(10) << empleado.getCiudadOrigen();
            cout << setw(10) << empleado.getEstadoOrigen();
            cout << setw(10) << empleado.getColonia();
            cout << setw(10) << empleado.getCalle();
            cout << setw(10) << empleado.getCP() << endl;
            cout << "------------------------" << endl;

            cout << "Deseas Eliminar este empleado?" <<endl;
            cout << "1) Si  2) No" <<endl;
            cin>>opc;

            if (opc == 1)
            {
                cout << "Eliminado correctamente" << endl;
            }
            else
            {
                cout << "Regresando al menu principal" << endl;
                return;
            }
        }

        if (indice.getID() != ID)
        {
            archivoEmpleados.seekg((stoi(indice.getID())-1)*sizeof(empleado), ios::beg);
            archivoEmpleados.read((char*)&empleado,sizeof(empleado));
            archivoEmpleadosTemp.seekp(indice.getPos(), ios::beg);
            archivoEmpleadosTemp.write((char *)&empleado, sizeof(empleado));
            archivoIndicesTemp.write((char *)(&indice), sizeof(indice));
        }
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivoEmpleados.close();
    archivoEmpleadosTemp.close();
    archivoIndicesTemp.close();
    archivoIndices.close();
    cont = 0;
    remove("Indices.txt");
    rename("IndicesTemp.txt", "Indices.txt");
    remove("Empleados.txt");
    rename("EmpleadosTemp.txt", "Empleados.txt");
    cout << "Se ha elimnado el Empleado correctamente" << endl;
}

void Empleado::Modificar(Empleado &empleado ,string ID, Indice &indice)
{
    ifstream archivoEmpleados("Empleados.txt", ios::app);
    ifstream  archivoIndices("Indices.txt", ios::app);
    ofstream archivoEmpleadosTemp("EmpleadosTemp.txt", ios::app);
    ofstream archivoIndicesTemp("IndicesTemp.txt", ios::app);
    int cont = 0, opc;
    char select;
    string temp;

    if (archivoIndices.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ID << endl;

    while (true)
    {
        archivoIndices.read((char*)(&indice), sizeof(indice));
        if(archivoIndices.eof()) break;

        if (indice.getID() == ID)
        {
            archivoEmpleados.seekg((stoi(indice.getID())-1)*sizeof(empleado), ios::beg);
            archivoEmpleados.read((char*)&empleado,sizeof(empleado));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "Nombre";
            cout << setw(10) << "Apellido";
            cout << setw(10) << "Ciudad";
            cout << setw(10) << "Estado";
            cout << setw(10) << "Colonia";
            cout << setw(10) << "Calle";
            cout << setw(10) << "CP" << endl;
            cout << setw(10) << empleado.getID();
            cout << setw(10) << empleado.getNombre();
            cout << setw(10) << empleado.getApellido();
            cout << setw(10) << empleado.getCiudadOrigen();
            cout << setw(10) << empleado.getEstadoOrigen();
            cout << setw(10) << empleado.getColonia();
            cout << setw(10) << empleado.getCalle();
            cout << setw(10) << empleado.getCP() << endl;
            cout << "------------------------" << endl;

            cout << "Deseas modificar este empleado?" <<endl;
            cout << "1) Si  2) No" <<endl;
            cin>>opc;

            if (opc == 1)
            {
                cout << "a) Modificar ID" << endl;
                cout << "b) Modificar Nombre" << endl;
                cout << "c) Modificar Apellido" << endl;
                cout << "d) Modificar Ciudad" << endl;
                cout << "e) Modificar Estado" << endl;
                cout << "f) Modificar Colonia" << endl;
                cout << "g) Modificar Calle" << endl;
                cout << "h) Modificar CP" << endl;
                cout << "i) Salir" << endl;
                cin >> select;
                cin.ignore();

                switch (select)
                {
                case 'a':
                {
                    cout << "Modificar ID" << endl;
                    cout << "Introduce el nuevo ID" << endl;
                    getline(cin, temp);
                    empleado.setID(temp);
                    break;
                }

                case 'b':
                {
                    cout << "Modificar Nombre" << endl;
                    cout << "Introduce el nuevo Nombre" << endl;
                    getline(cin, temp);
                    empleado.setNombre(temp);
                    break;
                }

                case 'c':
                {
                    cout << "Modificar Apellido" << endl;
                    cout << "Introduce el nuevo Apellido" << endl;
                    getline(cin, temp);
                    empleado.setApellido(temp);
                    break;
                }

                case 'd':
                {
                    cout << "Modificar Ciudad" << endl;
                    cout << "Introduce el nuevo Ciudad" << endl;
                    getline(cin, temp);
                    empleado.setCiudadOrigen(temp);
                    break;
                }

                case 'e':
                {
                    cout << "Modificar Estado" << endl;
                    cout << "Introduce el nuevo Estado" << endl;
                    getline(cin, temp);
                    empleado.setEstadoOrigen(temp);
                    break;
                }

                case 'f':
                {
                    cout << "Modificar Colonia" << endl;
                    cout << "Introduce el nuevo Colonia" << endl;
                    getline(cin, temp);
                    empleado.setColonia(temp);
                    break;
                }

                case 'g':
                {
                    cout << "Modificar Calle" << endl;
                    cout << "Introduce el nuevo Calle" << endl;
                    getline(cin, temp);
                    empleado.setCalle(temp);
                    break;
                }

                case 'h':
                {
                    cout << "Modificar CP" << endl;
                    cout << "Introduce el nuevo CP" << endl;
                    cin >> opc;
                    empleado.setCP(opc);
                    break;
                }

                case 'i':
                {
                    cout << "Salir" << endl;
                    cout << "Saliendo..." << endl;
                    break;
                }

                default:
                    cout << "Error: Opcion no valida" << endl;
                    break;
                }
            }
            else
            {
                cout << "Regresando al menu principal" << endl;
                return;
            }

           archivoEmpleadosTemp.seekp(indice.getPos(), ios::beg);
           archivoEmpleadosTemp.write((char *)&empleado, sizeof(empleado));
           archivoIndicesTemp.write((char *)(&indice), sizeof(indice));
        }

        archivoEmpleados.read((char*)&empleado,sizeof(empleado));
        if(archivoEmpleados.eof()) break;
        archivoEmpleadosTemp.seekp(indice.getPos(), ios::beg);
        archivoEmpleadosTemp.write((char *)&empleado, sizeof(empleado));
        archivoIndices.read((char*)(&indice), sizeof(indice));
        if(archivoIndices.eof()) break;
        archivoIndicesTemp.write((char *)(&indice), sizeof(indice));
    }
    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivoEmpleados.close();
    archivoEmpleadosTemp.close();
    archivoIndicesTemp.close();
    archivoIndices.close();
    cont = 0;
    remove("Indices.txt");
    rename("IndicesTemp.txt", "Indices.txt");
    remove("Empleados.txt");
    rename("EmpleadosTemp.txt", "Empleados.txt");
    cout << "Se ha modificado el atributo correctamente" <<endl;
}

string Empleado::getID() 
{
    return this->ID;
}

string Empleado::getNombre() 
{
    return this->nombre;
}

string Empleado::getApellido() 
{
    return this->apellido;
}

string Empleado::getEstadoOrigen() 
{
    return this->estadoOrigen;
}

string Empleado::getCiudadOrigen() 
{
    return this->ciudadOrigen;
}

string Empleado::getCalle() 
{
    return this->calle;
}

string Empleado::getColonia() 
{
    return this->colonia;
}

string Empleado::getDirrecion() 
{
    return this->direccion;
}

string Empleado::getNumeroCasa() 
{
    return this->numeroCasa;
}

int Empleado::getCP() 
{
    return this->CP;
}

void Empleado::setID(string ID)
{
    this->ID = ID;
}

void Empleado::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Empleado::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Empleado::setEstadoOrigen(string estadoOrigen)
{
    this->estadoOrigen = estadoOrigen;
}

void Empleado::setCiudadOrigen(string ciudadOrigen)
{
    this->ciudadOrigen = ciudadOrigen;
}

void Empleado::setCalle(string calle)
{
    this->calle = calle;
}

void Empleado::setColonia(string colonia)
{
    this->colonia = colonia;
}

void Empleado::setDirrecion(string direccion)
{
    this->direccion = direccion;
}

void Empleado::setNumeroCasa(string numeroCasa)
{
    this->numeroCasa = numeroCasa;
}

void Empleado::setCP(int CP)
{
    this->CP = CP;
}