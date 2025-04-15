#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int fila = 5, dim_palabra = 30;

int cargar_arreglo_string(char arreglo[][dim_palabra], int fila);

void mostrar_arreglo_string(char arreglo[][dim_palabra], int val);

int detectar_menor(char arreglo[][dim_palabra], int pos, int val);

void ordenada_seleccion(char arreglo[][dim_palabra], int val);

int main()
{
    char arreglo[fila][dim_palabra];
    int val = cargar_arreglo_string(arreglo, fila);
    mostrar_arreglo_string(arreglo, val);
    ordenada_seleccion(arreglo,  val);
    mostrar_arreglo_string(arreglo, val);
}

int cargar_arreglo_string(char arreglo[][dim_palabra], int fila)
{
    int continuar = 1, i = 0;
    while(continuar == 1 && i < fila)
    {
        printf("Ingrese una palabra: ");
        scanf("%s", arreglo[i]);
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

int detectar_menor(char arreglo[][dim_palabra], int pos, int val)
{

    int min_pos = pos;
    for(int i = pos + 1; i < val; i++)
    {
        if(strcmp(arreglo[i], arreglo[min_pos]) < 0)
        {
            min_pos = i;
        }
    }
    return min_pos;
}

void ordenada_seleccion(char arreglo[][dim_palabra], int val)
{
    int min_pos;
    for(int i = 0; i < val; i++)
    {
        min_pos = detectar_menor(arreglo, i, val);
        if(min_pos != i)
        {
            char buffer[dim_palabra];
            strcpy(buffer, arreglo[i]);
            strcpy(arreglo[i], arreglo[min_pos]);
            strcpy(arreglo[min_pos], buffer);
        }
    }
}

void ordenada_insercion(char arreglo[][dim_palabra], int val)
{
    for(int i = 1; i < val; i++)
    {
        char buffer[dim_palabra];
        strcpy(buffer, arreglo[i]);
        int j = i - 1;
        while(j >= 0 && strcmp(buffer, arreglo[j]) < 0)
        {
            strcpy(arreglo[j + 1], arreglo[j]);
            j--;
        }
        strcpy(arreglo[j + 1], buffer);
    }
}
