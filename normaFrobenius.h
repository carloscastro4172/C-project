#ifndef norm 
#define norm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función para calcular la norma de Frobenius de una matriz
double normaFrobenius(double **matriz, int filas, int columnas) {
    double suma = 0.0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma += matriz[i][j] * matriz[i][j];
        }
    }
    return sqrt(suma);
}

#endif