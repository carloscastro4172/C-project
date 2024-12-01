
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrand.h"
#include "imprimirMatriz.h"
#include "liberarMatriz.h"
#include "transponerMatriz.h"
#include "concatenarMatriz.h"
#include "normaFrobenius.h"
#include "aplicarMascara.h"

// Función principal
int main() {
    
    int filas = 3, columnas = 3;

    // Crear matrices dinámicas
    double **gradW = crearMatriz(filas, columnas);
    double **W = crearMatriz(filas, columnas);


    // Inicializar valores
    double gradW_valores[3][3] = {
        {1.0, -2.0, 3.0},
        {4.0, -5.0, 6.0},
        {-7.0, 8.0, -9.0}
    };

    double W_valores[3][3] = {
        {-1.0, 0.0, 2.0},
        {1.0, -1.0, 0.0},
        {3.0, -3.0, 4.0}
    };

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            gradW[i][j] = gradW_valores[i][j];
            W[i][j] = W_valores[i][j];
        }
    }
    double *resultado = NULL;
    int tamaño = 0;
    // Aplicar máscara
    aplicarMascara(gradW, W, filas, columnas,&resultado,&tamaño);

       printf("Elementos seleccionados:\n");
    for (int i = 0; i < tamaño; i++) {
        printf("%6.2f ", resultado[i]);
    }
    printf("\n");

    // Liberar memoria
    liberarMatriz(gradW, filas);
    liberarMatriz(W, filas);

    return 0;
}
