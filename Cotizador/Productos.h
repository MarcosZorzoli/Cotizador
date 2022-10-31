#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <cstring>

class Productos{

    private:

    int id_producto;
    char nombre[30];

   public:

    int get_id(){return id_producto;};
    const char* get_nombre(){return nombre;}
//sets
    void set_id(int nuevo_id){id_producto=nuevo_id;};
    void set_nombre(const char *n){strcpy(nombre, n);};

};


#endif // PRODUCTOS_H_INCLUDED
