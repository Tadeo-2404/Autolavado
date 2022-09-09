#include <iostream>
#include "Ticket.hpp"
#include <fstream>
#include <iomanip>
using namespace std;

Ticket::Ticket() 
{

}


Ticket::Ticket(int ID,string IDAuto, string IDCliente, string IDServicio) 
{
    this->ID = ID;
    this->IDAuto = IDAuto;
    this->IDCliente = IDCliente;
    this->IDServicio = IDServicio;
}

void Ticket::Crear(Ticket &ticket, int ID)
{
    ofstream archivoTickets("Tickets.txt", ios::app);
    string IDAuto, IDCliente, IDServicio;

    if (archivoTickets.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Bienvenido a crear Ticket" << endl;
    cout << "Ingrese el ID del Cliente" << endl;
    getline(cin, IDCliente);
    ticket.setIDCliente(IDCliente);

    cout << "Ingresa el ID del Auto" << endl;
    getline(cin, IDAuto);
    ticket.setIDAuto(IDAuto),

    cout << "Ingresa el ID del Servicio" << endl;
    getline(cin, IDServicio);
    ticket.setIDServicio(IDServicio);
    ticket.setID(ID);

    archivoTickets.write(reinterpret_cast<char*>(&ticket) ,sizeof(ticket));

    archivoTickets.close();
}

void Ticket::Mostrar(Ticket &ticket) 
{
    ifstream archivo("Tickets.txt", ios::in);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (true)
    {
        archivo.read(reinterpret_cast<char*>(&ticket), sizeof(ticket));
        if(archivo.eof()) break;

        cout << left << endl;
        cout << setw(10) << "ID";
        cout << setw(10) << "IDAuto";
        cout << setw(10) << "IDCliente";
        cout << setw(10) << "IDServicio" << endl;
        cout << setw(10) << ticket.getID();
        cout << setw(10) << ticket.getIDAuto();
        cout << setw(10) << ticket.getIDCliente();
        cout << setw(10) << ticket.getIDServicio() << endl;
        cout << "------------------------" << endl;
    }

    archivo.close();
}

void Ticket::Buscar(Ticket &ticket ,int ticketBuscado)
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
        archivo.read(reinterpret_cast<char*>(&ticket), sizeof(ticket));
        if(archivo.eof()) break;

        if (ticket.getID() == ticketBuscado)
        {
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "IDAuto";
            cout << setw(10) << "IDCliente";
            cout << setw(10) << "IDServicio" << endl;
            cout << setw(10) << ticket.getID();
            cout << setw(10) << ticket.getIDAuto();
            cout << setw(10) << ticket.getIDCliente();
            cout << setw(10) << ticket.getIDServicio() << endl;
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

void Ticket::Modificar(Ticket &ticket, int ticketBuscado)
{
    ifstream archivo("Tickets.txt");
    ofstream archivoTemporal("TicketsTemp.txt", ios::app);
    int cont = 0;
    int opc;
    string IDAuto, IDCliente, IDServicio;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ticketBuscado;

    while (true)
    {
        archivo.read(reinterpret_cast<char*>(&ticket), sizeof(ticket));
        if (archivo.eof())
            break;

        if (ticket.getID() == ticketBuscado)
        {
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "IDAuto";
            cout << setw(10) << "IDCliente";
            cout << setw(10) << "IDServicio" << endl;
            cout << setw(10) << ticket.getID();
            cout << setw(10) << ticket.getIDAuto();
            cout << setw(10) << ticket.getIDCliente();
            cout << setw(10) << ticket.getIDServicio() << endl;
            cout << "------------------------" << endl;
            cout << "1) IDAuto" << endl;
            cout << "2) IDCliente" << endl;
            cout << "3) IDServicio" << endl;
            cout << "Selecciona el atributo que deseas modificar" << endl;
            cin >> opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
                cout << "IDAuto" << endl;
                cout << "Introduce el nuevo ID del Auto" << endl;
                getline(cin, IDAuto);
                ticket.setIDAuto(IDAuto);
                break;

            case 2:
                cout << "IDCliente" << endl;
                cout << "Introduce el nuevo ID del Cliente" << endl;
                getline(cin, IDCliente);
                ticket.setIDCliente(IDCliente);
                break;

            case 3:
                cout << "IDServicio" << endl;
                cout << "Introduce el nuevo ID del Servicio" << endl;
                getline(cin, IDServicio);
                ticket.setIDServicio(IDServicio);
                break;

            default:
                cout << "Error: opcion invalida" << endl;
                break;
            }
        }
      archivoTemporal.write(reinterpret_cast<char*>(&ticket) ,sizeof(ticket));
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("Tickets.txt");
    rename("TicketsTemp.txt", "Tickets.txt");
    cout << "Se ha actualizado la informacion" << endl;
}

void Ticket::Eliminar(Ticket &ticket ,int ticketBuscado)
{
    ifstream archivo("Tickets.txt");
    ofstream archivoTemporal("TicketsTemp.txt", ios::app);
    int cont = 0;
    int opc;
    string IDAuto, IDCliente, IDServicio;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << ticketBuscado;

    while (true)
    {
        archivo.read(reinterpret_cast<char*>(&ticket), sizeof(ticket));
        if (archivo.eof())
            break;

        if (ticket.getID() == ticketBuscado)
        {
            cont++;
            cout << left << endl;
            cout << setw(10) << "ID";
            cout << setw(10) << "IDAuto";
            cout << setw(10) << "IDCliente";
            cout << setw(10) << "IDServicio" << endl;
            cout << setw(10) << ticket.getID();
            cout << setw(10) << ticket.getIDAuto();
            cout << setw(10) << ticket.getIDCliente();
            cout << setw(10) << ticket.getIDServicio() << endl;
            cout << "------------------------" << endl;
            cout << "Desear eliminar este Ticket?" << endl;
            cout << "1) SI" << endl;
            cout << "2) N0" << endl;
            cout << "Selecciona una opcion" << endl;
            cin >> opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
            {
                cout << "Ticket eliminado correctamente" << endl;
                break;
            }

            case 2:
                cout << "Regresando al menu principal" << endl;
                return;
                break;

            default:
                cout << "Error: opcion invalida" << endl;
                break;
            }
        }

        if (ticket.getID() != ticketBuscado)
        {
            archivoTemporal.write(reinterpret_cast<char *>(&ticket), sizeof(ticket));
        }
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("Tickets.txt");
    rename("TicketsTemp.txt", "Tickets.txt");
    cout << "Se ha actualizado la informacion" << endl;
}

int Ticket::getID() 
{
    return this->ID;
}

string Ticket::getIDAuto()
{
    return this->IDAuto;
}

string Ticket::getIDCliente()
{
    return this->IDCliente;
}

string Ticket::getIDServicio() 
{
    return this->IDServicio;
}

void Ticket::setID(int ID)
{
    this->ID = ID;
}

void Ticket::setIDAuto(string IDAuto)
{
    this->IDAuto = IDAuto;
}

void Ticket::setIDCliente(string IDCliente)
{
    this->IDCliente = IDCliente;
}

void Ticket::setIDServicio(string IDServicio)
{
    this->IDServicio = IDServicio;
}
