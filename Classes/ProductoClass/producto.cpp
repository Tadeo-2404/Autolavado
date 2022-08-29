#include <iostream>
#include <fstream>
#include <iomanip>
#include "Producto.hpp"
using namespace std;

Producto::Producto()
{
}

Producto::Producto(string codigo, string codigoProvedor, string precioVenta, string precioCompra, string descripcion)
{
    this->codigo = codigo;
    this->codigoProvedor = codigoProvedor;
    this->precioVenta = precioVenta;
    this->precioCompra = precioCompra;
    this->descripcion = descripcion;
}

Producto::~Producto()
{
}

void Producto::Crear()
{
    ofstream archivoProductos("productos.txt", ios::app);

    if (archivoProductos.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string codigo, codigoProvedor, precioVenta, precioCompra, descripcion;
    cout << "Bienvenido a crear producto" << endl;
    cout << "Ingrese el codigo de 10 digitos para el producto" << endl;
    getline(cin, codigo);

    cout << "Ingresa el Codigo del proveedor" << endl;
    getline(cin, codigoProvedor);

    cout << "Ingresa el precio de compra: ";
    getline(cin, precioCompra);

    cout << "Ingrese el precio de Venta: ";
    getline(cin, precioVenta);

    cout << "Ingrese una descripcion: ";
    getline(cin, descripcion);

    archivoProductos << codigo << ',' << codigoProvedor << ',' << precioCompra << ',' << precioVenta << ',' << descripcion << endl;
    archivoProductos.close();
};

void Producto::Mostrar()
{
    string codigo, codigoProvedor, precioVenta, precioCompra, descripcion;
    ifstream archivo("productos.txt");

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (true)
    {
        getline(archivo, codigo, ',');
        if (archivo.eof())
            break;
        getline(archivo, codigoProvedor, ',');
        getline(archivo, precioVenta, ',');
        getline(archivo, precioCompra, ',');
        getline(archivo, descripcion);
        Producto producto(codigo, codigoProvedor, precioVenta, precioCompra, descripcion);
        cout << left << endl;
        cout << setw(15) << "Codigo";
        cout << setw(20) << "Codigo Provedor";
        cout << setw(15) << "Precio Venta";
        cout << setw(15) << "Precio Compra";
        cout << setw(15) << "Descripcion" << endl;
        cout << setw(15) << codigo;
        cout << setw(20) << codigoProvedor;
        cout << setw(15) << precioVenta;
        cout << setw(15) << precioCompra;
        cout << setw(15) << descripcion << endl;
        cout << "------------------------" << endl;
    }

    archivo.close();
}

void Producto::Buscar(string productoBuscado)
{
    ifstream archivo("productos.txt");
    string codigo;
    int cont = 0;
    Producto producto;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << productoBuscado;

    while (true)
    {
        getline(archivo, codigo, ',');
        if (archivo.eof())
            break;
        getline(archivo, codigoProvedor, ',');
        getline(archivo, precioVenta, ',');
        getline(archivo, precioCompra, ',');
        getline(archivo, descripcion);
        if (codigo == productoBuscado)
        {
            cont++;
            Producto producto(codigo, codigoProvedor, precioVenta, precioCompra, descripcion);
            cout << left << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << setw(15) << "Codigo";
            cout << setw(20) << "Codigo Provedor";
            cout << setw(15) << "Precio Venta";
            cout << setw(15) << "Precio Compra";
            cout << setw(15) << "Descripcion" << endl;
            cout << setw(15) << codigo;
            cout << setw(20) << codigoProvedor;
            cout << setw(15) << precioVenta;
            cout << setw(15) << precioCompra;
            cout << setw(15) << descripcion <<endl;
        }
    }
    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
}

void Producto::Modificar(string productoBuscado) 
{
    ifstream archivo("productos.txt");
    ofstream archivoTemporal("productosTemp.txt", ios::app);
    int cont = 0;
    int opc;
    string newValue;
    Producto producto;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << productoBuscado;

    while (true)
    {
        getline(archivo, codigo, ',');
        if (archivo.eof())
            break;
        getline(archivo, codigoProvedor, ',');
        getline(archivo, precioVenta, ',');
        getline(archivo, precioCompra, ',');
        getline(archivo, descripcion);

        if (codigo == productoBuscado)
        {
            cont++;
            cout << left << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << setw(15) << "Codigo";
            cout << setw(20) << "Codigo Provedor";
            cout << setw(15) << "Precio Venta";
            cout << setw(15) << "Precio Compra";
            cout << setw(15) << "Descripcion" << endl;
            cout << setw(15) << codigo;
            cout << setw(20) << codigoProvedor;
            cout << setw(15) << precioVenta;
            cout << setw(15) << precioCompra;
            cout << setw(15) << descripcion <<endl;

            cout << "====================================================================" <<endl;
            cout << "1) Codigo" <<endl;
            cout << "2) Codigo Provedor" <<endl;
            cout << "3) Precio Venta" <<endl;
            cout << "4) Precio Compra" <<endl;
            cout << "5) Descripcion" <<endl;
            cout << "Selecciona el atributo que deseas modificar" <<endl;
            cin>>opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
                cout << "CODIGO" <<endl;
                cout << "Introduce el nuevo codigo del producto" <<endl;
                getline(cin, codigo);
                break;

            case 2:
                cout << "CODIGO PROVEDOR" <<endl;
                cout << "Introduce el nuevo codigo del provedor" <<endl;
                getline(cin, codigoProvedor);
                break;

            case 3:
                cout << "PRECIO VENTA" <<endl;
                cout << "Introduce el nuevo precio de venta" <<endl;
                getline(cin, precioVenta);
                break;

            case 4:
                cout << "PRECIO COMPRA" <<endl;
                cout << "Introduce el nuevo precio de compra" <<endl;
                getline(cin, precioCompra);
                break;

            case 5:
                cout << "DESCRIPCION" <<endl;
                cout << "Introduce la nueva descripcion" <<endl;
                getline(cin, codigo);
                break;
            
            default: cout << "Error: opcion invalida" <<endl;
                break;
            }
        }

        archivoTemporal << codigo << ',' << codigoProvedor << ',' << precioVenta << ',' << precioCompra << ',' << descripcion << endl;
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("productos.txt");
    rename("productosTemp.txt","productos.txt");
}

void Producto::Eliminar(string productoBuscado) 
{
    ifstream archivo("productos.txt");
    ofstream archivoTemporal("productosTemp.txt", ios::app);
    int cont = 0;
    int opc;
    string newValue;
    Producto producto;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << productoBuscado;

    while (true)
    {
        getline(archivo, codigo, ',');
        if (archivo.eof())
            break;
        getline(archivo, codigoProvedor, ',');
        getline(archivo, precioVenta, ',');
        getline(archivo, precioCompra, ',');
        getline(archivo, descripcion);

        if (codigo == productoBuscado)
        {
            cont++;
            cout << left << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << setw(15) << "Codigo";
            cout << setw(20) << "Codigo Provedor";
            cout << setw(15) << "Precio Venta";
            cout << setw(15) << "Precio Compra";
            cout << setw(15) << "Descripcion" << endl;
            cout << setw(15) << codigo;
            cout << setw(20) << codigoProvedor;
            cout << setw(15) << precioVenta;
            cout << setw(15) << precioCompra;
            cout << setw(15) << descripcion <<endl;

            cout << "====================================================================" <<endl;
            cout << "Desear eliminar este producto?" <<endl;
            cout << "1) SI" <<endl;
            cout << "2) N0" <<endl;
            cout << "Selecciona una opcion" <<endl;
            cin>>opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
                cout << "Producto eliminado correctamente" <<endl;
                break;

            case 2:
                cout << "Regresando al menu principal" <<endl;
                  return;
                break;
            
            default: cout << "Error: opcion invalida" <<endl;
                break;
            }
        }

        if(codigo != productoBuscado) 
        {
           archivoTemporal << codigo << ',' << codigoProvedor << ',' << precioVenta << ',' << precioCompra << ',' << descripcion << endl;
        }
    }

    if (cont == 0)
    {
        cout << "Error: Busqueda no exitosa" << endl;
        return;
    }

    archivo.close();
    archivoTemporal.close();
    remove("productos.txt");
    rename("productosTemp.txt","productos.txt");
}