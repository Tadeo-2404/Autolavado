#ifndef PROMOCIONESCOLISION_HPP
#define PROMOCIONESCOLISION_HPP
#include <string>
using namespace std;
#define NUMREGISTROS 100
#define CONTENEDOR   4

class PromocionesColision
{
    private:
        char id[ 12 ];
        char nombre[ 35 ];
        char proveedor[ 35 ];
        char precio[ 10 ];

        int dispersion( const char llave[ 12 ] );
        long int buscarId( const string & );
    public:
        PromocionesColision();
        PromocionesColision( const PromocionesColision &);
        void setId( const string & );
        void setNombre( const string & );
        void setProveedor( const string & );
        void setPrecio( const string & );
        friend ostream &operator<<( ostream &, const PromocionesColision & );

        bool Crear( const PromocionesColision & );
        void Mostrar( void );
        bool Buscar( const string &, PromocionesColision & );
        bool Eliminar( const string &, PromocionesColision & );
        bool Modificar( const string &, const PromocionesColision & );
        void mostrarIndice( void );
        PromocionesColision pedirRegistro( void );
        void genera( void );
};

#endif