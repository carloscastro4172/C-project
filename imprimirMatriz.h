#ifndef IMP
#define IMP

#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(double **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

#endif