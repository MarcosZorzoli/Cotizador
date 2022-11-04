#include "Categorias.h"
#include "archivo_categorias.h"
#include "cstring"
#include <iostream>
#include <string>

//gets
string categorias::getNombre()
{
    return _nombre;
}

int categorias::get_id()
{
    return id_categoria;
}

//sets
void categorias::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

    void categorias::set_id(int nuevo_id)
    {
        id_categoria=nuevo_id;
    }
void categorias::cargar() {
    Archivo_Categoria archi;
    categorias cat;
    cout << "------------------" << endl;
    cout << "Ingrese nombre: ";
    cin >> _nombre;
    cout << "Ingrese ID de categoria: ";
    cin >>id_categoria;

}
void categorias::mostrar()
{

  cout << "------------------" << endl;
  cout << "ID de categoria: " << id_categoria << endl;
  cout << "Nombre: " << _nombre << endl;
  cout << "------------------" << endl << endl;
}
void categorias::cargar_categias_vector(categorias vec[], int cantidad) {
  Archivo_Categoria ac;

  for (int i = 0; i < cantidad; i++) {
    vec[i] = ac.leer_categorias(i);
  }
}
