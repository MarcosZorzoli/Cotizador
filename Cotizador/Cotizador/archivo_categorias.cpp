#include "archivo_categorias.h"
#include <iostream>
using namespace std;

/*/void Archivo_Categoria::baja_Logica()
{
            categorias c;
            int cant_cat= cantidad_categorias();
            categorias* cat= new categorias[cant_cat];

            obtener_categorias(cat,cant_cat);
            listar_categorias();
            int cod;
            cout<<endl<<"ingresar el codigo de la Categoria a eliminar"<<endl;
            cin>>cod;
            for(int i=0; i< cant_cat; i++)
            {
                if(cod==cat[i].get_id())
                {
        std::cout<<"Si elimina la Categoria se borrara/n el/los siguiente/s producto/s y sus precios asociados"<<std::endl;
        Productos prod;
        archivo_productos aprod;
        int pos=0;
        while(pos<aprod.cantidad_de_registros())
        {
            prod=aprod.leer_de_disco(pos);
            if(prod.getId_Categoria()==cod&&prod.getEstado())
            {
                prod.mostrar();
                std::cout<<std::endl;
                pos++;
            }else{
            pos++;
            }
        }

        char op2;
        std::cout<<"esta seguro de que desea eliminar la Categoria?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {

  cat[i].setEstado(false);
                    cat[i].sobreescribir_categoria(c,i);
                    delete [] cat;
        int idproducto;
        int posicion=0;

        while(posicion<aprod.cantidad_de_registros())
        {
            prod=aprod.leer_de_disco(posicion);
            if(prod.getId_Categoria()==cod&&prod.getEstado())
            {
                idproducto=prod.getId_Producto();
                aprod.baja_Logica(cod);

                archivo_precios aprecios;
                Precios precio;
                int posi=0;

        while(posi<aprecios.cantidad_de_registros())
        {
            precio=aprecios.leer_de_disco(posi);
            if(precio.getId_Producto()==idproducto&&precio.getEstado())
            {
                aprecios.baja_Logica(idproducto);
                std::cout<<std::endl;
                posi++;
            }else{
            posi++;
            }
        posi++;
        }
                std::cout<<std::endl;
                posicion++;


            }else{
            posicion++;
            }
            posicion++;
        }


                      system("pause");
        } else {
                            delete [] cat;
                      break;
        }


                }
            }

}
/*/


void Archivo_Categoria::baja_Logica()
{
            categorias c;
            int cant_cat= cantidad_categorias();
            categorias* cat= new categorias[cant_cat];

            obtener_categorias(cat,cant_cat);
            listar_categorias();
            int cod;
            cout<<endl<<"ingresar el codigo de la Categoria a eliminar"<<endl;
            cin>>cod;
            for(int i=0; i< cant_cat; i++)
            {
                Productos prod;
        archivo_productos aprod;
                if(cod==cat[i].get_id())
                {
        std::cout<<"Si elimina la Categoria se borrara/n el/los siguiente/s producto/s y sus precios asociados"<<std::endl;

        int pos=0;
        while(pos<aprod.cantidad_de_registros())
        {
            prod=aprod.leer_de_disco(pos);
            if(prod.get_id()==cod&&prod.getEstado())
            {
                prod.mostrar();
                std::cout<<std::endl;
                pos++;
            }else{
            pos++;
            }
        }

        char op2;
        std::cout<<"esta seguro de que desea eliminar la Categoria?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {

                    cat[i].setEstado(false);
                    cat[i].sobreescribir_categoria(c,i);
                    delete [] cat;
       int posi=0;
        while(posi<aprod.cantidad_de_registros())
        {
            prod=aprod.leer_de_disco(posi);
            if(prod.getId_Categoria()==cod&&prod.getEstado())
            {
                Precios precio;
                archivo_precios aprec;
                int posicion=0;
                while(posicion<aprec.cantidad_de_registros())
                {
                    precio=aprec.leer_de_disco(posicion);
                    if(precio.getId_Producto()==prod.getId_Producto()&&precio.getEstado())
                    {
                        aprec.baja_Logica(precio.getId());
                        posicion++;

                    }else{
                    posicion++;}
                }

                aprod.baja_Logica(prod.get_id());
                std::cout<<std::endl;
                posi++;
            }else{
            posi++;
            }
        }

        }else{
            delete [] cat;
        }
        }}
        }

bool Archivo_Categoria::guardar_Categorias(categorias cat, int posicion)
{
  FILE* p;
  p = fopen("categoria.dat", "rb+");
  if (p == nullptr){
    std::cout<<"No se pudo abrir el archivo"<<std::endl;
  return false;
  }
  fseek(p, posicion * sizeof(categorias), SEEK_SET);
  fwrite(&cat, sizeof(categorias), 1, p);
  fclose(p);

  return true;
}

void Archivo_Categoria::guardar(categorias cat)
{

    FILE* pFile;

    pFile = fopen("categoria.dat", "ab");

    if (pFile == nullptr)
    {
        cout << "Error para guardar la Categoria" << endl;
    }

    fwrite(&cat, sizeof(categorias), 1, pFile);

    fclose(pFile);

}

categorias Archivo_Categoria::leer_de_disco(int posicion)
{
  categorias categoria;
  FILE* p;
  p = fopen("categoria.dat", "rb");

  if (p == nullptr){
    std::cout << "Error al abrir el archivo" << std::endl;
  }

  fseek(p, posicion * sizeof(categorias), SEEK_SET);
  fread(&categoria, sizeof(categorias), 1, p);
  fclose(p);

  return categoria;
}


int Archivo_Categoria::generar_categoria()
{
    return cantidad_categorias() + 1;
}

int Archivo_Categoria::cantidad_categorias()
{
    FILE* pFile;
    int cantidad = 0;

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
        cout<<"No se pudo abrir el archivo"<<endl;
    }

    fseek(pFile,pos*sizeof (categorias),SEEK_SET);
    bool ok= fread(this, sizeof(categorias),1,pFile);
    if(ok==false)
    {
        cout<<"No se pudo leer el archivo"<<endl;
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

            int cant_cat= cantidad_categorias();
            categorias* cat= new categorias[cant_cat];

            obtener_categorias(cat,cant_cat);

            for(int i=0; i< cant_cat; i++)
            {
                if(cat[i].getEstado())
                {
                cat[i].mostrar();
                }

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
            ac.listar_categorias();
            int cod;
            cout<<endl<<"ingresar codigo a modificar"<<endl;
            cin>>cod;
            for(int i=0; i< cant_cat; i++)
            {
                if(cod==cat[i].get_id())
                {
                    cat[i].mostrar();
                    system("pause");
                    char nuevo_nombre[30];
                    cout<<"ingresar nuevo nombre"<<endl;
                    cin>>nuevo_nombre;
                    cat[i].setNombre(nuevo_nombre);
                    system("pause");
                    cat[i].sobreescribir_categoria(c,i);
                    delete [] cat;
                }
            }

}
void Archivo_Categoria::agregar_categoria()
{
    categorias cat;
            Archivo_Categoria ac;
            system("cls");

            cat.cargar();
            ac.guardar(cat);
            cat.mostrar();
            cout<<endl;
            system("pause");
}

int Archivo_Categoria::get_cantidad_Activa(int cantidad)
{ int contador=0;

    for (int i = 0; i < cantidad; i++)
    {
        categorias categoria;
        categoria=leer_de_disco(i);
        if(categoria.getEstado())
        {
        contador++;
        }
    }
    return contador;
}
bool Archivo_Categoria::Existe(int op)
{
    categorias cat;
    for(int i=0;i<cantidad_categorias();i++)
    {
    cat=leer_de_disco(i);
      if(cat.get_id()==op)
      {
       return true;
      }

    }
    return false;

}

