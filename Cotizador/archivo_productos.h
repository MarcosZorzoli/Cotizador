#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Productos.h"

using namespace std;


class archivo_productos
{
public:
    bool guardarEnDisco(int);
    bool leerDeDisco(int);
    int buscarProducto(int ID);
  void guardar(Producto productos);
  int generarCodigo();
  int cantidadProductos();
  void leerProductos(Producto productos[], int cantidad);
  void mostrar_producto();
  Producto leer_Producto(int pos);
  void obtener_producto(Producto* prod, int cantidad);
  FILE* abrirArchivo();

  void listar_productos();
  void agregar_producto();
  void modificar_producto();

};


#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
