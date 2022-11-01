#include "archivo_productos.h"
#include <iostream>
using namespace std;


Producto archivo_productos::guardar(Producto producto)
{
  FILE* pFile;

  producto.setCodigo(generarCodigo());

  pFile = fopen("productos.dat", "ab");

  if (pFile == nullptr) {
    cout << "Error al abrir el archivo" << endl;
    exit(1552);
  }

  fwrite(&producto, sizeof(Producto), 1, pFile);

  fclose(pFile);

  return producto;
}

int archivo_productos::generarCodigo()
{
  return cantidadProductos() + 1;
}

int archivo_productos::cantidadProductos()
{
  FILE* pFile;
  int cantidad = 0;
  Producto producto;

  pFile = fopen("productos.dat", "rb");

  if (pFile == nullptr) {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Producto);

  fclose(pFile);

  return cantidad;
}

void archivo_productos::leerProductos(Producto productos[], int cantidad)
{
  FILE* pFile;
  pFile = fopen("productos.dat", "rb");
  if (pFile == nullptr) {
    return;
  }

  fread(productos, sizeof(Producto), cantidad, pFile);

  fclose(pFile);
}
int archivo_productos::buscar_producto(int codigo)
 {
  for (int i = 0; i < cantidadProductos(); i++) {
    if (Producto[i].getCodigo()== codigo)
     {

        return i;
    }
  }
  return -1;
}

void archivo_productos::mostrar_producto() {
  cout << endl;
  for (int i = 0; i < cantidadProductos(); i++) {
    cout << "----------------------------" << endl;
    cout << "Articulo: #" << i + 1 << endl;
    cout << "Codigo: " << Producto[i].getCodigo() << endl;
    cout << "Nombre: " << Producto[i].getNombre() << endl;
    cout << "Precio: " << Producto[i].getPrecio() << endl;

  }
}
