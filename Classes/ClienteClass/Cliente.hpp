#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
using namespace std;

class Cliente
{
    string ID;
    string nombre;
    string apellido;
    string correo;
    string numeroCelular;
    string IDVehiculo;

public:
    Cliente();
    Cliente(string ID, string nombre, string apellido, string correo, string numeroCelular, string IDVehiculo);
    void Crear();
    void Mostrar();
    void Buscar(string codigo);
    void Eliminar(string codigo);
    void Modificar(string codigo);

    void CrearEncriptacion();
    void MostrarEncriptacion();
    void BuscarEncriptacion(string codigo);
    void EliminarEncriptacion(string codigo);
    void ModificarEncriptacion(string codigo);
    
    string getID();
    string getNombre();
    string getApellido();
    string getCorreo();
    string getnumeroCelular();
    string getIDVehiculo();
    void setID(string ID);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setCorreo(string apellido);
    void setNumeroCelular(string numeroCelular);
    void setIDVehiculo(string ID);
};

#endif