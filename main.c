#include <stdio.h>
#include "funciones.h"

void limpiarBuffer()
{
    while (getchar() != '\n')
        ;
}

int main(int argc, char *argv[])
{
    float productos[productos_maximos][2] = {0};
    char nombresp[productos_maximos][nombres] = {""};
    int opcion = 0;
    float tmax = 0, cmax = 0, tt = 0, ct = 0;
    printf("Bienvenido al programa de gestion de produccion\n");

    do
    {
        printf("\n---------- Menu Principal -------------\n");
        printf("1. Ingresar datos de Produccion\n");
        printf("2. Editar datos de Produccion\n");
        printf("3. Mostrar resumen de Produccion\n");
        printf("4. Eliminar un Producto\n");
        printf("5. Salir\n");
        printf("---------------------------------------\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada invalida. Intente nuevamente.\n");
            limpiarBuffer();
            continue;
        }

        limpiarBuffer();
        switch (opcion)
        {
        case 1:
            ingresardatos(nombresp, productos, &cmax, &tmax);
            calculartotal(productos, &tt, &ct);
            break;

        case 2:
            if (ct == 0)
            {
                printf("No hay productos registrados para editar.\n");
            }
            else
            {
                editarProducto(nombresp, productos);
                calculartotal(productos, &tt, &ct);
            }
            break;

        case 3:
            if (ct == 0)
            {
                printf("No hay productos registrados para mostrar.\n");
            }
            else
            {
                imprimirdatos(nombresp, productos, cmax, tmax, tt, ct);
            }
            break;

        case 4:
            if (ct == 0)
            {
                printf("No hay productos registrados para eliminar.\n");
            }
            else
            {
                eliminar(nombresp, productos);
                calculartotal(productos, &tt, &ct);
            }
            break;

        case 5:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 5);

    return 0;
}
