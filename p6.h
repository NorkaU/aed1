#ifndef _MODULO_UNO
#define _MODULO_UNO
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Producto
{
    private:
        long long identificador;
        string nombre;
        string descripcion;
        double precio;
    public:
        Producto ();
        void leer(void);
        void mostrar(void);

        long long getIdentificador() {
            return identificador;
        }
        double getPrecio() {
            return precio;
        }
};

class DiccionarioProductos {
    private:
        list<Producto> lista;
        int contador;
    
    public:
        DiccionarioProductos();
        void insertar(Producto nuevo);
        void eliminar(long long id);
        void producto(long long id);
        void precios (double min, double max);
        int numElem ()
            {return contador;}
};

#endif