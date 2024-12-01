#ifndef TRANS
#define TRANS
#include <stdio.h>
#include <stdlib.h>
#include "crearMatriz.h"

// Función para transponer una matriz y almacenar el resultado en una matriz preexistente
void transponerMatriz(double **matriz, int filas, int columnas, double **transpuesta) {
    // Realizar la transposición de la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j]; // Asignar valor de la transposición
        }
    }
}
#endif