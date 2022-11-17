//#include "archivo_precios"
#include "Precios.h"
#include <iostream>

void Precios::setId(int ID){
id=ID;
}
void Precios::setPrecioU(float n_precio){
precioUnitario=n_precio;
}
void Precios::setUnidadMin(int UM){
unidadMinima=UM;
}
void Precios::setNombreM(std::string Nombre){
strcpy(nombre_marca,Nombre.c_str());
}
void Precios::setEstado(bool nEstado){
estado=nEstado;
}

/*/
Precios::Precios()
{
    archivo_Precios Archivo;
    id=Archivo.cantidad_de_registros()+1;
    estado=true;
    precio = 0;
    strcpy(nombre_marca, "");
    id_categoria=0;
}

/*/
int Precios::getId()
{
    return id;
}

void Precios::setId(int _id)
{
    id = _id;
}

float Precios::getPrecioU()
{
    return precioUnitario;
}

void Precios::setPrecioU(float _precio)
{
    precioUnitario = _precio;
}


std::string Precios::getNombreM()
{
    return nombre_marca;
}

void Precios::setNombreM(std::string _nombre)
{
    strcpy(nombre_marca, _nombre.c_str());
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
    cout << "------------------" << endl;
    cout << "------------------" << endl << endl;
}


