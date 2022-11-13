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
bool Archivo_Categoria::guardarEnDisco(int pos){
    FILE *p;
    p = fopen("categoria.dat", "rb+");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, pos * sizeof(categorias), SEEK_SET);
    ok = fwrite(this, sizeof(categorias), 1, p);
    fclose(p);
    return ok;
}
bool Archivo_Categoria::leerDeDisco(int nroRegistro){
    FILE *p;
    p = fopen("categoria.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(categorias), SEEK_SET);
    bool ok;
    ok = fread(this, sizeof(categorias), 1, p);
    fclose(p);
    return ok;
}

int Archivo_Categoria::buscarCategoria(int ID){
   Archivo_Categoria ac;
   categorias c;
    int i, cant = ac.cantidad_categorias();
    for(i =0; i<cant; i++){
    ac.leer_categorias(i);
        if (ID == c.get_id()){
            return i;
        }
    }
    return -1;
}
void Archivo_Categoria::listar_categorias()
{
    Archivo_Categoria ac;
            int cant_cat= ac.cantidad_categorias();
            categorias* cat= new categorias[cant_cat];

            ac.obtener_categorias(cat,cant_cat);

            for(int i=0; i< cant_cat; i++)
            {
                cout<<"----------------------"<<endl;
                cat[i].mostrar();
            }
            delete[] cat;
}
void Archivo_Categoria::modificar_categorias()
{
    Archivo_Categoria ac;
            categorias c;
            int cant_cat= ac.cantidad_categorias();
            categorias* cat= new categorias[cant_cat];

            ac.obtener_categorias(cat,cant_cat);
            int cod;
            cout<<"ingresar codigo a modificar"<<endl;
            cin>>cod;
            for(int i=0; i< cant_cat; i++)
            {
                if(cod==cat[i].get_id())
                {
                    cat[i].mostrar();
                    system("pause");
                    int nuevo_cod;
                    char nuevo_nombre[30];
                    cout<<"ingresar nuevo codigo"<<endl;
                    cin>>nuevo_cod;
                    cout<<"ingresar nuevo nombre"<<endl;
                    cin>>nuevo_nombre;
                    cat[i].setNombre(nuevo_nombre);
                    cat[i].set_id(nuevo_cod);
                    cat[i].mostrar();
                    system("pause");
                    cat[i].sobreescribir_categoria(c,i);
                }
            }
            delete [] cat;
}
void Archivo_Categoria::agregar_categoria()
{
    categorias cat;
            Archivo_Categoria ac;
            system("cls");

            cat.cargar();
            ac.guardar(cat);
}






