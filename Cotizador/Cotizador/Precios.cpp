//#include "archivo_precios"
#include "Precios.h"
#include <iostream>




void setId(int ID);
    void setPrecioU(float n_precio);
    void setUnidadMin(int UM);
    void setNombreM(std::string Nombre);
    void setEstado(bool nEstado);
    void setId_Categoria(int _id);
    void setId_Proveedor(int id);

    int setId();
    float getPrecioU();
    int getUnidadMin();
    std::string getNombreM();
    bool getEstado();
    int getId_Proveedor();
    int getId_Categoria();

    void cargar();
    void mostrar();

/*/
Precios::Precios()
{
    archivo_Precios Archivo;
    id=Archivo.cantidad_de_registros()+1;
    estado=true;
    precio = 0;
    strcpy(nombre_marca, "");
    id_proveedor=0;
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
    std::cout << "Ingrese nombre: ";
    std::cin >> nombre_marca;
    std::cout << "Ingrese precio: ";
    std::cin >> precioUnitario;
    //pre.guardar(productos);

}
void Precios::mostrar()
{
    cout << "------------------" << endl;
    cout << "------------------" << endl << endl;
}



