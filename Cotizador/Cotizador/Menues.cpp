#include "Menues.h"
#include "Categorias.h"
#include "archivo_Precios.h"
#include "archivo_categorias.h"
#include "archivo_productos.h"
#include "archivo_Proveedores.h"
#include "Proveedores.h"
#include "Productos.h"
#include <iostream>
#include <stdlib.h>


void Menu::menu_cotizar()
{
    bool menu_activo=true;

    while(menu_activo)
    {
        int op;

        system("cls");

        cout<<"-----Cotizar----- paso 1"<<endl<<endl;
        cout<<"Elegi una Categoria o crea una"<<endl<<endl;
        cout<<" 1-Crear categoria"<<endl<<endl;
        cout<<" 2 Ferreteria"<<endl;
        cout<<" 3 Almacen"<<endl;
        cout<<" 4 Otra categoria en un vec dinamico"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- volver"<<endl;
        cout<<"-----------------"<<endl;

        cin>>op;

        while(op<0||op>4)
        {
            cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
            cin>>op;
        }
        switch(op)
        {
        case 0:
        {
            menu_activo=false;
        }
        break;

        case 1:
        {
            system("cls");
            cout<<" 1 -  categoria"<<endl;
            //despues hago que esta opcion sea la letra "N", asi las categorias creadas se listan desde el 1
            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            cout<<" 2- Ferreteria"<<endl;
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            cout<<" 3- Almacen"<<endl;
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            cout<<" 4 - Otro producto de un vec dinamico"<<endl;
            system("pause");
        }
        break;
        }

    }
}

void Menu::menu_productos()
{
    int op;
    bool menu_activo=true;
    while(menu_activo)
    {
        system("cls");
        cout<<"----Productos----"<<endl<<endl;
        cout<<" 1- Listar"<<endl;
        cout<<" 2- Agregar"<<endl;
        cout<<" 3- Modificar"<<endl;
        cout<<" 4- Eliminar"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- SALIR"<<endl;
        cout<<"-----------------"<<endl;

        cin>>op;

        while(op<0||op>4)
        {
            cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
            cin>>op;
        }
        switch(op)
        {
        case 0:
        {
            menu_activo=false;
        }
        break;
        case 1:
        {
            while(menu_activo)
            {   system("cls");
            cout<<"Listar Productos"<<endl<<endl;;


                cout<<"1- Todos"<<endl;
                cout<<"2- Listar por categorias"<<endl<<endl;
                cout<<"0- volver"<<endl;
                cin>>op;

                while(op<0||op>2)
                {
                    cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
                    cin>>op;
                }
                switch(op)
                {

                case 1:
                {
                    system("cls");
                    cout<<"Lista de todos los productos"<<endl;
            archivo_productos archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Productos Activos"<<endl<<endl;
            }
            else
            {
                archivo.listar(cant);
            }
            system("pause");


                }

                break;
                case 2:
                {
                    system("cls");
                    cout<<" Lista por categoria"<<endl;
                           archivo_productos archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Productos Activos"<<endl<<endl;
            }
            else
            {
               archivo.listaXcategoria();
            }
            system("pause");

}
                break;
                case 0:
                {
                    menu_activo=false;
                }
                }

        }
                break;

        case 2:
        {
            system("cls");
            cout<<" 2- Agregar producto"<<endl;
            Productos producto;
            producto.Cargar();
            archivo_productos archivo;
            archivo.guardar(producto);
            producto.Mostrar();
            system("pause");


        }
        break;
        case 3:
        {
            system("cls");
            cout<<" 3-Modificar producto"<<endl;
           archivo_productos archivo;
            archivo.modificar();
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            cout<<" 4- Eliminar producto"<<endl;
             archivo_productos archivo;
            archivo.baja_Logica();
            system("pause");
        }
        break;

        }
    }
}
}
void Menu::menu_categorias()
{
    int op;
    bool menu_activo=true;
    while(menu_activo)
    {
        system("cls");
        cout<<"---Categorias----"<<endl<<endl;
        cout<<" 1- Listar"<<endl;
        cout<<" 2- Agregar"<<endl;
        cout<<" 3- Modificar"<<endl;
        cout<<" 4- Eliminar"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- SALIR"<<endl;
        cout<<"-----------------"<<endl;

        cin>>op;

        while(op<0||op>4)
        {
            cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
            cin>>op;
        }
        switch(op)
        {
        case 0:
        {
            menu_activo=false;
        }
        break;
        case 1:
        {
            system("cls");
            cout<<" 1- Lista de categorias"<<endl;
            Archivo_Categoria archivo;
            int cant=archivo.cantidad_categorias();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Proveedores Activos"<<endl<<endl;
            }
            else
            {
                archivo.listar_categorias();
            }
            system("pause");

        }
        break;

        case 2:
        {
            cout<<" 2- Agregar categoria"<<endl;

            Archivo_Categoria ac;
            ac.agregar_categoria();
        }
        break;
        case 3:
        {
            system("cls");
            cout<<" 3-Modificar categoria"<<endl;
            Archivo_Categoria ac;
            ac.modificar_categorias();
        }
        break;
        case 4:
        {
            system("cls");
            cout<<" 4- Eliminar categoria"<<endl;
            system("pause");
        }
        break;

        }
    }
}

void Menu::menu_proveedores()
{
    int op;
    bool menu_activo=true;
    while(menu_activo)
    {
        system("cls");
        cout<<"---Proveedores---"<<endl<<endl;
        cout<<" 1- Listar"<<endl;
        cout<<" 2- Agregar"<<endl;
        cout<<" 3- Registrar un precio"<<std::endl;
        cout<<" 4- Modificar"<<endl;
        cout<<" 5- Eliminar"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- SALIR"<<endl;
        cout<<"-----------------"<<endl;

        cin>>op;

        while(op<0||op>5)
        {
            cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
            cin>>op;
        }
        switch(op)
        {
        case 0:
        {
            menu_activo=false;
        }
        break;
        case 1:
        {

            system("cls");
            cout<<"Listar Proveedores"<<endl<<endl;
            archivo_Proveedores archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Proveedores Activos"<<endl<<endl;
            }
            else
            {
                archivo.listar(cant);
            }
            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            cout<<"Cargar Proveedor"<<endl<<endl;
            Proveedores Proveedor;
            Proveedor.Cargar();
            archivo_Proveedores archivo;
            archivo.guardar(Proveedor);
            Proveedor.Mostrar();
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
menu_precios();
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            cout<<"Modificar Proveedor"<<endl<<endl;
            archivo_Proveedores archivo;
            archivo.modificar();
            system("pause");
        }
        break;
        case 5:
        {
            system("cls");
            cout<<"Eliminar Proveedor"<<endl<<endl;

            archivo_Proveedores archivo;
            archivo.baja_Logica();
            system("pause");
        }
        break;

        }
    }
}


void Menu::menu_porcentajes()
{



}

void Menu::menu_informes()
{
    int op;
    bool menu_activo=true;

    while(menu_activo)
    {
        system("cls");
        cout<<"----Informes----"<<endl<<endl;
        cout<<" 1- Porcentajes mas utilizados"<<endl;
        cout<<" 2- Mayor porcentaje de descuento"<<endl;
        cout<<" 3- Mayor porcentaje de aumento"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- SALIR"<<endl;
        cout<<"-----------------"<<endl;

        cin>>op;

        while(op<0||op>3)
        {
            cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
            cin>>op;
        }
        switch(op)
        {
        case 0:
        {
            menu_activo=false;
        }
        break;
        case 1:
        {
            system("cls");
            cout<<"primer informe"<<endl;
            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            cout<<"segundo informe"<<endl;
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            cout<<"tercer informe"<<endl;
            system("pause");
        }
        }
    }

}
void Menu::menu_precios()
{
    int op;
    bool menu_activo=true;
    while(menu_activo)
    {
        system("cls");
        cout<<"---Proveedores---"<<endl<<endl;
        cout<<" 1- Listar"<<endl;
        cout<<" 2- Agregar"<<endl;
        cout<<" 3- Modificar"<<endl;
        cout<<" 4- Eliminar"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- SALIR"<<endl;
        cout<<"-----------------"<<endl;

        cin>>op;

        while(op<0||op>4)
        {
            cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
            cin>>op;
        }
        switch(op)
        {
        case 0:
        {
            menu_activo=false;
        }
        break;
        case 1:
        {

            system("cls");
            cout<<"Listar Precios"<<endl<<endl;
            archivo_precios archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Precios Activos"<<endl<<endl;
            }
            else
            {
                archivo.listar(cant);
            }
            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            cout<<"Cargar Precio"<<endl<<endl;
            Precios Precio;
            Precio.Cargar();
            archivo_precios archivo;
            archivo.guardar(Precio);
            Precio.Mostrar();
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            cout<<"Modificar Proveedor"<<endl<<endl;
            archivo_precios archivo;
            archivo.modificar();
            system("pause");
            }
        break;
        case 4:
        {
            system("cls");
            cout<<"Eliminar Proveedor"<<endl<<endl;

            archivo_precios archivo;
            archivo.baja_Logica();
            system("pause");
        }
        break;

        }
    }

}
