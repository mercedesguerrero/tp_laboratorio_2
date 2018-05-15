#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu()
{
    system("cls");

    printf("\nPERSONAS>>> Seleccione una opcion: \n\n");

    printf("1- Agregar una persona \n");
    printf("2- Borrar una persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}


void inicializarPersonasEstado(EPersona personas[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        personas[i].estado = LIBRE;
    }
}

void inicializarPersonasHardCode(EPersona personas[])
{
    char nombre[15][40]= {"Cecilia","Mara","Marcelo","Vanesa","Juan","Laura","Luis","Micaela","Guillermo","Pedro","Stella","Antonela","Gabriela","Carlos","Bruno"};
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

int obtenerEspacioLibre(EPersona personas[], int limite)
{
    int retorno = -2;
    int i;

    if(limite > 0 && personas != NULL)
    {
        retorno = -1;
        for(i=0; i<limite; i++)
        {
            if(personas[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }

    if(retorno<0)
    {
        printf("No hay lugar libre\n");
    }
    return retorno;
}

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
    fflush(stdin);
}

void getValidString(char mensaje[], char error[], char input[], int limite)
{
    int j;

    do
    {
        getString(mensaje, input);

        j= strlen(input);

        if(j>= limite)
        {
            printf("%s", error);
        }

    }while(j>= limite);

}

int pedirNumEntero(char mensaje[])
{
    int numeroEntero;

    printf("%s", mensaje);
    scanf("%d", &numeroEntero);

    return numeroEntero;
}

int pedirNumEnteroLong(char mensaje[])
{
    int numeroLong;

    printf("%s", mensaje);
    scanf("%dl", &numeroLong);

    return numeroLong;
}


int altaDePersona(EPersona personas[],int limite)
{
    int retorno=-1;
    int index;
    long int dni;
    char nombre[50];
    int edad;

    if(limite>0 && personas!= NULL)
    {
        retorno=-2;
        index= obtenerEspacioLibre(personas, limite);

        if(index>= 0)//HAY LUGAR
        {
            getValidString("Ingrese nombre: \n", "El nombre ingresado es muy largo, reingrese\n", nombre, 50);
            strcpy(personas[index].nombre, nombre);
            edad= pedirNumEntero("Ingrese edad: \n");
            personas[index].edad = edad;
            dni= pedirNumEnteroLong("Ingrese DNI: \n");
            personas[index].dni = dni;
            personas[index].estado = OCUPADO;
            retorno = 0;
        }
        else
        {
            printf("\n No hay lugar para cargar personas");
        }
    }

    return retorno;
}

int mostrarListadoDePersonas(EPersona personas[], int limite)
{
    int i;
    int retorno=-2;

    printf("%s\t\t %s\t\t %s\t\n","\nNombre","Edad", "DNI");

/**< Recorre el listado y si el estado es distinto de OCUPADO lo muestra */
    for(i=0; i<limite; i++)
    {
        retorno=-1;
        if(personas[i].estado==OCUPADO)
        {
            retorno=0;
            printf("%s\t\t %d\t\t %ld\t\n", personas[i].nombre, personas[i].edad, personas[i].dni);
        }
    }
    return retorno;
}

int borrarUnaPersona(EPersona personas[], int limite)
{
    int i;
    long int DniABuscar;
    int retorno= -1;

    mostrarListadoDePersonas(personas, CANTIDAD);

    if(mostrarListadoDePersonas(personas, limite)==0)
       {
            //mostrarListadoDePersonas(personas, limite);

            printf("Ingrese DNI de la persona que desea borrar");
            scanf("%dl", &DniABuscar);
            retorno= -2;

            for(i=0; i<limite; i++)
            {
                retorno= -3;
                if(personas[i].estado == OCUPADO && personas[i].dni == DniABuscar)
                {
                    personas[i].dni= 0;
                    personas[i].estado== LIBRE;
                }
            }
       }

    return retorno;
}


