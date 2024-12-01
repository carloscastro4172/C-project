#ifndef VECTORF
#define VECTORf

#include <stdio.h>
#include <stdlib.h>

// Función para fusionar dos vectores en un tercer vector de resultados
void fusionarVectores(double *vec1, int tam1, double *vec2, int tam2, double *resultado) {
    // Copiar elementos del primer vector al vector resultado
    for (int i = 0; i < tam1; i++) {
        resultado[i] = vec1[i];
    }

    // Copiar elementos del segundo vector al vector resultado después del primero
    for (int i = 0; i < tam2; i++) {
        resultado[tam1 + i] = vec2[i];
    }
}



#endif
