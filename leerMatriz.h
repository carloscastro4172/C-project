#ifndef lee  
#define lee  

#include <stdio.h>
#include <stdlib.h>
#include"crearMatriz.h"
double **leerMatriz(int filas, int columnas) {
    double **matriz = crearMatriz(filas, columnas);
    if (matriz == NULL) {
        printf("Error: No se pudo asignar memoria para la matriz.\n");
        return NULL;
    }
        printf("Introduce los elementos de la matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    return matriz;
}
#endif