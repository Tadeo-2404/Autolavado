#ifndef TICKET_HPP
#define TICKET_HPP
#include <string>
#include "../../Functions/functions.hpp"
using namespace std;

class Ticket {
    string ID = generarID();
    string IDAuto;
    string IDCliente;
    string IDServicio;
public:
   Ticket();
   Ticket(string ID,string IDAuto, string IDCliente, string IDServicio);
    void Crear(Ticket &ticket);
    void Mostrar(Ticket &ticket);
    void Buscar(Ticket &ticket ,string codigo);
    void Eliminar(Ticket &ticket ,string codigo);
    void Modificar(Ticket &ticket ,string codigo);
    string getID();
   string getIDAuto();
   string getIDCliente();
   string getIDServicio();
   void setID(string ID);
   void setIDAuto(string IDAuto);
   void setIDCliente(string IDCliente);
   void setIDServicio(string IDServicio);
};

#endif