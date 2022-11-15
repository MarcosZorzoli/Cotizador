#ifndef CATEGORIAS_H_INCLUDED
#define CATEGORIAS_H_INCLUDED
#include <string>

using namespace std;

class categorias
{
protected:

    char _nombre[50];
    int id_categoria;

public:
//gets
    int get_id();
    string getNombre();

//sets
    void set_id(int nuevo_id);
    void setNombre(string nombre);

    void cargar();
    void mostrar();
    void cargar_categias_vector(categorias vec[], int cantidad);
    void sobreescribir_categoria(categorias c, int pos);
};

#endif // CATEGORIAS_H_INCLUDED
