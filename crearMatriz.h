#ifndef CREARMATRIZ_H  // Si no está definido CREARMATRIZ_H
#define CREARMATRIZ_H  // Define CREARMATRIZ_H para que no se vuelva a incluir

#include <stdio.h>
#include <stdlib.h>

// Función para crear una matriz dinámica
double **crearMatriz(int filas, int columnas) {
    // Reservar memoria para los punteros a las filas
    double **matriz = (double **)malloc(filas * sizeof(double *));
    if (matriz == NULL) {
        printf("Error: No se pudo asignar memoria para la matriz.\n");
        exit(EXIT_FAILURE);
    }

    // Reservar memoria para cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = (double *)malloc(columnas * sizeof(double));
        if (matriz[i] == NULL) {
            printf("Error: No se pudo asignar memoria para la fila %d.\n", i);
            exit(EXIT_FAILURE);
        }

        // Inicializar la fila con ceros
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = 0.0; // Inicializar con ceros
        }
    }

    return matriz;
}

#endif  // Fin de la protección
