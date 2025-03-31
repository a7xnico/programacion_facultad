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

void caracter_en_arreglo(char array[], int validos);

void mostrar_arreglo_char(char array[], int validos);
// ejercicio 7 al crear la dimension sumarle 1 a el valor dado por el usuario para agregar el caracter
int insertar_caracter_en_arreglo(char array[], int validos);
// ejercicio 8 crear variable mayor para mostrarlo por medio de printf
char mayor_caracter_arreglo(char array[], int validos);
// ejercicio 9
void es_capicua(int array[], int validos);

void invertir_arreglo(int array[], int validos);

int detectar_menor(int array[], int pos, int validos);

void arreglo_por_seleccion(int array[], int validos);

void ordenada_insercion(int array[], int validos);


int main()
{
    int dim, val;
    printf("Ingresar dimension del arreglo: ");
    scanf("%d", &dim);
    int arreglo[dim];
    cargar_arreglo(arreglo, dim, &val);
    ordenada_insercion(arreglo, val);
    mostrar_arreglo(arreglo, val);

}

void cargar_arreglo(int array[], int dimension,int* validos)
{
    int seguir = 1, i = 0;
    while(i < dimension && seguir == 1)
    {
        printf("Ingrese un numero entero: ");
        scanf("%d", &array[i]);
        i++;
        printf("Presione 1 si quiere ingresar otro numero o cualquier otro para terminar de cargar el arreglo: ");
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
        printf("Ingresar caracter al arreglo: ");
        scanf(" %c", &array[i]); // el espacio para evitar problemas con el buffer
        i++;
        printf("Presione 1 para continuar o cualquier otra tecla para salir: ");
        scanf("%d", &seguir);
    }
    *validos = i;
}

void caracter_en_arreglo(char array[], int validos)
{
    char caracter;
    int encontrado = 0;
    printf("Ingrese el elemento que quiere buscar: ");
    scanf(" %c", &caracter); // lo mismo que en cargar_arreglo_char

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

int insertar_caracter_en_arreglo(char array[], int validos)
{
    char caracter, buffer;
    printf("Ingresar el caracter que quiera insertar al arreglo: ");
    scanf(" %c", &caracter);
    int i;
    for(i = 0; i < validos; i++)
    {
        if(caracter < array[i])
        {
            buffer = array[i];
            array[i] = caracter;
            caracter = buffer;
        }
    }
    array[i] = caracter;
    return validos++;
}

char mayor_caracter_arreglo(char array[], int validos)
{
    char mayor;
    for(int i = 0; i < validos; i++)
    {
        if(i == 0)
        {
            mayor = array[i];
        }
        if(mayor < array[i])
        {
            mayor = array[i];
        }
    }
    return mayor;
}

void es_capicua(int array[], int validos)
{
    int i;
    for(i = 0; i < (validos / 2); i++)
    {
        if(array[i] != array[validos - 1 - i])
        {
            printf("No es capicua");
            break;
        }
    }
    if(i == (validos / 2))
    {
        printf("Es capicua");
    }
}

void invertir_arreglo(int array[], int validos)
{
    int i, buffer;
    for(i = 0; i < (validos / 2); i++)
    {
        buffer = array[i];
        array[i] = array[validos - i - 1];
        array[validos - i - 1] = buffer;
    }
}

int detectar_menor(int array[],int pos, int validos)
{
    int menor = array[pos];
    int posmenor = pos;
    for(int i = pos +  1; i < validos; i++)
    {
        if(menor > array[i])
        {
            menor = array[i];
            posmenor = i;
        }
    }
    return posmenor;
}

void arreglo_por_seleccion(int array[], int validos)
{
    int posmenor, buffer;
    for(int i = 0; i < validos - 1; i++)
    {
        posmenor = detectar_menor(array, i, validos);
        buffer = array[posmenor];
        array[posmenor] = array[i];
        array[i] = buffer;
    }
}

void insertar(int array[], int validos, int dato)
{
    int i = validos;
    while(i>= 0 && dato < array[i])
    {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = dato;
}

void ordenada_insercion(int array[], int validos)
{
    for(int i = 0; i < validos - 1; i++)
    {
        insertar(array, validos, array[i + 1]);
    }
}





