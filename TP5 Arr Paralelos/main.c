#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dim 20
#define longPalabras 30

int cargarRegistro(int legajos[dim], int edad[dim], char nombres[dim][longPalabras]);

void mostrarRegistro(int legajos[], int edad[], char nombres[][longPalabras], int cargados);

int pedirLegajo();

int encontrarLegajo(int legajos[], int legajo_a_buscar, int cargados);

void mostrarNombrePorLegajo(int legajos[], int edad[], char nombres[][longPalabras], int cargados, int legajoBuscado);

void ordenarRegistro(int legajos[], int edad[], char nombres[][longPalabras], int cargados);

void intercambio(int legajos[], int edad[], char nombres[][longPalabras], int posActual, int posMenor);

int encontrarMenorNombre(char nombres[][longPalabras], int cargados, int pos);

int main()
{
    int legajos[dim];
    int edad[dim];
    char nombres[dim][longPalabras];
    int AlumnCargados = cargarRegistro(legajos, edad, nombres);
    mostrarRegistro(legajos, edad, nombres, AlumnCargados);
    int legajoBuscado = pedirLegajo();
    mostrarNombrePorLegajo(legajos, edad, nombres, AlumnCargados, legajoBuscado);
    ordenarRegistro(legajos, edad, nombres, AlumnCargados);
    printf("Legajo ordenado alfabeticamente: \n");
    mostrarRegistro(legajos, edad, nombres, AlumnCargados);
    return 0;
}

int cargarRegistro(int legajos[dim], int edad[dim], char nombres[dim][longPalabras])
{
    int i = 0;
    char seguir = 's';
    do
    {
        printf("Ingrese el nombre del alumno N%d: ", i + 1);
        scanf(" %s", nombres[i]);
        printf("Ingrese el legajo del alumno: ");
        scanf("%d", &legajos[i]);
        printf("Ingrese la edad del alumno: ");
        scanf("%d", &edad[i]);
        i++;

        printf("Quiere cargar otro alumno?(s/n): ");
        scanf(" %c", &seguir);
    }
    while(i < dim && seguir == 's');
    return i;
}

void mostrarRegistro(int legajos[], int edad[], char nombres[][longPalabras], int cargados)
{
    for(int i = 0; i < cargados; i++)
    {
        printf("---------ALUMNO N%d---------\n\n", i + 1);
        printf("NOMBRE: %s\n", nombres[i]);
        printf("EDAD: %d\n", edad[i]);
        printf("LEGAJO: %d\n", legajos[i]);
        printf("\n");
    }
    printf("---------------------------\n\n");
}

int encontrarLegajo(int legajos[], int legajo_a_buscar, int cargados)
{
    int encontrado = -1;
    for(int i = 0; i < cargados; i++)
    {
        if(legajo_a_buscar == legajos[i])
        {
            encontrado = i;
        }
    }
    return encontrado;
}

void mostrarNombrePorLegajo(int legajos[], int edad[], char nombres[][longPalabras], int cargados, int legajoBuscado)
{
    int posicion = encontrarLegajo(legajos, legajoBuscado, cargados);
    if(posicion != -1)
    {
        printf("El legajo %d le pertenece a: %s\n\n", legajoBuscado, nombres[posicion]);
    }
    else
    {
        printf("El legajo no se encuentra en el registro\n\n");
    }
}

void ordenarRegistro(int legajos[], int edad[], char nombres[][longPalabras], int cargados)
{
    int posMenor;
    for(int i = 0; i < cargados; i++)
    {
        posMenor = encontrarMenorNombre(nombres, cargados, i);
        if(posMenor != i)
        {
            intercambio(legajos, edad, nombres, i, posMenor);
        }
    }
}

int encontrarMenorNombre(char nombres[][longPalabras], int cargados, int pos)
{
    int posMenor = pos;
    for(int i = pos + 1; i < cargados; i++)
    {
        if(strcmpi(nombres[posMenor], nombres[i]) > 0)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

int pedirLegajo()
{
    int legajoBuscado;
    printf("Ingrese el legajo que quiera buscar: ");
    scanf("%d", &legajoBuscado);
    return legajoBuscado;
}

void intercambio(int legajos[], int edad[], char nombres[][longPalabras], int posActual, int posMenor)
{
    int buffer;
    char aux[longPalabras];
    strcpy(aux, nombres[posActual]);
    strcpy(nombres[posActual], nombres[posMenor]);
    strcpy(nombres[posMenor], aux);
    buffer = legajos[posActual];
    legajos[posActual] = legajos[posMenor];
    legajos[posMenor] = buffer;
    buffer = edad[posActual];
    legajos[posActual] = legajos[posMenor];
    legajos[posMenor] = buffer;
}

























