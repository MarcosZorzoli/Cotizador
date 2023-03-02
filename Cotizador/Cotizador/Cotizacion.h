#ifndef COTIZACION_H_INCLUDED
#define COTIZACION_H_INCLUDED

#include <iostream>
#include <cstring>
#include <string>
#include "Tiempo.h"

class Cotizacion{
private:
    Fecha fregistro;
    int id;
    int id_categoria;
    int id_producto;
    int id_proveedor;
    int id_precio;
    int unidadMinima;
    float precioUnitario;
    int cantidadCompra;
    char nombre_marca[50];
    char nombre_producto[50];
    char nombre_proveedor[50];
    bool estado;

public:

    Cotizacion();

    void setId(int ID);
    void setId_Categoria(int _id);
    void setId_Producto(int _id);
    void setId_Proveedor(int _id);
    void setId_Precio(int _id);
    void setPrecioU(float n_precio);
    void setUnidadMin(int UM);
    void setCantCompra(int CC);
    void setNombreMarca(std::string Nombre);
    void setNombreProd(std::string Nombre);
    void setNombreProv(std::string Nombre);
    void setEstado(bool nEstado);
    void setFecha();
    int getId();
    int getId_Categoria();
    int getId_Producto();
    int getId_Proveedor();
    int getId_Precios();
    float getPrecioU();
    int getUnidadMin();
    int getCantCompra();
    std::string getNombreMarca();
    std::string getNombreProd();
    std::string getNombreProv();
    bool getEstado();
    Fecha getFecha();


    void Cargar();
    void Mostrar(Cotizacion cot);


};



#endif // COTIZACION_H_INCLUDED
