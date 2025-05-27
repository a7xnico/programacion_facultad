#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dimPalabra 30

void consigna1();
int cantidadParArreglo(int a[], int dim);
int cargarArregloDinamico(int a[], int dim, int* arrDinamico);
void mostrarArreglo(int a[], int val);
int* crearArregloDinamico(int a[], int dim, int numPares);
int crearYcargarArreglo(int a[], int dim, int** arrDinamico);

typedef struct
{
    int legajo;
    char nombreYapellido [dimPalabra];
    int edad;
    int anio;
    /**año que cursa, recordar que no podemos utilizar la ñ para definir variables*/
} stAlumno;

int cantidadRegistrosAlumnos(char nombreArchivo[]);
int cargarAlumnos(stAlumno a[], char nombreArchivo[]);
void mostrarAlumno(stAlumno a);
void mostrarArregloAlumnos(stAlumno alumnos[], int validos);
stAlumno* crearYcargarAlumnos(char nombreArchivo[], int cantidadAlumnos);
int crearArregloAlumnos(char nombreArchivo[], stAlumno** arrAlumnos, int cantidadAlumnos);
stAlumno* realocarAlumnos(stAlumno alumnos[], int validos, int nuevosValidos);

int main()
{
    //consigna1();
    int dim = 10;
    int arregloCargado[] = {1,2,3,4,5,10,7,9,12,16};
    int* arregloDinamico;
    /** 2.A
    int numPares = cantidadParArreglo(arregloCargado, dim);
    arregloDinamico = malloc(numPares * sizeof(int));
    int valDinamico = cargarArregloDinamico(arregloCargado, dim, arregloDinamico);
    mostrarArreglo(arregloDinamico, valDinamico);*/
    /**2.B
    int numPares = cantidadParArreglo(arregloCargado, dim);
    arregloDinamico = crearArregloDinamico(arregloCargado, dim, numPares);
    mostrarArreglo(arregloDinamico, numPares);*/
    /**2.C
    int valDinamico = crearYcargarArreglo(arregloCargado, dim, &arregloDinamico);
    mostrarArreglo(arregloDinamico, valDinamico);*/

    char nombreArchivo[] = "alumnos.bin";
    int cantidadAlumnos = cantidadRegistrosAlumnos(nombreArchivo);
    /** 3.A
    stAlumno* arregloAlumnos;
    arregloAlumnos = malloc(cantidadAlumnos * sizeof(stAlumno));
    int alumnosValidos = cargarAlumnos(arregloAlumnos, nombreArchivo);
    mostrarArregloAlumnos(arregloAlumnos, alumnosValidos);*/

    /** 3.B
    stAlumno* arrAlumnos2;
    arrAlumnos2 = crearYcargarAlumnos(nombreArchivo, cantidadAlumnos);
    mostrarArregloAlumnos(arrAlumnos2, cantidadAlumnos);*/


    stAlumno* arrAlumnos3;
    int valAlumnos = crearArregloAlumnos(nombreArchivo, &arrAlumnos3, cantidadAlumnos);
    mostrarArregloAlumnos(arrAlumnos3, valAlumnos);

    stAlumno* nuevosAlumnos;
    int nuevaCantidad;
    printf("Ingrese la dimension que quiera del nuevo arreglo de alumnos: ");
    do
    {
        scanf("%d", &nuevaCantidad);
    }while(nuevaCantidad >= cantidadAlumnos);
    nuevosAlumnos = realocarAlumnos(arrAlumnos3, valAlumnos, nuevaCantidad);
    mostrarArregloAlumnos(nuevosAlumnos, nuevaCantidad);


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

int cantidadParArreglo(int a[], int dim)
{
    int cantidad = 0;
    for(int i = 0; i < dim; i++)
        if(a[i] % 2 == 0)
            cantidad++;
    return cantidad;
}

int cargarArregloDinamico(int a[], int dim, int* arrDinamico)
{
    int j = 0;
    for(int i = 0; i < dim; i++)
    {
        if(a[i] % 2 == 0)
        {
            arrDinamico[j] = a[i];
            j++;
        }
    }
    return j;
}

void mostrarArreglo(int a[], int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%d| ", a[i]);
    }
}

int* crearArregloDinamico(int a[], int dim, int numPares)
{
    int* arrDinamico;
    arrDinamico = malloc(numPares*sizeof(int));
    int j = 0;
    for(int i = 0; i < dim; i++)
    {
        if(a[i] % 2 == 0)
        {
            arrDinamico[j] = a[i];
            j++;
        }
    }
    return arrDinamico;
}

int crearYcargarArreglo(int a[], int dim, int** arrDinamico)
{
    int numPares = cantidadParArreglo(a, dim);
    *arrDinamico = malloc(numPares*sizeof(int));
    int j = 0;
    for(int i = 0; i < dim; i++)
    {
        if(a[i] % 2 == 0)
        {
            (*arrDinamico)[j] = a[i];
            j++;
        }
    }
    return j;
}

int cantidadRegistrosAlumnos(char nombreArchivo[])
{
    int registros = 0;
    long int bytes = 0;
    FILE *fp;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        fseek(fp, 0, SEEK_END);
        bytes = ftell(fp);
        registros = bytes / sizeof(stAlumno);
        fclose(fp);
    }
    else
        printf("\nError: No pudo abrirse el archivo.\n");
    return registros;
}

int cargarAlumnos(stAlumno a[], char nombreArchivo[])
{
    FILE* fp;
    stAlumno alumno;
    int i = 0;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        while(fread(&alumno, sizeof(stAlumno), 1, fp) > 0)
        {
            a[i] = alumno;
            i++;
        }
        fclose(fp);
    }
    else
    {
        printf("\nERROR: No pudo abrirse el archivo.");
    }
    return i;
}

void mostrarAlumno(stAlumno a)
{
    printf("=============LEGAJO: %d\n", a.legajo);
    printf("NOMBRE Y APELLIDO: %s\n", a.nombreYapellido);
    printf("=============EDAD: %d\n", a.edad);
    printf("=====ANIO CURSADO: %d\n", a.anio);
}

void mostrarArregloAlumnos(stAlumno alumnos[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("\n===========ALUMNO N%d==========\n", i+1);
        mostrarAlumno(alumnos[i]);
    }
    printf("\n===============================\n");
}

stAlumno* crearYcargarAlumnos(char nombreArchivo[], int cantidadAlumnos)
{
    stAlumno* arregloAlumnos;
    arregloAlumnos = malloc(cantidadAlumnos*sizeof(stAlumno));
    FILE* fp;
    stAlumno alumno;
    int i = 0;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        while(fread(&alumno, sizeof(stAlumno), 1, fp)>0)
        {
            arregloAlumnos[i] = alumno;
            i++;
        }
        fclose(fp);
    }
    else
    {
        printf("\nERROR: No pudo abrirse el archivo.");
    }
    return arregloAlumnos;
}

int crearArregloAlumnos(char nombreArchivo[], stAlumno** arrAlumnos, int cantidadAlumnos)
{
    *arrAlumnos = malloc(cantidadAlumnos*sizeof(stAlumno));
    FILE* fp;
    fp = fopen(nombreArchivo, "rb");
    int i = 0;
    if(fp)
    {
        stAlumno a;
        while(fread(&a, sizeof(stAlumno), 1, fp) > 0)
        {
            (*arrAlumnos)[i] = a;
            i++;
        }
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.");
    return i;

}

stAlumno* realocarAlumnos(stAlumno alumnos[], int validos, int nuevosValidos)
{
    stAlumno* nuevosAlumnos;
    nuevosAlumnos = realloc(alumnos, nuevosValidos*sizeof(stAlumno));
    return nuevosAlumnos;
}

