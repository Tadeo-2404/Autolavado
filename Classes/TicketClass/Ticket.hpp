#ifndef TICKET_HPP
#define TICKET_HPP
#include <string>
using namespace std;

class Ticket {
    string IDAuto;
    string IDCliente;
    string IDServicio;
public:
   Ticket();
   Ticket(string IDAuto, string IDCliente, string IDServicio);
    void Crear();
    void Mostrar();
    void Buscar(string codigo);
    void Eliminar(string codigo);
    void Modificar(string codigo);
   string getIDAuto();
   string getIDCliente();
   string getIDServicio();
   void setIDAuto(string IDAuto);
   void setIDCliente(string IDCliente);
   void setIDServicio(string IDServicio);
};

#endif