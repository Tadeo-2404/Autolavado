#include <iostream>
#include "Admin.hpp"
#include "../ClienteClass/Cliente.hpp"
#include "../ClienteClass/cliente.cpp"

#include "../ProductoClass/Producto.hpp"
#include "../ProductoClass/producto.cpp"

#include "../TicketClass/Ticket.hpp"
#include "../TicketClass/Ticket.cpp"

#include "../EmpleadoClass/Empleado.cpp"

#include "../ServicioClass/Servicio.hpp"
#include "../ServicioClass/servicio.cpp"

#include "../PromocionesClass/Promociones.hpp"
#include "../PromocionesClass/promociones.cpp"

#include "../PromocionesClass/PromocionesColision.hpp"
#include "../PromocionesClass/promocionesColisiones.cpp"
using namespace std;
Cliente cliente;
Producto producto;
Ticket ticket;
Empleado empleado;
Servicio servicio;
Promocion promocion;
PromocionesColision promocionColision;
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

//CLIENTE - ENCRYPTACION
void Admin::crearClienteEncryptado() {
    cliente.CrearEncriptacion();
}

void Admin::mostrarClientesEncryptado() {
    cliente.MostrarEncriptacion();
}

void Admin::buscarClientesEncryptado(string ID) {
    cliente.BuscarEncriptacion(ID);
}

void Admin::modificarClientesEncryptado(string ID) {
    cliente.ModificarEncriptacion(ID);
}

void Admin::eliminarClientesEncryptado(string ID) {
    cliente.EliminarEncriptacion(ID);
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
    empleado.Crear(this->empleadoAdmin, this->indiceAdmin);
    this->contEmpleado += 1;
}

void Admin::mostrarEmpleados() {
    empleado.Mostrar(this->empleadoAdmin, this->indiceAdmin);
}

void Admin::buscarEmpleados(string ID) {
    empleado.Buscar(this->empleadoAdmin ,ID, this->indiceAdmin);
}

void Admin::modificarEmpleados(string ID) {
    empleado.Modificar(this->empleadoAdmin ,ID, this->indiceAdmin);
}

void Admin::eliminarEmpleados(string ID) {
    empleado.Eliminar(this->empleadoAdmin ,ID, this->indiceAdmin);
    this->contEmpleado -= 1;
}

//SERVICIO
void Admin::crearServicio() {
    servicio.Crear(this->servicioAdmin, this->indiceAdmin);
}

void Admin::mostrarServicios() {
    servicio.Mostrar(this->servicioAdmin, this->indiceAdmin);
}

void Admin::buscarServicios(int ID) {
    servicio.Buscar(this->servicioAdmin ,ID, this->indiceAdmin);
}

void Admin::modificarServicios(int ID) {
    servicio.Modificar(this->servicioAdmin ,ID, this->indiceAdmin);
}

void Admin::eliminarServicios(int ID) {
    servicio.Eliminar(this->servicioAdmin ,ID, this->indiceAdmin);
}

//PROMOCION
void Admin::crearPromocion() {
    this->promocionAdmin = promocion.pedirRegistro();
    promocion.Crear(this->promocionAdmin);
}

void Admin::crearPromocionColision() {
    this->promocionColisionAdmin = promocionColision.pedirRegistro();
    promocionColision.Crear(this->promocionColisionAdmin);
}

void Admin::mostrarPromociones() {
    promocion.Mostrar();
}

void Admin::mostrarPromocionesColision() {
    promocionColision.Mostrar();
}

void Admin::buscarPromociones(const string& ID) {
    if(promocion.Buscar(ID, this->promocionAdmin))
    {
        cout << this->promocionAdmin;
    } else {
        cout << "No existe el registro" <<endl;
    }
}

void Admin::buscarPromocionesColision(const string& ID) {
    if(promocionColision.Buscar(ID, this->promocionColisionAdmin))
    {
        cout << this->promocionColisionAdmin;
    } else {
        cout << "No existe el registro" <<endl;
    }
}

void Admin::modificarPromociones(const string &ID) {
    Promocion promocionBuscar;
    if(promocion.Buscar(ID, this->promocionAdmin))
    {
        promocionBuscar = promocion.pedirRegistro();
        promocion.Modificar(ID, promocionBuscar);
    }
    promocion.Modificar(ID, this->promocionAdmin);
}

void Admin::modificarPromocionesColision(const string &ID) {
    PromocionesColision promocionBuscar;
    if(promocionColision.Buscar(ID, this->promocionColisionAdmin))
    {
        promocionBuscar = promocionColision.pedirRegistro();
        promocionColision.Modificar(ID, promocionBuscar);
    }
    promocionColision.Modificar(ID, this->promocionColisionAdmin);
}

void Admin::eliminarPromociones(const string& ID) {
    if (promocion.Buscar(ID, this->promocionAdmin))
    {
        promocion.Eliminar(ID, this->promocionAdmin);
        cout << this->promocionAdmin;
        cout << "Eliminado correctamente" <<endl;
    }
}

void Admin::eliminarPromocionesColision(const string& ID) {
    if (promocionColision.Buscar(ID, this->promocionColisionAdmin))
    {
        promocionColision.Eliminar(ID, this->promocionColisionAdmin);
        cout << this->promocionColisionAdmin;
        cout << "Eliminado correctamente" <<endl;
    }
}