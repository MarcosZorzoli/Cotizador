#include "Precios.h"
#include "archivo_Precios.h"
#include "Productos.h"
#include "archivo_productos.h"
#include "archivo_Proveedores.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void Precios::setId(int ID)
{
id=ID;
}
void Precios::setId_Proveedor(int _id)
{
    id_proveedor=_id;
}
void Precios::setId_Producto(int _id)
{
    id_producto=_id;
}
void Precios::setPrecioU(float n_precio)
{
precioUnitario=n_precio;
}
void Precios::setUnidadMin(int UM)
{
unidadMinima=UM;
}
void Precios::setNombreMarca(std::string Nombre)
{
    strcpy(nombre_marca,Nombre.c_str());
}
void Precios::setEstado(bool nEstado)
{
estado=nEstado;
}
Precios::Precios()
{
    archivo_precios Archivo;
    id=Archivo.cantidad_de_registros()+1;
    estado=true;
    precioUnitario = 0;
    strcpy(nombre_marca, "");
    strcpy(nombre_produto, "");
    id_producto=0;
    id_proveedor=0;
}
int Precios::getId()
{
    return id;
}
int Precios::getId_Proveedor()
{
    return id_proveedor;
}
int Precios::getId_Producto()
{
    return id_producto;
}
float Precios::getPrecioU()
{
    return precioUnitario;
}
int Precios::getUnidadMin()
{
    return unidadMinima;
}
std::string Precios::getNombreMarca()
{
    return nombre_marca;
}
std::string Precios::getNombreProd()
{
    return nombre_produto;
}
bool Precios::getEstado()
{
 return estado;
}

 void Precios::Cargar()
    {
        Precios Precio;
        archivo_Proveedores archivo;
        Productos Producto;
        archivo_productos archivoPROD;
        int cant=archivoPROD.cantidad_de_registros();
        archivoPROD.listar(cant);
        Productos prod;
        int op;
        std::cout<<"Ingrese el ID del Producto al cual desea asignarle un precio: "<<std::endl;
        std::cin>>op;
         while(op<0||op>cant)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
        Producto=archivoPROD.leer_de_disco(op-1);
        if(Producto.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }else if (op==prod.getId_Producto())
        {
        Precio.setId_Producto(prod.getId_Producto());
       //Precio.setNombreProd(prod.getNombre());
        }
        char Nombre[50];
        std::cout<<"ingrese el nombre de la Marca ofertada"<<endl;
        std::cin.ignore();
        std::cin>>Nombre;
        Precio.setNombreMarca(Nombre);
archivo_precios arp;
arp.guardar(Precio,op-1);
        Proveedores Proveedor;
        archivo_Proveedores archivoPROV;
        int cantidad=archivoPROV.cantidad_de_registros();
        archivoPROV.listar(cantidad);
        int op2;
        std::cout<<"Ingrese el ID del Proveedor que cotizo el precio: "<<std::endl;
        std::cin>>op2;
        while(op2<0||op2>cantidad)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op2;
        }
        Proveedor=archivo.leer_de_disco(op-1);
        if(Proveedor.getEstado()==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op2;
        }else{
        setId_Proveedor(Proveedor.getId());
        }

        std::cout<<"Ingrese el valor de una unidad del producto > $ ";
       float precio;
       std::cin>>precio;
        while(precio<0)
        {
            std::cout<<"Ingrese una opcion correcta"<<std::endl;
            cin>>precio;
        }
        setPrecioU(precio);
                std::cout<<"Ingrese la cantidad de unidades del producto, equivalente al precio>";
       int Cantidadxunidad;
       std::cin>>Cantidadxunidad;
       archivo_precios arPre;
        while(precio<0)
        {
            std::cout<<"Ingrese una opcion correcta"<<std::endl;
            cin>>Cantidadxunidad;
        }
        setUnidadMin(Cantidadxunidad);
        setPrecioU(precio);
        arPre.guardar(Precio,op-1);
    }

    void Precios::Mostrar(Precios pre)
    {
        std::cout<<"-Nombre del Producto: "<<pre.getNombreProd()<<std::endl;
        std::cout<<"-Marca ofertada: "<<pre.getNombreMarca()<<std::endl;
        std::cout<<"-#ID: "<<pre.getId()<<std::endl;
        std::cout<<"-Cantidad x unidad: "<<pre.getUnidadMin()<<std::endl;
        std::cout<<"-Valor: $"<<pre.getPrecioU()<<std::endl;

    }


