#include <stdio.h>
#include <stdlib.h>

// Multiplica dos matrices: matA de tamaño filasA x columnasA y matB de tamaño filasB x columnasB
// El resultado se almacena en la matriz 'resultado' de tamaño filasA x columnasB
void multMatrices(double **matA, int filasA, int columnasA, 
                  double **matB, int filasB, int columnasB,
                  double **resultado) {
    if (columnasA != filasB) {
        printf("Error: Las dimensiones no son compatibles para la multiplicación.\n");
        return;
    }

    // Realizar la multiplicación de matrices
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            resultado[i][j] = 0.0; // Inicializar la posición resultado[i][j] en 0
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += matA[i][k] * matB[k][j]; // Sumar el producto
            }
        }
    }
}