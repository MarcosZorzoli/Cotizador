#include "Menues.h"
#include "Productos.h"
#include "Categorias.h"
#include "archivo_categorias.h"
#include "archivo_productos.h"
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
            cout<<" 1 - Nueva categoria"<<endl;
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
            {
                system("cls");
                cout<<"1- Listar todos"<<endl;
                cout<<"2- Listar por categorias"<<endl;
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
            cout<<" 1- Lista de todos los productos"<<endl;
           archivo_productos ap;
           ap.listar_productos();

            system("pause");
                }


                break;
                case 2:
                {
                          system("pause");
                }
                break;
                case 0:
                {
                    menu_activo=false;
                }
                break;
                }
            }
        }

        case 2:
        {
            system("cls");
            cout<<" 2- Agregar producto"<<endl;
            archivo_productos ap;
            ap.agregar_producto();
            menu_activo=false;


            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            cout<<" 3-Modificar producto"<<endl;
           archivo_productos ap;
           ap.modificar_producto();
        }
        break;
        case 4:
        {
            system("cls");
            cout<<" 4- Eliminar producto"<<endl;
            system("pause");
        }
        break;

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
          Archivo_Categoria ac;
          ac.listar_categorias();


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

            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            cout<<" 2- Agregar proveedor"<<endl;
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            cout<<" 3-Modificar proveedor"<<endl;
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            cout<<" 4- Eliminar proveedor"<<endl;
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
