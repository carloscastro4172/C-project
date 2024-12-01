#ifndef CONCATENARMATRI
#define CONCATENARMATRI

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "crearMatriz.h"

// Función para concatenar dos matrices por filas o por columnas según corresponda
void concatenMatriz(double **matriz1, int filas1, int columnas1, 
                      double **matriz2, int filas2, int columnas2, 
                      double **matriz3, int filas3, int columnas3) {
    // Verificar que las dimensiones de la matriz de salida coincidan con las necesarias
    if ((filas1 == filas2 && columnas3 == columnas1 + columnas2 && filas3 == filas1) ||
        (columnas1 == columnas2 && filas3 == filas1 + filas2 && columnas3 == columnas1)) {
        
        // Concatenar por filas si tienen el mismo número de columnas
        if (columnas1 == columnas2) {
            for (int i = 0; i < filas1; i++) {
                for (int j = 0; j < columnas1; j++) {
                    matriz3[i][j] = matriz1[i][j];
                }
            }
            for (int i = 0; i < filas2; i++) {
                for (int j = 0; j < columnas2; j++) {
                    matriz3[filas1 + i][j] = matriz2[i][j];
                }
            }
        }
        // Concatenar por columnas si tienen el mismo número de filas
        else if (filas1 == filas2) {
            for (int i = 0; i < filas1; i++) {
                for (int j = 0; j < columnas1; j++) {
                    matriz3[i][j] = matriz1[i][j];
                }
                for (int j = 0; j < columnas2; j++) {
                    matriz3[i][columnas1 + j] = matriz2[i][j];
                }
            }
        }
    } else {
        printf("Error: Las dimensiones de las matrices no permiten concatenación.\n");
    }
}

#endif
