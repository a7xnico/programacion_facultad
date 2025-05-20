#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
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

void agregarAlumnoArchivo(char nombreArchivo[]);

void legajosAlumnosMayores(Pila *p, char nombreArchivo[]);

int pedirEdad();

int contarAlumnoPorEdad(int edadLimite, char nombreArchivo[]);

void rangosEdad(int *edadMin, int *edadMax);

int estaEnRango(int edadMin, int edadMax, stAlumno a);

void mostrarAlumnosEnRango(int edadMin, int edadMax, char nombreArchivo[]);

void mostrarNombreAlumno(stAlumno a);

stAlumno encontrarAlumnoMayor(stAlumno mayor, stAlumno actual);

void mostrarMayorAlumno(char nombreArchivo[]);

int pedirAnio();

int cantidadAlumnosAnio(int anioBuscado, char nombreArchivo[]);

int cargarArregloAlumnos(stAlumno alumnos[], int dim);

void copiarArregloArchivo(stAlumno alumnos[], char nombreArchivo[], int validos);

int copiarAlumnosAlArreglo(stAlumno totalAlumnos[], char nombreArchivo[], int anioBuscado);

void mostrarArregloAlumnos(stAlumno alumnos[], int validos);

int cantidadRegistrosAlumnos(char nombreArchivo[]);

int cantidadRegistroEntero(char nombreArchivo[]);

void mostrarAlumnoBuscado(char nombreArchivo[], int numeroAlumnoBuscado);

int pedirNumeroAlumno();

void verificacionCantAlumnos(char nombreArchivo[]);

void sobreescribirAlumno(char nombreArchivo[], int numAlumno);

void editarAlumno(char nombreArchivo[], int legajoBuscado);

void intercambiarArchivoEntero(char nombreArchivo[]);

int main()
{
    /*char archivoNumeros[dimPalabra] = "numeros.bin";
    agregarEnteros(archivo);
    agregarElemento(archivoNumeros);
    mostrarNumeros(archivoNumeros);
    int cantidadElementos = contarRegistros(archivoNumeros);
    printf("El archivo tiene un total de %d registros\n", cantidadElementos);*/

    char archivoAlumnos[] = "alumnos.bin";
    cargarAlumnos(archivoAlumnos);
    //agregarAlumnoArchivo(archivoAlumnos);
    mostrarAlumnos(archivoAlumnos);
    //Pila pilita;
    //inicpila(&pilita);
    //legajosAlumnosMayores(&pilita, archivoAlumnos);
    //mostrar(&pilita);
    //int edadMin = 0, edadMax = 0;
    //rangosEdad(&edadMin, &edadMax);
    //printf("EDAD MINIMA: %d\n", edadMin);
    //printf("EDAD MAXIMA: %d\n", edadMax);
    //mostrarAlumnosEnRango(edadMin, edadMax, archivoAlumnos);
    //stAlumno alumnos[10];
    //int validos = cargarArregloAlumnos(alumnos, 10);
    //copiarArregloArchivo(alumnos, archivoAlumnos, validos);
    //mostrarAlumnos(archivoAlumnos);
    //stAlumno totalAlumnosArchivo[30];
    //mostrarMayorAlumno(archivoAlumnos);
    //int anioBuscado = pedirAnio();
    //int cantidad = cantidadAlumnosAnio(anioBuscado, archivoAlumnos);
    //printf("\nHay %d alumnos que cursan ese anio.\n", cantidad);
    //int val = copiarAlumnosAlArreglo(totalAlumnosArchivo, archivoAlumnos, anioBuscado);
    //mostrarArregloAlumnos(totalAlumnosArchivo, val);
    //int cantRegistros = cantidadRegistrosAlumnos(archivoAlumnos);
    //printf("Hay un total de %d registros en el archivo alumnos", cantRegistros);

    //int alumnoBuscado = pedirNumeroAlumno();
    //verificacionCantAlumnos(archivoAlumnos);
    //mostrarAlumnoBuscado(archivoAlumnos, alumnoBuscado);
    //printf("Ingrese el numero del alumno que quiera sobreescribir: \n");
    //int alumnoIntercambiado = pedirNumeroAlumno();
    //sobreescribirAlumno(archivoAlumnos, alumnoIntercambiado);
    intercambiarArchivoEntero(archivoAlumnos);
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

void agregarAlumnoArchivo(char nombreArchivo[])
{
    FILE *fp;
    stAlumno a;
    fp = fopen(nombreArchivo, "ab");
    if(fp)
    {
        printf("=========================\n");
        a = cargarAlumno();
        fwrite(&a, sizeof(stAlumno), 1, fp);
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.\n");
}

void legajosAlumnosMayores(Pila *p, char nombreArchivo[])
{
    stAlumno a;
    FILE *fp;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        while(!feof(fp))
        {
            fread(&a, sizeof(stAlumno), 1, fp);
            if(!feof(fp))
                if(a.edad >= 18)
                    apilar(p, a.legajo);
        }
        fclose(fp);
    }
    else
        printf("\nERROR: No se pudo abrir el archivo.\n");
}

int pedirEdad()
{
    int edad;
    printf("Ingresar a que edad deben de ser los alumnos buscados: ");
    scanf("%d", &edad);
    while(getchar() != '\n');
    return edad;
}

int contarAlumnoPorEdad(int edadLimite, char nombreArchivo[])
{
    FILE *fp;
    stAlumno a;
    int alumnosMayores = 0;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        while(!feof(fp))
        {
            fread(&a, sizeof(stAlumno), 1, fp);
            if(!feof(fp))
                if(a.edad > edadLimite)
                    alumnosMayores++;
        }
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.");
    return alumnosMayores;
}

void rangosEdad(int *edadMin, int *edadMax)
{
    do
    {
        printf("Ingrese la edad minima del rango que quiera buscar: ");
        scanf("%d", edadMin);
        while(getchar() != '\n');

        printf("Ingrese la edad maxima del rango que quiera buscar: ");
        scanf("%d", edadMax);
        while(getchar() != '\n');

        if(*edadMax < *edadMin)
            printf("\nERROR: La edad maxima no puede ser menor a la edad minima. Intente nuevamente.\n");

    }
    while(*edadMax < *edadMin);
}

int estaEnRango(int edadMin, int edadMax, stAlumno a)
{
    int flag = 0;
    if(a.edad <= edadMax && a.edad >= edadMin)
        flag++;
    return flag;
}

void mostrarAlumnosEnRango(int edadMin, int edadMax, char nombreArchivo[])
{
    FILE *fp;
    stAlumno a;

    fp = fopen(nombreArchivo, "rb");

    if(fp)
    {
        while(!feof(fp))
        {
            fread(&a, sizeof(stAlumno), 1, fp);
            if(!feof(fp))
                if(estaEnRango(edadMin, edadMax, a))
                {
                    mostrarNombreAlumno(a);
                }
        }
        printf("-----------------------\n");
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.\n");
}

void mostrarNombreAlumno(stAlumno a)
{
    printf("-----------------------\n");
    printf("%s\n", a.nombreYapellido);
}

stAlumno encontrarAlumnoMayor(stAlumno mayor, stAlumno actual)
{
    if(actual.edad > mayor.edad)
        mayor = actual;
    return mayor;
}

void mostrarMayorAlumno(char nombreArchivo[])
{
    stAlumno mayor, actual;
    FILE *fp;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        if(!feof(fp))
            fread(&mayor, sizeof(stAlumno), 1, fp);
        while(fread(&actual, sizeof(stAlumno), 1, fp) > 0)
            mayor = encontrarAlumnoMayor(mayor, actual);
        printf("\nALUMNO DE MAYOR EDAD: \n");
        mostrarAlumno(mayor);
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.\n");
}

int pedirAnio()
{
    int anio;
    printf("INGRESE EL ANIO QUE QUIERA BUSCAR: ");
    scanf("%d", &anio);
    while(getchar() != '\n');
    return anio;
}

int cantidadAlumnosAnio(int anioBuscado, char nombreArchivo[])
{
    int cantidad = 0;
    FILE *fp;
    stAlumno a;

    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        while(fread(&a, sizeof(stAlumno), 1, fp) > 0)
            if(a.anio == anioBuscado)
                cantidad++;
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.\n");
    return cantidad;
}

int cargarArregloAlumnos(stAlumno alumnos[], int dim)
{
    int i = 0;
    char seguir = 's';
    do
    {
        printf("Cargue el alumno %d: \n", i);
        alumnos[i] = cargarAlumno();
        i++;
        printf("Quiere seguir cargando alumnos (s/n): ");
        scanf(" %c", &seguir);
    }
    while((seguir == 's' || seguir == 'S') && i < dim);
    return i;
}

void copiarArregloArchivo(stAlumno alumnos[], char nombreArchivo[], int validos)
{
    FILE *fp;
    fp = fopen(nombreArchivo, "ab");
    if(fp)
    {
        for(int i = 0; i < validos; i++)
            fwrite(&alumnos[i], sizeof(stAlumno), 1, fp);
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.\n");
}

int copiarAlumnosAlArreglo(stAlumno totalAlumnos[], char nombreArchivo[], int anioBuscado)
{
    stAlumno a;
    FILE *fp;
    int i = 0;

    fp = fopen(nombreArchivo, "rb");

    if(fp)
    {
        while(fread(&a, sizeof(stAlumno), 1, fp) > 0)
        {
            if(a.anio == anioBuscado)
            {
                totalAlumnos[i] = a;
                i++;
            }
        }
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.\n");
    return i;
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

int cantidadRegistroEntero(char nombreArchivo[])
{
    int registros = 0;
    long int bytes = 0;
    FILE *fp;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        fseek(fp, 0, SEEK_END);
        bytes = ftell(fp);
        registros = bytes / sizeof(int);
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo. \n");
    return registros;
}

void mostrarAlumnoBuscado(char nombreArchivo[], int numeroAlumnoBuscado)
{
    FILE *fp;
    stAlumno a;
    fp = fopen(nombreArchivo, "rb");
    if(fp)
    {
        fseek(fp, sizeof(stAlumno)*numeroAlumnoBuscado, SEEK_SET);
        fread(&a, sizeof(stAlumno), 1, fp);
        printf("\nAlumno buscado: \n");
        mostrarAlumno(a);
        fclose(fp);
    }
    else
    {
        printf("\nERRROR: No pudo abrirse el archivo.");
    }

}

int pedirNumeroAlumno()
{
    int numAlumno;
    do
    {
        printf("\nIngrese un numero entre el 0 y el 9: ");
        scanf("%d", &numAlumno);
        if(numAlumno < 0 || numAlumno > 9)
            printf("Ingresar un numero valido.\n");
    }
    while(numAlumno < 0 || numAlumno > 9);
    return numAlumno;
}

void verificacionCantAlumnos(char nombreArchivo[])
{
    int registros = cantidadRegistrosAlumnos(nombreArchivo);
    if(registros < 10)
    {
        FILE *fp;
        stAlumno a;
        printf("\nNo hay suficientes alumnos, cargue hasta que alla 10 en el archivo.\n\n");
        fp = fopen(nombreArchivo, "ab");
        if(fp)
        {
            while(registros < 10)
            {
                printf("\n-------Alumno %d---------\n", registros+1);
                a = cargarAlumno();
                fwrite(&a, sizeof(stAlumno), 1, fp);
                registros++;
            }
            fclose(fp);
        }
        else
            printf("\nError: no pudo abrirse el archivo.");
    }
}

int buscarPosAlumnoPorLegajo(char nombreArchivo[], int legajo)
{
    FILE *fp = fopen(nombreArchivo, "rb");
    stAlumno a;
    int pos = 0;
    int posEncontrada = -1;
    if(fp)
    {
        while(fread(&a, sizeof(stAlumno), 1, fp) > 0 && posEncontrada == -1)
        {
            if(a.legajo == legajo)
            {
                posEncontrada = pos;
            }
            pos++;
        }
        fclose(fp);
    }

    return posEncontrada;
}

void sobreescribirAlumno(char nombreArchivo[], int numAlumno)
{
    FILE *fp;
    stAlumno a;
    fp = fopen(nombreArchivo, "rb+");
    if(fp)
    {
        fseek(fp, sizeof(stAlumno)* numAlumno, SEEK_SET);
        a = cargarAlumno();
        fwrite(&a, sizeof(stAlumno), 1, fp);
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo");
}


void editarAlumno(char nombreArchivo[], int legajoBuscado)
{
    int pos = buscarPosAlumnoPorLegajo(nombreArchivo, legajoBuscado);

    if(pos == -1)
    {
        printf("\nNo se encontró un alumno con legajo %d.\n", legajoBuscado);
    }
    else
    {
        FILE *fp = fopen(nombreArchivo, "rb+");
        if(fp)
        {
            stAlumno a;
            fseek(fp, sizeof(stAlumno) * pos, SEEK_SET);
            fread(&a, sizeof(stAlumno), 1, fp);

            printf("\nDatos actuales del alumno:\n");
            mostrarAlumno(a);

            int opcion;
            printf("\n¿Qué desea modificar?\n");
            printf("1 - Legajo\n");
            printf("2 - Nombre y Apellido\n");
            printf("3 - Edad\n");
            printf("4 - Anio de cursada\n");
            printf("5 - Sobrescribir todo el alumno\n");
            do
            {
                printf("Ingrese su opción: ");
                scanf("%d", &opcion);
                while(getchar() != '\n');
            }
            while(opcion < 1 && opcion > 5);

            switch(opcion)
            {
            case 1:
                printf("Nuevo legajo: ");
                scanf("%d", &a.legajo);
                break;
            case 2:
                printf("Nuevo nombre: ");
                fflush(stdin);
                fgets(a.nombreYapellido, sizeof(a.nombreYapellido), stdin);
                a.nombreYapellido[strcspn(a.nombreYapellido, "\n")] = 0;
                break;
            case 3:
                printf("Nueva edad: ");
                scanf("%d", &a.edad);
                break;
            case 4:
                printf("Nuevo año de cursada: ");
                scanf("%d", &a.anio);
                break;
            case 5:
                fclose(fp);
                sobreescribirAlumno(nombreArchivo, pos);
                break;
            }
            if(opcion !=  5)
            {
                fseek(fp, sizeof(stAlumno) * pos, SEEK_SET);
                fwrite(&a, sizeof(stAlumno), 1, fp);
                fclose(fp);
            }
                printf("\nAlumno modificado correctamente.\n");
        }
        else
            printf("\nERROR: No pudo abrirse el archivo.\n");
    }

}

void intercambiarArchivoEntero(char nombreArchivo[])
{
    stAlumno a, b;
    int cantRegistros = cantidadRegistrosAlumnos(nombreArchivo);
    int pos = 0;
    FILE *fp = fopen(nombreArchivo, "r+b");
    if(fp)
    {
        while(pos <= cantRegistros/2)
        {
            //Leo
            fseek(fp, sizeof(stAlumno)*(pos), SEEK_SET);
            fread(&a, sizeof(stAlumno), 1, fp);
            fseek(fp, (-(pos+1))*(sizeof(stAlumno)), SEEK_END);
            fread(&b, sizeof(stAlumno), 1, fp);
            //Escribo
            fseek(fp, sizeof(stAlumno)*(pos), SEEK_SET);
            fwrite(&b, sizeof(stAlumno), 1, fp);
            fseek(fp, (-(pos+1))*(sizeof(stAlumno)), SEEK_END);
            fwrite(&a, sizeof(stAlumno), 1, fp);
            pos++;
        }
    }
}

int menuArchivos()
{
    int opcionMenu;
    printf("====MENU DE OPCIONES=======\n\n");
    printf("1-AGREGAR UN NÚMERO AL FINAL DE UN ARCHIVO.\n");
    printf("2-MUESTRA POR PANTALLA EL ARCHIVO DE NUMEROS.\n");
    printf("3-CANTIDAD DE REGISTROS QUE TIENE EL ARCHIVO \"numeros.bin\".\n");
    printf("4-CARGAR UN ARCHIVO DE ALUMNOS SI ESTE TIENE MENOS DE 5 REGISTROS.\n");
    printf("5-MUESTRA DE TODOS LOS ALUMNOS CARGADOS EN EL ARCHIVO.\n");
    printf("6-AGREGAR UN ALUMNO A \"alumnos.bin\" AL FINAL DEL ARCHIVO.\n");
    printf("7-PASAR A UNA PILA LOS ALUMNOS MAYORES DE EDAD Y SE MUESTRA EN PANTALLA.\n");
    printf("8-CONTAR CANTIDAD DE ALUMNOS MAYORES A EDAD INGRESADA.\n");
    printf("9-MOSTRAR EL NOMBRE DE CADA ALUMNO DENTRO DEL RANGO DE EDAD INGRESADO.\n");
    printf("10-MOSTRAR DATO DEL ALUMNO DE MAYOR EDAD EN EL ARCHIVO.\n");
    printf("11-MOSTRAR CANTIDAD DE ALUMNOS QUE CURSEN UN ANIO INGRESADO.\n");
    printf("12-COPIAR UN ARREGLO DE ALUMNOS A UN ARCHIVO O COPIAR EN UN ARREGLO LOS ALUMNOS DE UN ANIO INGRESADO.\n");
    printf("13-RETORNAR LA CANTIDAD DE REGISTROS EN \"alumnos.bim\" UTILIZANDO FTELL Y FSEEK.\n");
    printf("14-MOSTRAR UN REGISTRO ENTRE EL 0 Y EL 9 SEGUN CUAL SEA INGRESADO.\n");
    printf("15-MODIFICAR UN ALUMNO BUSCADO POR SU LEGAJO.\n");
    printf("16-INVERTIR TODOS LOS REGISTROS DEL ARCHIVO(EJ. alumno1, alumno2 -> alumno2, alumno1)\n");
}













