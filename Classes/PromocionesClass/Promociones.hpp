#ifndef PROMOCIONES_HPP
#define PROMOCIONES_HPP
#include<string>
using namespace std;
#define NUMREGISTROS 100
#define CONTENEDOR   4

class Promocion
{
    private:
        char id[ 12 ];
        char nombre[ 35 ];
        char proveedor[ 35 ];
        char precio[ 10 ];

        int dispersion( const char llave[ 12 ] );
        long int buscarId( const string & );
    public:
        Promocion();
        Promocion( const Promocion &);
        void setId( const string & );
        void setNombre( const string & );
        void setProveedor( const string & );
        void setPrecio( const string & );
        friend ostream &operator<<( ostream &, const Promocion & );

        bool Crear( const Promocion & );
        void Mostrar( void );
        bool Buscar( const string &, Promocion & );
        bool Eliminar( const string &, Promocion & );
        bool Modificar( const string &, const Promocion & );
        void mostrarIndice( void );
        Promocion pedirRegistro( void );
        bool contiene( const string & );
        void genera( void );
};

#endif