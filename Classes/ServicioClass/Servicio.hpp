#ifndef SERVICIO_HPP
#define SERVICIO_HPP
#include "../EmpleadoClass/Indice.hpp"
#include <string>
using namespace std;

class Servicio
{
private:
    int ID;
    string nombre;
    int precio;
    bool disponible;
public:
    Servicio();
    Servicio(int id, string nombre, int precio, bool disponible);
    ~Servicio();
    void Crear(Servicio &Servicio, Indice &indice);
    void Mostrar(Servicio &Servicio, Indice &indice);
    void Buscar(Servicio &Servicio, int ID, Indice &indice);
    void Eliminar(Servicio &Servicio, int ID, Indice &indice);
    void Modificar(Servicio &Servicio, int ID, Indice &indice);

    int getID();
    string getNombre();
    int getPrecio();
    bool getDisponible();

    void setID(int ID);
    void setNombre(string nombre);
    void setPrecio(int precio);
    void setDisponible(bool disponible);
};

#endif