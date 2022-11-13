#include "Productos.h"
#include "archivo_productos.h"
#include <iostream>


Producto::Producto()
{
    _codigo = 0;
    strcpy(_nombre, "");
    id_categoria=0;
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
int Producto::getID_categoria()
{
    return id_categoria;
}

void Producto::setPrecio(float precio) {
    _precio = precio;
}


std::string Producto::getNombre() {
    return _nombre;
}

void Producto::setNombre(string nombre) {
    strcpy(_nombre, nombre.c_str());
}

void Producto::cargar() {
    cout << "------------------" << endl;
     cout << "Imgrese ID de producto: "<<endl;
     cin>>_codigo;
    cout << "Ingrese nombre: "<<endl;
    cin>> _nombre;
     cout << "Ingrese ID de categoria: "<<endl;
    cin>> id_categoria;
     cout << "------------------" << endl << endl;

}
void Producto::mostrar()
{
  cout << "------------------" << endl;
  cout << "Codigo: " << _codigo << endl;
  cout << "Nombre: " << _nombre << endl;
  cout<<"ID categoria: "<<id_categoria<<endl;
  cout << "------------------" << endl << endl;
}
int Producto::buscar_producto(int id)
{
    Producto p;
    FILE* pFile;
  pFile = fopen("productos.dat", "rb");
  if (pFile == nullptr) {

    cout<<"error al abrir el archivo"<<endl;
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
void Producto::sobreescribir_producto(Producto p, int pos)
{
    FILE* pFile;
  pFile = fopen("producto.dat", "rb+");
  if (pFile == nullptr) {
    cout<<"error al abrir el archivo"<<endl;
  }

  fseek(pFile,pos*sizeof (Producto),0);
  bool ok= fwrite(this, sizeof(Producto),1,pFile);

  fclose(pFile);


}


