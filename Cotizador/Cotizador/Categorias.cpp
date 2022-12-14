#include "Categorias.h"
#include "archivo_categorias.h"
#include "cstring"
#include <iostream>
#include <string>


categorias::categorias()
{
        Archivo_Categoria Archivo;
        id_categoria=Archivo.cantidad_categorias()+1;
        estado=true;
}

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
    cout << "------------------" << endl;
    cout << "Ingrese nombre: ";
    cin >> _nombre;
}
void categorias::mostrar()
{

  cout << "------------------" << endl;
  cout << "ID de categoria: " << id_categoria << endl;
  cout << "Nombre: " << _nombre << endl;

}
void categorias::cargar_categias_vector(categorias vec[], int cantidad) {
  Archivo_Categoria ac;

  for (int i = 0; i < cantidad; i++) {
    vec[i] = ac.leer_categorias(i);
  }
}
void categorias::sobreescribir_categoria(categorias c, int pos)
{
    FILE* pFile;
  pFile = fopen("categoria.dat", "rb+");
  if (pFile == nullptr) {
    cout<<"error al abrir el archivo"<<endl;
  }

  fseek(pFile,pos*sizeof (categorias),0);
  fwrite(this, sizeof(categorias),1,pFile);

  fclose(pFile);


}
void categorias::setEstado(bool nEstado)
    {
        estado=nEstado;
    }
bool categorias::getEstado()
{

    return estado;
}
