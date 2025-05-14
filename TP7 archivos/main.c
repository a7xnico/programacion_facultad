#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dimPalabra 30

typedef struct
{
    int legajo;
    char nombreYapellido [dimPalabra];
    int edad;
    int anio;
    /**año que cursa, recordar que no podemos utilizar la ñ para definir variables*/
} stAlumno;

void agregarElemento(char archivo[]);

void agregarEnteros(char nombreArchivo[dimPalabra]);

void mostrarNumero(int a);

void mostrarNumeros(char nombreArchivo[]);

int contarRegistros(char nombreArchivo[]);

stAlumno cargarAlumno();

void cargarAlumnos(char nombreArchivo[]);

void mostrarAlumno(stAlumno a);

void mostrarAlumnos(char nombreArchivo[]);

int main()
{
    ///char archivoNumeros[dimPalabra] = "numeros.bin";
    /**agregarEnteros(archivo);
    agregarElemento(archivoNumeros);
    mostrarNumeros(archivoNumeros);
    int cantidadElementos = contarRegistros(archivoNumeros);
    printf("El archivo tiene un total de %d registros\n", cantidadElementos);*/

    char archivoAlumnos[] = "alumnos.bin";
    cargarAlumnos(archivoAlumnos);
    mostrarAlumnos(archivoAlumnos);

}

void agregarElemento(char archivo[])
{
    int num;
    printf("Ingrese el numero que quiera agregar al archivo: ");
    scanf("%d", &num);
    FILE *archi;
    archi = fopen(archivo, "ab");
    if(archi != NULL)
    {
        fwrite(&num, sizeof(int), 1, archi);
        fclose(archi);
    }
    else
        printf("\nERROR no pudo abrirse el archivo");
}

void agregarEnteros(char archivo[])
{
    int a;
    char seguir = 's';
    FILE *archi;
    archi = fopen(archivo, "ab");
    if(archi != NULL)
    {

        printf("\nQueres cargar numeros enteros? (s/n): ");
        fflush(stdin);
        scanf(" %c", &seguir);
        while(seguir == 's' || seguir == 'S')
        {
            puts("\n==============================================");
            printf("\nIngrese un numero al archivo: ");
            scanf("%d", &a);
            fflush(stdin);
            puts("\n==============================================");
            fwrite(&a, sizeof(int), 1, archi);

            printf("\nQuiere seguir cargando enteros? (s/n): ");
            scanf(" %c", &seguir);
        }
        fclose(archi);
    }
    else
        printf("\nERROR: No se pudo abrir el archivo.");
}

void mostrarNumero(int a)
{
    puts("\n----------------");
    printf("\n%d", a);
    puts("\n----------------");
}

void mostrarNumeros(char nombreArchivo[])
{
    FILE *archi;
    int a;
    archi = fopen(nombreArchivo, "rb");
    int i = 0;
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&a, sizeof(int), 1, archi);
            if(!feof(archi))
            {
                printf("\nEntero numero %d", i++);
                mostrarNumero(a);
            }
        }
        fclose(archi);
    }
    else
        printf("\nNo se pudo abrir el archivo.");
}

int contarRegistros(char nombreArchivo[])
{
    FILE *archi;
    int cant = 0;
    int temp;
    archi = fopen(nombreArchivo, "rb");
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&temp, sizeof(int), 1, archi);
            if(!feof(archi))
                cant++;
        }
        fclose(archi);
    }
    else
        printf("\nERROR: No se pudo abrir el archivo.");
    return cant;
}

stAlumno cargarAlumno()
{
    stAlumno a;
    printf("Ingrese el legajo del alumno: ");
    scanf("%d", &a.legajo);

    while (getchar() != '\n');

    printf("Ingrese nombre y apellido del alumno: ");
    fgets(a.nombreYapellido, sizeof(a.nombreYapellido), stdin);
    a.nombreYapellido[strcspn(a.nombreYapellido, "\n")] = 0;

    printf("Ingrese la edad del alumno: ");
    scanf("%d", &a.edad);
    while (getchar() != '\n');

    printf("Ingrese el anio de cursada del alumno: ");
    scanf("%d", &a.anio);
    while (getchar() != '\n');

    return a;
}

void cargarAlumnos(char nombreArchivo[])
{
    FILE *fp = fopen(nombreArchivo, "rb");
    stAlumno a;

    if(fp)
    {
        printf("Este archivo ya existe\n");
        fclose(fp);
    }
    else
    {
        fp = fopen(nombreArchivo, "wb");
        if(fp != NULL)
        {
            for(int i = 0; i < 5; i++)
            {
                printf("\n==========ALUMNO N%d==========\n", i + 1);
                a = cargarAlumno();
                puts("\n==================================\n");
                fwrite(&a, sizeof(stAlumno), 1, fp);
            }
            fclose(fp);
        }
        else
            printf("\nERROR: No pudo crearse el archivo.\n");
    }

}

void mostrarAlumno(stAlumno a)
{
    printf("     LEGAJO: %d\n", a.legajo);
    printf("NOMBRE Y APELLIDO: %s\n", a.nombreYapellido);
    printf("     EDAD: %d\n", a.edad);
    printf("     ANIO CURSADO: %d\n", a.anio);
}

void mostrarAlumnos(char nombreArchivo[])
{
    FILE *fp;
    fp = fopen(nombreArchivo, "rb");
    int counter = 0;
    stAlumno a;
    if(fp)
    {
        while(!feof(fp))
        {
            fread(&a, sizeof(stAlumno), 1, fp);
            if(!feof(fp))
            {
                printf("\n=========Alumno %d==========\n", ++counter);
                mostrarAlumno(a);
                printf("\n============================\n");
            }
        }
        fclose(fp);
    }
    else
        printf("\nERROR: No se pudo abrir el archivo\n");
}









