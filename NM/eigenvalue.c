#include <stdio.h>
#include <conio.h>
#include <math.h>

float calculate_absolute_difference(float num1, float num2) {
    if(num1 < num2) {
        return num2 - num1;
    }
    return num1 - num2;
}

int main() {
    int order_of_matrix, i, j, step = 1;
    printf("----------Subash katwal--------\n");
    printf("Enter the order of the matrix: ");
    scanf("%d", &order_of_matrix);

    float coefficient_matrix[order_of_matrix][order_of_matrix], initial_guess[order_of_matrix], updated_guess[order_of_matrix];
    float temp, new_eigenvalue, old_eigenvalue, tolerance, stored_value;

    printf("Enter Tolerable Error: ");
    scanf("%f", &tolerance);

    /* Input coefficients for the matrix */
    printf("Enter Coefficients of Matrix:\n");
    for (i = 0; i < order_of_matrix; i++) {
        for (j = 0; j < order_of_matrix; j++) {
            printf("coefficient_matrix[%d][%d] = ", i, j);
            scanf("%f", &coefficient_matrix[i][j]);
        }
    }

    /* Read Initial Guess Vector */
    printf("Enter Initial Guess Vector:\n");
    for (i = 0; i < order_of_matrix; i++) {
        printf("initial_guess[%d] = ", i);
        scanf("%f", &initial_guess[i]);
    }

    /* Initialize Old Eigenvalue */
    old_eigenvalue = 1;

    /* Matrix Multiplication */
    do {
        for (i = 0; i < order_of_matrix; i++) {
            temp = 0.0;
            for (j = 0; j < order_of_matrix; j++) {
                temp += coefficient_matrix[i][j] * initial_guess[j];
            }
            updated_guess[i] = temp;
        }

        /* Replace */
        for (i = 0; i < order_of_matrix; i++) {
            initial_guess[i] = updated_guess[i];
        }

        /* Find Largest Eigenvalue */
        new_eigenvalue = fabs(initial_guess[0]);
        for (i = 1; i < order_of_matrix; i++) {
            if (fabs(initial_guess[i]) > new_eigenvalue) {
                new_eigenvalue = fabs(initial_guess[i]);
            }
        }

        /* Normalize */
        for (i = 0; i < order_of_matrix; i++) {
            initial_guess[i] /= new_eigenvalue;
        }

        /* Display */
        printf("\n\nSTEP-%d:\n", step);
        printf("Eigen Value = %f\n", new_eigenvalue);
        printf("Eigen Vector:\n");
        for (i = 0; i < order_of_matrix; i++) {
            printf("%f\t", initial_guess[i]);
        }

        /* Check Accuracy */
        if (fabs(new_eigenvalue - old_eigenvalue) > tolerance) {
            stored_value = old_eigenvalue;
            old_eigenvalue = new_eigenvalue;
            step++;
        } else {
            break;
        }
    } while (fabs(stored_value - new_eigenvalue) > tolerance);

    return 0;
}
