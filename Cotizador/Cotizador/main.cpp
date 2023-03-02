#include <iostream>
#include <stdlib.h>
#include "Menues.h"
#include "Precios.h"
#include "Categorias.h"
#include "Productos.h"
#include "Cotizacion.h"
#include "archivo_Cotizacion.h"
#include "archivo_Precios.h"
#include "archivo_productos.h"
#include "archivo_Proveedores.h"
#include "archivo_categorias.h"


using namespace std;
int main()
{
    int op;
    while(true)
    {
        system("cls");
        cout<<"----Cotizador----"<<endl<<endl;
        cout<<" 1- Cotizaciones"<<endl;
        cout<<" 2- Categorias"<<endl;
        cout<<" 3- Productos"<<endl;
        cout<<" 4- Proveedores"<<endl;
        cout<<" 5- Informes"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- SALIR"<<endl;
        cout<<"-----------------"<<endl;

        cin>>op;

        while(op<0||op>6)
        {
            cout<<"opcion incorrecta, vuelva a ingresar una opcion"<<endl;
            cin>>op;
        }
        switch(op)
        {
        case 0:
        {
        char op2;
        std::cout<<"Esta seguro de que desea salir del programa?"<<std::endl;
        std::cout<<"[S/N]"<<std::endl;
        std::cin>>op2;
        if(op2=='s'||op2=='S')
        {
            return false;

        }
        }
        break;
        case 1:
        {
            system("cls");
            Archivo_Categoria aC;
            archivo_productos aProd;
            archivo_Proveedores aProv;
            archivo_precios aPrec;
            bool puede=true;
            if(aC.cantidad_categorias()==0)
            {
            std::cout<<"Primero necesita crear una Categoria"<<std::endl;
                     puede=false;
            }
            if(aProd.cantidad_de_registros()==0)
            {
            std::cout<<"Primero necesita crear un Producto"<<std::endl;
            puede=false;
            }
            if(aProv.cantidad_de_registros()==0)
            {
            std::cout<<"Primero necesita cargar un Proveedor"<<std::endl;
                     puede=false;
            }
            if(aPrec.cantidad_de_registros()==0)
            {
            std::cout<<"Primero necesita cargar un Precio dentro del menu Proveedores"<<std::endl;
                     puede=false;
            }
            if(puede)
            {
            Menu menu;
            menu.menu_cotizar();
            }

            system("pause");
        }
        break;
        case 2:
        {
            system("cls");

            Menu menu;
            menu.menu_categorias();
            system("pause");

        }
        break;
        case 3:
        {
            system("cls");

            Menu menu;
             menu.menu_productos();
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            Menu menu;
            menu.menu_proveedores();
            system("pause");
        }
        break;
        case 5:
        {
            system("cls");
            archivo_cotizacion aC;
            bool puede=true;
            if(aC.cantidad_de_registros()==0)
            {
            std::cout<<"Primero necesita Cotizar"<<std::endl;
                     puede=false;
            }
            if(puede)
            {
            Menu menu;
            menu.menu_informes();
            }
            system("pause");

        }
        break;

}
    }
}


