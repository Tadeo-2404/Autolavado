#include <iostream>
#include "Ticket.hpp"
#include <fstream>
#include <iomanip>
using namespace std;

Ticket::Ticket() 
{

}


Ticket::Ticket(string IDAuto, string IDCliente, string IDServicio) 
{
    this->IDAuto = IDAuto;
    this->IDCliente = IDCliente;
    this->IDServicio = IDServicio;
}

void Ticket::Crear(Ticket &ticket)
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
        cout << setw(10) << "IDAuto";
        cout << setw(10) << "IDCliente";
        cout << setw(10) << "IDServicio" << endl;
        cout << setw(10) << ticket.getIDAuto();
        cout << setw(10) << ticket.getIDCliente();
        cout << setw(10) << ticket.getIDServicio() << endl;
        cout << "------------------------" << endl;
    }

    archivo.close();
}

void Ticket::Buscar(string ticketBuscado)
{
    ticketBuscado = "hola";
}

void Ticket::Modificar(string ticketBuscado)
{
    ticketBuscado = "hola";
}

void Ticket::Eliminar(string ticketBuscado)
{
    ticketBuscado = "hola";
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
