#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Productos.h"

class archivo_productos
{
public:
  bool guardar(Producto productos);
  int generarCodigo();
  int cantidadProductos();
  void leerProductos(Producto productos[], int cantidad);
  void mostrar_producto();
  void modificar_precio();
  bool sobreescribir_precio(Producto p, int pos);
  Producto leer_Producto(int pos);

};


#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
