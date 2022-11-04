#ifndef FACTURA_HPP
#define FACTURA_HPP
#include "../EmpleadoClass/Indice.hpp"
#include <string>
using namespace std;

class Factura
{
    int ID;
    int IDCliente;
    int IDAuto;
    int IDServicio;
public:
    Factura();
    Factura(int ID, int IDCliente, int IDAuto, int IDServicio);
    ~Factura();
    void Crear(Factura &Factura, Indice &indice);
    void Mostrar(Factura &Factura, Indice &indice);
    void Buscar(Factura &Factura, int ID, Indice &indice);
    void Eliminar(Factura &Factura, int ID, Indice &indice);
    void Modificar(Factura &Factura, int ID, Indice &indice);

    int getID();
    int getIDCliente();
    int getIDAuto();
    int getIDServicio();

    void setID(int ID);
    void setIDCliente(int IDCliente);
    void setIDAuto(int IDAuto);
    void setIDServicio(int IDServicio);
};

#endif
