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
        cout << "1) Registrar Cliente" << endl;
        cout << "2) Registrar Ticket" << endl;
        cout << "3) Registrar Factura" << endl;
        cout << "4) Registrar Empleado" << endl;
        cout << "5) Registrar Servicio" << endl;
        cout << "6) Registrar Promocion" <<endl;
        cout << "0) Salir" <<endl;
        cin>>opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "Cliente" << endl;
            menu.MenuCliente();
            break;
        }

        case 2:
        {
            cout << "Ticket" << endl;
            menu.MenuTicket();
            break;
        }

        case 3:
        {
            cout << "Factura" << endl;
            menu.MenuFactura();
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
            cout << "Promociones" << endl;
            menu.MenuPromociones();
            break;
        }

        case 0:
        {
            cout << "Salir" <<endl;
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);

    return 0;
}
