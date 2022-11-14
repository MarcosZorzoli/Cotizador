#include "Proveedores.h"
#include "archivo_Proveedores.h"
    Proveedores::Proveedores()
    {
        archivo_Proveedores Archivo;
        id=Archivo.cantidad_de_registros()+1;
        estado=true;
    }

    void Proveedores::setNombre(std::string Nombre)
    {
        strcpy(nombre,Nombre.c_str());
    }

    void Proveedores::setId(int ID)
    {
        id=ID;
    }

    void Proveedores::setEstado(bool nEstado)
    {
        estado=nEstado;
    }

    std::string Proveedores::getNombre()
    {
        return nombre;
    }

    int Proveedores::getId()
    {
        return id;
    }

    bool Proveedores::getEstado()
    {
        return estado;
    }

    void Proveedores::Cargar()
    {
        std::string Nombre;
        std::cout<<"Ingrese el nombre del Proveedor: "<<std::endl;
        std::cin.ignore();
        getline(std::cin,Nombre);
        setNombre(Nombre);
    }

    void Proveedores::Mostrar()
    {
        std::cout<<"-Nombre del Proveedor: "<<getNombre()<<std::endl;
        std::cout<<"#ID del Proveedor: "<<getId()<<std::endl;
    }


