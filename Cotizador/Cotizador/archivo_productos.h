#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Productos.h"

using namespace std;


class archivo_productos
{
public:

void guardar(Productos producto);
    bool guardar(Productos producto, int posicion);
    int cantidad_de_registros();
    Productos leer_de_disco(int posicion);
    void listar(int cantidad);
    int get_cantidad_Activa(int cantidad);
    void baja_Logica();
    void modificar();
    void obtener_productos(Productos* prod, int cantidad);
    void listaXcategoria();



};


#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
