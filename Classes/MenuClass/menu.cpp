#include <iostream>
#include "Menu.hpp"
#include <fstream>
#include "../AdminClass/admin.cpp"
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
        cout << "0) Salir" << endl;
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
            cout << "Introduce el codigo del producto a buscar" << endl;
            getline(cin, codigoBuscado);
            admin.buscarProductos(codigoBuscado);
            break;
        }

        case 4:
        {
            string codigoBuscado;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el codigo del producto a eliminar" << endl;
            getline(cin, codigoBuscado);
            admin.eliminarProductos(codigoBuscado);
            break;
        }

        case 5:
        {
            string codigoBuscado;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el codigo del producto a modificar" << endl;
            getline(cin, codigoBuscado);
            admin.modificarProductos(codigoBuscado);
            break;
        }

        case 0:
        {
            cout << "Salir" << endl;
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
        cout << "1) Encriptacion" << endl;
        cout << "2) Sin Encriptar" << endl;
        cout << "0) Salir" << endl;
        cout << "Selecciona una opcion" << endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            do
            {
                cout << "Encriptacion" << endl;
                cout << "1) Crear" << endl;
                cout << "2) Mostrar" << endl;
                cout << "3) Buscar" << endl;
                cout << "4) Eliminar" << endl;
                cout << "5) Modificar" << endl;
                cout << "6) Desencryptar" << endl;
                cout << "0) Salir" << endl;
                cin >> opc;
                cin.ignore();

                switch (opc)
                {
                case 1:
                {
                    cout << "CREAR" << endl;
                    admin.crearClienteEncryptado();
                    break;
                }

                case 2:
                {
                    cout << "MOSTRAR" << endl;
                    admin.mostrarClientesEncryptado();
                    break;
                }

                case 3:
                {
                    string IDCliente;
                    cout << "BUSCAR" << endl;
                    cout << "Introduce el ID del cliente a buscar" << endl;
                    getline(cin, IDCliente);
                    admin.buscarClientesEncryptado(IDCliente);
                    break;
                }

                case 4:
                {
                    string IDCliente;
                    cout << "ELIMINAR" << endl;
                    cout << "Introduce el ID del cliente a eliminar" << endl;
                    getline(cin, IDCliente);
                    admin.eliminarClientesEncryptado(IDCliente);
                    break;
                }

                case 5:
                {
                    string IDCliente;
                    cout << "MODIFICAR" << endl;
                    cout << "Introduce el ID del cliente a modificar" << endl;
                    getline(cin, IDCliente);
                    admin.modificarClientesEncryptado(IDCliente);
                    break;
                }

                case 0:
                {
                    cout << "Salir" << endl;
                    break;
                }

                default:
                    cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
                    break;
                }

            } while (opc != 0);
            break;
        }

        case 2:
        {
            do
            {
                cout << "Registros de Longitud Variable (Campos de Dimension)" << endl;
                cout << "1) Crear" << endl;
                cout << "2) Mostrar" << endl;
                cout << "3) Buscar" << endl;
                cout << "4) Eliminar" << endl;
                cout << "5) Modificar" << endl;
                cout << "0) Salir" << endl;
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
                    cout << "Introduce el ID del cliente a buscar" << endl;
                    getline(cin, IDCliente);
                    admin.buscarClientes(IDCliente);
                    break;
                }

                case 4:
                {
                    string IDCliente;
                    cout << "ELIMINAR" << endl;
                    cout << "Introduce el ID del cliente a eliminar" << endl;
                    getline(cin, IDCliente);
                    admin.eliminarClientes(IDCliente);
                    break;
                }

                case 5:
                {
                    string IDCliente;
                    cout << "MODIFICAR" << endl;
                    cout << "Introduce el ID del cliente a modificar" << endl;
                    getline(cin, IDCliente);
                    admin.modificarClientes(IDCliente);
                    break;
                }

                case 0:
                {
                    cout << "Salir" << endl;
                    break;
                }

                default:
                    cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
                    break;
                }

            } while (opc != 0);
            break;
        }

        case 0:
        {
            cout << "Salir" << endl;
            break;
        }

        default:
            cout << "Error: opcion no valida" << endl;
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
        cout << "0) Salir" << endl;
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
            string IDticket;
            cout << "BUSCAR" << endl;
            cout << "Introduce el ID del ticket a buscar" << endl;
            cin >> IDticket;
            admin.buscarTickets(IDticket);
            break;
        }

        case 4:
        {
            string IDticket;
            cout << "ELIMINAR" << endl;
            cout << "Introduce el ID del ticket a eliminar" << endl;
            cin >> IDticket;
            admin.eliminarTickets(IDticket);
            break;
        }

        case 5:
        {
            string IDticket;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el ID del ticket a modificar" << endl;
            cin >> IDticket;
            admin.modificarTickets(IDticket);
            break;
        }

        case 0:
        {
            cout << "Salir" << endl;
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
        cout << "Empleados" << endl;
        cout << "1) Crear" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Buscar" << endl;
        cout << "4) Eliminar" << endl;
        cout << "5) Modificar" << endl;
        cout << "0) Salir" << endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "CREAR" << endl;
            admin.crearEmpleado();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            admin.mostrarEmpleados();
            break;
        }

        case 3:
        {
            string IDticket;
            cout << "BUSCAR" << endl;
            admin.mostrarEmpleados();
            cout << "Introduce el ID del empleado a buscar" << endl;
            cin >> IDticket;
            admin.buscarEmpleados(IDticket);
            break;
        }

        case 4:
        {
            string IDticket;
            cout << "ELIMINAR" << endl;
            admin.mostrarEmpleados();
            cout << "Introduce el ID del empleado a eliminar" << endl;
            cin >> IDticket;
            admin.eliminarEmpleados(IDticket);
            break;
        }

        case 5:
        {
            string IDticket;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el ID del ticket a modificar" << endl;
            cin >> IDticket;
            admin.modificarEmpleados(IDticket);
            break;
        }

        case 0:
        {
            cout << "Salir" << endl;
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
}

void Menu::MenuServicio()
{
    Admin admin;
    int opc;
    do
    {
        cout << "Servicios" << endl;
        cout << "1) Crear" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Buscar" << endl;
        cout << "4) Eliminar" << endl;
        cout << "5) Modificar" << endl;
        cout << "0) Salir" << endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "CREAR" << endl;
            admin.crearServicio();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            admin.mostrarServicios();
            break;
        }

        case 3:
        {
            string IDticket;
            cout << "BUSCAR" << endl;
            admin.mostrarServicios();
            cout << "Introduce el ID del Servicio a buscar" << endl;
            cin >> IDticket;
            admin.buscarServicios(IDticket);
            break;
        }

        case 4:
        {
            string IDticket;
            cout << "ELIMINAR" << endl;
            admin.mostrarServicios();
            cout << "Introduce el ID del Servicio a eliminar" << endl;
            cin >> IDticket;
            admin.eliminarServicios(IDticket);
            break;
        }

        case 5:
        {
            string IDticket;
            cout << "MODIFICAR" << endl;
            cout << "Introduce el ID del Servicio a modificar" << endl;
            cin >> IDticket;
            admin.modificarServicios(IDticket);
            break;
        }

        case 0:
        {
            cout << "Salir" << endl;
            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
}

void Menu::MenuFactura()
{
    Admin admin;
    int opc;

    do
    {
        cout << "Menu - Factura" <<endl;
        cout << "1) Compresion y Descompresion" <<endl;
        cout << "2) Serializacion" <<endl;
        cout << "0) Salir" <<endl;
        cin>>opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "Compresion y Descompresion" <<endl;
            do
            {
                cout << "1) Comprimir" <<endl;
                cout << "2) Descomprimir" <<endl;
                cout << "0) Salir" <<endl;
                cin>>opc;

                switch (opc)
                {
                case 1:
                {
                    cout << "Comprimir" <<endl;
                    admin.comprimirFacturas();
                    break;
                }

                case 2:
                {
                    cout << "Descomprimir" <<endl;
                    admin.descomprimirFactura();
                    break;
                }

                case 3:
                {
                    cout << "Salir" <<endl;
                    break;
                }
                
                default: cout << "Error: Opcion no valida" <<endl;
                    break;
                }
            } while (opc != 0);
            
            break;
        }

        case 2:
        {
            cout << "Serializacion" << endl;
            do
            {
                cout << "Facturas" << endl;
                cout << "1) Crear" << endl;
                cout << "2) Mostrar" << endl;
                cout << "3) Buscar" << endl;
                cout << "4) Eliminar" << endl;
                cout << "5) Modificar" << endl;
                cout << "0) Salir" << endl;
                cin >> opc;
                cin.ignore();

                switch (opc)
                {
                case 1:
                {
                    cout << "CREAR" << endl;
                    admin.crearFactura();
                    break;
                }

                case 2:
                {
                    cout << "MOSTRAR" << endl;
                    admin.mostrarFacturas();
                    break;
                }

                case 3:
                {
                    string IDticket;
                    cout << "BUSCAR" << endl;
                    admin.mostrarFacturas();
                    cout << "Introduce el ID de la Factura a buscar" << endl;
                    cin >> IDticket;
                    admin.buscarFactura(IDticket);
                    break;
                }

                case 4:
                {
                    string IDticket;
                    cout << "ELIMINAR" << endl;
                    admin.mostrarFacturas();
                    cout << "Introduce el ID de la Factura a eliminar" << endl;
                    cin >> IDticket;
                    admin.eliminarFacturas(IDticket);
                    break;
                }

                case 5:
                {
                    string IDticket;
                    cout << "MODIFICAR" << endl;
                    cout << "Introduce el ID de la Factura a modificar" << endl;
                    cin >> IDticket;
                    admin.modificarFactura(IDticket);
                    break;
                }

                case 0:
                {
                    cout << "Salir" << endl;
                    break;
                }

                default:
                    cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
                    break;
                }

            } while (opc != 0);
            break;
        }

        case 0:
        {
            cout << "Salir" <<endl;
            break;
        }

        default: cout << "Error: Opcion no valida" <<endl;
            break;
        }

    } while (opc != 0);
    
}

void Menu::MenuPromociones()
{
    Admin admin;
    Promocion promocion;
    PromocionesColision promocionColision;
    string idABuscar, idAModificar, idAEliminar;
    int opc, opcMain;

    cout << "Promociones" << endl;
    do
    {
        cout << "1) Resolviendo Colisiones" << endl;
        cout << "2) Sin Resolver Colisones" << endl;
        cout << "0) Salir" << endl;
        cin >> opcMain;
        cin.ignore();

        switch (opcMain)
        {
        case 1:
        {
            cout << "Promociones Sin Colisiones" << endl;
            promocion.genera();
            do
            {
                cout << "1) Crear" << endl;
                cout << "2) Mostrar" << endl;
                cout << "3) Buscar" << endl;
                cout << "4) Eliminar" << endl;
                cout << "5) Modificar" << endl;
                cout << "0) Salir" << endl;
                cin >> opc;
                cin.ignore();

                switch (opc)
                {
                case 1:
                {
                    cout << "CREAR" << endl;
                    admin.crearPromocion();
                    break;
                }

                case 2:
                {
                    cout << "MOSTRAR" << endl;
                    admin.mostrarPromociones();
                    break;
                }

                case 3:
                {
                    string IDticket;
                    cout << "BUSCAR" << endl;
                    admin.mostrarPromociones();
                    cout << "Introduce el ID de la Promocion a buscar" << endl;
                    getline(cin, IDticket);
                    admin.buscarPromociones(IDticket);
                    break;
                }

                case 4:
                {
                    string IDPromocion;
                    cout << "Eliminar" << endl;
                    admin.mostrarPromociones();
                    cout << "Introduce el ID de la Promocion a eliminar" << endl;
                    getline(cin, IDPromocion);
                    admin.eliminarPromociones(IDPromocion);
                    cout << "Se ha elimanado correctamente" << endl;
                    break;
                }

                case 5:
                {
                    string IDPromocion;
                    cout << "Modificar" << endl;
                    admin.mostrarPromociones();
                    cout << "Introduce el ID de la Promocion a modificar" << endl;
                    getline(cin, IDPromocion);
                    admin.modificarPromociones(IDPromocion);
                    cout << "Se ha modificado correctamente" << endl;
                    break;
                }

                case 0:
                {
                    cout << "Salir" << endl;
                    break;
                }

                default:
                    cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
                    break;
                }

            } while (opc != 0);
            break; // fin break 1
        }

        case 2:
        {
            cout << "Promociones con Colisiones" << endl;
            promocionColision.genera();
            do
            {
                cout << "1) Crear" << endl;
                cout << "2) Mostrar" << endl;
                cout << "3) Buscar" << endl;
                cout << "4) Eliminar" << endl;
                cout << "5) Modificar" << endl;
                cout << "0) Salir" << endl;
                cin >> opc;
                cin.ignore();

                switch (opc)
                {
                case 1:
                {
                    cout << "CREAR" << endl;
                    admin.crearPromocionColision();
                    break;
                }

                case 2:
                {
                    cout << "MOSTRAR" << endl;
                    admin.mostrarPromocionesColision();
                    break;
                }

                case 3:
                {
                    string IDticket;
                    cout << "BUSCAR" << endl;
                    admin.mostrarPromocionesColision();
                    cout << "Introduce el ID de la Promocion a buscar" << endl;
                    getline(cin, IDticket);
                    admin.buscarPromocionesColision(IDticket);
                    break;
                }

                case 4:
                {
                    string IDPromocion;
                    cout << "Eliminar" << endl;
                    admin.mostrarPromocionesColision();
                    cout << "Introduce el ID de la Promocion a eliminar" << endl;
                    getline(cin, IDPromocion);
                    admin.eliminarPromocionesColision(IDPromocion);
                    cout << "Se ha elimanado correctamente" << endl;
                    break;
                }

                case 5:
                {
                    string IDPromocion;
                    cout << "Modificar" << endl;
                    admin.mostrarPromocionesColision();
                    cout << "Introduce el ID de la Promocion a modificar" << endl;
                    getline(cin, IDPromocion);
                    admin.modificarPromocionesColision(IDPromocion);
                    cout << "Se ha modificado correctamente" << endl;
                    break;
                }

                case 0:
                {
                    cout << "Salir" << endl;
                    break;
                }

                default:
                    cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
                    break;
                }

            } while (opc != 0);
            break; // fin break 2
        }

        case 0:
        {
            cout << "Salir" << endl;
            break;
        }

        default:
            cout << "Error: Opcion Incorrecta" << endl;
            break;
        }
    } while (opcMain != 0);
}