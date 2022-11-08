#ifndef SERVICIO_HPP
#define SERVICIO_HPP
#include "../EmpleadoClass/Indice.hpp"
#include "../../Functions/functions.hpp"
#include <string>
using namespace std;

class Servicio
{
private:
    string ID;
    string nombre;
    int precio;
    bool disponible;
public:
    Servicio();
    Servicio(string id, string nombre, int precio, bool disponible);
    ~Servicio();
    void Crear(int contServicios ,Servicio &Servicio, Indice &indice);
    void Mostrar(Servicio &Servicio, Indice &indice);
    void Buscar(Servicio &Servicio, string ID, Indice &indice);
    void Eliminar(Servicio &Servicio, string ID, Indice &indice);
    void Modificar(Servicio &Servicio, string ID, Indice &indice);

    string getID();
    string getNombre();
    int getPrecio();
    bool getDisponible();

    void setID(string ID);
    void setNombre(string nombre);
    void setPrecio(int precio);
    void setDisponible(bool disponible);
};

#endif