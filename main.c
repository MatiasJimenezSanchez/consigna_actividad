#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define NOMBRES 50

int MAX_PRODUCTOS;

void limpiarBuffer()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    do
    {
        printf("Ingrese el numero maximo de items para la orden de produccion (maximo 5): \n");
        if (scanf("%d", &MAX_PRODUCTOS) == 1 && MAX_PRODUCTOS > 0 && MAX_PRODUCTOS <= 5)
        {
            break;
        }
        printf("Entrada invalida. Solo puedes ingresar maximo 5 productos. Intente nuevamente.\n");
        limpiarBuffer();
    } while (1);

    char nombres[MAX_PRODUCTOS][NOMBRES]; 
    float productos[MAX_PRODUCTOS][3]; 
    float costosD[MAX_PRODUCTOS];     
    float Tmax = 0, Cmax = 0, tT = 0, cT = 0; 
    int opc1 = 0, opc2 = 0;

    do
    {
        printf("\n----------------- Menu -----------------\n");
        printf("1. Ingresar datos\n");
        printf("2. Imprimir datos\n");
        printf("3. Editar Productos\n");
        printf("4. Eliminar Producto\n");
        printf("5. Salir\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opc1) != 1)
        {
            printf("Entrada invalida. Intente nuevamente.\n");
            limpiarBuffer();
            continue;
        }

        limpiarBuffer(); 
        switch (opc1)
        {
        case 1:
            ingresardatos(nombres, productos, &Cmax, &Tmax);
            costos(productos, costosD); 
            calcularTotales(productos, &tT, &cT, costosD);
            break;

        case 2:
            if (cT == 0)
            {
                printf("No hay productos registrados para mostrar.\n");
            }
            else
            {
                imprimirdatos(nombres, productos, Cmax, Tmax, cT, tT);
            }
            break;

        case 3:
            if (cT == 0)
            {
                printf("No hay productos registrados para editar.\n");
            }
            else
            {
                editarProducto(nombres, productos);
                costos(productos, costosD); 
                calcularTotales(productos, &tT, &cT, costosD); 
            }
            break;

        case 4:
            if (cT == 0)
            {
                printf("No hay productos registrados para eliminar.\n");
            }
            else
            {
                eliminar(nombres, productos);
                costos(productos, costosD);
                calcularTotales(productos, &tT, &cT, costosD);
           }
            break;

        case 5:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
        }

        if (opc1 != 5)
        {
            printf("\nDesea continuar?\n1. Si\n2. No\n");
            if (scanf("%d", &opc2) != 1 || (opc2 != 1 && opc2 != 2))
            {
                printf("Entrada invalida. Saliendo del programa...\n");
                break;
            }
            limpiarBuffer();
        }
    } while (opc1 != 5 && opc2 == 1);

    printf("Saliendo.....\n");
    return 0;
}
