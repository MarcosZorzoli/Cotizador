#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <string>

using namespace std;



class Producto
{
private:
  int _codigo;
  float _precio;
  char _nombre[50]; // usamos char por que esto representa la estructura de un archivo
int id_categoria;
public:
  Producto();
  int getCodigo();
  void setCodigo(int codigo);

  float getPrecio();
  void setPrecio(float precio);


  string getNombre();
  void setNombre(string nombre);

  void cargar();
  void mostrar();
  int buscar_producto(int codigo);
  void sobreescribir_producto(Producto p, int pos);


};


#endif // PRODUCTOS_H_INCLUDED
