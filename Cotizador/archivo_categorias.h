#ifndef ARCHIVO_CATEGORIAS_H_INCLUDED
#define ARCHIVO_CATEGORIAS_H_INCLUDED
#include "Categorias.h"
class Archivo_Categoria
{
public:
  bool guardar(categorias cat);
   int generar_categoria();
  int cantidad_categorias();
  categorias leer_categorias(int pos);
  void listar_categorias();

};
  void cargar_categias_vector(categorias vec[], int cantidad);


#endif // ARCHIVO_CATEGORIAS_H_INCLUDED
