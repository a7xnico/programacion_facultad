#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    /*
    Pila DADA, AUX1, AUX2;

    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);

    for(int i = 0; i < 5; i++)
    {
        leer(&DADA);
    }
    mostrar(&DADA);
    for(int i = 0; i < 5; i++)
    {
        if(i < 3)
        {
            apilar(&AUX1, desapilar(&DADA));
        }
        else
        {
            apilar(&AUX2, desapilar(&DADA));
        }
    }
    mostrar(&DADA);
    mostrar(&AUX1);
    mostrar(&AUX2);

    */

    /*
    Pila origen, destino;
    int seguir;

    inicpila(&origen);
    inicpila(&destino);

    do
    {
        leer(&origen);
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%i", &seguir);
    }
    while(seguir == 1);

    mostrar(&origen);
    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }
    mostrar(&origen);
    mostrar(&destino);

    */
    /*
    Pila dada, distintos;
    int verificacion;

    inicpila(&dada);
    inicpila(&distintos);

    do
    {
        leer(&dada);
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%i", &verificacion);
    }
    while(verificacion == 1);

    while(!pilavacia(&dada))
    {
        if(8 != tope(&dada))
        {
            apilar(&distintos, desapilar(&dada));
        }
        else
        {
            desapilar(&dada);
        }
    }

    mostrar(&distintos);
    */
    /*
    Pila origen, destino, aux;
    int seguir;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    do
    {
        leer(&origen);
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%i", &seguir);
    }
    while(seguir == 1);
    mostrar(&origen);
    while(!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }
    while(!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }
    mostrar(&destino);
    */
    /*
    Pila dada, aux1, aux2;
    int seguir;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    do
    {
        leer(&dada);
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%i", &seguir);
    }
    while(seguir == 1);
    mostrar(&dada);
    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }
    while(!pilavacia(&aux1))
    {
        apilar(&aux2, desapilar(&aux1));
    }
    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }
    mostrar(&dada);
    */
    /*
    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    int seguir;
    do
    {
        leer(&dada);
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%i", &seguir);
    }
    while(seguir == 1);
    mostrar(&dada);
    apilar(&aux2, desapilar(&dada));
    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }
    apilar(&dada, desapilar(&aux2));
    while(!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }
    mostrar(&dada);
    */
    /*
    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    int seguir;
    do
    {
        leer(&dada);
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%i", &seguir);
    }
    while(seguir == 1);
    mostrar(&dada);
    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }
    apilar(&aux2, desapilar(&aux1));
    while(!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }
    apilar(&dada, desapilar(&aux2));
    mostrar(&dada);

    */
    /*
    Pila mazo, jugador1, jugador2;
    int seguir;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    do
    {
        leer(&mazo);
        printf("Presione 1 para ingresar otro numero: ");
        scanf("%i", &seguir);
    }
    while(seguir == 1);
    while(!pilavacia(&mazo))
    {
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
    }
    mostrar(&jugador1);
    mostrar(&jugador2);
    */
    /*
    Pila pila_a, pila_b;

    inicpila(&pila_a);
    inicpila(&pila_b);

    for(int i = 0; i < 3; i++)
    {
        apilar(&pila_a, i);
        apilar(&pila_b, i);
        apilar(&pila_b, (i + 5));
    }
    mostrar(&pila_a);
    mostrar(&pila_b);

    while((!pilavacia(&pila_a)) && (!pilavacia(&pila_b)))
    {
        desapilar(&pila_a);
        desapilar(&pila_b);

        if(pilavacia(&pila_a))
        {
            printf("la pila b es mayor a la pila a");
        }
        else if(pilavacia(&pila_b))
        {
            printf("la pila a es mayor a la pila b");
        }
    }

    mostrar(&pila_a);
    mostrar(&pila_b);
    */
    /*
    Pila pila_a, pila_b;

    inicpila(&pila_a);
    inicpila(&pila_b);

    for(int i = 1; i < 6; i++)
    {
        apilar(&pila_a, i);
        apilar(&pila_b, i);
    }
    mostrar(&pila_a);
    mostrar(&pila_b);
    while(!pilavacia(&pila_a) && !pilavacia(&pila_b))
    {
        if(tope(&pila_a) != tope(&pila_b))
        {
            printf("Los elementos en las pilas no son completamente iguales");
            break;
        }
        desapilar(&pila_a);
        desapilar(&pila_b);
        if(pilavacia(&pila_a) && pilavacia(&pila_b))
        {
            printf("pila a y pila b son completamente iguales");
        }
        else if(pilavacia(&pila_a))
        {
            printf("estas pilas no tienen la misma cantidad de elementos");
        }
        else if(pilavacia(&pila_b))
        {
            printf("estas pilas no tienen la misma cantidad de elementos");
        }

    }
    */

    /*
    Pila dada, modelo,aux;

    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux);

    apilar(&modelo, rand()%4);

    for(int i = 0; i < 5; i++)
    {
        apilar(&dada, rand()%4);
    }

    mostrar(&modelo);
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        if(tope(&modelo) == tope(&dada))
        {
            desapilar(&dada);
        }
        else
        {
            apilar(&aux, desapilar(&dada));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }
    mostrar(&dada);
    */
    /*
    Pila modelo, dada, aux;

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux);

    int num_modelo = rand()%3 + 1;

    for(int i = 0; i < num_modelo; i++)
    {
        apilar(&modelo, rand()%5);
    }
    for(int i = 0; i < 6; i++)
    {
        apilar(&dada, rand()%5);
    }
    printf("Modelo: \n");
    mostrar(&modelo);
    printf("dada: \n");
    mostrar(&dada);

    while(!pilavacia(&modelo))
    {
        while(!pilavacia(&dada))
        {
            if(tope(&modelo) == tope(&dada))
            {
                desapilar(&dada);
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }
        desapilar(&modelo);
        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }
    }
    printf("Dada sin numeros de modelo: \n");
    mostrar(&dada);
    */
    /*
    Pila limite, dada, mayores, menores;

    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);

    apilar(&limite, rand()%5 + 5);

    for(int i = 0; i < 8; i++)
    {
        apilar(&dada, rand()%10);
    }
    printf("Limite: \n");
    mostrar(&limite);
    printf("pila dada: \n");
    mostrar(&dada);
    while(!pilavacia(&dada))
    {
        if(tope(&limite) > tope(&dada))
        {
            apilar(&menores, desapilar(&dada));
        }
        else
        {
            apilar(&mayores, desapilar(&dada));
        }
    }
    printf("Menores: \n");
    mostrar(&menores);
    printf("Mayores: \n");
    mostrar(&mayores);
    */

    Pila dada14, aux14, par, impar;
    inicpila(&dada14);
    inicpila(&aux14);
    inicpila(&par);
    inicpila(&impar);
    char control;
    printf("Cargando pila DADA\n");
    do{
        leer(&dada14);
        printf("Desea continuar cargando elementos a la pila? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }while(control == 's');

    printf("\nPila DADA:\n");
    mostrar(&dada14);

    while(!pilavacia(&dada14)){
        apilar(&aux14, desapilar(&dada14));
        if(!pilavacia(&dada14)){
        apilar(&aux14, desapilar(&dada14));
        }else{
            apilar(&impar, desapilar(&aux14));
            }
        }

    if(!pilavacia(&impar)){
        printf("\nLa pila DADA tiene una cantidad de elementos impar\n");
        mostrar(&impar);
    }else{
        apilar(&par, desapilar(&aux14));
        printf("\nLa pila DADA tiene una cantidada de elementos par\n");
        mostrar(&par);
        }











    }







