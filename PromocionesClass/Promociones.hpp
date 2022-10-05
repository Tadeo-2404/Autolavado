#ifndef PROMOCIONES_HPP
#define PROMOCIONES_HPP
#include <string>
using namespace std;

class Promociones {
    string nombre;
    string fechaInicioPromocion;
    string fechaFinPromocion;
    int precioOriginal:
    int precioConDescuento;
    int descuento:

public:
   Promociones();
   Promociones(string nombre, int precioOriginal, int descuento, string fechaInicioPromocion, string fechaFinPromocion);
   ~Promociones();
   string getNombre();
   string getFechaInicioPromocion();
   string getFechaFinPromocion();
   int getPrecioOriginal();
   int getPrecioConDescuento();
   int getDescuento();
   void setNombre(string nombre);
   void setFechaInicioPromocion(string fechaInicioPromocion);
   void setFechaFinPromocion(string fechaFinPromocion);
   void setPrecioOriginal(int precioOriginal);
   void setPrecioConDescuento(int precioConDescuento);
   void setDescuento(int descuento);
}

#endif