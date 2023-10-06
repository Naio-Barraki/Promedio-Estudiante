#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void LlenarNom(char *);
void AgregarCal(float cal[][3]);
void ModificarCal(float cal[][3]);
float PromSem(float cal[][3], int*);
float PromTot(float cal[][3]);

int main()
{
    char nombre[20];
    float prom[8][3], p;
    int opc, sem;
    do
    {
        printf("Que desea hacer?\n1.-Llenar las calificaciones\n2.-Modificar una calificacion\n3.-Calcular el promedio de un semestre\n4.-Calcular el promedio general\n5.-Salir\n");
        scanf("%d", opc);
        switch(opc)
        {
        case 1:
            {
                LlenarNom(nombre);
                AgregarCal(prom);
                system("cls");
            }
            break;
        case 2:
            {
                ModificarCal(prom);
                system("cls");
            }
            break;
        case 3:
            {
                p = PromSem(prom, &sem);
                printf("El promedio de %s en el semestre %d es de: %.1f\n", nombre, sem,p);
                sleep(2);
                system("cls");
            }
            break;
        case 4:
            {
                p = PromTot(prom);
                printf("El promedio de %s total es de: %.1f\n", nombre, p);
                sleep(2);
                system("cls");
            }
            break;
        case 5:
            {
                printf("Saliendo...\n");
                sleep(2);
                system("cls");
            }
        default:
            {
                printf("Ingrese una opcion valida\n");
                sleep(2);
                system("cls");
            }
            break;
        }
    } while (opc != 5);
    return 0;
}

void LlenarNom(char nom[])
{
    printf("Ingrese el nombre del alumno:\n");
    scanf("%s", nom);
}

void AgregarCal(float cal[8][3])
{
        int i, j;
    for (i = 0; i < 8; i++)
    {
        printf("Ingrese las calificaciones\nSemestre %d:\n", i+1);
        for (j = 0; j < 3; j++)
        {
            printf("Materia %d: ", j + 1);
            scanf("%f", &cal[i][j]);
        }
        system("cls");
    }
}

void ModificarCal(float cal[8][3])
{
    int i, j;
    float x;
    printf("Introduzca el semestre de la materia que desea modificar:\n");
    scanf("%d", &i);
    do
    {
        if (i <= 0 || i >= 9)
        {
            printf("Introduzca un semestre valido\ndesde 1 a 8\n");
            scanf("%d", &i);
        }
    }while (i <= 0 || i >= 9);
    printf("Introduzca la materia que desea modificar:\n");
    scanf("%d", &j);
    do
    {
        if (j <= 0 || j >= 4)
        {
            printf("Introduzca una materia valida\ndesde 1 a 3\n");
            scanf("%d", &j);
        }
    }while (j <= 0 || j >= 4);
    printf("Introduzca la nueva calificacion\n");
    scanf("%f", &x);
    do
    {
        if (x < 0 || x > 10)
        {
            printf("Introduzca una calificacion valida\ndesde 0 a 10\n");
            scanf("%f", &x);
        }
    }while (x < 0 || x > 10);
    cal[i-1][j-1] = x;
}

float PromSem(float cal[][3], int *x)
{
    int i, n;
    float r;
    printf("Introduzca el semestre que desea sacar promedio:\n");
    scanf("%d", &i);
    do
    {
        if (i <= 0 || i >= 9)
        {
            printf("Introduzca un semestre valido\ndesde 1 a 8\n");
            scanf("%d", &i);
        }
    }while (i <= 0 || i >= 9);
    for (n = 0; n < 3; n++)
    {
        r = cal[i - 1][n] + r;
    }
    *x = (i - 1);
    return (r / 3);
}

float PromTot(float cal[][3])
{
    int i, j;
    float r;
    for (i = 0; i < 8; i++)
    {

        for (j = 0; j < 3; j++)
        {
            r = cal[i][j];
        }
    }
    return (r / 24);
}
