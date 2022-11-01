#ifndef CATEGORIAS_H_INCLUDED
#define CATEGORIAS_H_INCLUDED
#include <string>


class categorias
{
private:

    char _nombre[50];
    int id_categoria;

public:
//gets
    int get_id();

   std::string getNombre();

//sets
    void set_id(int nuevo_id);
    void setNombre(std::string nombre);



};

#endif // CATEGORIAS_H_INCLUDED
