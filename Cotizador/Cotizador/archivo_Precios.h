#ifndef ARCHIVO_PRECIOS_H_INCLUDED
#define ARCHIVO_PRECIOS_H_INCLUDED
#include "Precios.h"
#include <iostream>
#include <fstream>

class archivo_precios{

public:

    void guardar(Precios Precio);
    bool guardar(Precios Precio, int posicion);
    int cantidad_de_registros();
    Precios leer_de_disco(int posicion);
    void listar(int cantidad);
    int get_cantidad_Activa(int cantidad);
    void baja_Logica();
    void modificar();
};

#endif // ARCHIVO_PRECIOS_H_INCLUDED
