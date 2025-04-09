#include <stdio.h>
#include <stdlib.h>

const int Fila = 5;
const int Columna = 5;
const int Max_palabra = 20;

int main()
{
    int elecciones[Fila][Columna]= {
        (1, 194, 48, 206, 45),
        {2, 180, 20, 320, 16},
        (3, 221, 90, 140, 20),
        (4, 432, 51, 821, 14),
        (5, 820, 61, 946, 18)
    };
    char encabezado[Fila][Max_palabra] = {"Distrito", "Candidato A", "Candidato B", "Candidato C", "Candidato D"};
    imprimir_tabla(elecciones, encabezado);


}

void imprimir_tabla(int eleccion[Fila][Columna], char encabezado[Fila][Max_palabra])
{
    for(int k = 0; k < Fila; k++)
    {
        printf(" |%s| ", encabezado[k]);
    }
    printf("\n");
    for(int i = 0; i < Fila; i ++)
    {
        for(int j = 0; j < Columna; j++)
        {
            printf(" |%i| ", eleccion[i][j]);
        }
        printf("\n");
    }
}
