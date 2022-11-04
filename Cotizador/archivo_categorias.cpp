#include "archivo_categorias.h"
#include <iostream>
using namespace std;

void Archivo_Categoria::guardar(categorias cat)
{

    FILE* pFile;

    pFile = fopen("categoria.dat", "ab");

    if (pFile == nullptr)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1552);
    }

    fwrite(&cat, sizeof(categorias), 1, pFile);

    fclose(pFile);

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

    pFile = fopen("categoria.dat", "rb");

    if (pFile == nullptr)
    {
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
    pFile = fopen("categoria.dat", "rb");
    if (pFile == nullptr)
    {
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


FILE* Archivo_Categoria::abrirArchivo()
{
    FILE* pFile;
    pFile = fopen("categoria.dat", "rb");

    if (pFile == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1550);
    }
    return pFile;
}
void Archivo_Categoria::obtener_categorias(categorias* cat, int cantidad)
{
    FILE* pFile = abrirArchivo();

    fread(cat, sizeof(categorias), cantidad, pFile);

    fclose(pFile);
}



