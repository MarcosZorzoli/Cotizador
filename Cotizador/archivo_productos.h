#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Productos.h"

class archivo_productos
{
public:
  Producto guardar(Producto productos);
  int generarCodigo();
  int cantidadProductos();
  void leerProductos(Producto productos[], int cantidad);
  int buscar_producto(int codigo);
  void mostrar_producto();
};


#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
