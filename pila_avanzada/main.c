#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    char control = 's';
    int opcion = 0;
    srand(time(NULL));

    while (control == 's'){
        printf("TP 3 - PILAS_Avanzadas\n\n");
        printf("1  -  Ejercicio 1\n");
        printf("2  -  Ejercicio 2\n");
        printf("3  -  Ejercicio 3\n");
        printf("4  -  Ejercicio 4\n");
        printf("5  -  Ejercicio 5\n");
        printf("6  -  Ejercicio 6\n");
        printf("7  -  Ejercicio 7\n");
        printf("8  -  Ejercicio 8\n");
        printf("9  -  Ejercicio 9\n");

        printf("Ingrese opcion numerica\n");
        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");

        switch(opcion)
        {
        case 1:
            printf("Sumar los elementos de una pila (usar variables enteras)\n\n");


            Pila a1, aux1;

            inicpila(&a1);
            inicpila(&aux1);
            int suma_pila1 = 0;
            int total_pila1 = rand()%10 + 3;
            for(int i = 0; i < total_pila1; i++)
            {
                apilar(&a1, rand()%10 + 1);
            }

            while(!pilavacia(&a1))
            {
                suma_pila1 += tope(&a1);
                apilar(&aux1, desapilar(&a1));
            }
            while(!pilavacia(&aux1))
            {
                apilar(&a1, desapilar(&aux1));
            }
            printf("pila a1\n \n");
            mostrar(&a1);
            printf("La suma de todos los numeros en la pila es de: %i \n \n", suma_pila1);
            system("pause");
            system("cls");
            break;

        case 2:
            printf("Contar los elementos de una pila (usar variables enteras)\n\n");
            Pila a2, aux2;
            inicpila(&a2);
            inicpila(&aux2);
            int contador2 = 0;
            int total_pila2 = rand()%10 + 3;
            for(int i = 0; i < total_pila2; i++)
            {
                apilar(&a2, rand()%10 + 1);
            }
            while(!pilavacia(&a2))
            {
                contador2++;
                apilar(&aux2, desapilar(&a2));
            }
            while(!pilavacia(&aux2))
            {
                apilar(&a2, desapilar(&aux2));
            }

            printf("pila a2\n \n");
            mostrar(&a2);
            printf("Hay un total de %i elementos en la pila \n", contador2);
            system("pause");
            system("cls");
            break;

        case 3:
            printf("Calcular el promedio de los valores de una pila (usar variables)\n \n");
            Pila a3, aux3;
            inicpila(&a3);
            inicpila(&aux3);
            float contador3 = 0;
            float suma_pila3 = 0;
            int total_pila3 = rand()%10 + 5;
            for(int i = 0; i < total_pila3; i++)
            {
                apilar(&a3, rand()%10 + 5);
            }

            while(!pilavacia(&a3))
            {
                contador3++;
                suma_pila3 += tope(&a3);
                apilar(&aux3, desapilar(&a3));
            }
            while(!pilavacia(&aux3))
            {
                apilar(&a3, desapilar(&aux3));
            }
            float promedio3 = suma_pila3 / contador3;

            printf("Pila 3: \n");
            mostrar(&a3);
            printf("El promedio de los elementos en pila 3 es de: %.2f \n \n", promedio3);

            system("pause");
            system("cls");
            break;

        case 4:
            printf("Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.\n \n");

            Pila a4, aux4;

            inicpila(&a4);
            inicpila(&aux4);

            int elemento4 = rand()%10 + 3;
            int total_pila4 = rand()%10 + 3;

            for(int i = 0; i < total_pila4; i++)
            {
                apilar(&a4, rand()%10 + 5);
            }
            printf("Elemento: %i \n", elemento4);
            printf("Pila 4: \n");
            mostrar(&a4);
            while(!pilavacia(&a4))
            {
                if(elemento4 == tope(&a4))
                {
                    printf("El elemento esta dentro de la pila \n");
                    break;
                }
                else
                {
                    apilar(&aux4, desapilar(&a4));
                }
            }
            if(pilavacia(&a4))
            {
                printf("No esta el elemento dentro de la pila \n");
            }
            system("pause");
            system("cls");
            break;

        case 5:
            printf("Eliminar un elemento de una pila. Al eliminarlo, finalizar el recorrido y dejar el resto de los elementos de la pila en el mismo orden. \n");

            Pila a5, aux5;

            inicpila(&a5);
            inicpila(&aux5);

            int elemento5 = rand()%5;
            int total_pila5 = rand()%5 + 5;

            for(int i = 0; i < total_pila5; i++)
            {
                apilar(&a5, rand()%5);
            }
            printf("Elemento a buscar: %i \n \n", elemento5);
            printf("Pila 5: \n");
            mostrar(&a5);
            while(!pilavacia(&a5))
            {
                if(elemento5 == tope(&a5))
                {
                    desapilar(&a5);
                    break;
                }
                else
                {
                    apilar(&aux5, desapilar(&a5));
                }
            }
            while(!pilavacia(&aux5))
            {
                apilar(&a5, desapilar(&aux5));
            }
            printf("Pila 5 sin el primer elemento encontrado: \n");
            mostrar(&a5);

            system("pause");
            system("cls");
            break;

        case 6:
            printf("Verificar si una pila DADA es capicua \n \n");
            Pila a6, aux6;
            inicpila(&a6);
            inicpila(&aux6);
            int tope6 = 0;
            int base6 = 0;
            int total_pila6 = rand()%5 + 5;
            for(int i = 0; i < total_pila6; i++)
            {
                apilar(&a6, rand()%5);
            }
            printf("Pila dada: \n \n");
            mostrar(&a6);
            tope6 = tope(&a6);
            while(!pilavacia(&a6))
            {
                apilar(&aux6, desapilar(&a6));
            }
            base6 = tope(&aux6);
            if(tope6 == base6)
            {
                printf("La pila dada es capicua \n");
            }
            else
            {
                printf("La pila dada no es capicua \n");
            }
            system("pause");
            system("cls");
            break;

        case 7:
            printf("Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión");

            Pila a7, b7, c7, auxb7, auxc7, aux7;
            inicpila(&a7);
            inicpila(&b7);
            inicpila(&c7);
            inicpila(&aux7);
            inicpila(&auxb7);
            inicpila(&auxc7);

            int total_pila7 = 8;

            for(int i = 0; i < total_pila7; i++)
            {
                apilar(&a7, rand()% 8);
                apilar(&b7, rand()% 8 + 5);
            }
            mostrar(&a7);
            mostrar(&b7);

            while(!pilavacia(&a7))
            {
                apilar(&aux7, desapilar(&a7));
                while(!pilavacia(&a7))
                {
                    if(tope(&a7) == tope(&aux7))
                    {
                        desapilar(&a7);
                    }
                    else
                    {
                        apilar(&auxc7, desapilar(&a7));
                    }
                }
                while(!pilavacia(&auxc7))
                {
                    apilar(&a7, desapilar(&auxc7));
                }
            }
            while(!pilavacia(&aux7))
            {
                apilar(&a7, desapilar(&aux7));
            }

            while(!pilavacia(&b7))
            {
                apilar(&auxb7, desapilar(&b7));
                while(!pilavacia(&b7))
                {
                    if(tope(&auxb7) == tope(&b7))
                    {
                        desapilar(&b7);
                    }
                    else
                    {
                        apilar(&auxc7, desapilar(&b7));
                    }
                }
                while(!pilavacia(&auxc7))
                {
                    apilar(&b7, desapilar(&auxc7));
                }
            }
            while(!pilavacia(&auxb7))
            {
                apilar(&b7, desapilar(&auxb7));
            }

            while(!pilavacia(&a7))
            {
                apilar(&auxc7, desapilar(&a7));
                while(!pilavacia(&b7))
                {
                    if(tope(&b7) == tope(&auxc7))
                    {
                        desapilar(&b7);
                    }
                    else
                    {
                        apilar(&auxb7, desapilar(&b7));
                    }
                }
                while(!pilavacia(&auxb7))
                {
                    apilar(&b7, desapilar(&auxb7));
                }
            }
            while(!pilavacia(&auxc7))
            {
                apilar(&c7, desapilar(&auxc7));
            }
            while(!pilavacia(&b7))
            {
                apilar(&auxb7, desapilar(&b7));
            }
            while(!pilavacia(&auxb7))
            {
                apilar(&c7, desapilar(&auxb7));
            }
            mostrar(&c7);
            system("pause");
            system("cls");
            break;



        case 8:
            printf("Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL)");

            Pila ordenada1, ordenada2, ordenadafinal, auxordenada;
            inicpila(&ordenada1);
            inicpila(&ordenada2);
            inicpila(&ordenadafinal);
            inicpila(&auxordenada);
            for(int i = 0; i < 6; i+=2)
            {
                apilar(&ordenada1, i);
                apilar(&ordenada2, i + 1);
            }
            printf("Ordenada \n");
            mostrar(&ordenada1);
            printf("Ordenada 2 \n");
            mostrar(&ordenada2);

            while(!pilavacia(&ordenada1) && !pilavacia(&ordenada2))
            {
                if(tope(&ordenada1) >= tope(&ordenada2))
                {
                    apilar(&auxordenada, desapilar(&ordenada1));
                }
                else
                {
                    apilar(&auxordenada, desapilar(&ordenada2));
                }
            }
            while(!pilavacia(&auxordenada))
            {
                apilar(&ordenadafinal, desapilar(&auxordenada));
            }
            printf("Ordenada final \n");
            mostrar(&ordenadafinal);

            system("pause");
            system("cls");
            break;

        case 9:
           printf("Ejercicio 9 \n \n");

           Pila mazo, jugador1, jugador2, puntosjug1, puntosjug2, auxjug1, auxjug2;
           inicpila(&mazo);
           inicpila(&jugador1);
           inicpila(&jugador2);
           inicpila(&puntosjug1);
           inicpila(&puntosjug2);
           inicpila(&auxjug1);
           inicpila(&auxjug2);
           int suma_jug1 = 0;
           int suma_jug2 = 0;
           for(int i = 0; i < 20; i++)
           {
               apilar(&mazo, rand()%100);
           }
           int puntos1 = 0;
           int puntos2 = 0;
           while(!pilavacia(&mazo))
           {
               apilar(&jugador1, desapilar(&mazo));
               apilar(&jugador2, desapilar(&mazo));
               apilar(&jugador1, desapilar(&mazo));
               apilar(&jugador2, desapilar(&mazo));

               while(!pilavacia(&jugador1))
               {
                   suma_jug1 += tope(&jugador1);
                   apilar(&auxjug1, desapilar(&jugador1));
               }
               while(!pilavacia(&jugador2))
               {
                   suma_jug2+= tope(&jugador2);
                   apilar(&auxjug2, desapilar(&jugador2));
               }
               if(suma_jug2 > suma_jug1)
               {


                   puntos2 += suma_jug1 + suma_jug2;
                   while(!pilavacia(&auxjug1) && !pilavacia(&auxjug2))
                   {
                       apilar(&puntosjug2, desapilar(&auxjug2));
                       apilar(&puntosjug2, desapilar(&auxjug1));
                   }
               }
               else
               {
                   puntos1 += suma_jug1 + suma_jug2;
                   while(!pilavacia(&auxjug1) && !pilavacia(&auxjug2))
                   {
                       apilar(&puntosjug1, desapilar(&auxjug2));
                       apilar(&puntosjug1, desapilar(&auxjug1));
                   }
               }

               suma_jug1 = 0;
               suma_jug2 = 0;
           }
        printf("Jugador 1: \n");
        mostrar(&puntosjug1);
        printf("Jugador 2: \n");
        mostrar(&puntosjug2);
        if(puntos1 > puntos2)
        {
            printf("Gana el jugador 1 con %i puntos \n", puntos1);
        }
        else if(puntos2 > puntos1)
        {
            printf("Gana el jugador 2 con %i puntos \n", puntos2);
        }
        else
        {
            printf("Es un empate \n");
        }
        system("pause");
        system("cls");
        break;

        }
        printf("Desea probar otro ejercicio? (s/n) ");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }

    printf("Hasta el proximo TP!\n");
    return 0;

}
