#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include<iostream>
using namespace std;

class Producto {
    string codigo;
    string codigoProvedor;
    string descripcion;
    string precioCompra;
    string precioVenta;
public:
    Producto(); //Constructor
    Producto(string codigo, string codigoProvedor, string precioVenta, string precioCompra, string descripcion);
    ~Producto();
    void Crear();
    void Mostrar();
    void Buscar(string codigo);
    void Eliminar(string codigo);
    void Modificar(string codigo);

    //GETTERS
    string getCodigo();
    string getCodigoProvedor();
    string getDescripcion();
    string getPrecioCompra();
    string getPrecioVenta();

    //SETTERS
    void setCodigo(string codigo);
    void setCodigoProvedor(string provedor); 
    void setDescripcion(string descripcion);
    void setPrecioCompra(string precioCompra);
    void setPrecioVenta(string precioVenta);

};

#endif // PRODUCTO_HPP
