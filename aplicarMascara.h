#ifndef APLICAR_MASCARA
#define APLICAR_MASCARA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "crearMatriz.h"

// Función para aplicar la máscara lógica y devolver un arreglo unidimensional con los valores seleccionados
void aplicarMascara(double **matriz1, double **matriz2, int filas, int columnas, double **resultado, int *tamano_resultado) {
    // Contar los elementos que cumplen la condición
    int count = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz1[i][j] < 0 || matriz2[i][j] > 0) {
                count++;
            }
        }
    }

    // Crear una matriz de una fila con `count` columnas para almacenar los resultados
    *resultado = (double *)malloc(count * sizeof(double));
    if (*resultado == NULL) {
        printf("Error al asignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    // Extraer los valores que cumplen la condición
    int index = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz1[i][j] < 0 || matriz2[i][j] > 0) {
                (*resultado)[index++] = matriz1[i][j];
            }
        }
    }

    // Devolver el tamaño del resultado
    *tamano_resultado = count;
}

#endif
