#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void consigna1();

int main()
{
    consigna1();
}

void consigna1()
{
    int valor = 5;
    int *p = &valor;
    int **pp = &p;
    printf("valor de la variable Valor: %d\nDir. de memoria: %p\n", valor, &valor);
    printf("valor del puntero p: %p\nDir. de memoria: %p\n", p, &p);
    printf("valor del puntero pp: %p\nDir. de memoria: %p\n", pp, &pp);
}
