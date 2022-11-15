//#include "archivo_precios"
#include "Precios.h"
#include <iostream>


Precios::Precios()
{
    id = 0;
    precio = 0;
    strcpy(nombre_marca, "");
    id_proveedor=0;
    id_categoria=0;
}

int Precios::get_id()
{
    return id;
}

void Precios::set_id(int _id)
{
    id = _id;
}

float Precios::get_precio()
{
    return precio;
}

void Precios::set_precio(float _precio)
{
    precio = _precio;
}


string Precios::get_nombre()
{
    return nombre_marca;
}

void Precios::set_nombre(string _nombre)
{
    strcpy(nombre_marca, _nombre.c_str());
}

void Precios::cargar()
{
    //archivo_precios pre;
    Precios _precio;
    cout << "------------------" << endl;
    cout << "Ingrese nombre: ";
    cin >> nombre_marca;
    cout << "Ingrese precio: ";
    cin >> precio;
    //pre.guardar(productos);

}
void Precios::mostrar()
{
    cout << "------------------" << endl;
    cout << "------------------" << endl << endl;
}



