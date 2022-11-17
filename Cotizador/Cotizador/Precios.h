#ifndef PRECIOS_H_INCLUDED
#define PRECIOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Precios:public Proveedores
{
private:
    int id;
    int id_categoria;
    int unidadMinima;
    float precioUnitario;
    char nombre_marca[50];
    bool estado;

public:

    Precios();

    void setId(int ID);
    void setPrecioU(float n_precio);
    void setUnidadMin(int UM);
    void setNombreM(std::string Nombre);
    void setEstado(bool nEstado);
    void setId_Categoria(int _id);

    int getId();
    float getPrecioU();
    int getUnidadMin();
    std::string getNombreM();
    bool getEstado();
    int getId_Categoria();

    void cargar();
    void mostrar();


};


#endif // PRECIOS_H_INCLUDED
