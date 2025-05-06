#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dimPalabra 30
#define maxLibros 20
#define maxClientes 20
#define maxEmpleados 5

libro cargarLibro();

cliente cargarCliente();

bibliotecario cargarEmpleado();

int cargarLibros(libro libros[], int dim);

int cargarClientes(cliente clientes[], int dim);

int cargarBibliotecarios(bibliotecario empleados[], int dim);





typedef struct{
    char titulo[dimPalabra];
    char autor[dimPalabra];
    char genero[dimPalabra];
    char distribuidora[dimPalabra];
    int anioPublicacion;
} libro;

typedef struct{
    char nombre[dimPalabra];
    int DNI;
    int cantPrestados;
} cliente;

typedef struct{
    char nombre[dimPalabra];
    char genero;
    int edad;
    int DNI;
} bibliotecario;

typedef struct{
    libro libPrestado;
    cliente usuario;
    char fechaPrestamo[dimPalabra];
    char fechaDevolucion[dimPalabra];
} prestamo;


int main()
{
    libro libros[maxLibros];
    cliente clientes[maxClientes];
    bibliotecario empleados[maxEmpleados];
    int cantLibros, cantClientes, cantEmpleados;
    cantLibros = cargarLibros(libros, maxLibros);
    return 0;
}

libro cargarLibro()
{
    libro lib;
    printf("Ingrese el titulo del libro a cargar: ");
    gets(lib.titulo);
    printf("Ingrese el autor del libro: ");
    gets(lib.autor);
    printf("Ingrese el genero al que pertenece: ");
    gets(lib.genero);
    printf("Ingresar la distribuidora que vende este libro: ");
    gets(lib.distribuidora);
    printf("Ingrese el anio de publicacion del libro: ");
    scanf("%i", &lib.anioPublicacion);
    return lib;
}

cliente cargarCliente()
{
    cliente john;
    printf("Ingrese el nombre del cliente: ");
    gets(john.nombre)
    printf("Ingrese el DNI del cliente: ");
    scanf("%i", &john.DNI);
    john.cantPrestados = 0;
    return john;
}

bibliotecario cargarEmpleado()
{
    bibliotecario a;
    printf("Ingrese nombre del empleado: ");
    gets(a.nombre);
    printf("Ingresar genero del empleado: ");
    scanf(" %c", &a.genero);
    printf("Ingresar su DNI: ");
    scanf("%i", &a.DNI);
    printf("Ingrese su edad: ");
    printf("%i", &a.edad);
    return a;
}

int cargarLibros(libro libros[], int dim)
{
    int seguir = 1, i = 0;
    do{
        printf("\n=====Libro N%d=====\n", i + 1);
        libros[i] = cargarLibro();
        printf("\n");
        i++;
        printf("Para cargar otro libro presione 1: ");
        scanf("%d", &seguir);
    }while(seguir == 1 && i < dim);
    return i;
}

int cargarClientes(cliente clientes[], int dim)
{
    int seguir = 1, i = 0;
    do{
        printf("\n=====Cliente N%d=====\n", i + 1);
        clientes[i] = cargarCliente();
        printf("\n");
        i++;
        printf("Para cargar otro cliente presione 1: ");
        scanf("%i", &seguir);
    }while(seguir == 1 && i < dim);
    return i;
}

int cargarBibliotecarios(bibliotecario empleados[], int dim)
{
    int seguir = 1, i = 0;
    do{
        printf("\n=====Empleado N%d=====\n", i + 1);
        empleados[i] = cargarEmpleado();
        printf("\n");
        i++;
        printf("Para cargar otro empleado presione 1: ");
        scanf("%i", &seguir);
    }while(seguir == 1 && i < dim);
    return i;
}
