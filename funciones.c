#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define NOMBRES 50

void ingresardatos(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3], float *presuI, float *TiempoMax)
{

    do
    {
        printf("Ingrese el presupuesto inicial ($): \n");
        if (scanf("%f", presuI) == 1 && *presuI > 0)
        {
            break;
        }

        printf("Entrada invalida. Intente nuevamente.\n");
        while (getchar() != '\n')
            ;
    } while (1);

    do
    {
        printf("Ingrese el tiempo total demando (horas): \n");
        if (scanf("%f", TiempoMax) == 1 && *TiempoMax > 0)
        {
            break;
        }
        printf("Entrada invalida. Intente nuevamente.\n");
        while (getchar() != '\n')
            ;
    } while (1);

    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        printf("\nProducto %d:\n", i + 1);
        printf("Ingresa el nombre del producto %d: ", i + 1);
        fflush(stdin);
        gets(nombres[i]);   

        do
        {
            printf("Ingrese los costos unitarios del producto %d ($) \n", i + 1);
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
            printf("Ingresa El tiempo de producion del producto %d (horas)\n", i + 1);
            if (scanf("%f", &productos[i][1]) == 1 && productos[i][1] > 0)
            {
                break;
            }
            printf("Entrada invalida. Intente nuevamente.\n");
            while (getchar() != '\n')
                ;
        } while (1);

        do
        {
            printf("Ingresa la demanda de producion del producto (unidades) %d\n", i + 1);
            if (scanf("%f", &productos[i][2]) == 1 && productos[i][2] > 0)
            {
                break;
            }
            printf("Entrada invalida. Intente nuevamente.\n");
            while (getchar() != '\n')
                ;
        } while (1);
    }
}

void costos(float productos[MAX_PRODUCTOS][3], float CostoD[MAX_PRODUCTOS])
{

    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        CostoD[i] = ((productos[i][0] * productos[i][1]) * productos[i][2]);

        printf("\nCosto por producion del producto %d del pedido es: %2.f$\n", i + 1, CostoD[i]);
    }
}

void calcularTotales(float productos[MAX_PRODUCTOS][3], float *tiempoT, float *costoT, float costoD[MAX_PRODUCTOS])
{

    float sumaT = 0, sumaC = 0;

    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        sumaT += (productos[i][1] * productos[i][2]);
    }

    *tiempoT = sumaT;

    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        sumaC += costoD[i];
    }

    *costoT = sumaC;
}

void imprimirdatos(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3], float presuI, float TiempoMax, float costoT, float tiempoT)
{
    printf("\n");
    printf("\tCantidad Disponible: %2.f\n", presuI);
    printf("\tTiempo Disponible: %2.f\n", TiempoMax);
    printf("--------------------------------------------------------------------------\n");
    printf("\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        if (productos[i][1] != 0 && productos[i][1] != 0)
        {
            printf("\t*Nombre del producto*: %s\nCosto de produccion: %2.f\nTiempo de produccion: %2.f\nDemanda: %2.f\n", nombres[i], productos[i][0], productos[i][1], productos[i][2]);
        }
    }

    printf("\n");
    printf("Tiempo Disponible: %.2f\n",TiempoMax);
    if (tiempoT > TiempoMax)
    {
        float resta = tiempoT - TiempoMax;
        printf("\nTiempo Total %.2f\n", tiempoT);
        printf("No hay suficiente tiempo disponible para la producion\nLas horas faltantes son %.2f\n", resta);
    }

    else

    {
        printf("El tiempo demandado esta dentro del tiempo de producion\n");
    }

    printf("\nCantidad Disponible:\n");

    if (costoT > presuI)
    {
        float restaD = costoT - presuI;

        printf("No se puede cumplir con la demanda, el costo de producion sobrepasa el presupuesto inicial\nPara cumplir con la demanda se requiere los siguientes fondos adicionales: %.2f\n", restaD);
        printf("Ingrese nuevamente los datos en el menu con un nuevo presupuesto (En caso de que exita un adelanto)");
    }
    else
    {
        printf("Si se puede cumplir con la demanda\n");
    }
}

void editarProducto(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3])
{
    char buscarnombre[NOMBRES];

    printf("\nIngrese el nombre del producto que desea editar\n");
    fflush(stdin);
    gets(buscarnombre);

    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        if (strcmp(nombres[i], buscarnombre) == 0)
        {
            printf("Ingresa el nuevo nombre del producto\n");
            fflush(stdin);
            gets(nombres[i]);

            do
            {
                printf("Ingrese el nuevo costo unitario del producto %d ($) \n", i + 1);
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
                printf("Ingresa el nuevo tiempo de producion del producto %d (horas)\n", i + 1);
                if (scanf("%f", &productos[i][1]) == 1 && productos[i][1] > 0)
                {
                    break;
                }
                printf("Entrada invalida. Intente nuevamente.\n");
                while (getchar() != '\n')
                    ;
            } while (1);

            do
            {
                printf("Ingresa la demanda de producion del producto  %d (unidades)\n", i + 1);
                if (scanf("%f", &productos[i][2]) == 1 && productos[i][2] > 0)
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

void eliminar(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3])
{

    char buscarnombre[NOMBRES];

    printf("\nIngrese el nombre del producto que desea eliminar\n");
    fflush(stdin);
    gets(buscarnombre);

    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        if (strcmp(nombres[i], buscarnombre) == 0)
        {
            strcpy(nombres[i], "");
            productos[i][0] = 0;
            productos[i][1] = 0;
            printf("Producto Eliminado\n");
            return;
        }
    }

    printf("Producto no encontrado\n");
}
