#include <iostream>
#include <stdlib.h>


using namespace std;
#include "Productos.h"
#include "Categorias.h"


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
            return false;
        }
        break;
        case 1:
        {
            system("cls");
            cout<<" 1- Cotizar"<<endl;
            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            cout<<" 2- Productos"<<endl;
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            cout<<" 3- Categorias"<<endl;
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            cout<<" 4- Proveedores"<<endl;
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
            cout<<" 6- Informes"<<endl;
            system("pause");
        }
        break;
        }
    }
}

