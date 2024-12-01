#ifndef LIB
#define LIB


#include <stdio.h>
#include <stdlib.h>

// Función para liberar la memoria de una matriz dinámica
void liberarMatriz(double **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
#endif