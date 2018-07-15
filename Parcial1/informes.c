#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>

void total_PromedioImportes(eProducto prod[],int tam){

    int totalImportes = 0;
    int cantidadImportes = 0;
    float promedioImportes = 0;
    int cantidadImportesSuperiores = 0;
    int cantidadImportesInferiores = 0;

    for (int i = 0; i < tam; i++)
    {
        if (prod[i].estado == 1)
        {
            totalImportes += prod[i].importe;
            cantidadImportes++;
        }
    }

    promedioImportes = (float) totalImportes / cantidadImportes;
     for (int i = 0; i < tam; i++)
    {
        if (prod[i].estado == 1)
        {
            if(prod[i].importe > promedioImportes)
            {
                cantidadImportesSuperiores++;
            }
            else
            {
                cantidadImportesInferiores++;
            }
        }
    }
    printf("-TOTAL de los importes\n");
    printf("%d\n\n", totalImportes);
    printf("-PROMEDIO de los  importes\n");
    printf("%.02f\n\n", promedioImportes);

    printf("---------------------------------------------------\n");
    printf("-CANTIDAD de productos que superan el promedio\n");
    printf("%d\n\n", cantidadImportesSuperiores);
    printf("-CANTIDAD de productos que NO superan el promedio\n");
    printf("%d\n\n", cantidadImportesInferiores);
    printf("---------------------------------------------------\n");
}
void cantidadProductos(eProducto prod[],int tam){

    int contMayor = 0;
    int contMenor_igual = 0;

    for (int i = 0; i < tam; i++)
    {
        if (prod[i].estado == 1)
        {
            if(prod[i].cantidad >= 10)
            {
                contMayor++;
            }
            else
            {
                contMenor_igual++;
            }
        }
    }
    printf("CANTIDAD de productos cuyo STOCK es MENOR o igual a 10\n");
    printf("%d\n\n", contMenor_igual);

    printf("CANTIDAD de productos cuyo STOCK es MAYOR o igual a 10\n");
    printf("%d\n\n", contMayor);

}
void informar(eProducto prod[],int tam){

    system("cls");
    total_PromedioImportes(prod,tam);
    cantidadProductos(prod,tam);
}
