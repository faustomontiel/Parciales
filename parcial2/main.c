#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "funciones.h"

int main()
{
    ArrayList* listaEmpleados =  al_newArrayList();
    ArrayList*  CopiaLista;
    ArrayList* listaEmpleados120=al_newArrayList();

    int flagmap=0;
    int flagarchivo=0;
    FILE* femp;
    int seguir=1;
    int opcion;
    int fsort;

   while(seguir==1)
    {

        switch(menu())
        {
        case '1':
            system("cls");

            if (parser(femp, listaEmpleados)==0)
            {
                printf("\n Empleados leidos\n");
                CopiaLista=listaEmpleados->clone(listaEmpleados);
                flagarchivo=1;
            }
            else
            {
                printf("\nError en leer el archivo\n");
            }
            system("pause");
            break;

       case '2':

            system("cls");
            if(flagarchivo==1){
                if(CopiaLista!=NULL){
                mostrarEmpleado(CopiaLista);
                }
            }
            else{printf("\nNo hay datos para listar\n");}

            system("pause");
            break;

        case '3':
            system("cls");
            if(flagarchivo==1){
                if(CopiaLista!=NULL){
                fsort=al_sort(CopiaLista,compareeEmpleado,1);
            }
            if(fsort==0){
               mostrarEmpleado(CopiaLista);
                }
            }
            else{printf("\nNO HAY DATOS PARA GENERAR LISTADO\n");
            }
            system("pause");
            break;
        case '4':
            system("cls");

            if(flagarchivo==1)
            {
            CopiaLista->map(CopiaLista,calcularSueldo);
            mostrarSueldo(CopiaLista);
            flagmap=1;
            }
            else{printf("\nNO HAY DATOS PARA GENERAR SUELDOS\n");}
            system("pause");

            break;
        case '5':
            system("cls");
            if(flagarchivo==1){
                listaEmpleados120= al_filter(listaEmpleados,calcularHoras);
                printf("Lista filtrada");
            }
            system("pause");
            break;

        case '6':
            system("cls");
            if(flagarchivo==1)
            {
                guardarArchivo(listaEmpleados120);
                printf("\nARCHIVO GENERADO CON EXITO\n");
            }
    system("pause");
            break;

        case '7':
            seguir=0;
            break;

        default:
            break;
        }
    }
    return 0;
}
void guardarArchivo(ArrayList* empleadoFiltrados)
{
    FILE* miArchivo;
    miArchivo = fopen("filtrado.csv","w");
    char nombre[50];
    char direccion[50];

    fprintf(miArchivo,"NOMBRE,DIRECCION,ID,HORAS,SUELDO\n");
    for(int i=0;i<al_len(empleadoFiltrados);i++)
    {
        eEmpleado* tmp=al_get(empleadoFiltrados,i);


        getNombre(tmp,nombre);
        getDireccion(tmp,direccion);
        fprintf(miArchivo,"%s,%s,%d,%d,%d\n",nombre,direccion,getId(tmp),getHora(tmp),getSueldo(tmp));
    }

    fclose(miArchivo);
}
