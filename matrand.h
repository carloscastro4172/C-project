#ifndef CONCATENARMATRIZ  
#define CONCATENARMATRIZ  


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrand(double **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (double)rand() / RAND_MAX;  // Valor aleatorio entre 0 y 1
        }
    }
}
#endif