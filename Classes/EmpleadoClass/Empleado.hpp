#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP
#include <string>
using namespace std;

class Empleado
{
private:
    string ID;
    string nombre;
    string apellido;
    string ciudadOrigen;
    string estadoOrigen;
    string colonia;
    string calle;
    string numeroCasa;
    string direccion;
    int CP;
    long int pos;

public:
    Empleado();
    Empleado(string ID, string nombre, string apellido, string ciudadOrigen, string estadoOrige, string colonia, string calle, string numeroCasa, int CP, long int pos);
    ~Empleado();
    void Crear(Empleado &Empleado, int ID);
    void Mostrar(Empleado &Empleado);
    void Buscar(Empleado &Empleado ,int ID);
    void Eliminar(Empleado &Empleado ,int ID);
    void Modificar(Empleado &Empleado ,int ID);
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
    long int getPos();

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
    void setPos(long int pos);

};

#endif