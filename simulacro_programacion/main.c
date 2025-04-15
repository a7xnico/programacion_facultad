#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int fila_palabras = 5, dim_palabras = 15;


int main()
{
    char arr_palabras[fila_palabras][dim_palabras];
    char arr_palabras2[fila_palabras][dim_palabras];
    int valA = cargar_palabras(arr_palabras);
    int valB = cargar_palabras(arr_palabras2);
    int coincidencias = encontrar_coincidencias(arr_palabras, arr_palabras2, valA, valB);
    printf("Arreglo 1: \n");
    mostrar_palabras(arr_palabras, valA);
    printf("Arreglo 2: \n");
    mostrar_palabras(arr_palabras2, valB);
    printf("coincidencias entre arreglos: %i", coincidencias);
}

int cargar_palabras(char arreglo[fila_palabras][dim_palabras])
{
    int cont = 1, i = 0;

    do
    {
        printf("Ingresar palabra al arreglo: ");
        scanf(" %s", arreglo[i]);
        i++;
        printf("Para continuar ingrese 1: ");
        scanf("%i", &cont);
    }while(i < fila_palabras && cont == 1);
    return i;
}

void mostrar_palabras(char arreglo[fila_palabras][dim_palabras], int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("%s\n", arreglo[i]);
    }
}

int encontrar_coincidencias(char arregloA[fila_palabras][dim_palabras], char arregloB[fila_palabras][dim_palabras], int valA, int valB)
{
    int coincidencias = 0;
    for(int i = 0; i < valA; i++)
    {
        for(int j = 0; j < valB; j++)
        {
            if(strcmp(arregloA[i], arregloB[j]) == 0)
            {
                coincidencias++;
            }
        }
    }
    return coincidencias;
}
