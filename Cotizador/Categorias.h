#ifndef CATEGORIAS_H_INCLUDED
#define CATEGORIAS_H_INCLUDED

#include <cstring>

class categorias
{
private:

    char nombre[30]={};
    int id_categoria;

public:
//gets
    int get_id(){return id_categoria;};
    const char* get_nombre(){return nombre;}
//sets
    void set_id(int nuevo_id){id_categoria=nuevo_id;};
    void set_nombre(const char *n){strcpy(nombre, n);}

};

#endif // CATEGORIAS_H_INCLUDED
