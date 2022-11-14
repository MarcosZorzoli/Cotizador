#include "archivo_Proveedores.h"

void archivo_Proveedores::guardar(Proveedores Proveedor)
{
 FILE* p;
  p = fopen("Proveedores.dat", "ab");
  if (p == nullptr)
  {
    std::cout<<"Error para guardar el Proveedor"<<std::endl;
  }
  fwrite(&Proveedor, sizeof(Proveedores), 1, p);
  fclose(p);
}
bool archivo_Proveedores::guardar(Proveedores Proveedor, int posicion)
{
  FILE* p;
  p = fopen("Proveedores.dat", "rb+");
  if (p == NULL){
    std::cout<<"No se pudo abrir el archivo"<<std::endl;
  return false;
  }
  fseek(p, posicion * sizeof(Proveedores), SEEK_SET);
  fwrite(&Proveedor, sizeof(Proveedores), 1, p);
  fclose(p);

  return true;
}

int archivo_Proveedores::cantidad_de_registros()
{
    int cantidad=0;
    FILE * p;
    p=fopen("Proveedores.dat","rb");
    if(p==nullptr)
    {
        return cantidad;
    }
    fseek(p,0,SEEK_END);//mueve e cursor al final del archivo
    cantidad=ftell(p)/sizeof(Proveedores); // cuenta la cantidad de registros
    fclose(p);
    return cantidad;
}

Proveedores archivo_Proveedores::leer_de_disco(int posicion)
{
  Proveedores Proveedor;
  FILE* p;
  p = fopen("Proveedores.dat", "rb");

  if (p == nullptr){
    std::cout << "Error al abrir el archivo" << std::endl;
  }

  fseek(p, posicion * sizeof(Proveedores), SEEK_SET);
  fread(&Proveedor, sizeof(Proveedores), 1, p);
  fclose(p);

  return Proveedor;
}

void archivo_Proveedores::listar(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        Proveedores Proveedor;
        Proveedor=leer_de_disco(i);
        if(Proveedor.getEstado())
        {std::cout<<"------------------"<<std::endl;
        Proveedor.Mostrar();
        }
    }
}

int archivo_Proveedores::get_cantidad_Activa(int cantidad)
{ int contador=0;

    for (int i = 0; i < cantidad; i++)
    {
        Proveedores Proveedor;
        Proveedor=leer_de_disco(i);
        if(Proveedor.getEstado())
        {
        contador++;
        }
    }
    return contador;
}

void archivo_Proveedores::baja_Logica()
{       int op;
        Proveedores proveedor;
        int cant=cantidad_de_registros();
        listar(cant);
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID del proveedor que desea eliminar"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        proveedor=leer_de_disco(op-1);
        if(proveedor.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else{

        char op2;
        std::cout<<"esta seguro de que desea eliminar al proveedor?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {

        proveedor.setEstado(false);
        guardar(proveedor, op-1);
        }
}
}

void archivo_Proveedores::modificar()
{
        int op;
        Proveedores proveedor;
        int cant=cantidad_de_registros();
        listar(cant);
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID del proveedor que desea modificar"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        proveedor=leer_de_disco(op-1);
        if(proveedor.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else{
    proveedor=leer_de_disco(op-1);
    proveedor.Cargar();}

     char op2;
        std::cout<<"esta seguro de que desea modificar al proveedor?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {
    guardar(proveedor, op-1);
        }
}

