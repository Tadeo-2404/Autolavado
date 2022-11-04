#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
using namespace std;

class Menu {
    int opc;
public:
    Menu();
    void MenuProducto();
    void MenuCliente();
    void MenuTicket();
    void MenuEmpleado();
    void MenuServicio();
    void MenuFactura();
    void MenuPromociones();
};

#endif