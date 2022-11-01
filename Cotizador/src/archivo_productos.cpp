#include "archivo_productos.h"

#include <iostream>
using namespace std;


Producto ArchivoProducto::guardar(Producto producto)
{
  FILE* pFile;

  producto.setCodigo(generarCodigo());

  pFile = fopen("productos.dat", "ab");

  if (pFile == nullptr) {
    cout << "Error al abrir el archivo" << endl;
    exit(1552);
  }

  fwrite(&producto, sizeof(Productos), 1, pFile);

  fclose(pFile);

  return producto;
}

int ArchivoProducto::generarCodigo()
{
  return cantidadProductos() + 1;
}

int ArchivoProducto::cantidadProductos()
{
  FILE* pFile;
  int cantidad = 0;
  Productos producto;

  pFile = fopen("productos.dat", "rb");

  if (pFile == nullptr) {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Productos);

  fclose(pFile);

  return cantidad;
}

void ArchivoProducto::leerProductos(Productos producto[], int cantidad)
{
  FILE* pFile;
  pFile = fopen("productos.dat", "rb");
  if (pFile == nullptr) {
        cout<<"no se puede abrir el archivo"<<endl;
    return;
  }

  fread(productos, sizeof(Productos), cantidad, pFile);

  fclose(pFile);
}
