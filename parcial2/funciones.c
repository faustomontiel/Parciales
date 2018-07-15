#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#include "funciones.h"

char menu()
{
    char c;
    system("cls");
    printf("1- Cargar Empleados\n");
    printf("2- Listar Empleados\n");
    printf("3- Ordenar\n");
    printf("4- Calcular Sueldo\n");
    printf("5- Filtrar empleados\n");
    printf("6- Guardar  empleados\n");

    printf("7-Salir\n");

     printf("Ingrese la opcion a Realizar <1-7>: ");
     c=getche();

    return c;
}
int parser(FILE* pFile, ArrayList* pArrayListEmpleado)

{
    eEmpleado *auxEmpleado;

    char nombre[51];
    char direccion[51];
    char horas[50];
    char id[10];

    int i=0;
    int idi;
    int ihoras;

    pFile=fopen("data.csv","r");

    if(pFile== NULL)
    {
        return 1;
    }
    else
    {

       fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", nombre, direccion, id, horas);


        while(!(feof(pFile)))
        {

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", nombre, direccion, id, horas);

                idi = atoi(id);
                ihoras = atoi(horas);

                auxEmpleado= nuevoEmpleado();

                if(auxEmpleado!=NULL)
                {

                setId(auxEmpleado,idi);
                setDireccion(auxEmpleado,direccion);
                setNombre(auxEmpleado,nombre);
                setHora(auxEmpleado,ihoras);

                al_add(pArrayListEmpleado,auxEmpleado);

                i++;
                }
     }
    }
    fclose(pFile);

    return 0;
}


eEmpleado* nuevoEmpleado()
{
    eEmpleado* returnAux;

    returnAux = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(returnAux != NULL)
    {
        returnAux->id = 0;
        strcpy(returnAux->nombre, " ");
        strcpy(returnAux->direccion, " ");
        returnAux->hora = 0;
        returnAux->sueldo = 0;
    }
    else
    {
        printf("No hay espacio suficiente\n");
    }
    return returnAux;
}


void mostrarEmpleado(eEmpleado* empleado)
{

    printf("\nNombre\tDireccion\t\tID\n\n");
    eEmpleado* aux;

    for (int i=0; i<al_len(empleado); i++ )
                {
                    aux=(eEmpleado*)al_get(empleado,i);
                    printeEmpleado(aux);
                }
}

void printeEmpleado(eEmpleado* empleado)
{
    char nombre[51];
    char direccion[51];
    getNombre(empleado,nombre);
    getDireccion(empleado,direccion);
    printf("%s\t\t%s\t\t\%d\n",nombre,direccion,getId(empleado));
}
int compareeEmpleado(void* pEmployeeA,void* pEmployeeB)
{

    if(strcmp(((eEmpleado*)pEmployeeA)->nombre,((eEmpleado*)pEmployeeB)->nombre)> 0)
    {
        return 1;
    }
    if(strcmp(((eEmpleado*)pEmployeeA)->nombre,((eEmpleado*)pEmployeeB)->nombre)< 0)
    {
        return 0;
    }
    return 0;


}
int calcularSueldo(void* empleado)
{
    if(empleado!=NULL)
    {
        eEmpleado *aux=(eEmpleado*) empleado;

        int horas=getHora(aux);

        if(horas >79 && horas < 121)
        {
            setSueldo(aux,180*horas);
        }

            else if(horas >120 && horas < 161)
            {
                setSueldo(aux,240*horas);
            }
                else if(horas >160 && horas < 241)
                {
                    setSueldo(aux,350*horas);
                }
    }
}

void mostrarSueldo(eEmpleado* empleado)
{
    //printf("\nNOmbre\t\tDIRECCION\t\t\tID\t\tSUELDO\n\n");
    eEmpleado* aux;
    for (int i=0; i<al_len(empleado); i++ )
                {
                    aux=(eEmpleado*)al_get(empleado,i);
                    printeEmpleado_sueldo(aux);
                }
}

void printeEmpleado_sueldo(eEmpleado* p)
{
    char d[51];
    char n[51];
    getNombre(p,n);
    getDireccion(p,d);
    printf("%s\t\t%s\t\t\%d\t\t%d\n",n,d,getId(p),getSueldo(p));
}
/*
void guardarArchivo(ArrayList* empleados)
{
    FILE* miArchivo;
    miArchivo = fopen("sueldos.csv","w");
    char nombre[50];
    char direccion[50];

    fprintf(miArchivo,"NOMBRE,DIRECCION,ID,HORAS,SUELDO\n");
    for(int i=0;i<al_len(empleados);i++)
    {
        eEmpleado* tmp=al_get(empleados,i);


        getNombre(tmp,nombre);
        getDireccion(tmp,direccion);
        fprintf(miArchivo,"%s,%s,%d,%d,%d\n",nombre,direccion,getId(tmp),getHora(tmp),getSueldo(tmp));
    }

    fclose(miArchivo);
}*/
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

int calcularHoras(void* empleado)
{
    int retorno=NULL;

    if(empleado!=NULL)
    {
        eEmpleado *aux=(eEmpleado*) empleado;

        int horas=getHora(aux);

        if(horas >120)
        {
            retorno=1;
        }

    }
    return retorno;
}


