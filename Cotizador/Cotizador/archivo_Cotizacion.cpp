#include "Cotizacion.h"
#include "archivo_Cotizacion.h"


void archivo_cotizacion::guardar(Cotizacion Cotiza)
{
 FILE* p;
  p = fopen("Cotizacion.dat", "ab");
  if (p == nullptr)
  {
    std::cout<<"Error para guardar la Cotizacion"<<std::endl;
  }
  fwrite(&Cotiza, sizeof(Cotizacion), 1, p);
  fclose(p);
}
bool archivo_cotizacion::guardar(Cotizacion Cotiza, int posicion)
{

  FILE* p;
  p = fopen("Cotizacion.dat", "rb+");
  if (p == nullptr){
    std::cout<<"No se pudo abrir el archivo"<<std::endl;
  return false;
  }
  fseek(p, posicion * sizeof(Cotizacion), SEEK_SET);
  fwrite(&Cotiza, sizeof(Cotizacion), 1, p);
  fclose(p);

  return true;
}

int archivo_cotizacion::cantidad_de_registros()
{
    int cantidad=0;
    FILE * p;
    p=fopen("Cotizacion.dat","rb");
    if(p==nullptr)
    {
        return cantidad;
    }
    fseek(p,0,SEEK_END);//mueve e cursor al final del archivo
    cantidad=ftell(p)/sizeof(Cotizacion); // cuenta la cantidad de registros
    fclose(p);
    return cantidad;
}

Cotizacion archivo_cotizacion::leer_de_disco(int posicion)
{
  Cotizacion Cotiza;
  FILE* p;
  p = fopen("Cotizacion.dat", "rb");

  if (p == nullptr){
    std::cout << "Error al abrir el archivo" << std::endl;
  }

  fseek(p, posicion * sizeof(Cotizacion), SEEK_SET);
  fread(&Cotiza, sizeof(Cotizacion), 1, p);
  fclose(p);

  return Cotiza;
}

void archivo_cotizacion::listar(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        Cotizacion Cotiza;
        Cotiza=leer_de_disco(i);
        if(Cotiza.getEstado())
        {std::cout<<"------------------"<<std::endl;
        Cotiza.Mostrar(Cotiza);
        }
    }
}

int archivo_cotizacion::get_cantidad_Activa(int cantidad)
{ int contador=0;

    for (int i = 0; i < cantidad; i++)
    {
        Cotizacion Cotiza;
        Cotiza=leer_de_disco(i);
        if(Cotiza.getEstado())
        {
        contador++;
        }
    }
    return contador;
}

void archivo_cotizacion::baja_Logica()
{       int op;
        Cotizacion Cotiza;
        int cant=cantidad_de_registros();
        listar(cant);
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID de la Cotizacion que desea eliminar"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        Cotiza=leer_de_disco(op-1);
        if(Cotiza.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else{

        char op2;
        std::cout<<"esta seguro de que desea eliminar la Cotizacion?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {

        Cotiza.setEstado(false);
        guardar(Cotiza, op-1);
        }
}
}



