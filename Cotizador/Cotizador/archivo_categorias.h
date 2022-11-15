#ifndef ARCHIVO_CATEGORIAS_H_INCLUDED
#define ARCHIVO_CATEGORIAS_H_INCLUDED
#include "Categorias.h"
class Archivo_Categoria
{
public:
    bool guardarEnDisco(int);
  void guardar(categorias cat);
   int generar_categoria();
  int cantidad_categorias();
  categorias leer_categorias(int pos);
  FILE* abrirArchivo();
  void obtener_categorias(categorias* cat, int cantidad);
int buscarCategoria(int ID);

void listar_categorias();
void modificar_categorias();
void agregar_categoria();
};




#endif // ARCHIVO_CATEGORIAS_H_INCLUDED
