#include "archivo_productos.h"
#include "Productos.h"

Productos::Productos()
    {
        archivo_productos Archivo;
        id_producto=Archivo.cantidad_de_registros()+1;
        estado=true;
    }

    void Productos::setNombre(std::string Nombre)
    {
        strcpy(_nombre,Nombre.c_str());
    }

    void Productos::setId_Producto(int ID)
    {
        id_producto=ID;
    }
    void Productos::setId_Categoria(int ID)
    {
        id_categoria=ID;
    }

    void Productos::setEstado(bool nEstado)
    {
        estado=nEstado;
    }

    std::string Productos::getNombre()
    {
        return _nombre;
    }

    int Productos::getId_Categoria()
    {
        return id_categoria;
    }
     int Productos::getId_Producto()
    {
        return id_producto;
    }

    bool Productos::getEstado()
    {
        return estado;
    }

    void Productos::Cargar()
    {
        std::string Nombre;
        std::cout<<"Ingrese el nombre del Producto: "<<std::endl;
        std::cin.ignore();
        getline(std::cin,Nombre);
        setNombre(Nombre);
    }

    void Productos::Mostrar()
    {
        std::cout<<"-Nombre del Producto: "<<getNombre()<<std::endl;
        std::cout<<"#ID del Producto: "<<getId_Producto()<<std::endl;
        std::cout<<"#ID de la Categoria: "<<getId_Categoria()<<std::endl;
    }
