#include "archivo_Precios.h"
#include "Precios.h"


void archivo_precios::guardar(Precios Precio)
{
 FILE* p;
  p = fopen("Precios.dat", "ab");
  if (p == nullptr)
  {
    std::cout<<"Error para guardar el Precio"<<std::endl;
  }
  fwrite(&Precio, sizeof(Precios), 1, p);
  fclose(p);
}
bool archivo_precios::guardar(Precios Precio, int posicion)
{

  FILE* p;
  p = fopen("Precios.dat", "rb+");
  if (p == nullptr){
    std::cout<<"No se pudo abrir el archivo"<<std::endl;
  return false;
  }
  fseek(p, posicion * sizeof(Precios), SEEK_SET);
  fwrite(&Precio, sizeof(Precios), 1, p);
  fclose(p);

  return true;
}

int archivo_precios::cantidad_de_registros()
{
    int cantidad=0;
    FILE * p;
    p=fopen("Precios.dat","rb");
    if(p==nullptr)
    {
        return cantidad;
    }
    fseek(p,0,SEEK_END);//mueve e cursor al final del archivo
    cantidad=ftell(p)/sizeof(Precios); // cuenta la cantidad de registros
    fclose(p);
    return cantidad;
}

Precios archivo_precios::leer_de_disco(int posicion)
{
  Precios Precio;
  FILE* p;
  p = fopen("Precios.dat", "rb");

  if (p == nullptr){
    std::cout << "Error al abrir el archivo" << std::endl;
  }

  fseek(p, posicion * sizeof(Precios), SEEK_SET);
  fread(&Precio, sizeof(Precios), 1, p);
  fclose(p);

  return Precio;
}

void archivo_precios::listar(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        Precios Precio;
        Precio=leer_de_disco(i);
        if(Precio.getEstado())
        {std::cout<<"------------------"<<std::endl;
        Precio.Mostrar(Precio);
        }
    }
}

int archivo_precios::get_cantidad_Activa(int cantidad)
{ int contador=0;

    for (int i = 0; i < cantidad; i++)
    {
        Precios Precio;
        Precio=leer_de_disco(i);
        if(Precio.getEstado())
        {
        contador++;
        }
    }
    return contador;
}

void archivo_precios::baja_Logica()
{       int op;
        Precios Precio;
        int cant=cantidad_de_registros();
        listar(cant);
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID del precio que desea eliminar"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        Precio=leer_de_disco(op-1);
        if(Precio.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else{

        char op2;
        std::cout<<"esta seguro de que desea eliminar al precio?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {

        Precio.setEstado(false);
        guardar(Precio, op-1);
        }
}
}

void archivo_precios::baja_Logica(int idprod)
{
        Precios Precio;
        int i=0;
        while(i<cantidad_de_registros())
        {
        Precio=leer_de_disco(i);
        if(Precio.getId_Producto()==idprod)
        {
        Precio.setEstado(false);
        guardar(Precio, idprod-1);
        break;
        }else{
        i++;
        }
        }

}


void archivo_precios::modificar()
{
        int op;
        Precios Precio;
        int cant=cantidad_de_registros();
        listar(cant);
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID del precio que desea modificar"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        Precio=leer_de_disco(op-1);
        if(Precio.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else{
    Precio.Cargar(Precio.getId());}

     char op2;
        std::cout<<"esta seguro de que desea modificar el precio?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {
    guardar(Precio, op-1);
        }
}

