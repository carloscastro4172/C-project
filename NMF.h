#ifndef NMFMA  
#define NMFMA  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "imprimirMatriz.h"
#include "liberarMatriz.h"
#include "transponerMatriz.h"
#include "concatenarMatriz.h"
#include "sumarMatrices.h"
#include "restarMatrices.h"
#include "multMatrices.h"
#include "copiarMatriz.h"
#include "aplicarMascara.h"
#include "vectorMatriz.h"
#include "fusionarVectores.h"
/*
Perform Non-negative Matrix Factorization (NMF) using projected gradients.

    Parameters:
    V : double nxm 
        Input matrix to factor.
    Winit : double nxr
        Initial factor matrix W.
    Hinit : double rxm
        Initial factor matrix H.
    tol :  float 
        Tolerance for the stopping condition.
    maxiter : int
        Maximum number of iterations.
*/
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
/*
    Returns:
    W : numpy.ndarray
        Factor matrix W after NMF.
    H : numpy.ndarray
        Factor matrix H after NMF.
*/
void NMF(double **V, double **Winit, double **Hinit, int n, int m, int r, float tol, int maxiter)
{
double **W = crearMatriz(n, r);
copiarMatriz(W, Winit, n, r);  // Copiar valores de Winit a W

double **H = crearMatriz(r, m);
copiarMatriz(H, Hinit, r, m);  // Copiar valores de Hinit a H

double **WT = crearMatriz(r, n);      // Para la transpuesta de W
double **op1 = crearMatriz(r, r);     // Para H * Ht
double **op2 = crearMatriz(n, r);     // Para V * Ht
double **op3 = crearMatriz(n, r);     // Para W * op1
double **op4 = crearMatriz(n, m);     // Para W * H
double **op5 = crearMatriz(r, m);     // Para W * V
double **op6 = crearMatriz(r, m);     // 
double **gradW = crearMatriz(n, r);   // Para gradW
double **gradH = crearMatriz(r, m);   // Para gradH
double **gradHT = crearMatriz(m, r);   // Para gradHT transpuesta
double **Ht = crearMatriz(m, r);      // Para almacenar la transpuesta de H
double initgrad;
double **concatenar = crearMatriz(n+m,r);
double **vectorc = crearMatriz(2,2*n);
double **vectorW = crearMatriz(1,2*n);
double **vectorH = crearMatriz(1,2*m);

transponerMatriz(H, r, m, Ht);  // Transponer H y almacenar en Ht

multMatrices(H, r, m, Ht, m, r, op1);  // op1 = H * Ht
multMatrices(V, n, m, Ht, m, r, op2);  // op2 = V * Ht
multMatrices(W, n, r, op1, r, r, op3);  // op3 = W * op1
gradW = restarMatrices(op3, op2, n, r);  // gradW = op3 - op2


transponerMatriz(W, n, r, WT);
multMatrices(W, n, r, H, r, m, op4);  // op4 = W * H
multMatrices(WT, r, n, V, n, m, op5);  // op5 = WT * V
multMatrices(WT, r, n, op4, n, m, op6);
gradH = restarMatrices(op6, op5, r, m);


transponerMatriz(gradH,r,m,gradHT);
concatenMatriz(gradW,n,r,gradHT,m,r,concatenar,n+m,r);
initgrad = normaFrobenius(concatenar,n+m,r);

int tolW = tol * initgrad;
int tolH = tolW;


    double *resultado = NULL;
    int tamaño = 0;
    double *resultado2 = NULL;
    int tamaño2 = 0;
    aplicarMascara(gradW,W,n,r,&resultado,&tamaño);
    aplicarMascara(gradH,H,r,m,&resultado2,&tamaño2);
    //Se debe fusionar con un vector completo 
    
    

    



}
#endif