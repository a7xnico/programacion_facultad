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

int main()
{
    galaxia galaxias[cantGalaxias];
    int val = cargarGalaxias(galaxias);
    return 0;
}

planeta cargarPlaneta()
{
    planeta p;

    printf("Ingresar el nombre del planeta: ");
    fgets(p.nombrePlaneta, 20, stdin);
    p.nombrePlaneta[strcspn(p.nombrePlaneta, '\n')] = 0;

    printf("Ingresar la estrella de este planeta: ");
    fgets(p.estrella, 20, stdin);
    p.estrella[strcspn(p.estrella, '\n')] = 0;

    printf("Ingresar la cantidad de satelites del planeta: ");
    scanf("%d", &p.cantidadSatelites);
    while(getchar() != '\n');

    printf("Ingresar la masa del planeta en relacion a la tierra: ");
    scanf("%f", p.masa);
    while(getchar() != '\n');

    printf("Ingresar la temperatura maxima del planeta: ");
    scanf("%d", p.tempMax);
    while(getchar() != '\n');

    printf("Ingresar la temperatura minima: ");
    scanf("%d", p.tempMin);
    while(getchar() != '\n');

    return p;
}

int cargarPlanetas(planeta planetas[], int dimPlanetas)
{
    int seguir;
    int val = 0;
    do
    {
        printf("\nPlaneta Numero %d:\n", val+1);
        planetas[val] = cargarPlaneta();
        val++;
        printf("Para cargar otro planeta presione 1: ");
        scanf("%d", seguir);
    }while(seguir == 1 && val < dimPlanetas);
    return val;
}

galaxia cargarGalaxia()
{
    galaxia g;

    printf("Ingresar el nombre de la galaxia: ");
    fgets(g.nombreGalaxia, 20, stdin);
    g.nombreGalaxia[strcspn(g.nombreGalaxia, '\n')] = 0;

    printf("Ingresar el tipo de galaxia: ");
    fgets(g.tipoGalaxia, 20, stdin);
    g.tipoGalaxia[strcspn(g.tipoGalaxia, '\n')] = 0;

    printf("Ingresar por quien fue descubierta: ");
    fgets(g.descubiertoPor, 20, stdin);
    g.descubiertoPor[strcspn(g.descubiertoPor, '\n')] = 0;

    g.valPlanetas = cargarPlanetas(g.listaPlanetas, 20);

    return g;
}

int cargarGalaxias(galaxia galaxias[])
{
    int seguir, val = 0;
    do
    {
        printf("Galaxia numero %d:\n", val+1);
        galaxias[val] = cargarGalaxia();
        val++;
        printf("Para cargar otra galaxia presione 1: ");
        scanf("%d", seguir);
    }while(seguir == 1 && val < cantGalaxias);
    return val;
}










