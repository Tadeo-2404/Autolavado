#include <iostream>
#include <fstream>
#include "Classes/MenuClass/menu.cpp"
using namespace std;

int main()
{
    int opc;
    Menu menu;
    do
    {
        cout << "AUTOLAVADO" << endl;
        cout << "1) Producto" << endl;
        cout << "2) Cliente" << endl;
        cout << "3) Ticket" << endl;
        cout << "4) Empleado" << endl;
        cout << "5) Servicio" << endl;
        cout << "6) Promocion" <<endl;
        cout << "0) Salir" <<endl;
        cin>>opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "Producto" << endl;
            menu.MenuProducto();
            break;
        }

        case 2:
        {
            cout << "Cliente" << endl;
            menu.MenuCliente();
            break;
        }

        case 3:
        {
            cout << "Ticket" << endl;
            menu.MenuTicket();
            break;
        }

        case 4:
        {
            cout << "Empleado" << endl;
            menu.MenuEmpleado();
            break;
        }

        case 5:
        {
            cout << "Servicio" << endl;
            menu.MenuServicio();
            break;
        }

        case 6:
        {
            cout << "Servicio" << endl;
            menu.MenuPromociones();
            break;
        }

        case 0:
        {
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);

    return 0;
}
