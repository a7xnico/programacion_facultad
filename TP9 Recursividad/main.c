#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int potencia(int x, int exp);

void mostrarArreglo(int a[], int val, int i);

void mostrarInvertido(int a[], int val, int i);

int capicua(int a[], int val, int i);

int sumaArreglo(int a[], int val, int i);

int main()
{
    int x;
    printf("Ingresar de que numero quiere ver su factorial: ");
    scanf("%d", &x);
    int factx = factorial(x);
    printf("factorial de %d: %d", x, factx);


    int base;
    printf("\nIngrese la base para ver su exponente: ");
    scanf("%d", &base);
    int exp;
    printf("Ingrese el exponente para su base: ");
    scanf("%d", &exp);
    int potX = potencia(base, exp);
    printf("%d elevado a la %d da: %d\n",base, exp, potX);

    int arreglo[] = {5,10,6,2,1,8,7};
    int val = 7;
    printf("Arreglo: \n");
    mostrarArreglo(arreglo, val, 0);

    printf("\nArreglo invertido: \n");
    mostrarInvertido(arreglo, val, 0);

    int arrCapicua[] = {1,3,5,3,1};
    int val2 = 5;
    if(capicua(arreglo, val, 0))
        printf("\nESTE ARREGLO ES CAPICUA.");
    else
        printf("\nEL ARREGLO NO ES CAPICUA.");

    int suma = sumaArreglo(arreglo, val, 0);
    printf("\nLa suma de todos los enteros del arreglo es de : %d", suma);

    int posMenor = posMenorElemento(arreglo, val, 0);
    printf("\nEl menor elemento es %d y esta en la posicion %d del arreglo.",arreglo[posMenor], posMenor);
}

int factorial(int x)
{
    int res = 1;
    if(x > 0)
        res = x * factorial(x-1);
    return res;
}

int potencia(int x, int exp)
{
    int res = 1;
    if(exp > 0)
        res = x * potencia(x, exp-1);
    return res;
}

void mostrarArreglo(int a[], int val, int i)
{
    printf("|%d|", a[i]);
    if(i < val-1)
        mostrarArreglo(a,val,i+1);
}

void mostrarInvertido(int a[], int val, int i)
{
    if(i< val-1)
        mostrarInvertido(a, val, i+1);
    printf("|%d|",a[i]);
}

int capicua(int a[], int val, int i)
{
    int flag = 0;
    if(a[i] == a[val-1-i])
        flag = 1;
    if(i < val/2 && flag == 1)
        flag = capicua(a, val, i+1);
    return flag;
}

int sumaArreglo(int a[], int val, int i)
{
    int suma = a[i];
    if(i < val-1)
        suma += sumaArreglo(a, val, i+1);
    return suma;
}

int posMenorElemento(int a[], int val, int i)
{
    int posMenor = i;
    if(i < val-1)
    {
        int posActual = posMenorElemento(a, val, i+1);
        if(a[posMenor] > a[posActual])
            posMenor = posActual;
    }
    return posMenor;
}

