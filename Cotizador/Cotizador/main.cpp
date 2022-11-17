#include <iostream>
#include <stdlib.h>
#include "Menues.h"
#include "Precios.h"
#include "Categorias.h"
#include "archivo_productos.h"
#include "archivo_productos.h"
#include "Productos.h"

using namespace std;
int main()
{
    int op;
    while(true)
    {
        system("cls");
        cout<<"----Cotizador----"<<endl<<endl;
        cout<<" 1- Cotizar"<<endl;
        cout<<" 2- Productos"<<endl;
        cout<<" 3- Categorias"<<endl;
        cout<<" 4- Proveedores"<<endl;
        cout<<" 5- Porcentajes"<<endl;
        cout<<" 6- Informes"<<endl;
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
            Menu menu;
            menu.menu_cotizar();
            system("pause");
        }
        break;
        case 2:
        {
            Menu menu;
             menu.menu_productos();
            system("cls");


            system("pause");
        }
        break;
        case 3:
        {
            system("cls");

            Menu menu;
            menu.menu_categorias();
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
            cout<<" 5- Porcentajes"<<endl;
            system("pause");
        }
        break;
        case 6:
        {
            system("cls");
            Menu menu;
            menu.menu_informes();
            system("pause");
        }
        break;
}
    }
}


