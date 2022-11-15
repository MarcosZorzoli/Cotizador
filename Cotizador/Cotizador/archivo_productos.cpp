#include "archivo_productos.h"
#include <iostream>

void archivo_productos::guardar(Productos producto)
{
 FILE* p;
  p = fopen("Producto.dat", "ab");
  if (p == nullptr)
  {
    std::cout<<"Error para guardar el Producto"<<std::endl;
  }
  fwrite(&producto, sizeof(Productos), 1, p);
  fclose(p);
}
bool archivo_productos::guardar(Productos producto, int posicion)
{
  FILE* p;
  p = fopen("Producto.dat", "rb+");
  if (p == NULL){
    std::cout<<"No se pudo abrir el archivo"<<std::endl;
  return false;
  }
  fseek(p, posicion * sizeof(Productos), SEEK_SET);
  fwrite(&producto, sizeof(Productos), 1, p);
  fclose(p);

  return true;
}

int archivo_productos::cantidad_de_registros()
{
    int cantidad=0;
    FILE * p;
    p=fopen("Producto.dat","rb");
    if(p==nullptr)
    {
        return cantidad;
    }
    fseek(p,0,SEEK_END);//mueve e cursor al final del archivo
    cantidad=ftell(p)/sizeof(Productos); // cuenta la cantidad de registros
    fclose(p);
    return cantidad;
}

Productos archivo_productos::leer_de_disco(int posicion)
{
  Productos producto;
  FILE* p;
  p = fopen("Producto.dat", "rb");

  if (p == nullptr){
    std::cout << "Error al abrir el archivo" << std::endl;
  }

  fseek(p, posicion * sizeof(Productos), SEEK_SET);
  fread(&producto, sizeof(Productos), 1, p);
  fclose(p);

  return producto;
}

void archivo_productos::listar(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        Productos producto;
        producto=leer_de_disco(i);
        if(producto.getEstado())
        {std::cout<<"------------------"<<std::endl;
        producto.Mostrar();
        }
    }
}

int archivo_productos::get_cantidad_Activa(int cantidad)
{ int contador=0;

    for (int i = 0; i < cantidad; i++)
    {
        Productos producto;
        producto=leer_de_disco(i);
        if(producto.getEstado())
        {
        contador++;
        }
    }
    return contador;
}

void archivo_productos::baja_Logica()
{       int op;
        Productos producto;
        int cant=cantidad_de_registros();
        listar(cant);
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID del producto que desea eliminar"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        producto=leer_de_disco(op-1);
        if(producto.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else{

        char op2;
        std::cout<<"esta seguro de que desea eliminar al producto?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {

        producto.setEstado(false);
        guardar(producto, op-1);
        }
}
}

void archivo_productos::modificar()
{
        int op;
        Productos producto;
        int cant=cantidad_de_registros();
        listar(cant);
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID del producto que desea modificar"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        producto=leer_de_disco(op-1);
        if(producto.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else{
    producto=leer_de_disco(op-1);
    producto.Cargar();}

     char op2;
        std::cout<<"esta seguro de que desea modificar al producto?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {
    guardar(producto, op-1);
        }
}
void archivo_productos::obtener_productos(Productos* prod, int cantidad)
{
     FILE* pFile;
    pFile = fopen("Producto.dat", "rb");

    if (pFile == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
    }

    fread(prod, sizeof(Productos), cantidad, pFile);

    fclose(pFile);
}
void archivo_productos::listaXcategoria()
{
     archivo_productos archivo;

            int cant_cat= archivo.cantidad_de_registros();
            Productos* prod= new Productos[cant_cat];

            archivo.obtener_productos(prod,cant_cat);
            int cat;
           cout<<"ingrese la categoria a listar: "<<endl;
           cin>>cat;
            for(int i=0; i< cant_cat; i++)
            {
                if(cat==prod[i].getId_Categoria())
                cout<<"----------------------"<<endl;
                prod[i].Mostrar();

            }
            delete[] prod;
}





