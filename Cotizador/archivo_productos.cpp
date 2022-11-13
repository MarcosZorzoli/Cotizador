#include "archivo_productos.h"
#include <iostream>



void archivo_productos::guardar(Producto producto)
{

  FILE* pFile;

  pFile = fopen("producto.dat", "ab");

  if (pFile == nullptr) {
    cout << "Error al abrir el archivo" << endl;
    exit(1552);
  }

  fwrite(&producto, sizeof(Producto), 1, pFile);

  fclose(pFile);

}

int archivo_productos::generarCodigo()
{
  return cantidadProductos() + 1;
}

int archivo_productos::cantidadProductos()
{
  FILE* pFile;
  int cantidad = 0;
  Producto producto;

  pFile = fopen("producto.dat", "rb");

  if (pFile == nullptr) {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Producto);

  fclose(pFile);

  return cantidad;
}

void archivo_productos::leerProductos(Producto productos[], int cantidad)
{
  FILE* pFile;
  pFile = fopen("producto.dat", "rb");
  if (pFile == nullptr) {
    return;
  }

  fread(productos, sizeof(Producto), cantidad, pFile);

  fclose(pFile);
}


Producto archivo_productos::leer_Producto(int pos)
{
    Producto p;
    FILE* pFile;
  pFile = fopen("producto.dat", "rb");
  if (pFile == nullptr) {
     cout<<"error al abrir el archivo"<<endl;
  }

  fseek(pFile,pos*sizeof (Producto),SEEK_SET);
  bool ok= fread(this, sizeof(Producto),1,pFile);
  if(ok==false)
  {
     cout<<"no se pudo leer el archivo"<<endl;
  }

  fclose(pFile);
  return p;
}
FILE* archivo_productos::abrirArchivo()
{
    FILE* pFile;
    pFile = fopen("producto.dat", "rb");

    if (pFile == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1550);
    }
    return pFile;
}
void archivo_productos::obtener_producto(Producto* prod, int cantidad)
{
    FILE* pFile = abrirArchivo();

    fread(prod, sizeof(Producto), cantidad, pFile);

    fclose(pFile);
}
int archivo_productos::buscarProducto(int ID){
    archivo_productos ap;
    Producto r;
    int i, cant = ap.cantidadProductos();
    for(i =0; i<cant; i++){
        ap.leer_Producto(i);
        if (ID == r.getCodigo()){
            return i;
        }
    }
    return -1;
}
bool archivo_productos::leerDeDisco(int nroRegistro){
    FILE *p;
    p = fopen("producto.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Producto), SEEK_SET);
    bool ok;
    ok = fread(this, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}
bool archivo_productos::guardarEnDisco(int pos){
    FILE *p;
    p = fopen("producto.dat", "rb+");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    ok = fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}
void archivo_productos::listar_productos()
{
     archivo_productos ap;
            int cant_prod= ap.cantidadProductos();
            Producto* prod= new Producto[cant_prod];

            ap.obtener_producto(prod,cant_prod);
            for(int i=0; i< cant_prod; i++)
            {
                cout<<"----------------------"<<endl;
                prod[i].mostrar();
            }
            delete[] prod;
}
void archivo_productos::agregar_producto()
{
    Producto product;
            archivo_productos ac;
            product.cargar();
            ac.guardar(product);
}
void archivo_productos::modificar_producto()
{
     archivo_productos ap;
            Producto prod;
            int cant_prod= ap.cantidadProductos();
            Producto* p= new Producto[cant_prod];

            ap.obtener_producto(p,cant_prod);
            int cod;
            cout<<"ingresar codigo a modificar"<<endl;
            cin>>cod;
            for(int i=0; i< cant_prod; i++)
            {
                if(cod==p[i].getCodigo())
                {
                    p[i].mostrar();
                    system("pause");
                    int nuevo_cod;
                    char nuevo_nombre[30];
                    cout<<"ingresar nuevo codigo"<<endl;
                    cin>>nuevo_cod;
                    cout<<"ingresar nuevo nombre"<<endl;
                    cin>>nuevo_nombre;
                    p[i].setCodigo(nuevo_cod);
                    p[i].setNombre(nuevo_nombre);
                    p[i].sobreescribir_producto(prod,i);

                }
                delete [] p;
            }

}



