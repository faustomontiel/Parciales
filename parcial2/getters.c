#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#include "funciones.h"

int setId(eEmpleado* p,int id)
{
    if (p!=NULL)
    {
        p->id = id;
        return 1;
    }
    return 0;
}
int setDireccion(eEmpleado* p,char* d)
{
if (p!=NULL)
    {
        strcpy(p->direccion,d);
        return 1;
    }
    return 0;
}
int setNombre(eEmpleado* p,char* n)
{
if (p!=NULL)
    {
        strcpy(p->nombre,n);
        return 1;
    }
    return 0;
}
 void getNombre(eEmpleado* p,char* nombre)
{

    strcpy(nombre,p->nombre);

}
int getId(eEmpleado* p)
{
    return p->id;
}


void getDireccion(eEmpleado* p,char* direccion)
{
    strcpy(direccion,p->direccion);
}

int setHora(eEmpleado* p,int h)
{
    if (p!=NULL)
    {
        p->hora = h;
        return 1;
    }
    return 0;
}
int setSueldo(eEmpleado* p,int s)
{
    if (p!=NULL)
    {
        p->sueldo = s;
        return 1;
    }
    return 0;
}

int getHora(eEmpleado* p)
{
    return p->hora;
}

int getSueldo(eEmpleado* p)
{
    return p->sueldo;
}
int empleado_getHorasTrabajadas(eEmpleado* this, int* horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && horasTrabajadas != NULL)
    {
            retorno = 0;
            *horasTrabajadas = this->hora;
    }
    return retorno;
}
