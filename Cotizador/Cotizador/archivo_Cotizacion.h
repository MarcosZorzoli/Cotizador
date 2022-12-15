#ifndef ARCHIVO_COTIZACION_H_INCLUDED
#define ARCHIVO_COTIZACION_H_INCLUDED
#include "Cotizacion.h"
#include <iostream>
#include <fstream>

class archivo_cotizacion{

public:

    void guardar(Cotizacion cotiza);
    bool guardar(Cotizacion cotiza, int posicion);
    int cantidad_de_registros();
    Cotizacion leer_de_disco(int posicion);
    void listar(int cantidad);
    int get_cantidad_Activa(int cantidad);
    void baja_Logica();

};

#endif // ARCHIVO_COTIZACION_H_INCLUDED
