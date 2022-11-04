#ifndef ARCHIVO_CATEGORIAS_H_INCLUDED
#define ARCHIVO_CATEGORIAS_H_INCLUDED
#include "Categorias.h"
class Archivo_Categoria
{
public:
  void guardar(categorias cat);
   int generar_categoria();
  int cantidad_categorias();
  categorias leer_categorias(int pos);
  FILE* abrirArchivo();
  void obtener_categorias(categorias* cat, int cantidad);

};
  void cargar_categias_vector(categorias vec[], int cantidad);


#endif // ARCHIVO_CATEGORIAS_H_INCLUDED
