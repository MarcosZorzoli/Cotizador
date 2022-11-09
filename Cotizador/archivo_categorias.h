#ifndef ARCHIVO_CATEGORIAS_H_INCLUDED
#define ARCHIVO_CATEGORIAS_H_INCLUDED
#include "Categorias.h"
class Archivo_Categoria
{
public:
    bool modificar();
    bool leerDeDisco(int);
    bool guardarEnDisco(int);
  void guardar(categorias cat);
   int generar_categoria();
  int cantidad_categorias();
  categorias leer_categorias(int pos);
  FILE* abrirArchivo();
  void obtener_categorias(categorias* cat, int cantidad);
int buscarCategoria(int ID);
void modificar_categoria();
void sobreescribir_categoria(categorias c, int pos);

};
  void cargar_categias_vector(categorias vec[], int cantidad);



#endif // ARCHIVO_CATEGORIAS_H_INCLUDED
