#include "Cotizacion.h"
#include "archivo_Cotizacion.h"
#include "Precios.h"
#include "archivo_Precios.h"
#include "Categorias.h"
#include "archivo_categorias.h"
#include "Productos.h"
#include "archivo_productos.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void Cotizacion::setId(int ID)
{
id=ID;
}
void Cotizacion::setId_Categoria(int _id)
{
    id_categoria=_id;
}
void Cotizacion::setId_Producto(int _id)
{
    id_producto=_id;
}
void Cotizacion::setId_Proveedor(int _id)
{
    id_proveedor=_id;
}
void Cotizacion::setId_Precio(int _id)
{
    id_precio=_id;
}
void Cotizacion::setPrecioU(float n_precio)
{
precioUnitario=n_precio;
}
void Cotizacion::setUnidadMin(int UM)
{
unidadMinima=UM;
}
void Cotizacion::setCantCompra(int CC)
{
cantidadCompra=CC;
}
void Cotizacion::setNombreMarca(std::string Nombre)
{
    strcpy(nombre_marca,Nombre.c_str());
}
void Cotizacion::setNombreProd(std::string Nombre)
{
    strcpy(nombre_producto,Nombre.c_str());
}
void Cotizacion::setNombreProv(std::string Nombre)
{
    strcpy(nombre_proveedor,Nombre.c_str());
}
void Cotizacion::setEstado(bool nEstado)
{
estado=nEstado;
}
Cotizacion::Cotizacion()
{
    archivo_cotizacion Archivo;
    id=Archivo.cantidad_de_registros()+1;
    estado=true;
    precioUnitario = 0;
    strcpy(nombre_marca, "");
    strcpy(nombre_producto, "");
    strcpy(nombre_proveedor, "");
    id_categoria=0;
    id_producto=0;
    id_proveedor=0;
    id_precio=0;
}
int Cotizacion::getId()
{
    return id;
}
int Cotizacion::getId_Categoria()
{
    return id_categoria;
}
int Cotizacion::getId_Producto()
{
    return id_producto;
}
int Cotizacion::getId_Proveedor()
{
    return id_proveedor;
}
int Cotizacion::getId_Precios()
{
    return id_precio;
}

float Cotizacion::getPrecioU()
{
    return precioUnitario;
}
int Cotizacion::getUnidadMin()
{
    return unidadMinima;
}
int Cotizacion::getCantCompra()
{
    return cantidadCompra;
}
std::string Cotizacion::getNombreMarca()
{
    return nombre_marca;
}
std::string Cotizacion::getNombreProd()
{
    return nombre_producto;
}
std::string Cotizacion::getNombreProv()
{
    return nombre_proveedor;
}
bool Cotizacion::getEstado()
{
 return estado;
}

 void Cotizacion::Cargar()
    {
        Cotizacion Cotiza;
        Archivo_Categoria archivoC;
        int op;
        archivoC.listar_categorias();
        std::cout<<std::endl;
        std::cout<<"Ingrese el Id de la categoria a cotizar"<<std::endl;
        cin>>op;

            while(op<0||op>archivoC.cantidad_categorias())
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        categorias cat;
            cat=archivoC.leer_de_disco(op-1);

            if(cat.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else if (op==cat.get_id())
        {
        system("cls");
        Cotiza.setId_Categoria(cat.get_id());
        }
        Productos prod;
        archivo_productos archivoProd;
        int canti=archivoProd.cantidad_de_registros();
        for(int y=0;y<canti;y++)
        {
            prod=archivoProd.leer_de_disco(y);
            if(prod.getEstado()&&prod.getId_Categoria()==Cotiza.getId_Categoria())
            {
                prod.Mostrar();
            }
        }
        int op2;
        std::cout<<std::endl;
        std::cout<<"Ingrese el Id del producto a cotizar"<<std::endl;
        cin>>op2;
        prod=archivoProd.leer_de_disco(op2-1);
        while(prod.getId_Categoria()!=Cotiza.getId_Categoria())
        {
            std::cout<<"Ingresa una opcion correcta"<<std::endl;
            cin>>op2;
            prod=archivoProd.leer_de_disco(op2-1);
        }
        system("cls");

        Cotiza.setId_Producto(prod.getId_Producto());
        Cotiza.setNombreProd(prod.getNombre());

        archivo_precios archivoPrec;
        Precios Prec;
int can=archivoPrec.cantidad_de_registros();
        for(int a=0;a<can;a++)
        {
            Prec=archivoPrec.leer_de_disco(a);
            if(Prec.getEstado()&&Prec.getId_Producto()==Cotiza.getId_Producto())
            {
                Prec.Mostrar(Prec);
                std::cout<<std::endl;
            }
        }
        int op3;
        std::cout<<std::endl;
        std::cout<<"Ingresa el ID de Precio para cotizar ese producto"<<std::endl;
        cin>>op3;

        Prec=archivoPrec.leer_de_disco(op3-1);
        while(Prec.getId_Producto()!=Cotiza.getId_Producto())
        {
            std::cout<<"Ingresa una opcion correcta"<<std::endl;
            cin>>op3;
            Prec=archivoPrec.leer_de_disco(op3-1);
        }
        system("cls");

        Cotiza.setId_Precio(Prec.getId());
        Cotiza.setId_Proveedor(Prec.getId_Proveedor());
        Cotiza.setNombreMarca(Prec.getNombreMarca());
        Cotiza.setNombreProv(Prec.getNombreProv());
        Cotiza.setUnidadMin(Prec.getUnidadMin());
        Cotiza.setPrecioU(Prec.getPrecioU());
        int cantidad;
        std::cout<<"Ingrese la cantidad que desea Cotizar de ese Producto con el Precio elegido"<<std::endl;
        cin>>cantidad;
        while(cantidad<=0)
        {
        std::cout<<"Cantidad incorrecta, ingrese nuevamente el dato"<<std::endl;
        cin>>cantidad;
        }
        Cotiza.setCantCompra(cantidad);
        std::cout<<"Total compra= $"<<Cotiza.getCantCompra()*Cotiza.getPrecioU()<<std::endl;
        archivo_cotizacion archivoCOT;
        archivoCOT.guardar(Cotiza);
        system("cls");
        Cotiza.Mostrar(Cotiza);
        }

    void Cotizacion::Mostrar(Cotizacion Cot)
    {
        std::cout<<std::endl;
        std::cout<<"-Nombre del Producto: "<<Cot.getNombreProd()<<std::endl;
        std::cout<<"-Marca ofertada: "<<Cot.getNombreMarca()<<std::endl;
        std::cout<<"-Nombre proveedor: "<<Cot.getNombreProv()<<std::endl;
        std::cout<<"-#ID: "<<Cot.getId()<<std::endl;
        std::cout<<"-Cantidad x unidad: "<<Cot.getUnidadMin()<<std::endl;
        std::cout<<"-Precio Unitario: $"<<Cot.getPrecioU()<<std::endl;
        std::cout<<"-Cantidad comprada: "<<Cot.getCantCompra()<<std::endl;
        std::cout<<"-Total Compra: $"<<Cot.getCantCompra()*Cot.getPrecioU()<<std::endl;

    }


