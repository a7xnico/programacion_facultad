#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
void crear_pila(Pila *p);

void mover_elementos(Pila *inicial, Pila *objetivo);

void mover_en_orden(Pila *inicial, Pila *objetivo, Pila *auxiliar);

void eliminar_menor_numero(Pila *a, Pila *auxiliar, Pila *basura, int *menor);

void pila_ordenada(Pila *a, Pila *auxiliar, Pila *ordenada, int *menor);

void insertar_pila(Pila *a, Pila *aux);

int main()
{
    int opcion;
    char continuar = 's';
    srand(time(NULL));
    while(continuar == 's')
    {
        printf("TP2 - FUNCIONES CON PILAS\n\n");
        printf("1 - Ingresar todos los elementos deseados a una pila\n");
        printf("2 - Pasar elementos de una pila a otra\n");
        printf("3 - Pasar elementos de una pila a otra en el mismo orden\n");
        printf("4 - Funcion que encuentra el menor numero en una pila lo retorna y lo borra de la pila\n");
        printf("5 - Funcion que ordena una pila de menor a mayor\n");
        printf("6 - Funcion que inserta un numero a una pila ordenada\n");
        printf("Ingrese el numero que usted desee realizar: ");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");

        switch(opcion)
        {
        case 1:;
            Pila pila1;
            inicpila(&pila1);
            crear_pila(&pila1);
            mostrar(&pila1);
            system("pause");
            system("cls");
            break;
        case 2:;
            Pila origen2, final2;
            inicpila(&origen2);
            inicpila(&final2);
            crear_pila(&origen2);
            printf("Pila inicial: ");
            mostrar(&origen2);
            mover_elementos(&origen2, &final2);
            printf("Pila Final: ");
            mostrar(&final2);
            system("pause");
            system("cls");
            break;
        case 3:;
            Pila origen3, destino3, aux3;
            inicpila(&origen3);
            inicpila(&destino3);
            inicpila(&aux3);
            crear_pila(&origen3);
            printf("Pila inicial: ");
            mostrar(&origen3);
            mover_en_orden(&origen3, &destino3, &aux3);
            printf("Pila final: ");
            mostrar(&destino3);
            system("pause");
            system("cls");
            break;
        case 4:;
            int menor4;
            Pila p4, aux4,basura4;
            inicpila(&p4);
            inicpila(&aux4);
            inicpila(&basura4);
            crear_pila(&p4);
            mostrar(&p4);
            eliminar_menor_numero(&p4, &aux4, &basura4, &menor4);
            printf("Menor numero a eliminar: %i", menor4);
            mostrar(&p4);
            system("pause");
            system("cls");
            break;
        case 5:;
            int menor5;
            Pila origen5, ordenada5, auxiliar5;
            inicpila(&origen5);
            inicpila(&ordenada5);
            inicpila(&auxiliar5);
            crear_pila(&origen5);
            mostrar(&origen5);
            pila_ordenada(&origen5, &auxiliar5, &ordenada5, &menor5);
            mostrar(&ordenada5);
            system("pause");
            system("cls");
            break;
        case 6:;
            int num6;
            Pila origen6, auxiliar6;
            inicpila(&origen6);
            inicpila(&auxiliar6);
            printf("Cree la pila ordenada de menor a mayor");
            crear_pila(&origen6);
            printf("Ingrese el numero que quiera insertar: ");
            scanf("%i", &num6);
            insertar_pila(&origen6, &auxiliar6, &num6);
            system("pause");
            system("cls");
            break;

        case 7:;
            Pila origen7, aux7, objetivo7;

        }
    }
}

void crear_pila(Pila *p)
{
    int num_pila = 0;
    char seguir = 's';
    do
    {
        printf("Ingrese elemento a la pila: ");
        scanf("%i", &num_pila);
        apilar(p, num_pila);
        printf("Desea ingresar otro elemento a la pila? (s/n)\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    while(seguir == 's');
}

void mover_elementos(Pila *inicial, Pila *objetivo)
{
    while(!pilavacia(inicial))
    {
        apilar(objetivo, desapilar(inicial));
    }
}

void mover_en_orden(Pila *inicial, Pila *objetivo, Pila *auxiliar)
{

    while(!pilavacia(inicial))
    {
        apilar(auxiliar, desapilar(inicial));
    }
    while(!pilavacia(auxiliar))
    {
        apilar(objetivo, desapilar(auxiliar));
    }

}

void eliminar_menor_numero(Pila *a, Pila *auxiliar, Pila *basura, int *menor)
{
    *menor = tope(a);
    while(!pilavacia(a))
    {
        apilar(auxiliar, desapilar(a));
        if(tope(a) < *menor)
        {
            *menor = tope(a);
        }
    }
    while(!pilavacia(auxiliar))
    {
        if(tope(auxiliar) == *menor)
        {
            apilar(basura, desapilar(auxiliar));
        }
        else
        {
            apilar(a, desapilar(auxiliar));
        }
    }

}

void pila_ordenada(Pila *a, Pila *auxiliar, Pila *ordenada, int *menor)
{
    while(!pilavacia(a))
    {
        eliminar_menor_numero(a, auxiliar, ordenada, menor);
    }
}

void insertar_pila(Pila *a, Pila *aux)
{
    while(!pilavacia(&a))
    {
        if(num < tope(&a))
        {
            apilar(&aux, desapilar(&a));
        }
        else
        {
            apilar(&a, num);
            while(!pilavacia(&aux))
            {
                apilar(&a, desapilar(&aux));
            }
            break;
        }
    }
    mostrar(&a);
}

void ordenada_insercion(Pila a, Pila aux, Pila objetivo)
{

}



