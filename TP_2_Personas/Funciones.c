#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mostrarMenu()
{
    system("cls");

    printf("\nPERSONAS>>> Seleccione una opcion: \n\n");

    printf("1- Agregar una persona \n");
    printf("2- Borrar una persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir gráfico de edades\n");
    printf("5- Salir\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}


void inicializarPersonasEstado(EPersona personas[], int cantidad)
{
     int i;

    for(i=0; i<cantidad; i++)
    {
        personas[i].estado = LIBRE;
    }
}

void inicializarPersonasHardCode(EPersona personas[])
{
    char nombre[15][40]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int edad[15]= {20,16,21,14,34,46,33,64,15,36,17,13,42,15,71};
    long int dni[15]= {42153281,45783294,39492384,23864398,34152378,52152237,23872235,39271452,24847392,56783256,34567238,41296374,60221378,33678219,63245632};

    int i;

    for(i=0; i<15; i++)
    {
        strcpy(personas[i].nombre, nombre[i]);
        personas[i].edad= edad[i];
        personas[i].dni= dni[i];
        personas[i].estado= OCUPADO;
    }
}

void mostrarListadoDePersonas(EPersona personas[], int cantidad)
{
    int i;

    printf("%s\t\t %s\t\t %s\t\n","\nNombre","Edad", "DNI");

/**< Recorre el listado y si el estado es distinto de OCUPADO lo muestra */
    for(i=0; i<cantidad; i++)
    {
        if(personas[i].estado==OCUPADO)
        {
            printf("%s\t\t %d\t\t %ld\t\n", personas[i].nombre, personas[i].edad, personas[i].dni);
        }
    }
}
