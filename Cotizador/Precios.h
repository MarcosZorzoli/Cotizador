#ifndef PRECIOS_H_INCLUDED
#define PRECIOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Precios
{
private:
    int id;
    float precio;
    char nombre_marca[50];
    int id_categoria;
    int id_proveedor;
public:

    Precios();

    int get_id();
    void set_id(int _id);

    float get_precio();
    void set_precio(float _precio);


    string get_nombre();
    void set_nombre(string _nombre);

    int get_id_proveedor();
    void set_id_proveedor(int id_proveedor);

    int get_id_categoria();
    void set_id_categoria(int id_categoria);

    void cargar();
    void mostrar();


};


#endif // PRECIOS_H_INCLUDED
