#include <iostream>
#include "Admin.hpp"
#include "../ClienteClass/cliente.cpp"
#include "../ProductoClass/producto.cpp"
#include "../TicketClass/Ticket.cpp"
#include "../EmpleadoClass/Empleado.cpp"
#include "../ServicioClass/servicio.cpp"
#include "../FacturaClass/factura.cpp"
#include "../PromocionesClass/promociones.cpp"
#include "../PromocionesClass/promocionesColisiones.cpp"
using namespace std;
Cliente cliente;
Producto producto;
Ticket ticket;
Empleado empleado;
Servicio servicio;
Factura factura;
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
    this->contClientes++;
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
    this->contClientes--;
    cliente.Eliminar(ID);
}

//CLIENTE - ENCRYPTACION
void Admin::crearClienteEncryptado() {
    this->contClientes++;
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
    this->contClientes--;
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
    ticket.Crear(this->ticketAdmin);
}

void Admin::mostrarTickets() {
    ticket.Mostrar(this->ticketAdmin);
}

void Admin::buscarTickets(string ID) {
    ticket.Buscar(this->ticketAdmin ,ID);
}

void Admin::modificarTickets(string ID) {
    ticket.Modificar(this->ticketAdmin ,ID);
}

void Admin::eliminarTickets(string ID) {
    this->contTicket--;
    ticket.Eliminar(this->ticketAdmin ,ID);
}

//EMPLEADO
void Admin::crearEmpleado() {
    this->contEmpleado++;
    empleado.Crear(this->empleadoAdmin, this->indiceAdmin);
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
    this->contEmpleado--;
    empleado.Eliminar(this->empleadoAdmin ,ID, this->indiceAdmin);
}

//SERVICIO
void Admin::crearServicio() {
    servicio.Crear(this->contServicio ,this->servicioAdmin, this->indiceAdmin);
}

void Admin::mostrarServicios() {
    servicio.Mostrar(this->servicioAdmin, this->indiceAdmin);
}

void Admin::buscarServicios(string ID) {
    servicio.Buscar(this->servicioAdmin ,ID, this->indiceAdmin);
}

void Admin::modificarServicios(string ID) {
    servicio.Modificar(this->servicioAdmin ,ID, this->indiceAdmin);
}

void Admin::eliminarServicios(string ID) {
    servicio.Eliminar(this->servicioAdmin ,ID, this->indiceAdmin);
}

//FACTURAS
void Admin::crearFactura() {
    this->contFacturas++;
    factura.Crear(this->contFacturas ,this->facturaAdmin, this->indiceAdmin);
}

void Admin::mostrarFacturas() {
    factura.Mostrar(this->facturaAdmin, this->indiceAdmin);
}

void Admin::buscarFactura(string ID) {
    factura.Buscar(this->facturaAdmin ,ID, this->indiceAdmin);
}

void Admin::modificarFactura(string ID) {
    factura.Modificar(this->facturaAdmin ,ID, this->indiceAdmin);
}

void Admin::eliminarFacturas(string ID) {
    this->contFacturas--;
    factura.Eliminar(this->facturaAdmin ,ID, this->indiceAdmin);
}

void Admin::comprimirFacturas(string entrada, string salida) {
    cout << "Comprimido exitosamente, revisa tu directorio" << endl;
}

void Admin::descomprimirFactura(string entrada, string salida) {
    cout << "Descomprimido exitosamente, revisa tu directorio" << endl;
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