#include <stdio.h>
#include <stdlib.h>
void copiarMatriz(double **destino, double **origen, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}