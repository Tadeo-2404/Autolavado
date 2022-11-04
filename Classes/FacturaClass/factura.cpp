#include <iostream>
#include <fstream>
#include <iomanip>
#include "Factura.hpp"
#include "../EmpleadoClass/indice.cpp"
using namespace std;

Factura::Factura()
{
    this->ID = NULL;
    this->IDCliente = NULL;
    this->IDServicio = NULL;
    this->IDAuto = NULL;
}

Factura::Factura(int ID, int IDCliente, int IDAuto, int IDServicio) 
{
    this->ID = ID;
    this->IDCliente = IDCliente;
    this->IDAuto = IDAuto;
    this->IDServicio = IDServicio;
}

Factura::~Factura()
{
    
}

void Factura::Crear(Factura &factura, Indice &indice)
{
    int temp;
    ofstream archivoFacturas, archivoIndices;
    archivoFacturas.open("Facturas.bin", ios::app | ios::binary);

    if(archivoFacturas.fail()) {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit(1);
    }

    cout << "Introduce el ID de la Factura" <<endl;
    cin>>temp;
    cin.ignore();
    factura.setID(temp);

    cout << "Introduce el ID del Cliente" <<endl;
    cin>>temp;
    cin.ignore();
    factura.setIDCliente(temp);

    cout << "Introduce el ID del Auto" <<endl;
    cin>>temp;
    cin.ignore();
    factura.setIDAuto(temp);

    cout << "Introduce el ID del Servicio" <<endl;
    cin>>temp;
    cin.ignore();
    factura.setIDServicio(temp);

    int pos = (factura.getID()-1)*sizeof(Factura);
    archivoFacturas.seekp(pos, ios::beg);
    archivoFacturas.write(reinterpret_cast<char*>(&factura), sizeof(Factura));
    archivoFacturas.close();
    indice.setPos(pos);
    indice.setID(to_string(ID));
    archivoIndices.open("Indices.bin", ios::app | ios::binary);
    archivoIndices.write(reinterpret_cast<char*>((&indice)), sizeof(Indice));
    archivoIndices.close();
    cout << "Registro almacenado correctamente" <<endl;
}

void Factura::Mostrar(Factura &factura, Indice &indice)
{
    ifstream archivoFacturas("Facturas.bin", ios::app | ios::binary);
    ifstream archivoIndices("Indices.bin", ios::app | ios::binary);

    if (archivoFacturas.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    if (archivoIndices.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Facturas" <<endl;

    while (true)
    {
        archivoFacturas.read(reinterpret_cast<char*>(&factura),sizeof(Factura));
        if(archivoFacturas.eof()) break;

        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "IDCliente";
        cout << setw(10) << "IDAuto";
        cout << setw(10) << "IDServicio" << endl;
        cout << setw(10) << factura.getID();
        cout << setw(10) << factura.getIDCliente();
        cout << setw(10) << factura.getIDAuto();
        cout << setw(10) << factura.getIDServicio() <<endl;
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
    archivoFacturas.close();
}

void Factura::Buscar(Factura &factura ,int ID, Indice &indice) 
{
    ifstream archivoFacturas("Facturas.bin", ios::app | ios::binary);
    ifstream  archivoIndices("Indices.bin", ios::app | ios::binary);
    int cont = 0;

    if (archivoIndices.fail() || archivoFacturas.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ID << endl;

    while (true)
    {
        archivoIndices.read((char*)(&indice), sizeof(indice));
        if(archivoIndices.eof()) break;

        if (stoi(indice.getID()) == ID)
        {
            archivoFacturas.seekg((stoi(indice.getID()) - 1) * sizeof(Factura), ios::beg);
            archivoFacturas.read((char *)&factura, sizeof(Factura));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "IDCliente";
            cout << setw(10) << "IDAuto";
            cout << setw(10) << "IDServicio" << endl;
            cout << setw(10) << factura.getID();
            cout << setw(10) << factura.getIDCliente();
            cout << setw(10) << factura.getIDAuto();
            cout << setw(10) << factura.getIDServicio() << endl;
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
    archivoFacturas.close();
}
    
void Factura::Eliminar(Factura &factura ,int ID, Indice &indice)
{
    ifstream archivoFacturas("Facturas.bin", ios::app | ios::binary);
    ifstream  archivoIndices("Indices.bin", ios::app | ios::binary);
    ofstream archivoFacturasTemp("FacturasTemp.bin", ios::app | ios::binary);
    ofstream archivoIndicesTemp("IndicesTemp.bin", ios::app | ios::binary);
    int cont = 0, opc;


    if (archivoIndices.fail() || archivoFacturas.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ID << endl;

    while (true)
    {
        archivoIndices.read((char*)(&indice), sizeof(indice));
        if(archivoIndices.eof()) break;

        if (stoi(indice.getID()) == ID)
        {
            archivoFacturas.seekg((stoi(indice.getID())-1)*sizeof(Factura), ios::beg);
            archivoFacturas.read((char*)&factura,sizeof(Factura));
            cont++;
        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "IDCliente";
        cout << setw(10) << "IDAuto";
        cout << setw(10) << "IDServicio" << endl;
        cout << setw(10) << factura.getID();
        cout << setw(10) << factura.getIDCliente();
        cout << setw(10) << factura.getIDAuto();
        cout << setw(10) << factura.getIDServicio() <<endl;
        cout << "------------------------" << endl;

            cout << "Deseas Eliminar este Factura?" <<endl;
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

        if (stoi(indice.getID()) != ID)
        {
            archivoFacturas.seekg((stoi(indice.getID())-1)*sizeof(Factura), ios::beg);
            archivoFacturas.read((char*)&factura,sizeof(Factura));
            archivoFacturasTemp.seekp(indice.getPos(), ios::beg);
            archivoFacturasTemp.write((char *)&factura, sizeof(Factura));
            archivoIndicesTemp.write((char *)(&indice), sizeof(indice));
        }
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivoFacturas.close();
    archivoFacturasTemp.close();
    archivoIndicesTemp.close();
    archivoIndices.close();
    cont = 0;
    remove("Indices.bin");
    rename("IndicesTemp.bin", "Indices.bin");
    remove("Facturas.bin");
    rename("FacturasTemp.bin", "Facturas.bin");
    cout << "Se ha elimnado el Empleado correctamente" << endl;
}

void Factura::Modificar(Factura &factura ,int ID, Indice &indice)
{
    ifstream archivoFacturas("Facturas.bin", ios::app | ios::binary);
    ifstream  archivoIndices("Indices.bin", ios::app | ios::binary);
    ofstream archivoFacturasTemp("FacturasTemp.bin", ios::app | ios::binary);
    ofstream archivoIndicesTemp("IndicesTemp.bin", ios::app | ios::binary);
    int cont = 0, opc;
    char select;

    if (archivoIndices.fail() || archivoFacturas.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ID << endl;

    while (true)
    {
        archivoIndices.read(reinterpret_cast<char*>(&indice), sizeof(Indice));
        if(archivoIndices.eof()) break;

        if (stoi(indice.getID()) == ID)
        {
            archivoFacturas.seekg((stoi(indice.getID()) - 1) * sizeof(Factura), ios::beg);
            archivoFacturas.read(reinterpret_cast<char *>(&factura), sizeof(Factura));
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "IDCliente";
            cout << setw(10) << "IDAuto";
            cout << setw(10) << "IDServicio" << endl;
            cout << setw(10) << factura.getID();
            cout << setw(10) << factura.getIDCliente();
            cout << setw(10) << factura.getIDAuto();
            cout << setw(10) << factura.getIDServicio() << endl;
            cout << "------------------------" << endl;

            cout << "Deseas modificar este empleado?" << endl;
            cout << "1) Si  2) No" << endl;
            cin >> opc;

            if (opc == 1)
            {
                cout << "a) Modificar ID" << endl;
                cout << "b) Modificar IDCliente" << endl;
                cout << "c) Modificar IDAuto" << endl;
                cout << "d) Modificar IDServicio" << endl;
                cout << "e) Salir" << endl;
                cin >> select;
                cin.ignore();

                switch (select)
                {
                case 'a':
                {
                    cout << "Modificar ID" << endl;
                    cout << "Introduce el nuevo ID" << endl;
                    cin>>opc;
                    factura.setID(opc);
                    break;
                }

                case 'b':
                {
                    cout << "Modificar IDCliente" << endl;
                    cout << "Introduce el nuevo IDCliente" << endl;
                    cin>>opc;
                    factura.setIDCliente(opc);
                    break;
                }

                case 'c':
                {
                    cout << "Modificar IDAuto" << endl;
                    cout << "Introduce el nuevo IDAuto" << endl;
                    cin>>opc;
                    factura.setIDAuto(opc);
                    break;
                }

                case 'd':
                {
                    cout << "Modificar IDServicio" << endl;
                    cout << "Introduce el nuevo IDServicio" << endl;
                    cin>>opc;
                    factura.setIDServicio(opc);
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

        archivoFacturas.read(reinterpret_cast<char*>(&factura), sizeof(Factura));
        archivoFacturasTemp.write(reinterpret_cast<char *>(&factura), sizeof(Factura));
        archivoIndicesTemp.write(reinterpret_cast<char *>(&indice), sizeof(Indice));
    }
    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivoFacturas.close();
    archivoFacturasTemp.close();
    archivoIndicesTemp.close();
    archivoIndices.close();
    cont = 0;
    remove("Indices.bin");
    rename("IndicesTemp.bin", "Indices.bin");
    remove("Facturas.bin");
    rename("FacturasTemp.bin", "Facturas.bin");
    cout << "Se ha modificado el atributo correctamente" <<endl;
}

int Factura::getID()
{
    return this->ID;
}

int Factura::getIDCliente()
{
    return this->IDCliente;
}

int Factura::getIDAuto()
{
    return this->IDAuto;
}

int Factura::getIDServicio()
{
    return this->IDServicio;
}

void Factura::setID(int ID)
{
    this->ID = ID;
}

void Factura::setIDCliente(int IDCliente) 
{
    this->IDCliente = IDCliente;
}

void Factura::setIDAuto(int IDAuto)
{
    this->IDAuto = IDAuto;
}

void Factura::setIDServicio(int IDServicio)
{
    this->IDServicio = IDServicio;
}
