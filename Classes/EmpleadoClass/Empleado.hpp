#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP
#include <string>
#include "Indice.hpp"
#include "../../Functions/functions.hpp"
using namespace std;

class Empleado
{
private:
    string ID = generarID();
    string nombre;
    string apellido;
    string ciudadOrigen;
    string estadoOrigen;
    string colonia;
    string calle;
    string numeroCasa;
    string direccion;
    int CP;

public:
    Empleado();
    Empleado(string ID, string nombre, string apellido, string ciudadOrigen, string estadoOrige, string colonia, string calle, string numeroCasa, int CP);
    ~Empleado();
    void Crear(Empleado &Empleado, Indice &indice);
    void Mostrar(Empleado &Empleado, Indice &indice);
    void Buscar(Empleado &Empleado, string ID, Indice &indice);
    void Eliminar(Empleado &Empleado, string ID, Indice &indice);
    void Modificar(Empleado &Empleado, string ID, Indice &indice);
    string getID();
    string getNombre();
    string getApellido();
    string getCiudadOrigen();
    string getEstadoOrigen();
    string getColonia();
    string getCalle();
    string getNumeroCasa();
    string getDirrecion();
    int getCP();

    void setID(string ID);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setCiudadOrigen(string ciudadOrigen);
    void setEstadoOrigen(string estadoOrigen);
    void setColonia(string colonia);
    void setCalle(string calle);
    void setNumeroCasa(string numeroCasa);
    void setDirrecion(string dirrecion);
    void setCP(int CP);
};

#endif