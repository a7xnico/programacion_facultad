#include <stdio.h>
#include <stdlib.h>
#define dimPalabra 30

void agregarEntero(char nombreArchivo[dimPalabra]);


int main()
{
    FILE *crear = fopen("archivo.bin", "rb");
    if(crear == NULL)
    {
        crear = fopen("archivo.bin", "wb");
    }
    fclose(crear);
    char archivo[dimPalabra] = "archivo.bin";
    agregarEntero(archivo);


}



void agregarEntero(char archivo[])
{
    int a;
    char seguir = 's';
    FILE *archi;
    archi = fopen(archivo, "ab");
    if(archi != NULL)
    {

        printf("\nQueres cargar numeros enteros? (s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);
        while(seguir=='s')
        {
            puts("\n==============================================");
            printf("\nIngrese un numero al archivo: ");
            fflush(stdin);
            scanf("%d", &a);
            puts("\n==============================================");
            fwrite(&a, sizeof(int), 1, archi);

            printf("\nQuiere seguir cargando enteros? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
        }
        fclose(archi);
    }
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
}
