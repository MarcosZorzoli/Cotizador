#include "archivo_categorias.h"
#include <iostream>
using namespace std;

bool Archivo_Categoria::guardar(categorias cat){

FILE* pFile;
  cat.set_id(generar_categoria());

  pFile = fopen("categorias.dat", "ab");

  if (pFile == nullptr) {
    cout << "Error al abrir el archivo" << endl;
    exit(1552);
  }

  bool i=fwrite(&cat, sizeof(categorias), 1, pFile);

  fclose(pFile);

  return i;
}

int Archivo_Categoria::generar_categoria()
{
  return cantidad_categorias() + 1;
}

int Archivo_Categoria::cantidad_categorias()
{
  FILE* pFile;
  int cantidad = 0;
  categorias cat;

  pFile = fopen("categorias.dat", "rb");

  if (pFile == nullptr) {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(categorias);

  fclose(pFile);

  return cantidad;
}
categorias Archivo_Categoria::leer_categorias(int pos)
{
    categorias cat;
    FILE* pFile;
  pFile = fopen("categorias.dat", "rb");
  if (pFile == nullptr) {
      cout<<"no se pudo abrir el archivo"<<endl;
  }

  fseek(pFile,pos*sizeof (categorias),SEEK_SET);
  bool ok= fread(this, sizeof(categorias),1,pFile);
  if(ok==false)
  {
       cout<<"no se pudo leer el archivo"<<endl;
  }

  fclose(pFile);
  return cat;
}
void Archivo_Categoria::listar_categorias()
{
     Archivo_Categoria ac;
  int cantidad_categorias = ac.cantidad_categorias();


  categorias* cat = new categorias[cantidad_categorias];

  for (int i = 0; i < cantidad_categorias; i++) {
    cat[i] = ac.leer_categorias(i);
    cat[i].mostrar();
  }





}



