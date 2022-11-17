#ifndef CATEGORIAS_H_INCLUDED
#define CATEGORIAS_H_INCLUDED
#include <string>

using namespace std;

class categorias
{
protected:

    char _nombre[50];
    int id_categoria;
    bool estado;

public:
//gets
    categorias();
    int get_id();
    string getNombre();
    bool getEstado();

//sets
    void set_id(int nuevo_id);
    void setNombre(string n_nombre);
    void setEstado(bool n_estado);

    void cargar();
    void mostrar();
    void cargar_categias_vector(categorias vec[], int cantidad);
    void sobreescribir_categoria(categorias c, int pos);
};

#endif // CATEGORIAS_H_INCLUDED
