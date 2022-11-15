#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

#include <string>
#include <iostream>
#include <cstring>
class Proveedores{

private:

    char nombre[50];
    int id;
    bool estado;

public:

    Proveedores();
    void setNombre(std::string Nombre);
    void setId(int ID);
    void setEstado(bool nEstado);

    std::string getNombre();
    int getId();
    bool getEstado();

    void Cargar();
    void Mostrar();

};

#endif // PROVEEDORES_H_INCLUDED
