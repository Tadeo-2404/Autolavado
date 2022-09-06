#include<iostream>
#include "Ticket.hpp"
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
