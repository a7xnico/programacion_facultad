#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include <math.h>
const int rangoPrecios = 6;
const int PrecioMaximo = 999999;
const int dimPalabras = 20;
const int filaPalabras = 5;
// Nicolas Araya Comision 7
// ejercicio 1
void cargarPilaCompras(int *cantidad, int *monto, Pila *compras);
// ejercicio 2
void ordenarPorInsercion(Pila *compras);
// inicializar el arreglo para que todos los lugares esten llenos
void iniciarPrecios(int arreglo[rangoPrecios]);
// verificacion de que se este cargando el arreglo correctamente
void mostrarArreglo(int arreglo[rangoPrecios], int arregloMonto[rangoPrecios]);
// ejercicio 3
// obtener cantidad de compras por rango de precio y guardar el dinero total en cada rango
void cargarArregloPorPrecio(int arregloCantidad[rangoPrecios], Pila *compras, int arregloMontos[rangoPrecios]);
// ejercicio 4
int MayorMontoCompras(int arregloMonto[rangoPrecios]);
// ejercicio 5
float calcularPorcentajeCompras(int arregloCantidad[rangoPrecios], int cantidad);
// ejercicio 6
int estaEnArreglo(char arregloPalabras[][dimPalabras], char palabra[dimPalabras], int validos);

int cargarArregloStrings(char arregloPalabras[filaPalabras][dimPalabras]);

void mostrarPalabras(char arregloPalabras[][dimPalabras], int validos);

int main()
{
    char arregloNombres[filaPalabras][dimPalabras];
    int cantidad = 0, monto = 0;
    int CantidadPorRango[rangoPrecios];
    int MontosPorRango[rangoPrecios];
    iniciarPrecios(CantidadPorRango);
    iniciarPrecios(MontosPorRango);
    Pila compras;
    inicpila(&compras);
    cargarPilaCompras(&cantidad, &monto, &compras);
    system("cls");
    mostrar(&compras); // prueba de que este bien cargada la pila
    printf("Cantidad de elementos comprados: %i\nMonto total de los elementos: %i\n\n", cantidad, monto); // fijarse que se hayan pasado por referencia correctamente los valores
    ordenarPorInsercion(&compras);
    printf("Pila tras ser ordenada mediante insercion: \n"); // prueba para ver que se ordenara de forma correcta
    mostrar(&compras);
    cargarArregloPorPrecio(CantidadPorRango, &compras, MontosPorRango);
    printf("------ Informe por rango de precios ------\n\n"); // muestra de todos los rangos de precios, de no tener ninguna compra mostrara que esta vacio
    mostrarArreglo(CantidadPorRango, MontosPorRango);
    int posMayorMonto = MayorMontoCompras(MontosPorRango); // busca el mayor monto
    printf("\n\nRango de compras con mayor monto acumulado: %i\nMonto acumulado en el rango: %i de %i\n\n", posMayorMonto + 1, MontosPorRango[posMayorMonto], monto); // pMM + 1 para mostrar el num de digitos
    float porcentaje = calcularPorcentajeCompras(CantidadPorRango, cantidad);
    printf("El porcentaje de el rango elegido sobre el total es de: %.2f%%\n\n", porcentaje);
    system("pause");
    system("cls"); // limpia todo para poder cargar los nombres sin que se llene la consola
    int palValidas = cargarArregloStrings(arregloNombres);
    printf("------ Lista de nombres en el arreglo ------\n\n"); // muestra la lista entera
    mostrarPalabras(arregloNombres, palValidas);
    return 0;
}

void cargarPilaCompras(int *cantidad, int *monto, Pila *compras)
{
    char continuar = 's';
    int valor = 0;
    printf("PRECIO MAXIMO A LA COMPRA: %i\n", PrecioMaximo);
    while(continuar == 's')
    {
        printf("Ingrese el valor de su compra (en numeros enteros): ");
        scanf("%i", &valor);
        if(valor <= PrecioMaximo)
        {
            apilar(compras, valor);
            (*cantidad)++;
            *monto += valor;
            printf("Desea ingresar otra compra? (s/n)\n");
            scanf(" %c", &continuar);
        }
        else
        {
            printf("ERROR. VALOR EXCEDE MONTO MAXIMO PARA COMPRA\n");
            continue;
        }
    }
}

void ordenarPorInsercion(Pila *compras)
{
    Pila aux1, aux2;
    inicpila(&aux1);
    inicpila(&aux2);
    int num;
    while(!pilavacia(compras))
    {
        num = desapilar(compras);
        while(!pilavacia(&aux1)&& num < tope(&aux1))
        {
            apilar(&aux2, desapilar(&aux1));
        }
        apilar(&aux1, num);
        while(!pilavacia(&aux2))
        {
            apilar(&aux1, desapilar(&aux2));
        }
    }
    while(!pilavacia(&aux1))
    {
        apilar(&aux2, desapilar(&aux1));
    }
    while(!pilavacia(&aux2))
    {
        apilar(compras, desapilar(&aux2));
    }
}

void iniciarPrecios(int arreglo[rangoPrecios])
{
    for(int i = 0; i < rangoPrecios; i++)
    {
        arreglo[i] = 0;
    }
}

void mostrarArreglo(int arregloCantidad[rangoPrecios], int arregloMonto[rangoPrecios])
{
    for(int i = 0; i < rangoPrecios; i++)
    {
        if(arregloCantidad[i] != 0)
        {
            printf("Compras con valor en el rango de %i digito(s): %i\n", i + 1, arregloCantidad[i]);
            printf("Monto total en el rango de %i digito(s): %i\n", i + 1, arregloMonto[i]);
        }
        else
        {
            printf("No hubo compras en el rango de %i digito(s)\n", i + 1);
        }
    }
}

void cargarArregloPorPrecio(int arregloCantidad[rangoPrecios], Pila *compras, int arregloMontos[rangoPrecios])
{
    int i = rangoPrecios - 1;
    Pila aux1;
    inicpila(&aux1);
    int dato, rangoMinimo;
    while(!pilavacia(compras))
    {
        rangoMinimo= 1 * (int)pow(10, i);
        if(tope(compras) < rangoMinimo)
        {
            i--;
        }
        else
        {
            dato = desapilar(compras);
            apilar(&aux1, dato);
            arregloCantidad[i]++;
            arregloMontos[i] += dato;
        }
    }
    while(!pilavacia(&aux1))
    {
        apilar(compras, desapilar(&aux1));
    }
}

int MayorMontoCompras(int arregloMonto[rangoPrecios])
{
    int mayorMonto = arregloMonto[0];
    int posMayorMonto = 0;
    for(int i = 1; i < rangoPrecios; i++)
    {
        if(mayorMonto < arregloMonto[i])
        {
            mayorMonto = arregloMonto[i];
            posMayorMonto = i;
        }
    }
    return posMayorMonto;
}

float calcularPorcentajeCompras(int arregloCantidad[rangoPrecios], int cantidad)
{
    int opciones;
    do
    {
        printf("Ingresar rango deseado por cantidad de digitos para ver el %% de compras comparadas al total(1 a 6):\n");
        scanf("%i", &opciones);
    }while(opciones > 6 || opciones < 1);

    float porcentaje = (arregloCantidad[opciones - 1]/(float)cantidad) * 100;
    return porcentaje;
}

int estaEnArreglo(char arregloPalabras[][dimPalabras], char palabra[dimPalabras], int validos)
{
    int encontrado = 0;
    for(int i = 0; i < validos; i++)
    {
        if(strcasecmp(palabra, arregloPalabras[i]) == 0)
        {
            encontrado = 1;
        }
    }
    return encontrado;
}

int cargarArregloStrings(char arregloPalabras[filaPalabras][dimPalabras])
{
    char palabra[dimPalabras];
    int continuar = 1;
    int validos = 0;
    while(continuar == 1 && validos < filaPalabras)
    {
        printf("Ingrese el nombre que quiera agregar al arreglo: ");
        scanf(" %s", palabra);
        if(estaEnArreglo(arregloPalabras, palabra, validos))
        {
            printf("ERROR. Este nombre ya esta en el arreglo, ingrese otro nombre.\n");
            continue;
        }
        else
        {
            strcpy(arregloPalabras[validos], palabra);
            validos++;
            printf("Para agregar otro nombre presione 1: ");
            scanf("%i", &continuar);
        }
    }
    return validos;
}

void mostrarPalabras(char arregloPalabras[][dimPalabras], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%s\n", arregloPalabras[i]);
    }
}












