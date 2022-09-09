#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "../TicketClass/Ticket.hpp"

class Admin {
    int contTicket = 0;
    Ticket ticketAdmin; //Auxiliar para crear ticket
public:
    Admin(); //CONSTRUCTOR
    void setTicketAdmin(Ticket ticket);
    Ticket getTicketAdmin();

    void crearCliente(); //CREAR UNA INSTANCIA DE CLIENTE EN EL ARCHIVO CLIENTE.TXT
    void mostrarClientes(); //MUESTRA LOS CLIENTES DEL CLIENTES.TXT
    void buscarClientes(string ID); //BUSCA UN CLIENTE DEL ARCHIVO CLIENTES.TXT
    void modificarClientes(string ID); //MODIFICA UN CLIENTE DEL ARCHIVO CLIENTES.TXT
    void eliminarClientes(string ID); //ELIMINA UN CLIENTE DEL ARCHIVO DEL CLIENTES.TXT

    void crearProducto(); //CREAR UNA INSTANCIA DE PRODUCTO EN EL ARCHIVO PRODUCTOS.TXT
    void mostrarProductos(); //MUESTRA LOS PRODUCTOS DEL ARCHIVO PRODUCTOS.TXT
    void buscarProductos(string ID); //BUSCA UN PROUDUCTO DEL ARCHIVO PRODUCTOS.TXT
    void modificarProductos(string ID); //MODIFICA UN PRODUCTO DEL ARCHIVO PRODUCTOS.TXT
    void eliminarProductos(string ID); //ELIMINA UN PRODUCTO DEL ARCHIVO PRODUCTOS.TXT

    void crearTicket(); //CREAR UNA INSTANCIA DE TICKET EN EL ARCHIVO TICKETS.TXT
    void mostrarTickets(); //MUESTRA LOS TICKETS DEL ARCHIVO TICKETS.TXT
    void buscarTickets(int ID); //BUSCA UN TICKET DEL ARCHIVO TICKETS.TXT
    void modificarTickets(int ID); //MODIFICA UN TICKET DEL ARCHIVO TICKETS.TXT
    void eliminarTickets(int ID); //ELIMINA UN TICKET DEL ARCHIVO TICKETS.TXT
};

#endif