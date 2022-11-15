#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include "Categorias.h"
#include <string>
#include <iostream>
#include <cstring>

class Productos:public categorias
{
private:
    int id_producto;
    bool estado;
public:
    Productos();
    void setNombre(std::string _nombre);
    void setId_Categoria(int id_categoria);
    void setId_Producto(int id_producto);
    void setEstado(bool nEstado);

    std::string getNombre();
    int getId_Categoria();
    int getId_Producto();
    bool getEstado();

    void Cargar();
    void Mostrar();
};


#endif // PRODUCTOS_H_INCLUDED
