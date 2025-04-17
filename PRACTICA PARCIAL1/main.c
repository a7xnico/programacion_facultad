#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include <math.h>
const int rangoPrecios = 6;
const int PrecioMaximo = 999999;
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

int main()
{
    int cantidad = 0, monto = 0;
    int CantidadPorRango[rangoPrecios];
    int MontosPorRango[rangoPrecios];
    iniciarPrecios(CantidadPorRango);
    iniciarPrecios(MontosPorRango);
    Pila compras;
    inicpila(&compras);
    cargarPilaCompras(&cantidad, &monto, &compras);
    system("cls");
    mostrar(&compras);
    printf("Cantidad de elementos comprados: %i\nMonto total de los elementos: %i\n\n", cantidad, monto);
    ordenarPorInsercion(&compras);
    printf("Pila tras ser ordenada mediante insercion: \n");
    mostrar(&compras);
    cargarArregloPorPrecio(CantidadPorRango, &compras, MontosPorRango);
    printf("------ Informe por rango de precios ------\n\n");
    mostrarArreglo(CantidadPorRango, MontosPorRango);
    int posMayorMonto = MayorMontoCompras(MontosPorRango);
    printf("\n\nRango de compras con mayor monto acumulado: %i\nMonto acumulado en el rango: %i de %i\n\n", posMayorMonto + 1, MontosPorRango[posMayorMonto], monto);
    float porcentaje = calcularPorcentajeCompras(CantidadPorRango, cantidad);
    printf("El porcentaje de el rango elegido sobre el total es de: %.2f%%", porcentaje);
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


















