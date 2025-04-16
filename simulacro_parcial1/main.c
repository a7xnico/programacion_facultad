#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#define fila 3
#define col 3
#define filaPalabras 5
#define dimPalabra 10
// Nicolas Araya com 7
int menu();


// punto 1 cargar pila con cantidad par de elementos
void cargar_pila(Pila *pilita);


// punto 2 cargar en arreglo todos los multiplos de 5 de una pila
int arreglo_multiplos_5(int array[20], Pila *pila);
// muestra el array para el punto 2 y los siguientes
void mostrar_array(int array[], int validos);


// ejercicio 3 le pide al usuario el arreglo
int cargar_arreglo(int array[], int dim);
// busca el menor numero en el arreglo
int encontrar_menor(int array[], int validos);


// ejercicio 4
void cargar_matriz(int matriz[fila][col]);
void mostrar_matriz(int matriz[fila][col]);


// ejercicio 5
int pedir_pos_arreglo(int array[], int validos);
void mostrar_posicion(int array[], int validos);

//ejercicio 6
int detectar_menor(Pila *p);
void ordenada_seleccion(Pila *p, Pila *ordenada);

//ejercicio 7
float prom_matriz(int matriz[fila][col]);

//ejercicio 8
int cargar_arr_string(char arrPalabra[filaPalabras][dimPalabra]);
void mostrar_arr_palabras(char arrPalabra[][dimPalabra], int validos);

// ejercicio 9
int encontrar_coincidencia(char arrPalabra1[][dimPalabra], int val1, char arrPalabra2[][dimPalabra], int val2);


int main()
{
    char continuar = 's';
    while(continuar == 's')
    {
        int opcion = menu();
        switch(opcion)
        {
        case 0:
            continuar = 'n';
            system("cls");
            break;
        case 1:;
            Pila pilita;
            inicpila(&pilita);
            cargar_pila(&pilita);
            mostrar(&pilita);
            system("pause");
            system("cls");
            break;


        case 2:;
            Pila pilita2;
            inicpila(&pilita2);
            cargar_pila(&pilita2);
            int array2[20];
            int validos = arreglo_multiplos_5(array2, &pilita2);
            mostrar(&pilita2);
            printf("arreglo con los multiplos de 5 en la pila: \n");
            mostrar_array(array2, validos);
            system("pause");
            system("cls");
            break;

        case 3:;
            int array3[20];
            int val3 = cargar_arreglo(array3, 20);
            int menor = encontrar_menor(array3, val3);
            mostrar_array(array3, val3);
            printf("el numero %i se encuentra en la posicion %i\n", array3[menor], menor);
            system("pause");
            system("cls");
            break;

        case 4:;
            int matriz[fila][col];
            cargar_matriz(matriz);
            mostrar_matriz(matriz);
            system("pause");
            system("cls");
            break;

        case 5:;
            int array5[20];
            int val5 = cargar_arreglo(array5, 20);
            mostrar_posicion(array5, val5);
            system("pause");
            system("cls");
            break;
        case 6:;
            Pila desordenada6, ordenada6;
            inicpila(&desordenada6);
            inicpila(&ordenada6);
            cargar_pila(&desordenada6);
            printf("PILA INICIAL: \n");
            mostrar(&desordenada6);
            ordenada_seleccion(&desordenada6, &ordenada6);
            printf("PILA ORDENADA: \n");
            mostrar(&ordenada6);
            system("pause");
            system("cls");
            break;

        case 7:;
            int matriz7[fila][col];
            cargar_matriz(matriz7);
            float promedio = prom_matriz(matriz7);
            mostrar_matriz(matriz7);
            printf("El promedio de esta matriz es: %.2f\n", promedio);
            system("pause");
            system("cls");
            break;

        case 8:;
            char arrPalabra[filaPalabras][dimPalabra];
            int val8 = cargar_arr_string(arrPalabra);
            mostrar_arr_palabras(arrPalabra, val8);
            system("pause");
            system("cls");
            break;

        case 9:;
            char arrPalabraA[filaPalabras][dimPalabra];
            char arrPalabraB[filaPalabras][dimPalabra];
            printf("ARREGLO 1: \n");
            int val9A = cargar_arr_string(arrPalabraA);
            printf("ARREGLO 2: \n");
            int val9B = cargar_arr_string(arrPalabraB);
            int coincidencias = encontrar_coincidencia(arrPalabraA, val9A, arrPalabraB, val9B);
            system("cls");
            printf("ARREGLO 1 \n");
            mostrar_arr_palabras(arrPalabraA, val9A);
            printf("\n");
            printf("ARREGLO 2 \n");
            mostrar_arr_palabras(arrPalabraB, val9B);
            printf("\n");
            printf("Estos arreglos coinciden %i veces\n", coincidencias);
            system("pause");
            system("cls");
            break;
        default:;
            printf("ERROR. NUMERO NO ESTA DENTRO DEL MENU DE OPCIONES\n");
            system("pause");
            system("cls");
            break;
        }
    }
    printf("Hasta la proxima!");
    return 0;
}
// ejercicio 1
void cargar_pila(Pila *pilita)
{
    char seguir = 's';
    int elem_pila = 0;
    do
    {
        leer(pilita);
        elem_pila++;
        printf("quiere seguir cargando? s/n\n");
        scanf(" %c", &seguir); // con el espacio te libras del buffer al scanear un char
    }while(seguir == 's');
    if(elem_pila % 2 != 0)
    {
        printf("Cantidad impar de elementos agregue otro a la pila\n");
        leer(pilita);
    }
}

int arreglo_multiplos_5(int array[], Pila *pila)
{
    int i = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(pila) && i < 20)
    {
        if(tope(pila) %5 == 0)
        {
            array[i] = tope(pila);
            i++;
        }
        apilar(&aux, desapilar(pila));
    }
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
    return i;
}

void mostrar_array(int array[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("| %i |", array[i]);
    }
    printf("\n");
}

int cargar_arreglo(int array[], int dim)
{
    char seguir = 's';
    int i = 0;
    while(seguir == 's' && i < dim)
    {
        printf("Cargue un numero en el arreglo: ");
        scanf("%i", &array[i]);
        i++;
        printf("Desea cargar mas numeros? (s/n)\n");
        scanf(" %c", &seguir);
    }
    return i;
}

int encontrar_menor(int array[], int validos)
{
    int posMenor = 0;
    int menor = array[0];
    for(int i = 1; i < validos; i++)
    {
        if(array[i] < menor)
        {
            menor = array[i];
            posMenor = i;
        }
    }
    return posMenor;
}

void cargar_matriz(int matriz[fila][col])
{
    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Ingresar numero a la fila %i columna %i : ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void mostrar_matriz(int matriz[fila][col])
{
    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("| %i |", matriz[i][j]);
        }
        printf("\n");
    }
}

int pedir_pos_arreglo(int array[], int validos)
{
    int pos;
    do
    {
        printf("Ingrese la posicion a buscar: ");
        scanf("%i", &pos);

        if(pos>= validos)
        {
            printf("Error. ingrese posicion dentro de los validos\n");
        }
        else if(pos < 0)
        {
            printf("ERROR. no ingresar posicion negativa\n");
        }
    }while(pos < 0 || pos >= validos);

    return pos;
}

void mostrar_posicion(int array[], int validos)
{
    int posicion = pedir_pos_arreglo(array, validos);
    printf("El numero que esta en la posicion %i del arreglo es %i\n", posicion, array[posicion]);
}

int detectar_menor(Pila *p)
{
    Pila aux;
    inicpila(&aux);
    int menor = desapilar(p);
    while(!pilavacia(p))
    {
        if(tope(p) < menor)
        {
            apilar(&aux, menor);
            menor = desapilar(p);
        }
        else
        {
            apilar(&aux, desapilar(p));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(p, desapilar(&aux));
    }
    return menor;
}

void ordenada_seleccion(Pila *p, Pila *ordenada)
{
    while(!pilavacia(p))
    {
        apilar(ordenada, detectar_menor(p));
    }
}

float prom_matriz(int matriz[fila][col])
{
    int elementos = fila * col;
    int suma = 0;
    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < col; j++)
        {
            suma += matriz[i][j];
        }
    }
    float prom = suma / (float)elementos;
    return prom;
}

int cargar_arr_string(char arrPalabra[filaPalabras][dimPalabra])
{
    char seguir = 's';
    int i = 0;
    while(seguir == 's' && i < filaPalabras)
    {
        printf("Ingrese una palabra: ");
        scanf(" %s", arrPalabra[i]);
        i++;
        printf("Quiere cargar otra palabra? (s/n)\n");
        scanf(" %c", &seguir);
    }
    return i;
}

void mostrar_arr_palabras(char arrPalabra[][dimPalabra], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%s\n", arrPalabra[i]);
    }
}

int encontrar_coincidencia(char arrPalabra1[][dimPalabra], int val1, char arrPalabra2[][dimPalabra], int val2)
{
    int coincidencias = 0;
    for(int i = 0; i < val1; i++)
    {
        for(int j = 0; j < val2; j++)
        {
            if(strcasecmp(arrPalabra1[i], arrPalabra2[j])== 0)
            {
                coincidencias++;
            }
        }
    }
    return coincidencias;
}

























// funcion para el punto 10, mantiene mas libre main mientras permite elegir cada punto a realizar
int menu()
{
    int opcion;
    printf("MENU DE OPCIONES \n");
    printf("1 - CARGAR UNA PILA DE NUM ENTEROS\n");
    printf("2 - COPIAR MULTIPLOS DE 5 DE PILA A ARREGLO\n");
    printf("3 - ENCONTRAR POSICION DEL MENOR NUMERO EN EL ARREGLO\n");
    printf("4 - CARGA DE MATRIZ Y MUESTRA DE LA MISMA\n");
    printf("5 - PEDIR Y MOSTRAR POSICION DE UN ARREGLO\n");
    printf("6 - ORDENAR PILA POR SELECCION\n");
    printf("7 - CALCULAR PROMEDIO DE UNA MATRIZ DE ENTEROS\n");
    printf("8 - CARGAR MATRIZ TIPO CHAR\n");
    printf("9 - ENCONTRAR COINCIDENCIAS ENTRE 2 ARREGLOS DE STRINGS\n");
    printf("0 - Salir del programa\n");
    printf("Elegir que punto quiere realizar: ");
    scanf("%i", &opcion);
    system("cls");
    return opcion;
}
