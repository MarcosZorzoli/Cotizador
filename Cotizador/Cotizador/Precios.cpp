#include "Precios.h"
#include "archivo_Precios.h"
#include <iostream>

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

void Precios::cargar()
{
    //archivo_precios pre;
    std::cout << "------------------" << std::endl;
    std::cout << "Ingrese la marca ofertada: ";
    std::cin >> nombre_marca;
    std::cout << "Ingrese el precio unitario: ";
    std::cin >> precioUnitario;
    //pre.guardar(productos);

}
void Precios::mostrar()
{
    std::cout<< "------------------"<<std::endl;
    std::cout<<"Producto: "<<getNombreProd()<<std::endl;
    std::cout<<"Marca: "<<getNombreMarca()<<std::endl;
    std::cout<<"ID propio: "<<getId()<<std::endl;
    std::cout<<"Cantidad por unidad: "<<getUnidadMin()<<std::endl;
    std::cout<<"Valor de esa unidad: "<<getPrecioU()<<std::endl;
    std::cout<< "------------------"<<std::endl<<std::endl;
}


