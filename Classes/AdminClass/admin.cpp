#include <iostream>
#include "Admin.hpp"
#include "../ClienteClass/Cliente.hpp"
#include "../ProductoClass/Producto.hpp"
#include "../TicketClass/Ticket.hpp"
#include "../EmpleadoClass/Empleado.hpp"
#include "../ClienteClass/cliente.cpp"
#include "../ProductoClass/producto.cpp"
#include "../TicketClass/Ticket.cpp"
#include "../EmpleadoClass/Empleado.cpp"
using namespace std;
Cliente cliente;
Producto producto;
Ticket ticket;
Empleado empleado;

//CONSTRUCTOR
Admin::Admin()
{

}

Ticket Admin::getTicketAdmin() {
    return this->ticketAdmin;
}

void Admin::setTicketAdmin(Ticket ticket) {
    this->ticketAdmin = ticket;
}

//CLIENTE
void Admin::crearCliente() {
    cliente.Crear();
}

void Admin::mostrarClientes() {
    cliente.Mostrar();
}

void Admin::buscarClientes(string ID) {
    cliente.Buscar(ID);
}

void Admin::modificarClientes(string ID) {
    cliente.Modificar(ID);
}

void Admin::eliminarClientes(string ID) {
    cliente.Eliminar(ID);
}

//PRODUCTO
void Admin::crearProducto() {
    producto.Crear();
}

void Admin::mostrarProductos() {
    producto.Mostrar();
}

void Admin::buscarProductos(string ID) {
    producto.Buscar(ID);
}

void Admin::modificarProductos(string ID) {
    producto.Modificar(ID);
}

void Admin::eliminarProductos(string ID) {
    producto.Eliminar(ID);
}

//TICKET
void Admin::crearTicket() {
    this->contTicket++;
    ticket.Crear(this->ticketAdmin, this->contTicket);
}

void Admin::mostrarTickets() {
    ticket.Mostrar(this->ticketAdmin);
}

void Admin::buscarTickets(int ID) {
    ticket.Buscar(this->ticketAdmin ,ID);
}

void Admin::modificarTickets(int ID) {
    ticket.Modificar(this->ticketAdmin ,ID);
}

void Admin::eliminarTickets(int ID) {
    ticket.Eliminar(this->ticketAdmin ,ID);
}

//EMPLEADO
void Admin::crearEmpleado() {
    this->contEmpleado++;
    empleado.Crear(this->empleadoAdmin, this->contEmpleado);
}

void Admin::mostrarEmpleados() {
    empleado.Mostrar(this->empleadoAdmin);
}

void Admin::buscarEmpleados(int ID) {
    empleado.Buscar(this->empleadoAdmin ,ID);
}

void Admin::modificarEmpleados(int ID) {
    empleado.Modificar(this->empleadoAdmin ,ID);
}

void Admin::eliminarEmpleados(int ID) {
    empleado.Eliminar(this->empleadoAdmin ,ID);
}