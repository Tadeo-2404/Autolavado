#include <iostream>
#include "Promociones.hpp"
using namespace std;

int calcularPrecio();

Promociones::Promociones()
{

}

Promociones::Promociones(string nombre, int precioOriginal, int descuento, string fechaInicioPromocion, string fechaFinPromocion) 
{
    this->nombre = nombre;
    this->precioOriginal = precioOriginal;
    this->descuento = descuento;
    this->precioConDescuento = calcularPrecio(precioOriginal, descuento); 
    this->fechaInicioPromocion = fechaInicioPromocion;
    this->fechaFinPromocion = fechaFinPromocion;
}

string getNombre()
{
    return this->nombre;
}

string getFechaInicioPromocion() 
{
    return this-> fechaInicioPromocion;
}

string getFechaFinPromocion() 
{
    return this-> fechaFinPromocion;
}

int getPrecioOriginal()
{
    return this-> precioOriginal;
}

int getPrecioConDescuento()
{
    return this-> precioConDescuento;
}

int getDescuento()
{
    return this->descuento;
}

void setNombre(string nombre)
{
    this->nombre = nombre;
}

void setFechaInicioPromocion(string fechaInicioPromocion)
{
    this->fechaInicioPromocion = fechaInicioPromocion;
}

void setFechaFinPromocion(string fechaFinPromocion)
{
    this->fechaFinPromocion = fechaFinPromocion;
}

void setPrecioOriginal(int precioOriginal)
{
    this->precioOriginal = precioOriginal;
}

void setPrecioConDescuento(int precioConDescuento)
{
    this->precioConDescuento = precioConDescuento;
}

void setDescuento(int descuento)
{
    this->descuento = descuento
}

int calcularPrecio(int precioOriginal, int descuento)
{
    int precioConDescuento;
    int valorDescuento;
    int porcentaje:
    porcentaje = descuento* 0.01;
    valorDescuento = precioOriginal*porcentaje;

    return precioOriginal - valorDescuento;
}

