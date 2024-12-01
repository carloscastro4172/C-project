#include <stdio.h>
#include <stdlib.h>


// Función para restar dos matrices A y B de las mismas dimensiones
double** restarMatrices(double** A, double** B, int filas, int columnas) {
    double** resultado = crearMatriz(filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
    return resultado;
}