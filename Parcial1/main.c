#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMPROV 4
#define TAMPROD 40
int main()
{




    eProducto productos[TAMPROD]= {{1000, "gomita", 150,1,5,1},{1001, "alfajor", 250,2,10,1},{1002, "chicle", 100,3,6,1},{1003, "gaseosa", 300,1,5,1}};
    eProvedor provedores[]={{1, "Juan"}, {2,"Ana"}, {3, "Pablo"}, {4, "Jose"}};
    inicializarProductos(productos,TAMPROD);
     //harcodeo

    for(int i=0; i< TAMPROV; i++)
    {
        productos[i].estado = 1;
    }

    int salir = 0;
    do
    {
        switch(menu())
        {

        case 1:
            altaProducto(productos,TAMPROD,provedores,TAMPROV);
            system("pause");
            break;
        case 2:
           modificarProducto(productos,TAMPROD,provedores,TAMPROV);
            system("pause");
            break;
        case 3:
            eliminarProducto(productos,TAMPROD,provedores,TAMPROV);
            system("pause");
            break;
        case 4:
            informar(productos,TAMPROD);
            system("pause");
            break;
        case 5:
            listar(productos,TAMPROD,provedores,TAMPROV);
            system("pause");
            break;
        case 6:
            printf("\nSalir\n\n");
            salir = 1;
            break;
        default:
            printf("\nOpcion Incorrecta\n\n");
            break;
            system("pause");
        }
    }
    while(salir != 1);

    return 0;
}


