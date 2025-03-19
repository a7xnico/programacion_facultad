#include <stdio.h>
#include <stdlib.h>

int crear_numero_aleatorio();

void calcular_mayor_menor();

int calcular_sumatoria(int a);

void crear_tabla_multiplicar(int a);

int calculadora(int a);

int main()
{
    char control = 's';
    int opcion = 0;
    srand(time(NULL));

    while(control == 's')
    {
        printf("TP1 FUNCIONES VARIABLES SIMPLES\n\n");
        printf("1 - obtener un numero aleatorio entre el 0 y el 100\n");
        printf("2 - recibe 3 numeros enteros, muestra el mayor y el menor\n");
        printf("3 - Obtener la sumatoria de un numero\n");
        printf("4 - tabla de multiplicar de numero a eleccion\n");
        printf("5 - calculadora basica \n");
        printf("\n\n");
        printf("Ingrese el numero deseado: ");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");

        switch(opcion)
        {
        case 1:;
            int numero_aleatorio;
            numero_aleatorio = crear_numero_aleatorio();
            printf("El numero aleatorio que salio entre el 0 y el 100 es: %i\n", numero_aleatorio);
            system("pause");
            system("cls");
            break;
        case 2:
            calcular_mayor_menor();
            system("pause");
            system("cls");
            break;
        case 3:;
            int indice_suma, suma_final;
            printf("De que numero quiere calcular la sumatoria: ");
            scanf("%i", &indice_suma);
            suma_final = calcular_sumatoria(indice_suma);
            printf("La suma de todos los numeros anteriores a %i es: %i\n",indice_suma, suma_final);
            system("pause");
            system("cls");
            break;
        case 4:;
            int multiplicando;
            printf("Ingrese el numero que quiera ver su tabla de multiplicar: ");
            scanf("%i", &multiplicando);
            crear_tabla_multiplicar(multiplicando);
            system("pause");
            system("cls");
            break;
        case 5:;
            int resultado, operacion;
            do
            {
                printf("1 - SUMA\n");
                printf("2 - RESTA\n");
                printf("3 - MULTIPLICACION");
                printf("4 - DIVISION");
                fflush(stdin);
                scanf("%i", &operacion);
            }
            while((operacion <= 4) && (operacion >= 1));









        }
    }
}


int crear_numero_aleatorio()
{
    int num = rand()%101;
    return num;
}

void calcular_mayor_menor()
{
    int num1, num2, num3, mayor, menor;
    printf("Ingrese el primer numero entero: ");
    scanf("%i", &num1);
    printf("Ingrese el segundo numero entero: ");
    scanf("%i", &num2);
    printf("Ingrese el tercer numero entero: ");
    scanf("%i", &num3);

   if(num1 > num2){
       if(num1 > num3){
           mayor = num1;
       }
       else{
           mayor = num3;
       }
   }
   else{
       if(num2 > num3){
        mayor = num2;
       }
       else{
           mayor = num3;
       }
   }

   if(num1 < num2){
        if(num1 < num3){
            menor = num1;
        }
        else{
            menor = num3;
        }
   }
   else{
        if(num2 < num3){
            menor = num2;
        }
        else{
            menor = num3;
        }
   }

   printf("Numero menor: %i\n", menor);
   printf("Numero mayor: %i\n", mayor);

}


int calcular_sumatoria(int a)
{
    int sumatoria = 0;
    for(int i = 0; i < a; i++)
    {
        sumatoria+= i;
    }
    return sumatoria;
}


void crear_tabla_multiplicar(int a)
{
    int producto;
    for(int i = 1; i <= 10; i++)
    {
        producto = a * i;
        printf("%i * %i = %i \n", a, i, producto);
    }
}

int calculadora(int a)
{
    int x, y;
    printf("Ingresar numero x : ");
    scanf("%i", &x);
    printf("Ingresar numero y : ");
    scanf("%i, &x");
    switch(a)
    {
    case 1:

    }
}








