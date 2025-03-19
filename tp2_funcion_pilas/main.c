#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pila.h"

void crear_pila(Pila* p);

void mover_elementos(Pila* inicial, Pila* objetivo);

void mover_en_orden(Pila* inicial, Pila* objetivo, Pila* auxiliar);

void eliminar_menor_numero(Pila* a, Pila* auxiliar, Pila* basura, int* menor);

void pila_ordenada(Pila* a, Pila* auxiliar, Pila* ordenada, int* menor);

void insertar_pila(Pila* a, Pila* aux, Pila* num_a_insertar);

void ordenada_insercion(Pila* a, Pila* aux, Pila* num_a_insertar);

int suma_tope_anterior(Pila* origen, Pila* auxiliar);

void promedio_pila(Pila* inicial, Pila* aux, float *promedio);

int suma_elementos_pila(Pila* inicial);

int numero_elementos();

float division_pila(int suma, int elementos);

int pasar_decimal(Pila *inicial, Pila *aux);

void mostrar_pila(Pila* inicial, Pila* aux);

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
        printf("7 - Funcion que inserta una pila a otra para crear una nueva ordenada\n");
        printf("8 - Funcion que suma el tope y su anterior de una pila\n");
        printf("9 - Calcular el promedio de una pila\n");
        printf("10 - Transformar numeros de la pila en un decimal\n");
        printf("11 - Mostrar los elementos de la pila sin la funcion default\n");
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
            Pila origen6, auxiliar6, num_apilar6;
            inicpila(&origen6);
            inicpila(&auxiliar6);
            inicpila(&num_apilar6);
            printf("Cree la pila ordenada de menor a mayor\n");
            crear_pila(&origen6);
            printf("Ingrese el numero que quiera insertar: ");
            scanf("%i", &num6);
            apilar(&num_apilar6, num6);
            insertar_pila(&origen6, &auxiliar6, &num_apilar6);
            mostrar(&origen6);
            system("pause");
            system("cls");
            break;

        case 7:;
            Pila origen7, aux7, objetivo7;
            inicpila(&origen7);
            inicpila(&aux7);
            inicpila(&objetivo7);
            crear_pila(&origen7);
            mostrar(&origen7);
            ordenada_insercion(&objetivo7, &aux7, &origen7);
            mostrar(&objetivo7);
            mostrar(&aux7);
            system("pause");
            system("cls");
            break;

        case 8:;
            int suma;
            Pila origen8, aux8;
            inicpila(&origen8);
            inicpila(&aux8);
            crear_pila(&origen8);
            suma = suma_tope_anterior(&origen8, &aux8);
            printf("La suma del tope y su anterior es: %i\n", suma);
            system("pause");
            system("cls");
            break;
        case 9:;
            Pila origen9, aux9;
            float promedio9;
            inicpila(&origen9);
            inicpila(&aux9);
            crear_pila(&origen9);
            promedio_pila(&origen9, &aux9, &promedio9);
            printf("El promedio de los numeros en la pila es de: %.2f", promedio9);
            system("pause");
            system("cls");
            break;

        case 10:;
            Pila origen10, aux10;
            int suma10= 0;
            inicpila(&origen10);
            inicpila(&aux10);
            printf("Ingresar numeros de 1 digito\n");
            crear_pila(&origen10);
            mostrar(&origen10);
            suma10 = pasar_decimal(&origen10, &aux10);
            printf("La pila en decimal es: %i\n", suma10);
            system("pause");
            system("cls");
            break;
        case 11:;
            Pila origen11, aux11;
            inicpila(&origen11);
            inicpila(&aux11);
            crear_pila(&origen11);
            mostrar_pila(&origen11, &aux11);
            system("pause");
            system("cls");
            break;


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

void insertar_pila(Pila *a, Pila *aux, Pila *num_a_insertar)
{
    while(!pilavacia(a))
    {
        if(tope(num_a_insertar) < tope(a))
        {
            apilar(aux, desapilar(a));
        }
        else
        {
            apilar(a, desapilar(num_a_insertar));
            while(!pilavacia(aux))
            {
                apilar(a, desapilar(aux));
            }

        }
        if(pilavacia(num_a_insertar))
        {
            break;
        }
    }

}

void ordenada_insercion(Pila *a, Pila *aux, Pila *num_a_insertar)
{
    while(!pilavacia(num_a_insertar))
    {
        if(pilavacia(a))
        {
            apilar(a, desapilar(num_a_insertar));
        }
        else
        {
            insertar_pila(a, aux, num_a_insertar);
        }
    }
}

int suma_tope_anterior(Pila* origen, Pila* auxiliar)
{
    apilar(auxiliar, desapilar(origen));
    int suma = tope(origen) + tope(auxiliar);
    apilar(origen, desapilar(auxiliar));
    return suma;
}

void promedio_pila(Pila* inicial, Pila* aux, float* promedio)
{
    int suma = 0, elementos= 0;
    while(!pilavacia(inicial))
    {
        suma += suma_elementos_pila(inicial);
        elementos += numero_elementos();
        apilar(aux, desapilar(inicial));
    }
    while(!pilavacia(aux))
    {
        apilar(inicial, desapilar(aux));
    }
    *promedio = division_pila(suma, elementos);
}

int suma_elementos_pila(Pila* inicial)
{
    int suma = tope(inicial);
    return suma;
}

int numero_elementos()
{
    int counter= 0;
    return counter + 1;
}

float division_pila(int suma, int elementos)
{
    float resultado = (float) suma / elementos;
    return resultado;
}

int pasar_decimal(Pila *inicial, Pila *aux)
{
    int suma;
    int counter = 0;
    while(!pilavacia(inicial))
    {
        suma += tope(inicial) * pow(10, counter);
        apilar(aux, desapilar(inicial));
        counter++;
    }
    while(!pilavacia(aux))
    {
        apilar(inicial, desapilar(aux));
    }
    return suma;
}


void mostrar_pila(Pila* inicial, Pila* aux)
{
    int num;
    while(!pilavacia(inicial))
    {
        apilar(aux, desapilar(inicial));
    }
    while(!pilavacia(aux))
    {
        num = tope(aux);
        printf("| %i ", num);
        apilar(inicial, desapilar(aux));
    }
    printf("\n");
}
