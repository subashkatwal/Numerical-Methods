#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10

void cholesky(double A[MAX_SIZE][MAX_SIZE], double L[MAX_SIZE][MAX_SIZE], int n) {
    int i, j, k;

    // Initialize the lower triangular matrix L
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            L[i][j] = 0;
        }
    }

    // Perform the Cholesky decomposition
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            double sum = 0;

            if (i == j) {
                for (k = 0; k < j; k++) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

void forward_substitution(double L[MAX_SIZE][MAX_SIZE], double C[MAX_SIZE], double Z[MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * Z[j];
        }
        Z[i] = (C[i] - sum) / L[i][i];
    }
}

int main() {
    int n;
    printf("-----------Subash Katwal-----------\n");
    printf("Enter the order of the matrix (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    double A[MAX_SIZE][MAX_SIZE], L[MAX_SIZE][MAX_SIZE];
    double C[MAX_SIZE], Z[MAX_SIZE];

    printf("Enter the elements of the matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the elements of the vector C:\n");
    for (int i = 0; i < n; i++) {
        printf("C[%d]: ", i);
        scanf("%lf", &C[i]);
    }

    cholesky(A, L, n);

    printf("Enter the values of x, y, and z: ");
    scanf("%lf %lf %lf", &Z[0], &Z[1], &Z[2]);

    forward_substitution(L, C, Z, n);

    printf("The values of Z after solving:\n");
    for (int i = 0; i < n; i++) {
        printf("Z[%d]: %.3f\n", i, Z[i]);
    }

    return 0;
}
