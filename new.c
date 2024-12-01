#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void matrix_multiply(double* A, double* B, double* C, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i * colsB + j] = 0;
            for (int k = 0; k < colsA; ++k) {
                C[i * colsB + j] += A[i * colsA + k] * B[k * colsB + j];
            }
        }
    }
}

void matrix_transpose(double* A, double* At, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            At[j * rows + i] = A[i * cols + j];
        }
    }
}

double vector_norm(double* vec, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

void update_matrix(double* V, double* W, double* H, int rowsV, int colsV, int k, double tol, int maxiter) {
    double* gradH = (double*)malloc(k * colsV * sizeof(double));
    double* WtW = (double*)malloc(k * k * sizeof(double));
    double* WtV = (double*)malloc(k * colsV * sizeof(double));

    for (int iter = 0; iter < maxiter; ++iter) {
        // Compute gradients
        matrix_multiply(W, W, WtW, k, rowsV, k);
        matrix_multiply(W, V, WtV, k, rowsV, colsV);

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < colsV; ++j) {
                gradH[i * colsV + j] = 0;
                for (int l = 0; l < k; ++l) {
                    gradH[i * colsV + j] += WtW[i * k + l] * H[l * colsV + j];
                }
                gradH[i * colsV + j] -= WtV[i * colsV + j];
            }
        }

        // Check convergence
        double projgrad = 0;
        for (int i = 0; i < k * colsV; ++i) {
            projgrad += gradH[i] * gradH[i];
        }
        projgrad = sqrt(projgrad);

        if (projgrad < tol) {
            break;
        }

        // Update H
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < colsV; ++j) {
                H[i * colsV + j] = MAX(H[i * colsV + j] - gradH[i * colsV + j] / WtW[i * k + i], 0);
            }
        }
    }

    free(gradH);
    free(WtW);
    free(WtV);
}

int main() {
    int rowsV = 10, colsV = 5, k = 3;
    double tol = 1e-4;
    int maxiter = 200;

    // Initialize V, W, H
    double V[10 * 5] = {0}; // Populate with random values
    double W[10 * 3] = {0}; // Populate with random values
    double H[3 * 5] = {0};  // Populate with random values

    srand(time(NULL));
    for (int i = 0; i < 10 * 5; ++i) V[i] = (double)rand() / RAND_MAX;
    for (int i = 0; i < 10 * 3; ++i) W[i] = (double)rand() / RAND_MAX;
    for (int i = 0; i < 3 * 5; ++i) H[i] = (double)rand() / RAND_MAX;

    // Perform NMF
    update_matrix(V, W, H, rowsV, colsV, k, tol, maxiter);

    // Print results
    printf("Final H:\n");
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < colsV; ++j) {
            printf("%f ", H[i * colsV + j]);
        }
        printf("\n");
    }

    return 0;
}
