#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int numAlumnos = 20;

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; // m, f, o
} alumno;

alumno cargarAlumno();

int cargarAlumnos(alumno a[], int dim);

void mostrarAlumno(alumno a);

void mostrarAlumnos(alumno a[], int validos);

int encontrarMatricula(alumno a[], int validos, int matriculaBuscada);

int pedirMatricula();

void mostrarPorMatricula(alumno a[], int validos, int matriculaBuscada);

int buscarMenor(alumno a[], int validos, int posActual);

void ordenarSeleccion(alumno a[], int validos);

void intercambio(alumno a[], int posActual, int posMenor);

char pedirGenero();

void mostrarSegunGenero(alumno a[], int validos, char generoDado);

void insertarAlumno(alumno a[], int validos, alumno dato);

void ordenarInsercion(alumno a[], int validos);

int contarSegunGenero(alumno a[], int validos, char generoDado);

int menuPrincipal();


int main()
{
    char seguir = 's';
    alumno alumnos[numAlumnos];
    int validos;
    char generoBuscado;
    int cantGenero;
    int matriculaBuscada;
    do
    {
        int opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
        {
            validos = cargarAlumnos(alumnos, numAlumnos);
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            validos = cargarAlumnos(alumnos, numAlumnos);
            mostrarAlumnos(alumnos, validos);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            validos = cargarAlumnos(alumnos, numAlumnos);
            matriculaBuscada = pedirMatricula();
            mostrarPorMatricula(alumnos, validos, matriculaBuscada);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            validos = cargarAlumnos(alumnos, numAlumnos);
            mostrarAlumnos(alumnos, validos);
            printf("REGISTRO DE ALUMNOS TRAS SER ORDENADOS SEGUN SU MATRICULA: \n\n");
            ordenarSeleccion(alumnos, validos);
            mostrarAlumnos(alumnos, validos);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            validos = cargarAlumnos(alumnos, numAlumnos);
            generoBuscado = pedirGenero();
            mostrarSegunGenero(alumnos, validos, generoBuscado);
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            alumno dato;
            printf("Ingrese los alumnos en orden segun su matricula: \n");
            validos = cargarAlumnos(alumnos, numAlumnos - 1);
            printf("Ingrese otro alumno que quiera insertar: \n");
            dato = cargarAlumno();
            insertarAlumno(alumnos, validos, dato);
            validos++;
            mostrarAlumnos(alumnos, validos);
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            validos = cargarAlumnos(alumnos, numAlumnos);
            mostrarAlumnos(alumnos, validos);
            ordenarInsercion(alumnos, validos);
            printf("ALUMNOS YA ORDENADOS POR EL METODO DE INSERCION \n\n");
            mostrarAlumnos(alumnos, validos);
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            validos = cargarAlumnos(alumnos, numAlumnos);
            generoBuscado = pedirGenero();
            cantGenero = contarSegunGenero(alumnos, validos, generoBuscado);
            printf("Hay un total de %d alumno(s) de genero %c en el registro", cantGenero, generoBuscado);
            system("pause");
            system("cls");
            break;
        }
        default:
            system("cls");
            seguir = 'n';
            break;
        }
        if(seguir == 's')
        {
            printf("Quiere ver otra opcion?(s/n): ");
            scanf(" %c", &seguir);
        }
    }
    while(seguir == 's');
    printf("Gracias por utilizar el programa\n\n");

    return 0;

}

alumno cargarAlumno()
{
    alumno a;
    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &a.matricula);
    printf("Ingrese el nombre del alumno: ");
    scanf(" %s", &a.nombre);
    printf("Ingrese el genero del alumno: ");
    scanf(" %c", &a.genero);
    return a;
}

int cargarAlumnos(alumno a[], int dim)
{
    int i = 0, seguir = 1;
    while(i < dim && seguir == 1)
    {
        a[i] = cargarAlumno();
        i++;
        printf("Para ingresar otro alumno presione 1: ");
        scanf("%d", &seguir);
    }
    return i;
}

void mostrarAlumno(alumno a)
{
    printf("\nMatricula: %d", a.matricula);
    printf("\nNombre: %s", a.nombre);
    printf("\nGenero: %c\n", a.genero);
}

void mostrarAlumnos(alumno a[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("\n===== ALUMNO %d =====\n", i + 1);
        mostrarAlumno(a[i]);
    }
    printf("=====================\n");
}

int encontrarMatricula(alumno a[], int validos, int matriculaBuscada)
{
    for(int i = 0; i < validos; i++)
        if(matriculaBuscada == a[i].matricula)
            return i;
    return -1;
}

int pedirMatricula()
{
    int matricula;
    printf("Ingrese la matricula que quiera buscar: ");
    scanf("%d", &matricula);
    return matricula;
}

void mostrarPorMatricula(alumno a[], int validos, int matriculaBuscada)
{
    int posMatricula = encontrarMatricula(a, validos, matriculaBuscada);
    if(posMatricula == -1)
        printf("La matricula no se encuentra en el registro\n");
    else
    {
        printf("=====ALUMNO BUSCADO=====\n\n");
        mostrarAlumno(a[posMatricula]);
    }
}

int buscarMenor(alumno a[], int validos, int posActual)
{
    int posMenor = posActual;
    int menor = a[posMenor].matricula;
    for(int i = posActual + 1; i < validos; i++)
        if(menor > a[i].matricula)
        {
            menor = a[i].matricula;
            posMenor = i;
        }
    return posMenor;
}

void ordenarSeleccion(alumno a[], int validos)
{
    int posMenor;
    for(int i = 0; i < validos; i++)
    {
        posMenor = buscarMenor(a, validos, i);
        if(posMenor != i)
            intercambio(a, i, posMenor);
    }
}

void intercambio(alumno a[], int posActual, int posMenor)
{
    alumno buffer;
    buffer = a[posMenor];
    a[posMenor] = a[posActual];
    a[posActual] = buffer;
}

char pedirGenero()
{
    char genero;
    do
    {
        printf("Ingresar el genero que quiera buscar(m/f/o):  ");
        scanf(" %c", &genero);
        if(genero != 'm' && genero != 'f' && genero != 'o')
            printf("INGRESE UN GENERO VALIDO (m/f/o)\n");
    }
    while(genero != 'm' && genero != 'f' && genero != 'o');
    return genero;
}

void mostrarSegunGenero(alumno a[], int validos, char generoDado)
{
    for(int i = 0; i < validos; i++)
        if(a[i].genero == generoDado)
        {
            printf("=====================\n");
            mostrarAlumno(a[i]);
        }
    printf("=====================\n");
}

void insertarAlumno(alumno a[], int validos, alumno dato)
{
    int i = validos - 1;
    while(i >= 0 && dato.matricula < a[i].matricula)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = dato;
}

void ordenarInsercion(alumno a[], int validos)
{
    alumno dato;
    for(int i = 1; i < validos; i++)
    {
        dato = a[i];
        insertarAlumno(a, i, dato);
    }
}

int contarSegunGenero(alumno a[], int validos, char generoDado)
{
    int counter = 0;
    for(int i = 0; i < validos; i++)
        if(a[i].genero == generoDado)
            counter++;
    return counter;
}

int menuPrincipal()
{
    int opcion;
    printf("======= MENU PRINCIPAL - TP6 =======\n\n");
    printf("INGRESE EL NUMERO DE LA OPCION QUE QUIERA REALIZAR: \n\n");
    printf("1 - CARGAR ALUMNOS HASTA QUE EL USUARIO DECIDA\n");
    printf("2 - MUESTRA DEL ARREGLO DE ALUMNOS, SE PEDIRA CARGAR UN ARREGLO DE ALUMNOS\n");
    printf("3 - MUESTRA POR PANTALLA UN ALUMNO DEPENDIENDO DE LA MATRICULA BUSCADA\n");
    printf("4 - ORDENAMIENTO POR SELECCION DE LOS ALUMNOS SEGUN SU MATRICULA\n");
    printf("5 - MUESTRA DE TODOS LOS ESTUDIANTES DE UN GENERO CARGADO POR EL USUARIO\n");
    printf("6 - INSERCION DE UN ALUMNO MEDIANTE SU MATRICULA\n");
    printf("7 - ORDENAMIENTO POR INSERCION UTILIZANDO LA FUNCION ANTERIOR \n");
    printf("8 - CONTADOR DE LA CANTIDAD DE ALUMNOS DE UN GENERO DADO POR EL USUARIO \n");
    printf("CUALQUIER OTRO NUMERO PARA FINALIZAR EL PROGRAMA\nOPCION: ");
    scanf("%d", &opcion);
    return opcion;
}












