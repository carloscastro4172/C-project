#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrand.h"
#include "imprimirMatriz.h"
#include "liberarMatriz.h"
#include "transponerMatriz.h"
#include "concatenarMatriz.h"
#include "normaFrobenius.h"
#include "NMF.h"

int main(void)
{
//Primero creamos las matrices Winit y Hinit
int usuarios = 3;
int n = usuarios;
int movies = 3;
int m = movies;
int latente = 2;
int r = latente;

double **Winit = crearMatriz(n,r);
double **Hinit = crearMatriz(r,m);
double **V = crearMatriz(n,m);
//double **pr = crearMatriz(n,r);
double pr;
//Ahora inicialisamos las matrices random
matrand(Hinit,r,m);
matrand(Winit,n,r);
//
   double valor = 1.0;  // Valor inicial para llenar la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            V[i][j] = valor;  // Asignar el valor a la matriz
            valor += 1.0;      // Incrementar el valor
        }
    }
   imprimirMatriz(V,n,m);
   printf("\n");
   float tol = 0.001;
   int maxiter = 100;

   NMF(V,Winit,Hinit,n, m, r,tol,maxiter);
   
   
    liberarMatriz(Winit, n);
    liberarMatriz(Hinit, r);
    liberarMatriz(V, n);
}