#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int potencia(int x, int exp);

void mostrarArreglo(int a[], int val, int i);

void mostrarInvertido(int a[], int val, int i);

int capicua(int a[], int val, int i);

int sumaArreglo(int a[], int val, int i);

void cargarArchivoEnteros(char archivo[]);

int menorNumeroArchivo(FILE* buffer);

void mostrarArchivoInvertido(FILE* buffer);

void mostrarArchivo(FILE* buffer);

int cantidadRegistro(char archivo[]);

void invertirArchivo(FILE* buffer, int i, int registros);

void pedirYmostrarCaracteres();

int buscarElemento(int arr[], int elemBuscado, int val, int i);

int main()
{
    int x;
    printf("Ingresar de que numero quiere ver su factorial: ");
    scanf("%d", &x);
    int factx = factorial(x);
    printf("factorial de %d: %d", x, factx);


    int base;
    printf("\nIngrese la base para ver su exponente: ");
    scanf("%d", &base);
    int exp;
    printf("Ingrese el exponente para su base: ");
    scanf("%d", &exp);
    int potX = potencia(base, exp);
    printf("%d elevado a la %d da: %d\n",base, exp, potX);

    int arreglo[] = {5,10,6,2,1,8,7};
    int val = 7;
    printf("Arreglo: \n");
    mostrarArreglo(arreglo, val, 0);

    printf("\nArreglo invertido: \n");
    mostrarInvertido(arreglo, val, 0);

    int arrCapicua[] = {1,3,5,3,1};
    int val2 = 5;
    if(capicua(arreglo, val, 0))
        printf("\nESTE ARREGLO ES CAPICUA.");
    else
        printf("\nEL ARREGLO NO ES CAPICUA.");

    int suma = sumaArreglo(arreglo, val, 0);
    printf("\nLa suma de todos los enteros del arreglo es de : %d", suma);

    int posMenor = posMenorElemento(arreglo, val, 0);
    printf("\nEl menor elemento es %d y esta en la posicion %d del arreglo.\n",arreglo[posMenor], posMenor);

    char nombreArchivo[] = "numeros.bin";
    //cargarArchivoEnteros(nombreArchivo);
    FILE* buffer;
    buffer = fopen(nombreArchivo, "rb");
    if(buffer)
    {
        int menorNum = menorNumeroArchivo(buffer);
        fclose(buffer);
        printf("EL MENOR NUMERO DEL ARCHIVO ES: %d\n", menorNum);
    }

    buffer = fopen(nombreArchivo, "rb");
    if(buffer)
    {
        printf("\nARCHIVO EN ORDEN INVERSO: \n");
        mostrarArchivoInvertido(buffer);
        fclose(buffer);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.");
    /**Asegurarse que este invertido en la funcion anterior
    buffer = fopen(nombreArchivo, "rb");
    if(buffer)
    {
        printf("\nARCHIVO ORDEN NORMAL:\n");
        mostrarArchivo(buffer);
        fclose(buffer);
    }
    else
        printf("ERROR: No pudo abrirse el archivo.");*/
    int registros = cantidadRegistro(nombreArchivo);
    buffer = fopen(nombreArchivo, "rb+");
    if(buffer)
    {
        invertirArchivo(buffer, 0, registros);
        fclose(buffer);
    }
    buffer = fopen(nombreArchivo, "rb");
    if(buffer)
    {
        printf("\nARCHIVO INVERTIDO Y MOSTRADO EN ORDEN INVERSO: \n");
        mostrarArchivoInvertido(buffer);
        fclose(buffer);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo");
    printf("\n\n");
    pedirYmostrarCaracteres();
    int elemBuscado;
    printf("\nIngresar el elemento a buscar en el arreglo: ");
    scanf("%d", &elemBuscado);
    if(buscarElemento(arreglo, elemBuscado, val, 0))
        printf("EL ELEMENTO ESTA EN EL ARREGLO.\n");
    else
        printf("EL ELEMENTO NO ESTA EN EL ARREGLO.\n");
    mostrarArreglo(arreglo, val, 0);
}

int factorial(int x)
{
    int res = 1;
    if(x > 0)
        res = x * factorial(x-1);
    return res;
}

int potencia(int x, int exp)
{
    int res = 1;
    if(exp > 0)
        res = x * potencia(x, exp-1);
    return res;
}

void mostrarArreglo(int a[], int val, int i)
{
    printf("|%d|", a[i]);
    if(i < val-1)
        mostrarArreglo(a,val,i+1);
}

void mostrarInvertido(int a[], int val, int i)
{
    if(i< val-1)
        mostrarInvertido(a, val, i+1);
    printf("|%d|",a[i]);
}

int capicua(int a[], int val, int i)
{
    int flag = 0;
    if(a[i] == a[val-1-i])
        flag = 1;
    if(i < val/2 && flag == 1)
        flag = capicua(a, val, i+1);
    return flag;
}

int sumaArreglo(int a[], int val, int i)
{
    int suma = a[i];
    if(i < val-1)
        suma += sumaArreglo(a, val, i+1);
    return suma;
}

int posMenorElemento(int a[], int val, int i)
{
    int posMenor = i;
    if(i < val-1)
    {
        int posActual = posMenorElemento(a, val, i+1);
        if(a[posMenor] > a[posActual])
            posMenor = posActual;
    }
    return posMenor;
}

void cargarArchivoEnteros(char archivo[])
{
    FILE* fp;
    int a;
    int seguir = 1;
    fp = fopen(archivo, "ab");
    if(fp)
    {
        while(seguir == 1)
        {
            printf("Ingrese un numero para agregar al archivo: ");
            scanf("%d", &a);
            fwrite(&a, sizeof(int), 1, fp);
            printf("\nPresione 1 para cargar otro numero al archivo: ");
            scanf("%d", &seguir);
        }
        fclose(fp);
    }
    else
        printf("ERROR: No pudo abrirse el archivo.");
}

int menorNumeroArchivo(FILE* buffer)
{
    int a;
    int menorNum;
    if(fread(&a, sizeof(int), 1, buffer)>0)
    {
        menorNum = menorNumeroArchivo(buffer);
        if(a < menorNum)
            menorNum = a;
    }
    else
    {
        fseek(buffer, -sizeof(int), SEEK_END);
        fread(&menorNum, sizeof(int), 1, buffer);
    }

    return menorNum;
}

void invertirArchivo(FILE* buffer, int i, int registros)
{
    int a, b;
    if(i < registros/2)
    {
        // lectura
        fseek(buffer, i * sizeof(int), SEEK_SET);
        fread(&a, sizeof(int), 1, buffer);
        fseek(buffer, -(i+1)*sizeof(int), SEEK_END);
        fread(&b, sizeof(int), 1, buffer);
        // escritura
        fseek(buffer, i * sizeof(int), SEEK_SET);
        fwrite(&b, sizeof(int), 1, buffer);
        fseek(buffer, -(i+1)*sizeof(int), SEEK_END);
        fwrite(&a, sizeof(int), 1, buffer);
        // hacer con los siguientes registros
        invertirArchivo(buffer, i+1, registros);
    }
}


void mostrarArchivoInvertido(FILE* buffer)
{
    int a;
    if(fread(&a, sizeof(int), 1, buffer)>0)
    {
        mostrarArchivoInvertido(buffer);
        printf("|%d|", a);
    }
}

void mostrarArchivo(FILE* buffer)
{
    int a;
    if(fread(&a, sizeof(int), 1, buffer)> 0)
    {
        printf("|%d|", a);
        mostrarArchivo(buffer);
    }
}

int cantidadRegistro(char archivo[])
{
    long bytes;
    int registros = 0;
    FILE*fp;
    fp = fopen(archivo, "rb");
    if(fp)
    {
        fseek(fp, 0, SEEK_END);
        bytes = ftell(fp);
        registros = bytes / sizeof(int);
    }
    else
        printf("ERROR: No pudo abrirse el archivo");
    return registros;
}

void pedirYmostrarCaracteres()
{
    char a;
    printf("Ingresar un caracter o ingresar (*) para terminar de cargar: ");
    scanf(" %c", &a);
    if(a != '*')
    {
        pedirYmostrarCaracteres();
        printf("|%c|", a);
    }
}

int buscarElemento(int arr[], int elemBuscado, int val, int i)
{
    int flag= 0;
    if(i < val)
    {
        if(arr[i] == elemBuscado)
            flag = 1;
        else
            flag = buscarElemento(arr,elemBuscado, val, i+1);
    }
    return flag;
}







