#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>


void inicializarProductos(eProducto vec[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        vec[i].estado=0;
    }
}//inicializo el estado del producto
void mostrarProductos(eProducto vec[], int tamProd, eProvedor provedores[],int tamProv)
{

    system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos ORDENADOS\n");
    printf("---------------------------------------------------\n\n");
    printf("  Codigo  Nombre    Importe  cantidad  Provedor \n\n");
    for(int i=0; i< tamProd; i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarProducto(vec[i], provedores, tamProv);
        }
    }
}/*se ingresa el array de la gente y el tamanio y el array sector y el tamanio,si esta lleno lo muestra*/

void mostrarProducto(eProducto prod, eProvedor provedores[], int tam){

    int indice;
    for(int i=0; i< tam; i++)
    {
        if(prod.idProvedor == provedores[i].codProvedor )
        {
            indice = i;
            break;
        }
    }
    printf("  %4d%11s%10.2f  %4d   %10s\n", prod.codProducto, prod.nombreProducto, prod.importe,prod.cantidad ,provedores[indice].nombreProvedor);
}

int buscarLibre(eProducto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarProducto(eProducto vec[], int tam, int codigo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].estado== 1 && vec[i].codProducto == codigo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void altaProducto(eProducto prod[], int tamProd, eProvedor provedores[], int tamProv){

    int i;
    eProducto nuevoProducto;
    int codProd;
    char importe[6];
    char cantidad[5];
    int esNumero;

    for(i=0;i<tamProd;i++)
    {
        if(prod[i].estado==0)
        {
            system("cls");

            codProd=(1000+i);

            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            gets(nuevoProducto.nombreProducto);
            esNumero = validarString(nuevoProducto.nombreProducto);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(nuevoProducto.nombreProducto);
            esNumero = validarString(nuevoProducto.nombreProducto);

        }
            printf("Ingrese la cantidad del producto: ");
            fflush(stdin);
            gets(cantidad);
            esNumero = validarNumero(cantidad);

        while (esNumero == 1)
        {
            printf("Error. cantidad incorrecta, reingrese la canidad: ");
            fflush(stdin);
            gets(cantidad);
            esNumero = validarNumero(cantidad);
        }

        nuevoProducto.cantidad = atoi(cantidad);

            printf("Ingrese el importe del producto: ");
            fflush(stdin);
            gets(importe);
            esNumero = validarNumero(importe);

        while (esNumero == 1)
        {
            printf("Error. importe incorrecta, reingrese el Importe: ");
            fflush(stdin);
            gets(importe);
            esNumero = validarNumero(importe);
        }

        nuevoProducto.importe= atoi(importe);

            nuevoProducto.idProvedor = pedirProvedor(provedores, tamProv);
            prod[i] = nuevoProducto;



            prod[i].estado=1;
            prod[i].codProducto=codProd;
            printf("\nEl codigo del producto  es %d\n",codProd);
            break;
        }
    }
        if(i==tamProd)
        {
            printf("No hay mas espacio.\n");
        }
}


int pedirProvedor(eProvedor provedores[], int tam)
{

    int idProv;

    printf("Provedores: \n\n");

    for(int i=0; i< tam; i++)
    {
        printf("%d- %s\n", provedores[i].codProvedor, provedores[i].nombreProvedor);

    }
    printf("\nIndique proveedor: ");
    fflush(stdin);
    scanf("%d", &idProv);





    return idProv;
}
void modificarProducto(eProducto prod[],int tamprod,eProvedor provedor[],int tamprov){

    char sCodProd[10];
    int codProd;
    int i;
    char rta;
    int opcion;
    char importe[10];
    char cantidad[5];
    int esNumero;
    system("cls");
    mostrarProductos(prod,tamprod,provedor,tamprov);

    printf("Ingrese el codigo del producto: \n");
    fflush(stdin);
    gets(sCodProd);
    esNumero = validarNumero(sCodProd);

    while (esNumero == 1)
    {
        printf("Error. CODIGO incorrecto, reingrese el codigo: ");
        gets(sCodProd);
        esNumero = validarNumero(sCodProd);
    }

    codProd = atoi(sCodProd);



    for(i=0;i<tamprod;i++)
    {
        if(prod[i].estado==1 && prod[i].codProducto==codProd)
        {
            mostrarProducto(prod[i],provedor,tamprod);
            printf("Eliga la opcion que quiere modificar: \n");

            printf("1- Nombre\n");
            printf("2- Importe\n");
            printf("3- Cantidad\n");

            scanf("%d",&opcion);

        while(opcion<1 || opcion>3){
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                printf("\nIngrese nuevo Nombre: ");
                fflush(stdin);
                gets(prod[i].nombreProducto);
                esNumero = validarString(prod[i].nombreProducto);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(prod[i].nombreProducto);
            esNumero = validarString(prod[i].nombreProducto);

        }
        printf("El cambio se ha realizado!\n");
                break;
            case 2:
            printf("Ingrese el Nuevo importe del producto: ");
            fflush(stdin);
            gets(importe);
            esNumero = validarNumero(importe);

        while (esNumero == 1)
        {
            printf("Error. importe incorrecta, reingrese el uuevo Importe: ");
            fflush(stdin);
            gets(importe);
            esNumero = validarNumero(importe);
        }

        prod[i].importe= atoi(importe);
        printf("El cambio se ha realizado!\n");
                break;
            case 3:
            printf("Ingrese la Nueva cantidad del producto: ");
            fflush(stdin);
            gets(cantidad);
            esNumero = validarNumero(cantidad);

        while (esNumero == 1)
        {
            printf("Error. Cantidad incorrecta, reingrese la Nueva canidad: ");
            fflush(stdin);
            gets(cantidad);
            esNumero = validarNumero(cantidad);
        }

        prod[i].cantidad = atoi(cantidad);
        printf("El cambio se ha realizado!\n");
                break;
            default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
        }


        }
    }


    if(prod[i].estado==0 && prod[i].codProducto!=codProd)
    {
        printf("\nEste abonado no existe\n");
    }
}
void eliminarProducto(eProducto prod[],int tam,eProvedor provedor[],int tamprov)
{
    int i;
    char rta;
    char stCodProd[10];
    int codProd;
    int esNumero;

    system("cls");
    mostrarProductos(prod,tam,provedor,tamprov);
    printf("Ingrese el codigo del producto: \n");
    fflush(stdin);
    gets(stCodProd);
    esNumero = validarNumero(stCodProd);

    while (esNumero == 1)
    {
        printf("Error. CODIGO incorrecto, reingrese el codigo: ");
        gets(stCodProd);
        esNumero = validarNumero(stCodProd);
    }

    codProd = atoi(stCodProd);

    for(i=0;i<tam;i++)
    {
        if(prod[i].estado==1 && prod[i].codProducto==codProd)
        {
            mostrarProducto(prod[i],provedor,tam);
            printf("Desea eliminar este producto?");
            rta=tolower(getche());
            if(rta=='s')
            {
                prod[i].estado=0;
                printf("\nEl producto se ha eliminado!\n\n");

                break;
            }
            else if(rta!='s')
            {
                printf("\nNo se han realizado modificaciones\n\n");
                break;
            }
        }
    }
    if(prod[i].estado==0 && prod[i].codProducto!=codProd)
    {
        printf("\nEste cliente no existe\n");
    }
}
void listar(eProducto prod[],int tam,eProvedor prov[],int tamp)
{
    int total= 0;
    int cont = 0;
    int totalP;
    float promedio;
    char stOpcion[5];
    int opcion;
    int esNumero;
    int salir=0;
    int indiceDelCont;
    int provMax;
    int flag=0;
    int provEl;
    int contImp;
    int masBarato;
    int codigo;
    char productoMasBarato[50];
    int masCaro;
    int codigoC;
    char productoMasCaro[50];


    for (int i = 0; i < tam; i++){
        if (prod[i].estado == 1){
            total += prod[i].importe;
            cont++;
        }
    }
    promedio = (float) total / cont;

do{
    switch(menuLista()){

    case 1:
    system("cls");
    ordenarProductos(prod,tam,prov,tamp);
    system("pause");
    break;
    case 2:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos MENORES O IGUALES a 10\n");
    printf("---------------------------------------------------\n\n");

    for (int i = 0; i < tam; i++)
    {
        if (prod[i].estado == 1 && prod[i].cantidad <= 10)
        {
            mostrarProducto(prod[i],prov,tam);
        }
    }
    system("pause");
    break;
    case 3:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos MAYORES a 10\n");
    printf("---------------------------------------------------\n\n");

    for (int i = 0; i < tam; i++)
    {
        if (prod[i].estado == 1 && prod[i].cantidad > 10)
        {
           mostrarProducto(prod[i],prov,tam);
        }
    }
    system("pause");
    break;
    case 4:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos que superan el promedio de importes\n");
    printf("---------------------------------------------------\n\n");

    for (int i = 0; i < tam; i++)
    {
        if (prod[i].estado == 1 && prod[i].importe > promedio)
        {
            mostrarProducto(prod[i],prov,tam);
        }
    }
    system("pause");
    break;
    case 5:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos que  NO superan el promedio de importes\n");
    printf("---------------------------------------------------\n\n");

    for (int i = 0; i < tam; i++)
    {
        if (prod[i].estado == 1 && prod[i].importe < promedio)
        {
            mostrarProducto(prod[i],prov,tam);
        }
    }
    system("pause");
    break;
    case 6:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Provedores cuya cantidad de productos es MENOR O IGUAL a 10\n");
    printf("---------------------------------------------------\n\n");

    for(int i=0; i< tamp; i++)
    {
        totalP=0;

        for(int j=0; j < tam; j++)
        {

            if(prod[j].idProvedor == prov[i].codProvedor && prod[j].cantidad <=10)
            {
                totalP+=prod[j].cantidad;
            }

        }
            printf("%11s  %4d\n",prov[i].nombreProvedor,totalP);

    }
    system("pause");
    break;
    case 7:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos provistos por cada Provedor\n");
    printf("---------------------------------------------------\n\n");
    for(int i=0; i< tamp; i++)
    {
        printf("- %s\n\n", prov[i].nombreProvedor);

        for(int j=0; j < tam; j++)
        {
            if(prod[j].idProvedor == prov[i].codProvedor)
            {
                mostrarProducto(prod[j],prov,tam);
            }
        }
    }
    system("pause");
    break;
    case 8:
    system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos provistos por cada Provedor DETERMINADO\n");
    printf("---------------------------------------------------\n\n");

    printf("ingrese codigo del provedor: ");

    scanf("%d",&provEl);
    for (int i = 0; i < tamp; i++)
    {
        if (prov[i].codProvedor == provEl)
        {
            printf("- %s\n\n", prov[i].nombreProvedor);

        }

        for (int j = 0; j < tam; j++)


    {
        if (prod[j].idProvedor == provEl && prod[j].estado==1)
        {
            printf("%s\n", prod[j].nombreProducto);
        }

    }

break;
}
    system("pause");
    break;
    case 9:
    system("cls");
    printf("---------------------------------------------------\n");
    printf("-Productos que mas provee\n");
    printf("---------------------------------------------------\n\n");
        provedorQueMasProvee(prod,tam,prov,tamp);

    system("pause");
        break;
    case 10:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Provedor con producto mas caro\n");
    printf("---------------------------------------------------\n\n");


    for (int i = 0; i < tam; i++)
    {
        if ((i == 0 || prod[i].importe > masCaro) && prod[i].estado== 1)
        {
            masCaro = prod[i].importe;
            codigoC = prod[i].idProvedor;
            strcpy(productoMasCaro, prod[i].nombreProducto);
        }
    }

    for (int j = 0; j < tamp; j++)
    {
        if (prov[j].codProvedor == codigoC)
        {
            printf("\nEl proveedor con el producto mas caro es: %s, y el producto es: %s-\n\n", prov[j].nombreProvedor, productoMasCaro);
        }
    }

        system("pause");
        break;
    case 11:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Provedor con producto mas barato \n");
    printf("---------------------------------------------------\n\n");

    for (int i = 0; i < tam; i++)
    {
        if ((i == 0 || prod[i].importe < masBarato) && prod[i].estado == 1)
        {
            masBarato = prod[i].importe;
            codigo = prod[i].idProvedor;
            strcpy(productoMasBarato, prod[i].nombreProducto);
        }
    }
     for (int j = 0; j < tamp; j++)
    {
        if (prov[j].codProvedor == codigo)
        {
            printf("\nEl proveedor con el producto mas barato es: %s, y el producto es: %s\n", prov[j].nombreProvedor, productoMasBarato);
        }
    }

        system("pause");
        break;
    case 12:
        system("cls");
    printf("---------------------------------------------------\n");
    printf("-Listado Parcial\n");
    printf("---------------------------------------------------\n\n");

    listarParcial(prod,tam,prov,tamp);

        system("pause");
        break;
    case 13:
        salir=1;
        break;
    default:
            printf("opcion incorrecta.");
            break;
            system("pause");
    }
    }while(salir !=1);

}

void ordenarProductos(eProducto prod[], int tam,eProvedor prov[],int tamp)
{

    eProducto auxProducto;

    for(int i=0; i< tam-1; i++)
    {
        for(int j=i +1; j< tam; j++)
        {
            if (strcmp(prod[i].nombreProducto,prod[j].nombreProducto)>0){
                        auxProducto=prod[i];
                        prod[i]=prod[j];
                        prod[j]=auxProducto;
        } else {
                if (strcmp(prod[i].nombreProducto,prod[j].nombreProducto)==0){
                        if (prod[i].nombreProducto<prod[j].nombreProducto){
                            auxProducto=prod[i];
                            prod[i]=prod[j];
                            prod[j]=auxProducto;
                    }

                }

            }
        }
    }
    mostrarProductos(prod,tam,prov,tamp);
}
void provedorQueMasProvee(eProducto productos[],int tam,eProvedor proveedores[],int tamProv){

    int codigo;
    int contador = 0;
    int maximo = 0;
    int flag=0;

    for (int i = 0; i < tamProv; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if(productos[j].idProvedor == proveedores[i].codProvedor && productos[j].estado == 1)
            {
                contador++;
            }
        }
        if (contador > maximo && flag==0)
        {
            maximo = contador;
            codigo = proveedores[i].codProvedor;
            flag=1;
        }
    }

    for (int i = 0; i < tamProv; i++)
    {
        if (proveedores[i].codProvedor == codigo)
        {
            printf("\nEl proveedor que provee mas productos es: %s--\n", proveedores[i].nombreProvedor);

        }
         for (int i = 0; i < tam; i++)
        {
        if(productos[i].idProvedor == codigo && productos[i].estado == 1)
            {
            printf("Producto: %s\n", productos[i].nombreProducto);
            }
        }
        break;
    }
}
void productoMasCaro(eProducto prod[],int tam,eProvedor prov[],int tamp)
{
    int max;
    int flag=0;

    for(int i=0; i< tamp; i++){
            for(int j=0; j< tam; j++){

    if(prod[j].importe > max  || flag == 0){
        max = prod[i].importe;
        flag = 1;
    }


    if(prod[j].importe == max){
        printf("%s %s\n",prov[i].nombreProvedor,prod[j].nombreProducto);

        }

    }
    break;
    }

}
void productoMasBarato(eProducto prod[],int tam,eProvedor prov[],int tamp){

    int min;
    int flag=0;

    for(int i=0; i< tamp; i++){
            for(int j=0; j< tam; j++){

    if(prod[j].importe < min  || flag == 0){
        min = prod[i].importe;
        flag = 1;
    }


    if(prod[j].importe == min){
        printf("%s %s\n",prov[i].nombreProvedor,prod[j].nombreProducto);

        }

    }
    break;
    }



}
void listarParcial(eProducto prod[],int tam,eProvedor prov[],int tamp){

    float totalImporte=0;
    int flag=0;


    for(int i=0; i< tamp; i++){
        totalImporte=0;
        for(int j=0; j< tam; j++){

    if(prod[j].idProvedor == prov[i].codProvedor){

        totalImporte+=prod[j].importe;


        }

    }
    printf("%s %2.f \n\n",prov[i].nombreProvedor,totalImporte);
}


}
