#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresardatos(char nombresp[productos_maximos][nombres], float productos[productos_maximos][2], float *CantidadMAx, float *tiempoMax)
{
    do
    {
        printf("Ingresar la cantidad total de recursos economicos($) disponibles para producir su producto: ");
        if (scanf("%f", CantidadMAx) == 1 && *CantidadMAx > 0)
        {
            break;
        }

        printf("Entrada invalida. Intente nuevamente.\n");
        while (getchar() != '\n')
            ;
    } while (1);
    do
    {
        printf("Ingresar el tiempo maximo de produccion disponible (en semanas): ");
        if (scanf("%f", tiempoMax) == 1 && *tiempoMax > 0)
        {
            break;
        }
        printf("Entrada invalida. Intente nuevamente.\n");
        while (getchar() != '\n')
            ;
    } while (1);
    for (int i = 0; i < productos_maximos; i++)
    {
        printf("\nProducto %d:\n", i + 1);
        printf("Ingresa el nombre del producto %d: ", i + 1);
        fflush(stdin);
        fgets(nombresp[i], nombres, stdin);
        nombresp[i][strcspn(nombresp[i], "\n")] = '\0';
        do
        {
            printf("Ingresar la cantidad economica para realizar este producto ($): ");
            if (scanf("%f", &productos[i][0]) == 1 && productos[i][0] > 0)
            {
                break;
            }
            printf("Entrada invalida. Intente nuevamente.\n");
            while (getchar() != '\n')
                ;
        } while (1);
        do
        {
            printf("Ingrese el tiempo de produccion requerido para este producto (en semanas): ");
            if (scanf("%f", &productos[i][1]) == 1 && productos[i][1] > 0)
            {
                break;
            }
            printf("Entrada invalida. Intente nuevamente.\n");
            while (getchar() != '\n')
                ;
        } while (1);
    }
}

void calculartotal(float productos[productos_maximos][2], float *tiempoT, float *cantidadT)
{
    *cantidadT = 0;
    *tiempoT = 0;
    float *ptr = &productos[0][0];
    for (int i = 0; i < productos_maximos; i++, ptr += 2)
    {
        *cantidadT += *ptr;
        *tiempoT += *(ptr + 1);
    }
}

void imprimirdatos(char nom[productos_maximos][nombres], float productos[productos_maximos][2], float cantidadMax, float tiempoMax, float tiempot, float cantidad)
{
    printf("\n------Resumen de produccion--------\n");
    printf("Cantidad total de recursos economicos disponibles: %.2f $\n", cantidadMax);
    printf("Tiempo maximo disponible: %.2f semanas\n", tiempoMax);
    for (int i = 0; i < productos_maximos; i++)
    {
        if (productos[i][0] > 0 && productos[i][1] > 0)
        {
            printf("producto %d:\n", i + 1);
            printf("nombre : %s\n", nom[i]);
            printf("cantidad de economica demanda: %.2f $\n", productos[i][0]);
            printf("tiempo de produccion: %.2f semanas\n", productos[i][1]);
        }
    }
    printf("Resultados: \n");
    printf("Tiempo total requerido: %.2f semanas \n", tiempot);
    if (tiempot > tiempoMax)
        printf("El tiempo requerido excede el tiempo disponible\n");
    else
        printf("El tiempo requerido esta dentro del tiempo disponible\n");
    printf("Cantidad total requerida: %2.f unidades\n", cantidad);
    if (cantidad > cantidadMax)
        printf("La cantidad economica requerida excede los recursos disponibles\n");
    else
        printf("La cantidad economica requerida cumple los recursos disponibles\n");
}

void editarProducto(char nom[productos_maximos][nombres], float productos[productos_maximos][2])
{
    char buscarnombre[nombres];

    printf("\nIngrese el nombre del producto que desea editar\n");
    fflush(stdin);
    gets(buscarnombre);

    for (int i = 0; i < productos_maximos; i++)
    {
        if (strcmp(nom[i], buscarnombre) == 0)
        {
            printf("Ingresa el nuevo nombre del producto\n");
            fflush(stdin);
            gets(nom[i]);
            do
            {
                printf("Ingresar la nueva cantidad economica demandada para realizar este producto ($): ");
                if (scanf("%f", &productos[i][0]) == 1 && productos[i][0] > 0)
                {
                    break;
                }
                printf("Entrada invalida. Intente nuevamente.\n");
                while (getchar() != '\n')
                    ;
            } while (1);
            do
            {
                printf("Ingrese el nuevo tiempo de produccion requerido para este producto (en semanas): ");
                if (scanf("%f", &productos[i][1]) == 1 && productos[i][1] > 0)
                {
                    break;
                }
                printf("Entrada invalida. Intente nuevamente.\n");
                while (getchar() != '\n')
                    ;
            } while (1);
            return;
        }
    }

    printf("Producto no encontrado\n");
}

void eliminar(char nom[productos_maximos][nombres], float productos[productos_maximos][2])
{
    char buscarnombre[nombres];

    printf("\nIngrese el nombre del producto que desea eliminar: ");
    fgets(buscarnombre, nombres, stdin);
    buscarnombre[strcspn(buscarnombre, "\n")] = '\0';

    for (int i = 0; i < productos_maximos; i++)
    {
        if (strcmp(nom[i], buscarnombre) == 0)
        {
            strcpy(nom[i], "");
            productos[i][0] = 0;
            productos[i][1] = 0;
            printf("Producto '%s' eliminado con exito.\n", buscarnombre);
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

/*PRESUESTO GLOBAL = 1000
0

SE REQUIERE FABRICAR 5 PRODUCTOS 

SE DEMORAN 3 HORAS EN PRODUCIR CADA PRODUCTO 

COSTOT = 15 DOLARES 

SI SE PASA DEL PROSUPUERTO GLOBAL SOLICITAR AL USUARIO QUE SINGRISE SI SE VA TENER UN ADELANTO 

ADELANTO + PRESUPUERTO GLOBAL
*/