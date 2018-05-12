#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAMPERSONA 20



int main()
{
    /**< Array lista de personas */
    EPersona listaDePersonas[TAMPERSONA];

    inicializarPersonasHardCode(listaDePersonas);
    inicializarPersonasEstado(listaDePersonas, TAMPERSONA);

    char seguir='s';
    int opcion=0;
    char nombre[10];

    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaDePersona(listaDePersonas, TAMPERSONA);
                presionarContinuar();
                break;
            case 2:

                printf("\nMODIFICAR DATOS DEL USUARIO \n");
                presionarContinuar();
                break;
            case 3:
                mostrarListadoDePersonas(listaDePersonas, TAMPERSONA);
                presionarContinuar();
                break;
            case 4:
                //printf("\nPUBLICAR PRODUCTO \n");
                presionarContinuar();
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    return 0;
}
