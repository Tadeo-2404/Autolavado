#ifndef TICKET_HPP
#define TICKET_HPP
#include <string>
using namespace std;

class Ticket {
    int ID;
    int cont;
    string IDAuto;
    string IDCliente;
    string IDServicio;
public:
   Ticket();
   Ticket(int ID,string IDAuto, string IDCliente, string IDServicio);
    void Crear(Ticket &ticket, int ID);
    void Mostrar(Ticket &ticket);
    void Buscar(Ticket &ticket ,int codigo);
    void Eliminar(Ticket &ticket ,int codigo);
    void Modificar(Ticket &ticket ,int codigo);
    int getID();
   string getIDAuto();
   string getIDCliente();
   string getIDServicio();
   void setID(int ID);
   void setIDAuto(string IDAuto);
   void setIDCliente(string IDCliente);
   void setIDServicio(string IDServicio);
};

#endif