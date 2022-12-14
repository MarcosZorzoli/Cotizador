#include "archivo_productos.h"
#include "Productos.h"
#include "archivo_categorias.h"

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

    bool Productos::Cargar()
    {   Archivo_Categoria arch;
        if(arch.cantidad_categorias()>0){
        CargarCategoria();
        std::string Nombre;
        std::cout<<"Ingrese el nombre del Producto: "<<std::endl;
        std::cin.ignore();
        getline(std::cin,Nombre);
        setNombre(Nombre);
        return true;
        }else{
        std::cout<<"Primero deben haber Categorias activas"<<std::endl;
            return false;}
    }

    void Productos::CargarCategoria()
    {
        int op;
        Archivo_Categoria ArchivoC;
        int cant=ArchivoC.cantidad_categorias();
        ArchivoC.listar_categorias();
    std::cout<<std::endl;
    std::cout<<"Ingrese de ID de la categoria a..."<<std::endl;
    std::cout<<" ...la que pertenece el producto"<<std::endl;
    std::cout<<std::endl;
    std::cin>>op;

        while(ArchivoC.Existe(op)==false)
        {
            std::cout<<"ingrese una opcion correcta"<<std::endl;
            std::cin>>op;
        }
       if(op!=0)
       {
        setId_Categoria(op);
       }

    }

    void Productos::Mostrar()
    {
        std::cout<<"-Nombre del Producto: "<<getNombre()<<std::endl;
        std::cout<<"#ID del Producto: "<<getId_Producto()<<std::endl;
        std::cout<<"#ID de la Categoria: "<<getId_Categoria()<<std::endl;
    }
