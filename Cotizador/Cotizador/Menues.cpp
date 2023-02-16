#include "Menues.h"
#include "Categorias.h"
#include "archivo_Precios.h"
#include "archivo_categorias.h"
#include "archivo_productos.h"
#include "archivo_Proveedores.h"
#include "Proveedores.h"
#include "Productos.h"
#include "Cotizacion.h"
#include "archivo_Cotizacion.h"
#include <iostream>
#include <stdlib.h>
#include "Informes.h"

void Menu::menu_cotizar()
{
    bool menu_activo=true;

    while(menu_activo)
    {
        int op;

        system("cls");

        cout<<"-----Cotizar-----"<<endl<<endl;
        cout<<" 1-Cotizar"<<endl;
        cout<<" 2 Listar"<<endl;
        cout<<" 3 Eliminar"<<endl;
        cout<<"-----------------"<<endl;
        cout<<" 0- volver"<<endl;
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
            Cotizacion Cotiza;
            Cotiza.Cargar();
                //despues hago que esta opcion sea la letra "N", asi las categorias creadas se listan desde el 1
            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            archivo_cotizacion archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardadas Cotizaciones Activas"<<endl<<endl;
                system("pause");

            }else{
                archivo_cotizacion archivo;
                archivo.listar(archivo.cantidad_de_registros());
                system("pause");
        }}
        break;
        case 3:
        {
            system("cls");
            archivo_cotizacion archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardadas Cotizaciones Activas"<<endl<<endl;
                system("pause");

            }else{
            system("cls");
                archivo_cotizacion archivo;
                archivo.baja_Logica();
                system("pause");
        }
        break;
        }

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
            bool menu2activo=true;

            while(menu2activo)
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
                    menu2activo=false;
                }
                }

        }
                }break;

        case 2:
        {
            system("cls");
            cout<<" 2- Agregar producto"<<endl;
            Productos producto;
            bool leyo=producto.Cargar();
            if(leyo)
            {
            archivo_productos archivo;
            archivo.guardar(producto);
            producto.Mostrar();
            system("pause");
            cout<<endl;

            }


        }
        break;
        case 3:
        {
            system("cls");

            archivo_productos archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Productos Activos"<<endl<<endl;
                system("pause");

            }else{
            system("cls");
            cout<<" 3-Modificar producto"<<endl;
           archivo_productos archivo;
            archivo.modificar();
            system("pause");
            }

        }
        break;
        case 4:
        {
            system("cls");
                        archivo_productos archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Productos Activos"<<endl<<endl;
                system("pause");

            }else{
            cout<<" 4- Eliminar producto"<<endl;
             archivo_productos archivo;
            archivo.baja_Logica();
            system("pause");
        }}
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
            Archivo_Categoria archivo;
            int cant=archivo.cantidad_categorias();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardadas categorias Activas"<<endl<<endl;
            }
            else
            {
                archivo.listar_categorias();
                cout<<endl<<endl;
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
            Archivo_Categoria cat;
            cat.baja_Logica();
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
        cout<<" 5- Menu de precios"<<std::endl;

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
            cout<<"Modificar Proveedor"<<endl<<endl;
            archivo_Proveedores archivo;
            archivo.modificar();
            system("pause");
        }
        break;
        case 4:
        {
             system("cls");
            cout<<"Eliminar Proveedor"<<endl<<endl;

            archivo_Proveedores archivo;
            archivo.baja_Logica();
            system("pause");
        }
        break;
        case 5:
        {

                        system("cls");
menu_precios();
            system("pause");
        }
        break;

        }
    }
}


void Menu::menu_informes()
{
    int op;
    bool menu_activo=true;

    while(menu_activo)
    {
        system("cls");
        cout<<"----Informes----"<<endl<<endl;
        cout<<" 1- Producto mas cotizado"<<endl;
        cout<<" 2- Cotizacion de mayor importe"<<endl;
        cout<<" 3- Categoria mas cotizada"<<endl;
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
            cout<<"Producto mas cotizado"<<endl<<endl;

            ProdMasCot();
            cout<<endl;
            system("pause");
        }
        break;
                case 2:
        {
            system("cls");
            cout<<"Cotizacion de mayor importe"<<endl<<endl;
            CotMaxImp();
            cout<<endl;
            system("pause");
        }
        break;
                case 3:
        {
            system("cls");
            cout<<"Categoria mas cotizada"<<endl<<endl;

            CatMasCot();
            cout<<endl;
            system("pause");
        }
        break;

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
        cout<<"---Precios---"<<endl<<endl;
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
            Precio.Mostrar(Precio);
            archivo.guardar(Precio);
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            archivo_precios archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Precios Activos"<<endl<<endl;
                        system("pause");

            }
            else
            {
            cout<<"Modificar Precio"<<endl<<endl;
            archivo_precios archivo;
            archivo.modificar();
            system("pause");
            }
        }
        break;
        case 4:
            {

            system("cls");
             archivo_precios archivo;
            int cant=archivo.cantidad_de_registros();
            int cantActiva=archivo.get_cantidad_Activa(cant);
            if (cantActiva==0)
            {
                cout<<"No se encuentran guardados Precios Activos"<<endl<<endl;
            }
            else
            {
            cout<<"Eliminar Precio"<<endl<<endl;

            archivo_precios archivo;
            archivo.baja_Logica();
        }
        system("pause");
            }
        break;

        }
    }

}
