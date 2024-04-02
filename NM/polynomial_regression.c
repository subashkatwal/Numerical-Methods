#include <stdio.h>
#include <math.h>

#define MAX_SIZE 50
#define MAX_DEGREE 5

// Function to perform polynomial regression
void polynomial_regression(float x[], float y[], int n, int degree, float coefficients[]) {
    float X[MAX_SIZE][MAX_DEGREE + 1] = {0}; // Design matrix
    float XT[MAX_DEGREE + 1][MAX_SIZE] = {0}; // Transpose of design matrix
    float XTX[MAX_DEGREE + 1][MAX_DEGREE + 1] = {0}; // X^T * X
    float invXTX[MAX_DEGREE + 1][MAX_DEGREE + 1] = {0}; // Inverse of X^T * X
    float XTY[MAX_DEGREE + 1] = {0}; // X^T * Y

    // Populate the design matrix
    for (int i = 0; i < n; i++) {
        X[i][0] = 1; // First column with 1's for the intercept term
        for (int j = 1; j <= degree; j++) {
            X[i][j] = pow(x[i], j);
        }
    }

    // Calculate X^T
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= degree; j++) {
            XT[j][i] = X[i][j];
        }
    }

    // Calculate X^T * X
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            for (int k = 0; k < n; k++) {
                XTX[i][j] += XT[i][k] * X[k][j];
            }
        }
    }

    // Calculate inverse of X^T * X
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            if (i == j) {
                invXTX[i][j] = 1; // Initialize diagonal elements to 1
            }
            else {
                invXTX[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= degree; i++) {
        float pivot = XTX[i][i];
        for (int j = 0; j <= degree; j++) {
            XTX[i][j] /= pivot;
            invXTX[i][j] /= pivot;
        }
        for (int k = 0; k <= degree; k++) {
            if (k != i) {
                float ratio = XTX[k][i];
                for (int j = 0; j <= degree; j++) {
                    XTX[k][j] -= ratio * XTX[i][j];
                    invXTX[k][j] -= ratio * invXTX[i][j];
                }
            }
        }
    }

    // Calculate X^T * Y
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j < n; j++) {
            XTY[i] += XT[i][j] * y[j];
        }
    }

    // Calculate coefficients
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = 0;
        for (int j = 0; j <= degree; j++) {
            coefficients[i] += invXTX[i][j] * XTY[j];
        }
    }
}

int main() {
    int n, degree;
    float x[MAX_SIZE], y[MAX_SIZE], coefficients[MAX_DEGREE + 1];
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    polynomial_regression(x, y, n, degree, coefficients);

    printf("The coefficients of the polynomial equation are:\n");
    for (int i = 0; i <= degree; i++) {
        printf("a%d = %.3f\n", i, coefficients[i]);
    }

printf("The required polynomial equation is: ");
for (int i = 0; i <= degree; i++) {
    if (i == 0) {
        printf("%.3f", coefficients[i]);
    } else {
        printf(" + %.3f*x^%d", coefficients[i], i);
    }
}
printf("\n");
    return 0;
}
