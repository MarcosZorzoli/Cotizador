#include "Categorias.h"
#include "cstring"
#include <string>

//gets
std::string categorias::getNombre()
{
    return _nombre;
}

int categorias::get_id()
{
    return id_categoria;
};

//sets
void categorias::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

    void categorias::set_id(int nuevo_id)
    {
        id_categoria=nuevo_id;
    }
