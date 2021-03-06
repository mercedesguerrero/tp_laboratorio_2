#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define OCUPADO 1
#define LIBRE 0
#define CANTIDAD 20

typedef struct {

    char nombre[40];
    int edad;
    long int dni;
    int estado;

}EPersona;

void inicializarPersonasEstado(EPersona[], int cantidad);
void inicializarPersonasHardCode(EPersona[]);

void mostrarMenu();
void presionarContinuar();

int mostrarListadoDePersonas(EPersona[], int limite);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona listaDePersonas[], int limite);

int altaDePersona(EPersona[], int cantidad);

void getString(char mensaje[], char input[]);
void getValidString(char mensaje[], char error[], char input[], int limite);
int pedirNumEntero(char mensaje[]);
int pedirNumEnteroLong(char mensaje[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona listaDePersonas[], long int dni, int limite);


int borrarUnaPersona(EPersona[], int limite);


#endif // FUNCIONES_H_INCLUDED

