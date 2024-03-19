#include <stdio.h>
#include<conio.h>
void solveLinearSystem(int n, float l[n][n], float u[n][n], float b[n], float x[n]) {
    // Forward substitution for Ly = b
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < i; j++) {
            sum += l[i][j] * x[j];
        }
        x[i] = b[i] - sum;
    }

    // Backward substitution for Ux = y
    for (int i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += u[i][j] * x[j];
        }
        x[i] = (x[i] - sum) / u[i][i];
    }
}

int main() {
    int n, i, j, k;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    float original_mat[n][n], l[n][n], u[n][n], b[n], x[n];

    printf("Enter the data inside the matrix below:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &original_mat[i][j]);
        }
    }

    printf("\nEnter the elements of the RHS vector :\n");
    for (i = 0; i < n; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    // Doolittle LU Decomposition
    for (i = 0; i < n; i++) {
        // Upper Triangular
        for (j = i; j < n; j++) {
            float sum = 0;
            for (k = 0; k < i; k++) {
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = original_mat[i][j] - sum;
        }

        // Lower Triangular
        for (j = i; j < n; j++) {
            if (i == j)
                l[i][i] = 1;
            else {
                float sum = 0;
                for (k = 0; k < i; k++) {
                    sum += l[j][k] * u[k][i];
                }
                l[j][i] = (original_mat[j][i] - sum) / u[i][i];
            }
        }
    }

    // Solve the system of linear equations
    solveLinearSystem(n, l, u, b, x);

    // Display the solution
    printf("\nThe solution of the given system is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i + 1, x[i]);
    }

    return 0;
}