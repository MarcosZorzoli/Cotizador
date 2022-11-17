#ifndef PRECIOS_H_INCLUDED
#define PRECIOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Precios
{
private:
    int id;
    float precioUnitario;
    int unidadMinima;
    char nombre_marca[50];
    int id_categoria;
    int id_proveedor;
    bool estado;
public:

    Precios();

    void setId(int ID);
    void setPrecioU(float n_precio);
    void setUnidadMin(int UM);
    void setNombreM(std::string Nombre);
    void setEstado(bool nEstado);
    void setId_Categoria(int _id);
    void setId_Proveedor(int id);

    int getId();
    float getPrecioU();
    int getUnidadMin();
    std::string getNombreM();
    bool getEstado();
    int getId_Proveedor();
    int getId_Categoria();

    void cargar();
    void mostrar();


};


#endif // PRECIOS_H_INCLUDED
