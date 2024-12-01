#ifndef VECTORMATRIZ
#define VECTORMATRIZ

#include <stdio.h>
#include <stdlib.h>

void vectorMatriz(double *vector, int size, double **matriz, int *filas, int *columnas) {
    *filas = 1; // La matriz tendrá 1 fila
    *columnas = size; // El número de columnas será igual al tamaño del vector

    // Asignar memoria para la matriz de 1 fila y 'size' columnas
    *matriz = (double *)malloc((*filas) * (*columnas) * sizeof(double));
    if (*matriz == NULL) {
        printf("Error al asignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    // Copiar el vector en la matriz (en la primera fila)
    for (int i = 0; i < size; i++) {
        (*matriz)[i] = vector[i];
    }
}
#endif