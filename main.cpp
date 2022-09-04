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
        cout << "0) Salir" <<endl;
        cin >> opc;
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

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);

    return 0;
}
