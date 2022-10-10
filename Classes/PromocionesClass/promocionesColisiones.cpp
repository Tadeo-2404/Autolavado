#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PromocionesColision.hpp"
using namespace std;

PromocionesColision::PromocionesColision()
{
    for( int i = 0; i < sizeof( id ); id[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( nombre ); nombre[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( proveedor ); proveedor[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( precio ); precio[ i++ ] = '\0' );
}

bool PromocionesColision::Crear( const PromocionesColision &nuevaPromocionesColision )
{
    PromocionesColision promo;
    string cadena;
    int posIndice, contador;
    long int posByte;
    string idString = nuevaPromocionesColision.id;

    fstream archivo( "dispersionColision.txt", ios::in | ios::out );
    posIndice = dispersion( nuevaPromocionesColision.id );
    cout << "Se guardara en la posicion indice: " << posIndice << endl;
    posByte = posIndice * ( sizeof( PromocionesColision ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) ); // lee el numero de registros en el contador
    if( contador < CONTENEDOR ) // si el contenedor no esta lleno
    {
        // aumenta el contador y lo escribe
        contador++;
        archivo.seekg( posByte, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // escribe el nuevo registro en el contenedor
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &promo, sizeof( PromocionesColision ) );
            if( promo.id[ 0 ] == '\0' )
            {
                archivo.seekg( ( long )archivo.tellg() - sizeof( PromocionesColision ), ios::beg );
                archivo.write( ( char * ) &nuevaPromocionesColision, sizeof( PromocionesColision ) );
                archivo.close();
                return true;
            }
        }

    }
    else
        cout << endl << "No hay mas espacio para este registro" << endl;
    archivo.close();
    return false;
}

void PromocionesColision::Mostrar( void )
{
    PromocionesColision promo;
    int contador;

    ifstream archivo( "dispersionColision.txt", ios::in );
    if( !archivo )
        cout << "No existe el archivo" << endl;
    else
    {
        cout << endl;
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
            archivo.read( ( char * ) &contador, sizeof( int ) );
            if( contador > 0 )
            {
                for( int j = 0; j < CONTENEDOR; j++ )
                {
                    archivo.read( ( char * ) &promo, sizeof( PromocionesColision ) );
                    if( promo.id[ 0 ] != '\0' )
                        cout << promo << endl;
                }
            }
            else
                archivo.seekg( sizeof( PromocionesColision ) * CONTENEDOR, ios::cur );
        }
    }
    archivo.close();
}

bool PromocionesColision::Buscar( const string &idABuscar, PromocionesColision &promocionEncontrada )
{
    long int posByte;

    ifstream archivo( "dispersionColision.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return false;
    }
    
    posByte = buscarId( idABuscar );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &promocionEncontrada, sizeof( PromocionesColision ) );
    archivo.close();
    return true;
}

bool PromocionesColision::Modificar( const string &idAModificar, const PromocionesColision &promocionNueva )
{
    PromocionesColision registroLimpio, promo;
    fstream archivo( "dispersionColision.txt", ios::in | ios::out );
    int posIndiceAntiguo, posIndiceNuevo, contador;
    long int posByteAntiguo, posByteNuevo;

    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    posIndiceAntiguo = dispersion( idAModificar.c_str() );
    posByteAntiguo = buscarId( idAModificar );
    posIndiceNuevo = dispersion( promocionNueva.id );
    posByteNuevo = posIndiceNuevo * ( sizeof( PromocionesColision ) * CONTENEDOR + sizeof( int ) );

    if( posByteAntiguo == posByteNuevo )
    {
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &promocionNueva, sizeof( PromocionesColision ) );
    }
    else
    {
        // quita el registro antiguo y resta uno al contador del contenedor
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &registroLimpio, sizeof( PromocionesColision ) );
        posByteAntiguo = posIndiceAntiguo * ( sizeof( PromocionesColision ) * CONTENEDOR + sizeof( int ) );
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        contador--; 
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // intenta meter el nuevo registro en la nueva posicion
        archivo.seekg( posByteNuevo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        if( contador < CONTENEDOR )
        {
            // aumenta el contador y lo escribe
            contador++;
            archivo.seekg( posByteNuevo, ios::beg );
            archivo.write( ( char * ) &contador, sizeof( int ) );

            // escribe el nuevo registro en el contenedor
            for( int i = 0; i < CONTENEDOR; i++ )
            {
                archivo.read( ( char * ) &promo, sizeof( PromocionesColision ) );
                if( promo.id[ 0 ] == '\0' ) // si el lugar no esta ocupado
                {
                    archivo.seekg( ( long )archivo.tellg() - sizeof( PromocionesColision ), ios::beg );
                    archivo.write( ( char * ) &promocionNueva, sizeof( PromocionesColision ) );
                    archivo.close();
                    return true;
                }
            }
        }
        else
        {
            return false;
        }  
    }

    return true;
} // fin funcion modificar

bool PromocionesColision::Eliminar( const string &idAEliminar, PromocionesColision &destinoEliminado )
{
    PromocionesColision promo;
    int posIndice, posByte, contador;

    fstream archivo( "dispersionColision.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    } 

    posIndice = dispersion( idAEliminar.c_str() );
    posByte = buscarId( idAEliminar );

    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &destinoEliminado, sizeof(  PromocionesColision) );
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &promo, sizeof(  PromocionesColision) );

    posByte = posIndice * ( sizeof( PromocionesColision ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    contador--;
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &contador, sizeof( int ) );
    archivo.close();
    return true;
}

PromocionesColision PromocionesColision::pedirRegistro( void )
{
    PromocionesColision registroARetornar;
    string cadena;

    cout << "Introduce el ID" <<endl;
    getline( cin, cadena );
    registroARetornar.setId( cadena );

    cout << "Introduce el nombre" <<endl;
    getline( cin, cadena );
    registroARetornar.setNombre( cadena );

    cout << "Introduce el nombre del proveedor" <<endl;
    getline( cin, cadena );
    registroARetornar.setProveedor( cadena );
    
    cout << "Introduce el precio" <<endl;
    getline( cin, cadena );
    registroARetornar.setPrecio( cadena );

    return registroARetornar;
}

void PromocionesColision::genera( void )
{
    PromocionesColision promo;
    int contador = 0;
    ofstream archivo( "dispersionColision.txt", ios::out );
    if( !archivo )
        cout << "No se pudo crear el archivo" << endl;
    else
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
        	// indica cuantos registros hay en el contenedor
        	archivo.write( ( char * ) &contador, sizeof( int ) );
        	for( int j = 0; j < CONTENEDOR; j++ )
            	archivo.write( ( char * ) &promo, sizeof( PromocionesColision ) );
        }
    archivo.close();
}

int PromocionesColision::dispersion( const char llave[ 12 ] )
{
    // llena la el sobrante de la llave con espacios
    char llaveCopia[ 12 ];
    strcpy( llaveCopia, llave );
    if( strlen( llaveCopia ) < 12 )
        for( int i = strlen( llaveCopia ); i < 12; i++ )
            llaveCopia[ i ] = ' ';
    llaveCopia[ 12 ] = '\0';

    // realiza el algoritmo
    long sum = 0;
    int j = 0;
    while( j < 12 )
    {
        sum = ( sum + 100 * llaveCopia[ j ] + llaveCopia[ j + 1 ] )  % 20000;
        j += 2;
    }
    return ( sum % 99 ); // retorna la posición donde se guardará el registros.
}

// retorna la posición donde se encontro el registro
long int PromocionesColision::buscarId( const string &idABuscar )
{
    PromocionesColision promo;
    int contador, posIndice;
    long int posByte;

    ifstream archivo( "dispersionColision.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return -1;
    }

    posIndice = dispersion( idABuscar.c_str() );
    posByte = posIndice * ( ( sizeof( PromocionesColision ) * CONTENEDOR ) + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    if( contador > 0 )
    {
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &promo, sizeof( PromocionesColision ) );
            if( strcmp( promo.id, idABuscar.c_str() ) == 0 )
            {
                posByte = ( long )archivo.tellg() - sizeof( PromocionesColision );
                archivo.close();
                return posByte;
            }
        }
    }

    archivo.close();
    return -1;
}

void PromocionesColision::setId( const string &valorId )
{
    int longitud = valorId.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorId.copy( id, longitud );
    id[ longitud ] = '\0';
}

void PromocionesColision::setNombre( const string &valorNombre )
{
    int longitud = valorNombre.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorNombre.copy( nombre, longitud );
    nombre[ longitud ] = '\0';
}

void PromocionesColision::setProveedor( const string &valorProveedor )
{
    int longitud = valorProveedor.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorProveedor.copy( proveedor, longitud );
    proveedor[ longitud ] = '\0';
}

void PromocionesColision::setPrecio( const string &valorPrecio )
{
    int longitud = valorPrecio.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorPrecio.copy( precio, longitud );
    precio[ longitud ] = '\0';
}

ostream &operator<<( ostream &salida, const PromocionesColision &promocion )
{
    salida << "ID:        " << promocion.id << endl
            << "Producto:  " << promocion.nombre << endl
            << "Proveedor: " << promocion.proveedor << endl
            << "Precio:    " << promocion.precio << endl;

    return salida;
}