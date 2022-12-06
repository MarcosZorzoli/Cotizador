#ifndef PRECIOS_H_INCLUDED
#define PRECIOS_H_INCLUDED
#include "Productos.h"
#include <iostream>
#include <cstring>
#include <string>


class Precios{
private:
    int id;
    int id_proveedor;
    int id_producto;
    int unidadMinima;
    float precioUnitario;
    char nombre_marca[50];
    char nombre_produto[50];
    bool estado;

public:

    Precios();

    void setId(int ID);
    void setId_Proveedor(int _id);
    void setId_Producto(int _id);
    void setPrecioU(float n_precio);
    void setUnidadMin(int UM);
    void setNombreMarca(std::string Nombre);
    void setNombreProd(std::string Nombre);
    void setEstado(bool nEstado);

    int getId();
    int getId_Proveedor();
    int getId_Producto();
    float getPrecioU();
    int getUnidadMin();
    std::string getNombreMarca();
    std::string getNombreProd();
    bool getEstado();


    void Cargar();
    void Mostrar(Precios pre);


};


#endif // PRECIOS_H_INCLUDED
