#ifndef ARCHIVO_PROVEEDORES_H_INCLUDED
#define ARCHIVO_PROVEEDORES_H_INCLUDED
#include "Proveedores.h"
#include <iostream>
#include <fstream>

class archivo_Proveedores{

public:

    void guardar(Proveedores Proveedor);
    bool guardar(Proveedores Proveedor, int posicion);
    int cantidad_de_registros();
    Proveedores leer_de_disco(int posicion);
    void listar(int cantidad);
    int get_cantidad_Activa(int cantidad);
    void baja_Logica();
    void modificar();
};
#endif // ARCHIVO_PROVEEDORES_H_INCLUDED
