#include <iostream>
#include "Empleado.hpp"
#include <fstream>
using namespace std;

Empleado::Empleado(string ID, string nombre, string apellido, string ciudadOrigen, string estadoOrigen, string colonia, string calle, string numeroCasa, int CP, long int pos)
{
    this->ID = ID;
    this->nombre = nombre;
    this->apellido = apellido;
    this->ciudadOrigen = ciudadOrigen;
    this->estadoOrigen = estadoOrigen;
    this->colonia = colonia;
    this->calle = calle;
    this->numeroCasa = numeroCasa;
    this->direccion = ciudadOrigen + "," + estadoOrigen + "," + calle + "," + "#" + numeroCasa, "," + colonia + "," + to_string(CP);
    this->CP = CP;
    this->pos = pos;
}

Empleado::~Empleado()
{

}

void Empleado::Crear(Empleado &empleado, int ID)
{

}

void Empleado::Mostrar(Empleado &empleado)
{

}

void Empleado::Buscar(Empleado &Empleado ,int ID) 
{

}
    
void Empleado::Eliminar(Empleado &Empleado ,int ID)
{

}

void Empleado::Modificar(Empleado &Empleado ,int ID)
{
    
}

string Empleado::getID() 
{
    return this->ID;
}

string Empleado::getNombre() 
{
    return this->nombre;
}

string Empleado::getApellido() 
{
    return this->apellido;
}

string Empleado::getEstadoOrigen() 
{
    return this->estadoOrigen;
}

string Empleado::getCiudadOrigen() 
{
    return this->ciudadOrigen;
}

string Empleado::getCalle() 
{
    return this->calle;
}

string Empleado::getColonia() 
{
    return this->colonia;
}

string Empleado::getDirrecion() 
{
    return this->direccion;
}

string Empleado::getNumeroCasa() 
{
    return this->numeroCasa;
}

int Empleado::getCP() 
{
    return this->CP;
}

long int Empleado::getPos()
{
    return this->pos;
}

void Empleado::setEstadoOrigen(string ID)
{
    this->ID = ID;
}

void Empleado::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Empleado::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Empleado::setEstadoOrigen(string estadoOrigen)
{
    this->estadoOrigen = estadoOrigen;
}

void Empleado::setCiudadOrigen(string ciudadOrigen)
{
    this->ciudadOrigen = ciudadOrigen;
}

void Empleado::setCalle(string calle)
{
    this->calle = calle;
}

void Empleado::setColonia(string colonia)
{
    this->colonia = colonia;
}

void Empleado::setDirrecion(string direccion)
{
    this->direccion = direccion;
}

void Empleado::setNumeroCasa(string numeroCasa)
{
    this->numeroCasa = numeroCasa;
}

void Empleado::setCP(int CP)
{
    this->CP = CP;
}

void Empleado::setPos(long int pos)
{
    this->pos = pos;
}