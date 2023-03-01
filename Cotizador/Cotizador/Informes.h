#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "archivo_productos.h"
#include "Productos.h"
#include "archivo_Cotizacion.h"
#include "Cotizacion.h"

/*/
        cout<<" 1- Producto más cotizado"<<endl;
        cout<<" 2- Cotizacion de mayor importe"<<endl;
        cout<<" 3- Principal Categoria"<<endl;



int contarCotizaciones(int IDprod)
{
    archivo_cotizacion obj;
Cotizacion cot;
int cantCot=0;

for(int y=0;y<obj.cantidad_de_registros();y++){

    cot=obj.leer_de_disco(y);

   if(cot.getId_Producto()==IDprod)
   {
    cantCot++;
   }
}
return cantCot;
}

int maximoVector(int *vec,int cant)
{
        int posMax=0;
        for(int i=0;i<cant;i++)
        {
            if(vec[i]>vec[posMax])
            {
                    posMax=i;

            }
        }
    return posMax;
}

void ProdMasCot(){

int cantReg;
int *vReg;
archivo_productos a_prod;
cantReg=a_prod.cantidad_de_registros();
vReg=new int[cantReg];
if(vReg==NULL)
{
    std::cout<<"Error de asignacion de memoria"<<std::endl;
    return;

}
Productos prod;

int pos=0;

for(int y=0;y<a_prod.cantidad_de_registros();y++){
if(prod.getEstado())
{
vReg[pos]=contarCotizaciones(prod.getId_Producto());
}
}

int posicion=maximoVector(vReg, cantReg);

std::cout<<"El Producto mas cotizado es: "<<std::endl;
prod=a_prod.leer_de_disco(posicion);
prod.Mostrar();

delete vReg;

}
/*/


int contarCotizaciones(int IDprod)
{
    archivo_cotizacion obj;
Cotizacion cot;
int cantCot=0;

for(int y=0;y<obj.cantidad_de_registros();y++){

    cot=obj.leer_de_disco(y);

   if(cot.getId_Producto()==IDprod)
   {
    cantCot++;
   }
}
return cantCot;
}

int contarCategorias(int IDcat)
{
    archivo_cotizacion obj;
Cotizacion cot;
int cantCot=0;

for(int y=0;y<obj.cantidad_de_registros();y++){

    cot=obj.leer_de_disco(y);

   if(cot.getId_Categoria()==IDcat)
   {
    cantCot++;
   }
}
return cantCot;
}

void ProdMasCot(){

Productos prod;
archivo_productos aprod;
int pos=0;
bool primero=true;
int posMax=0;
int maximo=0;

while(pos<aprod.cantidad_de_registros())
{
    prod=aprod.leer_de_disco(pos);
    if(prod.getEstado())
    {
    if(primero==true)
    {
    maximo=contarCotizaciones(prod.getId_Producto());
    posMax=pos;
    pos++;
    }else{
    if(contarCotizaciones(prod.getId_Producto())>maximo)
       {
    maximo=contarCotizaciones(prod.getId_Producto());
    posMax=pos;
    pos++;
       }
    }
    }
    pos++;


}

std::cout<<"El Producto mas cotizado es: "<<std::endl;
prod=aprod.leer_de_disco(posMax);
prod.Mostrar();
std::cout<<"Con un total de: "<<maximo<<" cotizaciones."<<std::endl;

}

void CotMaxImp()
{
Cotizacion cot;
archivo_cotizacion acot;
int pos=0;
bool primero=true;
int posMax=0;
float maximo=0;

while(pos<acot.cantidad_de_registros())
{
    cot=acot.leer_de_disco(pos);
    if(cot.getEstado())
    {
    if(primero==true)
    {
    maximo=cot.getPrecioU()*cot.getCantCompra();
    posMax=pos;
    pos++;
    }else{
    if((cot.getPrecioU()*cot.getCantCompra())>maximo)
       {
    maximo=cot.getPrecioU()*cot.getCantCompra();
    posMax=pos;
    pos++;
       }
    }

    }
    pos++;


}

std::cout<<"El ID de la cotizacion mas actual y de mayor importe, es la Cotizacion "<<std::endl;
std::cout<<"numero #"<< posMax+1<<std::endl;
std::cout<<"Con un importe total de: $"<<maximo<<std::endl<<std::endl;

std::cout<<"---- Resumen de cotizacion: ----"<<std::endl;
cot=acot.leer_de_disco(posMax);
cot.Mostrar(cot);

}

void CatMasCot(){

categorias cat;
Archivo_Categoria acat;
int pos=0;
bool primero=true;
int posMax=0;
int maximo=0;

while(pos<acat.cantidad_categorias())
{
    cat=acat.leer_de_disco(pos);
    if(cat.getEstado())
    {
    if(primero==true)
    {
    maximo=contarCategorias(cat.get_id());
    posMax=pos;
    pos++;
    }else{
    if(contarCategorias(cat.get_id())>maximo)
       {
    maximo=contarCategorias(cat.get_id());
    posMax=pos;
    pos++;
       }
    }
    }
    pos++;


}

std::cout<<"El ID de la categoria actualmente mas cotizada es:"<<std::endl;
std::cout<<"---- Categoria :----"<<std::endl;
cat=acat.leer_de_disco(posMax);
cat.mostrar();
std::cout<<"Con un total de: "<<maximo<<" cotizaciones."<<std::endl<<std::endl;


}


#endif // INFORMES_H_INCLUDED
