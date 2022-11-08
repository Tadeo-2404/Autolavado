#include <iostream>
#include <fstream>
#include <iomanip>
#include "Servicio.hpp"
#include "../EmpleadoClass/indice.cpp"
using namespace std;

Servicio::Servicio()
{

}

Servicio::Servicio(string id, string nombre, int precio, bool disponible) 
{
    this->ID = id;
    this->nombre = nombre;
    this->precio = precio;
    this->disponible = disponible;
}

Servicio::~Servicio()
{

}

void Servicio::Crear(int contServicio ,Servicio &servicio, Indice &indice)
{
    int temp;
    string nombre;

    ofstream archivoServicios, archivoIndices;
    archivoServicios.open("Servicios.bin", ios::app | ios::binary);

    if(archivoServicios.fail()) {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit(1);
    }

    servicio.setID(generarID());
    cout << "Introduce el Nombre del servicio" <<endl;
    getline(cin, nombre);
    servicio.setNombre(nombre);

    cout << "Introduce el Precio del servicio" <<endl;
    cin>>temp;
    servicio.setPrecio(temp);

    cout << "Esta disponible el Servicio?" <<endl;
    cout << "1)Si  0)No" <<endl;
    cin>>temp;
    servicio.setDisponible(temp);

    int pos = (contServicio-1)*sizeof(Servicio);
    archivoServicios.seekp(pos, ios::beg);
    archivoServicios.write(reinterpret_cast<char*>(&servicio), sizeof(Servicio));
    archivoServicios.close();
    indice.setPos(pos);
    indice.setID(servicio.getID());
    archivoIndices.open("Indices.bin", ios::app | ios::binary);
    archivoIndices.write(reinterpret_cast<char*>((&indice)), sizeof(Indice));
    archivoIndices.close();
    cout << "Registro almacenado correctamente" <<endl;
}

void Servicio::Mostrar(Servicio &servicio, Indice &indice)
{
    ifstream archivoServicios("Servicios.bin", ios::app | ios::binary);
    ifstream archivoIndices("Indices.bin", ios::app | ios::binary);

    if (archivoServicios.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    if (archivoIndices.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }



    cout << "Servicios" <<endl;

    while (true)
    {
        archivoServicios.read(reinterpret_cast<char*>(&servicio),sizeof(Servicio));
        if(archivoServicios.eof()) break;

        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "Nombre";
        cout << setw(10) << "Precio";
        cout << setw(10) << "Disponible" << endl;
        cout << setw(10) << servicio.getID();
        cout << setw(10) << servicio.getNombre();
        cout << setw(10) << servicio.getPrecio();
        cout << setw(10) << servicio.getDisponible() <<endl;
        cout << "------------------------" << endl;
    }

    cout << "Indices" <<endl;

    while (true)
    {
        archivoIndices.read((char*)&indice,sizeof(Indice));
        if(archivoIndices.eof()) break;

        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "POS" << endl;
        cout << setw(10) << indice.getID();
        cout << setw(10) << indice.getPos() <<endl;
        cout << "------------------------" << endl;
    }

    archivoIndices.close();
    archivoServicios.close();
}

void Servicio::Buscar(Servicio &servicio ,string ID, Indice &indice) 
{
    ifstream archivoServicios("Servicios.bin", ios::app | ios::binary);
    ifstream  archivoIndices("Indices.bin", ios::app | ios::binary);
    int cont = 0;

    if (archivoIndices.fail() || archivoServicios.fail())
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
            archivoServicios.seekg((stoi(indice.getID())-1)*sizeof(servicio), ios::beg);
            archivoServicios.read((char*)&servicio,sizeof(servicio));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "Nombre";
            cout << setw(10) << "Precio";
            cout << setw(10) << "Disponible" << endl;
            cout << setw(10) << servicio.getID();
            cout << setw(10) << servicio.getNombre();
            cout << setw(10) << servicio.getPrecio();
            cout << setw(10) << servicio.getDisponible() << endl;
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
    archivoServicios.close();
}
    
void Servicio::Eliminar(Servicio &servicio ,string ID, Indice &indice)
{
    ifstream archivoServicios("Servicios.bin", ios::app | ios::binary);
    ifstream  archivoIndices("Indices.bin", ios::app | ios::binary);
    ofstream archivoServiciosTemp("ServiciosTemp.bin", ios::app | ios::binary);
    ofstream archivoIndicesTemp("IndicesTemp.bin", ios::app | ios::binary);
    int cont = 0, opc;


    if (archivoIndices.fail() || archivoServicios.fail())
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
            archivoServicios.seekg((stoi(indice.getID())-1)*sizeof(servicio), ios::beg);
            archivoServicios.read((char*)&servicio,sizeof(servicio));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "Nombre";
            cout << setw(10) << "Precio";
            cout << setw(10) << "Disponible" << endl;
            cout << setw(10) << servicio.getID();
            cout << setw(10) << servicio.getNombre();
            cout << setw(10) << servicio.getPrecio();
            cout << setw(10) << servicio.getDisponible() << endl;
            cout << "------------------------" << endl;

            cout << "Deseas Eliminar este Servicio?" <<endl;
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
            archivoServicios.seekg((stoi(indice.getID())-1)*sizeof(servicio), ios::beg);
            archivoServicios.read((char*)&servicio,sizeof(servicio));
            archivoServiciosTemp.seekp(indice.getPos(), ios::beg);
            archivoServiciosTemp.write((char *)&servicio, sizeof(servicio));
            archivoIndicesTemp.write((char *)(&indice), sizeof(indice));
        }
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivoServicios.close();
    archivoServiciosTemp.close();
    archivoIndicesTemp.close();
    archivoIndices.close();
    cont = 0;
    remove("Indices.bin");
    rename("IndicesTemp.bin", "Indices.bin");
    remove("Servicios.bin");
    rename("ServiciosTemp.bin", "Servicios.bin");
    cout << "Se ha elimnado el Empleado correctamente" << endl;
}

void Servicio::Modificar(Servicio &servicio ,string ID, Indice &indice)
{
    ifstream archivoServicios("Servicios.bin", ios::app | ios::binary);
    ifstream  archivoIndices("Indices.bin", ios::app | ios::binary);
    ofstream archivoServiciosTemp("ServiciosTemp.bin", ios::app | ios::binary);
    ofstream archivoIndicesTemp("IndicesTemp.bin", ios::app | ios::binary);
    int cont = 0, opc;
    char select;
    string temp;

    if (archivoIndices.fail() || archivoServicios.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ID << endl;

    while (true)
    {
        archivoIndices.read(reinterpret_cast<char*>(&indice), sizeof(Indice));
        if(archivoIndices.eof()) break;

        if (indice.getID() == ID)
        {
            archivoServicios.seekg((stoi(indice.getID())-1)*sizeof(Servicio), ios::beg);
            archivoServicios.read(reinterpret_cast<char*>(&servicio),sizeof(Servicio));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "Nombre";
            cout << setw(10) << "Precio";
            cout << setw(10) << "Disponible" << endl;
            cout << setw(10) << servicio.getID();
            cout << setw(10) << servicio.getNombre();
            cout << setw(10) << servicio.getPrecio();
            cout << setw(10) << servicio.getDisponible() << endl;
            cout << "------------------------" << endl;

            cout << "Deseas modificar este empleado?" <<endl;
            cout << "1) Si  2) No" <<endl;
            cin>>opc;

            if (opc == 1)
            {
                cout << "a) Modificar ID" << endl;
                cout << "b) Modificar Nombre" << endl;
                cout << "c) Modificar Precio" << endl;
                cout << "d) Modificar Disponible" << endl;
                cout << "e) Salir" << endl;
                cin >> select;
                cin.ignore();

                switch (select)
                {
                case 'a':
                {
                    cout << "Modificar ID" << endl;
                    cout << "Introduce el nuevo ID" << endl;
                    getline(cin, temp);
                    servicio.setID(temp);
                    break;
                }

                case 'b':
                {
                    cout << "Modificar Nombre" << endl;
                    cout << "Introduce el nuevo Nombre" << endl;
                    getline(cin, temp);
                    servicio.setNombre(temp);
                    break;
                }

                case 'c':
                {
                    cout << "Modificar Precio" << endl;
                    cout << "Introduce el nuevo Precio" << endl;
                    cin>>opc;
                    servicio.setPrecio(opc);
                    break;
                }

                case 'd':
                {
                    cout << "Modificar Disponibilidad" << endl;
                    cout << "Introduce Disponibilidad 1)Si 0)No" << endl;
                    cin>>opc;
                    servicio.setDisponible(opc);
                    break;
                }

                case 'e':
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
        }

        archivoServicios.read(reinterpret_cast<char*>(&servicio), sizeof(Servicio));
        archivoServiciosTemp.write(reinterpret_cast<char *>(&servicio), sizeof(Servicio));
        archivoIndicesTemp.write(reinterpret_cast<char *>(&indice), sizeof(Indice));
    }
    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivoServicios.close();
    archivoServiciosTemp.close();
    archivoIndicesTemp.close();
    archivoIndices.close();
    cont = 0;
    remove("Indices.bin");
    rename("IndicesTemp.bin", "Indices.bin");
    remove("Servicios.bin");
    rename("ServiciosTemp.bin", "Servicios.bin");
    cout << "Se ha modificado el atributo correctamente" <<endl;
}

string Servicio::getID()
{
    return this->ID;
}

string Servicio::getNombre()
{
    return this->nombre;
}

int Servicio::getPrecio()
{
    return this->precio;
}

bool Servicio::getDisponible()
{
    return this->disponible;
}

void Servicio::setID(string id)
{
    this->ID = id;
}

void Servicio::setNombre(string nombre) 
{
    this->nombre = nombre;
}

void Servicio::setPrecio(int precio)
{
    this->precio = precio;
}

void Servicio::setDisponible(bool disponible)
{
    this->disponible = disponible;
}