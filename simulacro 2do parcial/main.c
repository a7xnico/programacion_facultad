#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define cantGalaxias 5

typedef struct
{
	char nombrePlaneta [20];
	char estrella [20];
	int cantidadSatelites;
	float masa; ///(se mide en relación a la Tierra, por ejemplo Neptuno es 17,14 Tierras)
	int tempMax;
	int tempMin;
}planeta;

typedef struct
{
	char nombreGalaxia [20];
	char tipoGalaxia [20]; ///elíptica, lenticular, espiral, irregular, etc
	char descubiertoPor [20];
	planeta listaPlanetas[20];
	int valPlanetas;
}galaxia;

planeta cargarPlaneta();

int cargarPlanetas(planeta planetas[], int dimPlanetas);

galaxia cargarGalaxia();

int cargarGalaxias(galaxia galaxias[]);

void mostrarPlaneta(planeta p);

void mostrarPlanetas(planeta p[], int val);

void mostrarGalaxia(galaxia g);

void mostrarGalaxias(galaxia galaxias[], int val, char tipo[20]);

int cantidadSatelitesTotal(galaxia galaxias[], int valGalaxias, int i);

int cantidadSatelitesGalaxia(galaxia g, int valPlanetas, int i);

void guardarArregloPlanetas(char nombreArchivo[], planeta planetas[], int valPlanetas, float masaMinima);

int ArregloDinamicoPlanetas(char nombreArchivo[], planeta** arrDinamico);

int menuOpciones();

int main()
{
    galaxia galaxias[cantGalaxias];
    int valGalaxias = 0;
    int opcion;
    char tipoGalaxia[20];
    float masaMinima;
    planeta* arregloDinamico;
    int cantPlanetas;
    char archivo[] = "planetas.bin";
    do
    {
        opcion = menuOpciones();

        switch(opcion)
        {
        case 1:
            {
                valGalaxias = cargarGalaxias(galaxias);
                printf("Se cargaron las galaxias correctamente.\n");
                system("pause");
                system("cls");
                break;
            }
        case 2:
            {
                printf("Ingresar el tipo de galaxia a mostrar: ");
                fgets(tipoGalaxia, 20, stdin);
                tipoGalaxia[strcspn(tipoGalaxia, "\n")] = 0;
                mostrarGalaxias(galaxias, valGalaxias, tipoGalaxia);
                system("pause");
                system("cls");
                break;
            }
        case 3:
            {
                if(valGalaxias > 0)
                    printf("Cantidad de satelites: %d\n", cantidadSatelitesTotal(galaxias, valGalaxias, 0));
                else
                    printf("Cargar las galaxias primero.\n");
                system("pause");
                system("cls");
                break;
            }
        case 4:
            {
                printf("Ingrese la masa minima: ");
                scanf("%f", &masaMinima);
                while(getchar() != '\n');
                for(int i = 0; i < valGalaxias; i++)
                    guardarArregloPlanetas(archivo, galaxias[i].listaPlanetas, galaxias[i].valPlanetas, masaMinima);
                printf("Planetas guardados en el archivo.\n");
                system("pause");
                system("cls");
                break;
            }
        case 5:
            {
                cantPlanetas = ArregloDinamicoPlanetas(archivo, &arregloDinamico);
                if(cantPlanetas)
                {
                    printf("Planetas cargados desde el archivo: \n");
                    mostrarPlanetas(arregloDinamico, cantPlanetas);
                }
                else
                    printf("Cargar planetas al archivo primero.\n");
                system("pause");
                system("cls");
                break;
            }
        case 6:
            {
                printf("Gracias por utilizar el programa!\n");
                system("pause");
                system("cls");
                break;
            }
        default:
            printf("Opcion Invalida.\n");
            system("pause");
            system("cls");
        }
    }while(opcion != 6);

    return 0;
}

planeta cargarPlaneta()
{
    planeta p;

    printf("Ingresar el nombre del planeta: ");
    fgets(p.nombrePlaneta, 20, stdin);
    p.nombrePlaneta[strcspn(p.nombrePlaneta, "\n")] = 0;

    printf("Ingresar la estrella de este planeta: ");
    fgets(p.estrella, 20, stdin);
    p.estrella[strcspn(p.estrella, "\n")] = 0;

    printf("Ingresar la cantidad de satelites del planeta: ");
    scanf("%d", &p.cantidadSatelites);
    while(getchar() != '\n');

    printf("Ingresar la masa del planeta en relacion a la tierra: ");
    scanf("%f", &p.masa);
    while(getchar() != '\n');

    printf("Ingresar la temperatura maxima del planeta: ");
    scanf("%d", &p.tempMax);
    while(getchar() != '\n');

    printf("Ingresar la temperatura minima: ");
    scanf("%d", &p.tempMin);
    while(getchar() != '\n');

    return p;
}

int cargarPlanetas(planeta planetas[], int dimPlanetas)
{
    int seguir = 0;
    int val = 0;
    do
    {
        printf("\nPlaneta Numero %d:\n", val+1);
        planetas[val] = cargarPlaneta();
        val++;
        printf("Para cargar otro planeta presione 1: ");
        scanf("%d", &seguir);
        while(getchar() != '\n');
    }while(seguir == 1 && val < dimPlanetas);
    return val;
}

galaxia cargarGalaxia()
{
    galaxia g;

    printf("Ingresar el nombre de la galaxia: ");
    fgets(g.nombreGalaxia, 20, stdin);
    g.nombreGalaxia[strcspn(g.nombreGalaxia, "\n")] = 0;

    printf("Ingresar el tipo de galaxia: ");
    fgets(g.tipoGalaxia, 20, stdin);
    g.tipoGalaxia[strcspn(g.tipoGalaxia, "\n")] = 0;

    printf("Ingresar por quien fue descubierta: ");
    fgets(g.descubiertoPor, 20, stdin);
    g.descubiertoPor[strcspn(g.descubiertoPor, "\n")] = 0;

    g.valPlanetas = cargarPlanetas(g.listaPlanetas, 20);

    return g;
}

int cargarGalaxias(galaxia galaxias[])
{
    int seguir = 1, val = 0;
    do
    {
        printf("Galaxia numero %d:\n", val+1);
        galaxias[val] = cargarGalaxia();
        val++;
        printf("Para cargar otra galaxia presione 1: ");
        scanf("%d", &seguir);
        while(getchar() != '\n');
    }while(seguir == 1 && val < cantGalaxias);
    return val;
}

void mostrarPlaneta(planeta p)
{
    printf("Nombre del planeta: %s\n", p.nombrePlaneta);
    printf("Estrella del planeta: %s\n", p.estrella);
    printf("Cantidad de satelites: %d\n", p.cantidadSatelites);
    printf("Temperaturas MAX: %d  MIN: %d\n", p.tempMax, p.tempMin);
    printf("Masa del planeta: %.2f\n", p.masa);
}

void mostrarPlanetas(planeta p[], int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("\n-----PLANETA %d-----\n", i+1);
        mostrarPlaneta(p[i]);
    }
}

void mostrarGalaxia(galaxia g)
{
    printf("\n\n=========%s=========\n\n", g.nombreGalaxia);
    printf("Descubierto por: %s\n", g.descubiertoPor);
    printf("Galaxia tipo: %s\n", g.tipoGalaxia);
    mostrarPlanetas(g.listaPlanetas, g.valPlanetas);
}

void mostrarGalaxias(galaxia galaxias[], int val, char tipoBuscado[20])
{
    for(int i = 0; i < val; i++)
        if(strcasecmp(galaxias[i].tipoGalaxia, tipoBuscado) == 0)
            mostrarGalaxia(galaxias[i]);
}

int cantidadSatelitesTotal(galaxia galaxias[], int valGalaxias, int i)
{
    int satelites = cantidadSatelitesGalaxia(galaxias[i], galaxias[i].valPlanetas, i);
    if(i < valGalaxias - 1)
        satelites += cantidadSatelitesTotal(galaxias, valGalaxias, i+1);
    return satelites;
}

int cantidadSatelitesGalaxia(galaxia g, int valPlanetas, int i)
{
    int satelites = g.listaPlanetas[i].cantidadSatelites;
    if(i < valPlanetas - 1)
        satelites += cantidadSatelitesGalaxia(g, valPlanetas, i+1);
    return satelites;
}

void guardarArregloPlanetas(char nombreArchivo[], planeta planetas[], int valPlanetas, float masaMinima)
{
    FILE* fp;
    int i = 0;
    planeta a;
    fp = fopen(nombreArchivo, "ab");
    if(fp)
    {
        while(i < valPlanetas)
        {
            a = planetas[i];
            if(a.masa >= masaMinima)
                fwrite(&a, sizeof(planeta), 1, fp);
            i++;
        }
        fclose(fp);
    }
    else
        printf("\nERROR: No pudo abrirse el archivo.\n");
}

int ArregloDinamicoPlanetas(char nombreArchivo[], planeta** arrDinamico)
{
    FILE* fp;
    fp = fopen(nombreArchivo, "rb");
    int cantPlanetas = 0;
    int i = 0;
    planeta a;
    if(fp)
    {
        fseek(fp, 0 , SEEK_END);
        cantPlanetas = (ftell(fp) / sizeof(planeta));
        *arrDinamico = malloc(cantPlanetas * sizeof(planeta));
        rewind(fp);
        while(fread(&a, sizeof(planeta), 1, fp) > 0)
        {
            (*arrDinamico)[i] = a;
            i++;
        }
        fclose(fp);
    }

    return i;
}


int menuOpciones()
{
    int opcion;
    printf("\n============== MENU DE OPCIONES ==============\n");
    printf("1. Cargar galaxias y sus planetas\n");
    printf("2. Mostrar galaxias de un tipo con sus planetas\n");
    printf("3. Contar satelites totales de todas las galaxias\n");
    printf("4. Guardar planetas con masa mayor a una minima en archivo\n");
    printf("5. Cargar planetas desde archivo a arreglo dinamico\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    while(getchar() != '\n');
    return opcion;
}
