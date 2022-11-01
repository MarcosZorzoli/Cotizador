#include "Productos.h"
#include "archivo_productos.h"

#include <iostream>
using namespace std;

Producto::Producto()
{
    _codigo = 0;
    _precio = 0;
    strcpy(_nombre, "");
    id_categoria;
}

int Producto::getCodigo() {
    return _codigo;
}

void Producto::setCodigo(int codigo) {
    _codigo = codigo;
}

float Producto::getPrecio() {
    return _precio;
}

void Producto::setPrecio(float precio) {
    _precio = precio;
}


std::string Producto::getNombre() {
    return _nombre;
}

void Producto::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}

void Producto::cargar() {
    archivo_productos archi;
    Producto productos;
    cout << "------------------" << endl;
    cout << "Ingrese nombre: ";
    cin >> _nombre;
    cout << "Ingrese precio: ";
    cin >> _precio;
    archi.guardar(productos);

}
void Producto::mostrar()
{
  cout << "------------------" << endl;
  cout << "Codigo: " << _codigo << endl;
  cout << "Nombre: " << _nombre << endl;
  cout << "Precio: " << _precio << endl;
  cout << "------------------" << endl << endl;
}
int Producto::buscar_producto(int id)
{
    Producto p;
    FILE* pFile;
  pFile = fopen("productos.dat", "rb");
  if (pFile == nullptr) {

    return -2;
  }
int i=0;
  while(fread(&p,sizeof(Producto),1,pFile)){
    if(p.getCodigo()==id)
  {
      fclose(pFile);
      return i;
  }
  i++;
}
  fclose(pFile);
  return -1;
}


