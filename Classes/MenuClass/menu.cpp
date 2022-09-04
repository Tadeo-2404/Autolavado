#include <iostream>
#include "Menu.hpp"
#include "../ClienteClass/Cliente.hpp"
#include "../ProductoClass/Producto.hpp"
#include "../ClienteClass/cliente.cpp"
#include "../ProductoClass/producto.cpp"
using namespace std;

Menu::Menu()
{

}

void Menu::MenuProducto() 
{
    int opc;
    Producto producto;
    do
    {
        cout << "Producto" << endl;
        cout << "1) Crear" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Buscar" << endl;
        cout << "4) Eliminar" << endl;
        cout << "5) Modificar" << endl;
        cout << "0) Salir" <<endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "CREAR" << endl;
            producto.Crear();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            producto.Mostrar();
            break;
        }

        case 3:
        {
            string codigoBuscado;
            cout << "BUSCAR" << endl;
            cout << "Introduce el codigo del producto a buscar" <<endl;
            getline(cin, codigoBuscado);
            producto.Buscar(codigoBuscado);
            break;
        }

        case 4:
        {
            string codigoBuscado;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el codigo del producto a eliminar" <<endl;
            getline(cin, codigoBuscado);
            producto.Eliminar(codigoBuscado);
            break;
        }

        case 5:
        {
            string codigoBuscado;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el codigo del producto a modificar" <<endl;
            getline(cin, codigoBuscado);
            producto.Modificar(codigoBuscado);
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
}

void Menu::MenuCliente()
{
    Cliente cliente;
    int opc;
    do
    {
        cout << "Cliente" << endl;
        cout << "1) Crear" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Buscar" << endl;
        cout << "4) Eliminar" << endl;
        cout << "5) Modificar" << endl;
        cout << "0) Salir" <<endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "CREAR" << endl;
            cliente.Crear();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            cliente.Mostrar();
            break;
        }

        case 3:
        {
            string IDCliente;
            cout << "BUSCAR" << endl;
            cout << "Introduce el ID del cliente a buscar" <<endl;
            getline(cin, IDCliente);
            cliente.Buscar(IDCliente);
            break;
        }

        case 4:
        {
            string IDCliente;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el ID del cliente a eliminar" <<endl;
            getline(cin, IDCliente);
            cliente.Eliminar(IDCliente);
            break;
        }

        case 5:
        {
            string IDCliente;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el ID del cliente a modificar" <<endl;
            getline(cin, IDCliente);
            cliente.Modificar(IDCliente);
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
}