#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int fila = 3, col = 4;
// ejercicio 1
void cargar_matriz(int matriz[fila][col]);
// ejercicio 2
void mostrar_matriz(int matriz[fila][col]);
// ejercicio 3
void cargar_aleatorio(int matriz[fila][col]);
// ejercicio 4, crear variable suma en main
int sumatoria_matriz(int matriz[fila][col]);
// ejercicio 5 crear variable promedio en main, no es necesario crear la suma esta hecho en el promedio
float promedio_matriz(int matriz[fila][col]);
// ejercicio 6 no necesita crear variable, buscar si es V o F con ! en un if statement
int encontrar_elemento(int matriz[fila][col], int elemento);



int main()
{
    int matriz[fila][col];
    int elemento;
    cargar_aleatorio(matriz);
    printf("Cargar el elemento que quiera buscar en la matriz: ");
    scanf("%i", &elemento);
    mostrar_matriz(matriz);
    if(!encontrar_elemento(matriz, elemento))
    {
        printf("El elemento %i no esta en la matriz", elemento);
    }
    else
    {
        printf("El elemento %i esta en la matriz", elemento);
    }
}

void cargar_matriz(int matriz[fila][col])
{
    int i, j;
    for(i = 0; i < fila; i++)
    {
        printf("Cargue la fila %i \n", i);
        for(j = 0; j < col; j++)
        {
            printf("Ingrese el numero a la matriz: ");
            scanf("%i", &matriz[i][j]);
        }
    }
}

void mostrar_matriz(int matriz[fila][col])
{
    for(int i = 0; i < fila; i++)
    {
        printf("|");
        for(int j = 0; j < col; j++)
        {
            printf(" %i|", matriz[i][j]);
        }
        printf("\n");
    }
}

void cargar_aleatorio(int matriz[fila][col])
{
    srand(time(NULL));
    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < col; j++)
        {
            matriz[i][j] = rand()%21;
        }
    }
}

int sumatoria_matriz(int matriz[fila][col])
{
    int suma = 0;
    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < col; j++)
        {
            suma += matriz[i][j];
        }
    }
    return suma;
}

float promedio_matriz(int matriz[fila][col])
{
    int total = fila * col;
    int suma = sumatoria_matriz(matriz);
    float promedio = suma / (float)total;
    return promedio;
}

int encontrar_elemento(int matriz[fila][col], int elemento)
{
    int encontrado = 0;
    for(int i = 0; i < fila && encontrado == 0; i++)
    {
        for(int j = 0; j < col && encontrado == 0; j++)
        {
            if(elemento == matriz[i][j])
            {
                encontrado = 1;
            }
        }
    }
    return encontrado;
}
