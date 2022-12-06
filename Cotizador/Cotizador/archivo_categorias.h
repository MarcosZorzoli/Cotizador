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
int get_cantidad_Activa(int cantidad);
categorias leer_de_disco(int posicion);
void baja_Logica();
void listar_categorias();
void modificar_categorias();
void agregar_categoria();
bool guardar_Categorias(categorias cat, int posicion);
};




#endif // ARCHIVO_CATEGORIAS_H_INCLUDED
