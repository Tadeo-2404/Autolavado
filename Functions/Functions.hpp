#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include "time.h"
#include "../ClienteClass/cliente.cpp"
#include "../ProductoClass/producto.cpp"
#include "../TicketClass/Ticket.cpp"
#include "../EmpleadoClass/Empleado.cpp"
#include "../ServicioClass/servicio.cpp"
#include "../FacturaClass/factura.cpp"

string generarID()
{
    srand(time(NULL));
    const int size = 36;
    int length = 1 + rand() % 10;
    char characters[size] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                             'h', 'i', 'j', 'k', 'l', 'm', 'n',
                             'o', 'p', 'q', 'r', 's', 't', 'u',
                             'v', 'w', 'x', 'y', 'z', '0', '1',
                             '2', '3', '4', '5', '6', '7', '8',
                             '9'};
    string result = "";
    for (int i = 0; i < length; i++)
        result = result + characters[rand() % size];

    return result;
};

bool ClienteExiste(string clienteBuscado)
{
    string ID, nombre, apellido, correo, numeroCelular, IDVehiculo;
    ifstream archivo("Clientes.txt");
    int cont = 0;
    int IDsize = 0, nombreSize = 0, apellidoSize = 0, correoSize = 0, numeroCelularSize = 0, IDVehiculoSize = 0;
    Cliente Cliente;

    if (archivo.fail())
    {
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

        if (ID == clienteBuscado)
        {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

bool AutoExiste(string ID)
{
    bool flag = false;
    return flag;
}

bool ServicioExiste(Servicio &servicio, string ID, Indice &indice)
{
    bool flag = false;
    ifstream archivoServicios("Servicios.bin", ios::app | ios::binary);
    ifstream archivoIndices("Indices.bin", ios::app | ios::binary);
    int cont = 0;

    if (archivoIndices.fail() || archivoServicios.fail())
    {
        return;
    }

    while (true)
    {
        archivoIndices.read((char *)(&indice), sizeof(indice));
        if (archivoIndices.eof())
            break;

        if (indice.getID() == ID)
        {
            archivoIndices.close();
            archivoServicios.close();
            return true;
        }
    }

    archivoIndices.close();
    archivoServicios.close();
    return false;
}

bool TicketExiste(string ticketBuscado)
{
    ifstream archivo("Tickets.txt");
    int cont = 0;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ticketBuscado << endl;

    while (true)
    {
        archivo.read(reinterpret_cast<char *>(&ticket), sizeof(ticket));
        if (archivo.eof())
            break;

        if (ticket.getID() == ticketBuscado)
        {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;;
}

bool FacturaExiste(Factura &factura ,string ID, Indice &indice)
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
        if (archivoIndices.eof())
            break;

        if (indice.getID() == ID)
        {
            archivoIndices.close();
            archivoFacturas.close();
            return true;
        }
    }

    archivoIndices.close();
    archivoFacturas.close();
    return false;
}

bool EmpleadoExiste(Empleado &empleado ,string ID, Indice &indice)
{
        ifstream archivoEmpleados("Empleados.txt", ios::app);
    ifstream  archivoIndices("Indices.txt", ios::app);
    int cont = 0;

    if (archivoIndices.fail() || archivoEmpleados.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (true)
    {
        archivoIndices.read((char*)(&indice), sizeof(indice));
        if(archivoIndices.eof()) break;

        if (indice.getID() == ID)
        {
            archivoIndices.close();
            archivoEmpleados.close();
            return false;
        }
    }

    archivoIndices.close();
    archivoEmpleados.close();
    return true;
}

#endif
