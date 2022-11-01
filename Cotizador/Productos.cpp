#include "Productos.h"

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
    cout << "------------------" << endl;
    cout << "Ingrese nombre: ";
    cin >> _nombre;
    cout << "Ingrese precio: ";
    cin >> _precio;
}
void Producto::mostrar()
{
  cout << "------------------" << endl;
  cout << "Codigo: " << _codigo << endl;
  cout << "Nombre: " << _nombre << endl;
  cout << "Precio: " << _precio << endl;
  cout << "------------------" << endl << endl;
}
