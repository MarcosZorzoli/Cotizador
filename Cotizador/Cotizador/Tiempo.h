#ifndef TIEMPO_H_INCLUDED
#define TIEMPO_H_INCLUDED
#include <iostream>
#include <ctime>

struct Fecha
{
    int dia, mes, anio;

Fecha diadehoy(){
time_t t;
t=time(NULL);
struct tm *f;
f=localtime(&t);
Fecha aux;
aux.anio=f->tm_year+1900;
aux.mes=f->tm_mon+1;
aux.dia=f->tm_mday;
return aux;
}

void mostrarFecha(Fecha f)
{
std::cout<<f.dia<<"/"<<f.mes<<"/"<<f.anio<<std::endl;
}
};



#endif // TIEMPO_H_INCLUDED
