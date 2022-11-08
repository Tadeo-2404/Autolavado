#ifndef FACTURA_HPP
#define FACTURA_HPP
#include "../EmpleadoClass/Indice.hpp"
#include "../../Functions/Functions.hpp"
#include <string>
using namespace std;

class Factura
{
    string ID;
    string IDCliente;
    string IDAuto;
    string IDServicio;
public:
    Factura();
    Factura(string ID, string IDCliente, string IDAuto, string IDServicio);
    ~Factura();
    void Crear(int contFactura, Factura &Factura, Indice &indice);
    void Mostrar(Factura &Factura, Indice &indice);
    void Buscar(Factura &Factura, string ID, Indice &indice);
    void Eliminar(Factura &Factura, string ID, Indice &indice);
    void Modificar(Factura &Factura, string ID, Indice &indice);

    string getID();
    string getIDCliente();
    string getIDAuto();
    string getIDServicio();

    void setID(string ID);
    void setIDCliente(string IDCliente);
    void setIDAuto(string IDAuto);
    void setIDServicio(string IDServicio);
};

#endif
