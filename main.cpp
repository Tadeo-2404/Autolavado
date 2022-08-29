#include <iostream>
#include <fstream>
#include "Classes/ProductoClass/Producto.hpp"
#include "Classes/ProductoClass/Producto.cpp"
using namespace std;

int main()
{
    int opc;
    Producto producto;
    do
    {
        cout << "PRODUCTOS" << endl;
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

    return 0;
}
