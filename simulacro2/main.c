#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre [20];
    char posicion [20];
    int curso;
    int puntosGanados;
} stJugador;

typedef struct
{
    char nombreEquipo[20];
    int puntosGanados;
    stJugador dato[25];
    int valEquipo;

} stEquipo;

int menu();

stJugador cargarJugador();

int cargarJugadores(stJugador j[], int dim);

stEquipo cargarEquipo();

int cargarEquipos(stEquipo equipos[], int dim);

void ordenarJugadores(stJugador j[], int val);

int encontrarMenorID(stJugador j[], int val, int posActual);

int sumarPuntosJugadores(stJugador jugadores[], int val, int i);

void asignarPuntosEquipos(stEquipo equipos[], int val);

int elegirEquipo(stEquipo equipos[], int cantEquipos);

int encontrarID(stEquipo equipo, char nombre[], int i);

int elegirEquipo(stEquipo equipos[], int cantEquipos);

void guardarEquipo(char nombreArchivo[], stEquipo equipo);

int cargarArrDinamico(char nombreArchivo[], stJugador** arrJugadores);

int main()
{
    stEquipo equipos[5];
    int cantEquipos = 0;
    int equipoElegido;
    int opcion;
    char nombreBuscado[20];
    int id;
    stJugador* arrJugadores;
    int valJugadoresArrego;
    char archivo[] = "jugadores.bin";

    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
        {
            cantEquipos = cargarEquipos(equipos, 5);
            printf("Equipos cargados correctamente!");
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {

            printf("Elegir el equipo que quiera ordenar por su subindice: \n");
            equipoElegido = elegirEquipo(equipos, cantEquipos);
            ordenarJugadores(equipos[equipoElegido].dato, equipos[equipoElegido].valEquipo);
            printf("Jugadores ordenados correctamente.");
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            asignarPuntosEquipos(equipos, cantEquipos);
            printf("Puntos asignados correctamente.");
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            printf("Ingresar el subindice del eqipo que quiera buscar: ");
            equipoElegido = elegirEquipo(equipos, cantEquipos);
            printf("Ingresar el nombre del jugador para buscar su id: ");
            fgets(nombreBuscado, 20, stdin);
            nombreBuscado[strcspn(nombreBuscado, "\n")] = 0;

            id = encontrarID(equipos[equipoElegido], nombreBuscado, 0);
            if(id == -1)
                printf("No se encontro al jugador en este equipo.\n");
            else
                printf("La id del jugador %s es: %d\n", nombreBuscado, id);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            printf("Elegir el equipo que quiera guardar en un archivo.\n");
            equipoElegido = elegirEquipo(equipos, cantEquipos);
            guardarEquipo(archivo, equipos[equipoElegido]);
            printf("Jugadores guardados correctamente.\n");
            system("pause");
            system("cls");
            break;
        }
        case 6:
            {
                valJugadoresArrego = cargarArrDinamico(archivo, &arrJugadores);
                printf("Jugadores guardados al arreglo.\n");
                system("pause");
                system("cls");
                break;
            }
        case 7:
            {
                printf("Gracias por utilizar el programa.\n");
                system("pause");
                system("cls");
                break;
            }
        default:
            {
                printf("Opcion invalida.\n");
                system("pause");
                system("cls");
                break;
            }

        }
    }
    while(opcion != 7);
    cargarEquipos(equipos, 5);
    return 0;
}

stJugador cargarJugador()
{
    stJugador j;

    printf("Ingresar la ID del jugador: ");
    scanf("%d", &j.id);
    while(getchar()!= '\n');

    printf("Ingresar el nombre del jugador: ");
    fgets(j.nombre, 20, stdin);
    j.nombre[strcspn(j.nombre, "\n")] = 0;

    printf("Ingresar la posicion del jugardor: ");
    fgets(j.posicion, 20, stdin);
    j.posicion[strcspn(j.posicion, "\n")] = 0;

    printf("Ingresar el curso del jugador: ");
    scanf("%d", &j.curso);
    while(getchar() != '\n');

    printf("Ingresar los puntos ganados por el jugador: ");
    scanf("%d", &j.puntosGanados);
    while(getchar() != '\n');

    return j;
}

int cargarJugadores(stJugador j[], int dim)
{
    int seguir = 1;
    int i = 0;
    do
    {
        printf("====Jugador numero %d====\n", i+1);
        j[i] = cargarJugador();
        i++;
        printf("Para cargar otro jugador ingrese 1:");
        scanf("%d", &seguir);
        while(getchar() != '\n');
    }
    while(seguir == 1 && i < dim);
    return i;
}

stEquipo cargarEquipo()
{
    stEquipo e;

    printf("Ingresar el nombre del equipo: ");
    fgets(e.nombreEquipo, 20, stdin);
    e.nombreEquipo[strcspn(e.nombreEquipo, "\n")] = 0;

    printf("Cargar los jugadores del equipo: \n");
    e.valEquipo = cargarJugadores(e.dato, 25);

    e.puntosGanados = -1;

    return e;
}

int cargarEquipos(stEquipo equipos[], int dim)
{
    int seguir=1;
    int i = 0;
    do
    {
        printf("====Equipo numero %d====\n", i+1);
        equipos[i] = cargarEquipo();
        i++;
        printf("Para cargar otro equipo presione 1: ");
        scanf("%d", &seguir);
    }
    while(seguir == 1 && i < dim);
    return i;
}

int menu()
{
    int opcion;
    printf("=====MENU DE OPCIONES======\n");
    printf("1.CARGAR EQUIPOS Y SUS JUGADORES.\n");
    printf("2.ORDENAR LOS JUGADORES DE UN EQUIPO SEGUN LOS PUNTOS GANADOS.\n");
    printf("3.SUMAR LOS PUNTOS DE LOS JUGADORES Y ASIGNARLOS A CADA EQUIPO.\n");
    printf("4.INGRESAR NOMBRE DEL EQUIPO Y JUGADOR PARA BUSCAR SU ID.\n");
    scanf("%d", &opcion);
    while(getchar() != '\n');
    return opcion;
}

void ordenarJugadores(stJugador j[], int val)
{
    int posMin;
    for(int i = 0; i < val; i++)
    {
        posMin = encontrarMenorID(j, val, i);
        if(posMin != i)
        {
            stJugador aux;
            aux = j[i];
            j[i] = j[posMin];
            j[posMin] = aux;
        }
    }
}

int encontrarMenorID(stJugador j[], int val, int posActual)
{
    int posMenor = posActual;
    for(int i = posActual+1; i < val; i++)
        if(j[i].id < j[posMenor].id)
            posMenor = i;
    return posMenor;
}

int sumarPuntosJugadores(stJugador jugadores[], int val, int i)
{
    int puntos = jugadores[i].puntosGanados;
    if(i < val - 1)
        puntos += sumarPuntosJugadores(jugadores, val, i+1);
    return puntos;
}

void asignarPuntosEquipos(stEquipo equipos[], int val)
{
    for(int i = 0; i < val; i++)
        equipos[i].puntosGanados = sumarPuntosJugadores(equipos[i].dato, equipos[i].valEquipo, 0);
}

int encontrarID(stEquipo equipo, char nombre[], int i)
{
    int id = -1;
    if(i < equipo.valEquipo)
    {
        if(strcasecmp(nombre, equipo.dato[i].nombre) == 0)
            id = equipo.dato[i].id;
        else
            id = encontrarID(equipo, nombre, i+1);
    }
    return id;
}

int elegirEquipo(stEquipo equipos[], int cantEquipos)
{
    int equipoElegido;
    for(int i = 0; i < cantEquipos; i++)
        printf("EQUIPO %d: %s\n", i+1, equipos[i].nombreEquipo);
    do
    {
        printf("Ingrese su opcion: ");
        scanf("%d", &equipoElegido);
        if(equipoElegido <= 0 || equipoElegido > cantEquipos)
            printf("Ingresar una opcion valida.\n");
    }
    while(equipoElegido <= 0 || equipoElegido > cantEquipos);

    return equipoElegido;
}

void guardarEquipo(char nombreArchivo[], stEquipo equipo)
{
    FILE* fp;
    fp = fopen(nombreArchivo, "ab");
    stJugador aux;
    int i;
    if(fp)
    {
        for(i = 0; i < equipo.valEquipo; i++)
        {
            aux = equipo.dato[i];
            fwrite(&aux, sizeof(stJugador), 1, fp);
        }
        fclose(fp);
    }
    else
        printf("ERROR: No pudo abrirse el archivo.\n");
}

int cargarArrDinamico(char nombreArchivo[], stJugador** arrJugadores)
{
    FILE*fp;
    fp = fopen(nombreArchivo, "rb");
    int cantJugadores;
    stJugador aux;
    int i;
    if(fp)
    {
        fseek(fp, 0, SEEK_END);
        cantJugadores = ftell(fp) / cantJugadores;
        *arrJugadores = malloc(cantJugadores*sizeof(stJugador));
        rewind(fp);
        while(fread(&aux, sizeof(stJugador), 1, fp)>0)
        {
            (*arrJugadores)[i] = aux;
            i++;
        }
        fclose(fp);
    }
    else
        printf("ERROR: No pudo abrirse el archivo.\n");
    return i;
}
