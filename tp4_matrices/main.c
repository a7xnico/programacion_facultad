#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
const int fila = 3, col = 4, dim_palabra = 30;
// ejercicio 1
void cargar_matriz(int matriz[fila][col]);
// ejercicio 2
void mostrar_matriz(int matriz[fila][col]);
// ejercicio 3
void cargar_aleatorio(int matriz[fila][col]);
// ejercicio 4, crear variable suma en main
int sumar_matriz(int matriz[fila][col]);
// ejercicio 5 crear variable promedio en main, no es necesario crear la suma esta hecho en el promedio
float promedio_matriz(int matriz[fila][col]);
// ejercicio 6 no necesita crear variable, buscar si es V o F con ! en un if statement
int encontrar_elemento(int matriz[fila][col], int elemento);
// ejercicio 7
int cargar_arreglo_string(char arreglo[][dim_palabra], int fila);
// ejercicio 8
void mostrar_arreglo_string(char arreglo[][dim_palabra], int val);
// ejercicio 9, hacer if statement con -1 o cualquier otro valor para ver la fila en donde esta o no la string dada
int buscar_string(char arreglo[][dim_palabra], int val, char palabra_buscada[dim_palabra]);

int detectar_menor_string(char array[][dim_palabra], int pos, int val);

void arreglo_por_seleccion(char arreglo[][dim_palabra], int val);

int main()
{
    char arreglo[fila][dim_palabra];
    int val = cargar_arreglo_string(arreglo, fila);
    arreglo_por_seleccion(arreglo, val);
    mostrar_arreglo_string(arreglo, val);

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

int sumar_matriz(int matriz[fila][col])
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
    int suma = sumar_matriz(matriz);
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

int cargar_arreglo_string(char arreglo[][dim_palabra], int fila)
{
    int continuar = 1, i = 0;
    while(continuar == 1 && i < fila)
    {
        printf("Ingrese una palabra: ");
        scanf("%s", &arreglo[i]);
        i++;
        printf("Para continuar aprete 1 \n");
        scanf("%i", &continuar);
    }
    return i;
}

void mostrar_arreglo_string(char arreglo[][dim_palabra], int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("%s\n", arreglo[i]);
    }
}

int buscar_string(char arreglo[][dim_palabra], int val, char palabra_buscada[dim_palabra])
{
    int encontrado = -1;
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(palabra_buscada, arreglo[i]) == 0)
        {
            encontrado = i;
        }
    }
    return encontrado;
}

void arreglo_por_seleccion(char arreglo[][dim_palabra], int val)
{
    for(int i = 0; i < val; i++)
    {
        int min_pos = i;
        for(int j = i + 1; j < val; j++)
        {
            if(strcmp(arreglo[j], arreglo[min_pos]) < 0)
            {
                min_pos = j;
            }
        }
        if(min_pos != i)
        {
            char buffer[dim_palabra];
            strcpy(buffer, arreglo[i]);
            strcpy(arreglo[i], arreglo[min_pos]);
            strcpy(arreglo[min_pos], buffer);
        }
    }
}



