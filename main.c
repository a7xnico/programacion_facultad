#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
// ejercicio 1
void cargar_arreglo(int array[], int dimension,int* validos);
// ejercicio 2
void mostrar_arreglo(int array[], int validos);
// ejercicio 3
int suma_arreglo(int array[], int validos);
// ejercicio 4
void arreglo_a_pila(int array[], int validos, Pila* pila);
// ejercicio 5 las 3 de float, inicializar la dimension a 100 sin preguntarle al usuario
void cargar_arreglo_float(float array[], int dimension, int* validos);

void mostrar_arreglo_float(float array[], int validos);

float suma_arreglo_float(float array[], int validos);
// ejercicio 6 las 3 de char
void cargar_arreglo_char(char array[], int dimension, int* validos);

void caracter_en_arreglo(char array[], int dimension, int validos);

void mostrar_arreglo_char(char array[], int validos);


int main()
{
    int dim, val;
    printf("indique dimension del arreglo: ");
    scanf("%d", &dim);
    char arreglo[dim];
    cargar_arreglo_char(arreglo, dim, &val);
    caracter_en_arreglo(arreglo, dim, val);
    mostrar_arreglo_char(arreglo, val);
}

void cargar_arreglo(int array[], int dimension,int* validos)
{
    int seguir = 1, i = 0;
    while(i < dimension && seguir == 1)
    {
        printf("Ingrese un numero entero: ");
        scanf("%d", &array[i]);
        i++;
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%d", &seguir);
    }
    *validos = i;
}

void mostrar_arreglo(int array[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("Posicion %d: %d\n", i, array[i]);
    }
}

int suma_arreglo(int array[], int validos)
{
    int suma = 0;
    for(int i = 0; i < validos; i++)
    {
        suma+= array[i];
    }
    return suma;
}

void arreglo_a_pila(int array[], int validos, Pila* pila)
{
    for(int i = 0; i < validos; i++)
    {
        apilar(pila, array[i]);
    }
}

void cargar_arreglo_float(float array[], int dimension, int* validos)
{
    int i;
    for(i = 0; i < dimension; i++)
    {
        printf("Ingrese un numero real: ");
        scanf("%f", &array[i]);
    }
    *validos = i;
}

void mostrar_arreglo_float(float array[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("Posicion %d: %f\n", i, array[i]);
    }
}

float suma_arreglo_float(float array[], int validos)
{
    float suma = 0;
    for(int i = 0; i < validos; i++)
    {
        suma += array[i];
    }
    return suma;
}

void cargar_arreglo_char(char array[], int dimension, int* validos)
{
    int seguir = 1, i = 0;
    while(i < dimension && seguir == 1)
    {
        fflush(stdin);
        printf("Ingresar caracter al arreglo: ");
        scanf("%c", &array[i]);
        i++;
        printf("Presione 1 para agregar otro caracter: ");
        scanf("%d", &seguir);
    }
    *validos = i;
}

void caracter_en_arreglo(char array[], int dimension, int validos)
{
    char caracter;
    int encontrado = 0;
    printf("Ingrese el elemento que quiere buscar: ");
    fflush(stdin);
    scanf("%c", &caracter);

    for(int i = 0; i < validos; i++)
    {
        if(caracter == array[i])
        {
            printf("El caracter %c esta en el arreglo\n", caracter);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado)
    {
        printf("El caracter %c no esta en el arreglo\n", caracter);
    }
}
void mostrar_arreglo_char(char array[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("Posicion %d: %c\n", i, array[i]);
    }
}










