#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <ctype.h>

int menu()
{
    char  stOpcion[5];
    int opcion;
    int esNumero;
    system("cls");
    printf("---ABM Productos---\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Listar\n");

    printf("6-Salir\n");

     printf("Ingrese la opcion a Realizar: ");
            fflush(stdin);
            gets(stOpcion);
            esNumero = validarNumero(stOpcion);

        while (esNumero == 1)
        {
            printf("\nOpcion incorrecta, reingrese de nuevo la  opcion: ");
            fflush(stdin);
            gets(stOpcion);
            esNumero = validarNumero(stOpcion);
        }
        opcion= atoi(stOpcion);

    while(opcion<1 || opcion>6){
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
            break;
        }


    return opcion;
}
int menuLista(){

    char  stOpcion[5];
    int opcion;
    int esNumero;
    system("cls");
    printf("Elija la opcion a listar: \n\n");
    printf("1- Ordenar\n");
    printf("2- Productos MENORES O IGUALES a 10\n");
    printf("3- Productos MAYORES a 10\n");
    printf("4- Productos que superan el promedio de importes\n");
    printf("5- Productos que  NO superan el promedio de importes\n");
    printf("6- Proveedores cuya cantidad de productos es MENOR O IGUAL a 10\n");
    printf("7- Productos provistos por cada Proveedor\n");
    printf("8- Productos provistos por un Proveedor Determinado\n");
    printf("9- Proveedor que mas provee mas productos\n");
    printf("10- Proveedor que mas caro provee\n");
    printf("11- Proveedor que mas barato provee\n");
    printf("12- Listar Parcial\n");

    printf("13-Salir\n");

     printf("Ingrese la opcion a Realizar: ");
            fflush(stdin);
            gets(stOpcion);
            esNumero = validarNumero(stOpcion);

        while (esNumero == 1)
        {
            printf("\nOpcion incorrecta, reingrese de nuevo la  opcion: ");
            fflush(stdin);
            gets(stOpcion);
            esNumero = validarNumero(stOpcion);
        }
        opcion= atoi(stOpcion);

    while(opcion<1 || opcion>13){
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
            break;
        }


    return opcion;

}
int validarString (char cadena[])
{
    int esNumero = 0;

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (isalpha(cadena[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}

int validarNumero (char numero[])
{
    int esNumero = 0;
    int len;

    len = strlen(numero);

    for (int i = 0; i < len; i++)
    {
        if (isdigit(numero[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}
