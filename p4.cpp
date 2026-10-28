#include <iostream>
#include <string>
using namespace std;
const int MAX_DIGITO = 13;
const int MAX_PRECIO = 10000;

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
};
Producto :: Producto()
{
    identificador = 0;
    nombre = "";
    descripcion = "";
    precio = 0.0;
}

void Producto::leer()
{
    cin >> identificador; // 898988
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


int main() 
{
    Producto p;
    string comando;
    int i = 1;
    while (cin >> comando) 
    {
        if (comando == "insertar")
        {
            p.leer();
            cout << i << ". ";
            p.mostrar();
            i++;
        }
    }
}