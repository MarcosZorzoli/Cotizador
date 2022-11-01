#include "archivo_productos.h"
#include <iostream>



bool archivo_productos::guardar(Producto producto)
{
  FILE* pFile;
  producto.setCodigo(generarCodigo());

  pFile = fopen("productos.dat", "ab");

  if (pFile == nullptr) {
    cout << "Error al abrir el archivo" << endl;
    exit(1552);
  }

  bool i=fwrite(&producto, sizeof(Producto), 1, pFile);

  fclose(pFile);

  return i;
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
void archivo_productos::modificar_precio()
{
    archivo_productos ar_producto;
    Producto productos;
    float nuevo_precio;
    int cantidad=cantidadProductos();

    int id, pos;
    cout<<"ID a buscar: "<<endl;
    cin>>id;

     pos=productos.buscar_producto(id);

    if(pos>=0)
    {
        productos=leer_Producto(pos);
        productos.mostrar();


    cout<<endl;
    cout<<"ingrese nuevo precio:"<<endl;
    cin>>nuevo_precio;
    if(sobreescribir_precio(productos, pos))
    {
        cout<<"PRECIO MODIFICADO"<<endl;
    }
    }
    else { cout<<"no existe el registro"<<endl;}

    }
Producto archivo_productos::leer_Producto(int pos)
{
    Producto p;
    FILE* pFile;
  pFile = fopen("productos.dat", "rb");
  if (pFile == nullptr) {
        p.setPrecio(-1);
    return p;
  }

  fseek(pFile,pos*sizeof (Producto),SEEK_SET);
  bool ok= fread(this, sizeof(Producto),1,pFile);
  if(ok==false)
  {
         p.setPrecio(-1);
    return p;
  }

  fclose(pFile);
  return p;
}
bool archivo_productos::sobreescribir_precio(Producto p, int pos)
{
    FILE* pFile;
  pFile = fopen("productos.dat", "rb+");
  if (pFile == nullptr) {
    return false;
  }

  fseek(pFile,pos*sizeof (Producto),0);
  bool ok= fwrite(this, sizeof(Producto),1,pFile);

  fclose(pFile);
  return ok;

}




