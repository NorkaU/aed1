#include <iostream>
#include <string>
#include <list>
#include "p6.h"
using namespace std;

Producto :: Producto()
{
    identificador = 0;
    nombre = "";
    descripcion = "";
    precio = 0.0;
}

void Producto::leer()
{
    cin >> identificador;
    cin.ignore();
    getline(cin,nombre);
    getline(cin,descripcion);
    cin >> precio;

}

void Producto::mostrar(void) {
    cout << nombre << " (" << identificador << ")" <<  endl;
    cout << "  " << descripcion << endl;
    cout << "  " << precio << " euros" << endl;
}

void procesar_insertar(Producto &p, int &total)
{
    total++;
    p.leer();
    cout << total << " productos" << endl;    
}

void procesar_palabras(Producto &p){
    string palabras;
    getline(cin,palabras);
    cout << "palabras" << palabras << endl;
    cout << "1. ";
    p.mostrar();
    cout << "Total: 1 producto" << endl;
}

void procesar_producto(Producto &p)
{
    long long identificador;
    cin >> identificador;
    cout << "producto " << identificador << endl;
    cout << "1. ";
    p.mostrar();
    cout << "Total: 1 producto" << endl;
}

void procesar_precios(Producto &p)
{
    double precio_min;
    double precio_max;
    cin >> precio_min;
    cin >> precio_max;
    cout << "precios " << precio_min << " "<< precio_max << endl;
    cout << "1. ";
    p.mostrar();
    cout << "Total: 1 producto" << endl;
}

void procesar_eliminar(int &total)
{
    long long identificador;
    cin >> identificador;
    total= total-1;
    cout << total << " productos" << endl; 
}

DiccionarioProductos::DiccionarioProductos ()
{
    contador= 0;
}
void DiccionarioProductos::insertar (Producto nuevo) {
    list<Producto>::iterator itLista = lista.begin();
    while (itLista != lista.end() && itLista->getIdentificador() < nuevo.getIdentificador())
    {
        itLista++;
    }
    lista.insert(itLista, nuevo);
    contador++;
}

void DiccionarioProductos::eliminar(long long id) {
    list<Producto>::iterator itLista = lista.begin();
    while (itLista != lista.end() && itLista->getIdentificador() < id)
    {
        itLista++;
    }
    if (itLista != lista.end() && itLista->getIdentificador() == id)
    {
        lista.erase(itLista);
        contador--;
    }
    
}

void DiccionarioProductos::producto(long long id)
{
    list<Producto>::iterator itLista = lista.begin();
    while (itLista != lista.end() && itLista->getIdentificador() < id)
    {
        itLista++;
    }
    if (itLista != lista.end() && itLista->getIdentificador() == id)
    {
        itLista->mostrar();
    }
}
void DiccionarioProductos::precios (double max, double min) {
    list<Producto>::iterator itLista = lista.begin();
    while (itLista != lista.end() && itLista->getPrecio() >= min && itLista->getPrecio() <= max)
    {
        itLista->mostrar();
        itLista++;
    }
}



int main() 
{
    Producto p;
    string comando;
    int i = 0;
    while (cin >> comando) 
    {
        if (comando == "insertar")
        {
            procesar_insertar(p, i);
        }
        else if (comando == "palabras")
        {
            procesar_palabras(p);
        }
        else if (comando == "precios") 
        {
            procesar_precios(p);
        }
        else if (comando == "eliminar")
        {
            procesar_eliminar(i);
        }
        else if (comando == "producto")
        {
            procesar_producto(p);
        }
    }
}