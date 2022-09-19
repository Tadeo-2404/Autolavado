#include <iostream>
#include "Menu.hpp"
#include "../AdminClass/Admin.hpp"
#include "../AdminClass/Admin.cpp"
using namespace std;

Menu::Menu()
{

}

void Menu::MenuProducto() 
{
    Admin admin;
    int opc;
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
            admin.crearProducto();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            admin.mostrarProductos();
            break;
        }

        case 3:
        {
            string codigoBuscado;
            cout << "BUSCAR" << endl;
            cout << "Introduce el codigo del producto a buscar" <<endl;
            getline(cin, codigoBuscado);
            admin.buscarProductos(codigoBuscado);
            break;
        }

        case 4:
        {
            string codigoBuscado;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el codigo del producto a eliminar" <<endl;
            getline(cin, codigoBuscado);
            admin.eliminarProductos(codigoBuscado);
            break;
        }

        case 5:
        {
            string codigoBuscado;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el codigo del producto a modificar" <<endl;
            getline(cin, codigoBuscado);
            admin.modificarProductos(codigoBuscado);
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
    Admin admin;
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
            admin.crearCliente();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            admin.mostrarClientes();
            break;
        }

        case 3:
        {
            string IDCliente;
            cout << "BUSCAR" << endl;
            cout << "Introduce el ID del cliente a buscar" <<endl;
            getline(cin, IDCliente);
            admin.buscarClientes(IDCliente);
            break;
        }

        case 4:
        {
            string IDCliente;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el ID del cliente a eliminar" <<endl;
            getline(cin, IDCliente);
            admin.eliminarClientes(IDCliente);
            break;
        }

        case 5:
        {
            string IDCliente;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el ID del cliente a modificar" <<endl;
            getline(cin, IDCliente);
            admin.modificarClientes(IDCliente);
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
}

void Menu::MenuTicket()
{
    Admin admin;
    int opc;
    do
    {
        cout << "Ticket" << endl;
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
            admin.crearTicket();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            admin.mostrarTickets();
            break;
        }

        case 3:
        {
            int IDticket;
            cout << "BUSCAR" << endl;
            cout << "Introduce el ID del ticket a buscar" <<endl;
            cin>>IDticket;
            admin.buscarTickets(IDticket);
            break;
        }

        case 4:
        {
            int IDticket;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el ID del ticket a eliminar" <<endl;
            cin>>IDticket;
            admin.eliminarTickets(IDticket);
            break;
        }

        case 5:
        {
            int IDticket;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el ID del ticket a modificar" <<endl;
            cin>>IDticket;
            admin.modificarTickets(IDticket);
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
}

void Menu::MenuEmpleado()
{
        Admin admin;
    int opc;
    do
    {
        cout << "Ticket" << endl;
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
            admin.crearTicket();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            admin.mostrarTickets();
            break;
        }

        case 3:
        {
            int IDticket;
            cout << "BUSCAR" << endl;
            cout << "Introduce el ID del ticket a buscar" <<endl;
            cin>>IDticket;
            admin.buscarTickets(IDticket);
            break;
        }

        case 4:
        {
            int IDticket;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el ID del ticket a eliminar" <<endl;
            cin>>IDticket;
            admin.eliminarTickets(IDticket);
            break;
        }

        case 5:
        {
            int IDticket;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el ID del ticket a modificar" <<endl;
            cin>>IDticket;
            admin.modificarTickets(IDticket);
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
}