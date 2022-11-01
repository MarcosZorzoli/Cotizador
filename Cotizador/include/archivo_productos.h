#ifndef ARCHIVO_PRODUCTOS_H
#define ARCHIVO_PRODUCTOS_H

using namespace std;
class ArchivoProducto
{
public:
  Producto guardar(Productos producto);
  int generarCodigo();
  int cantidadProductos();
  void leerProductos(Productos productos[], int cantidad);
};

#endif // ARCHIVO_PRODUCTOS_H
