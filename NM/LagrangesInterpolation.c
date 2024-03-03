#include <stdio.h>

float lagrange_interpolation(float x[], float y[], int n, float xp) {
    float result = 0.0;
    for (int j = 0; j < n; j++) {
        float term = y[j];
        for (int m = 0; m < n; m++) {
            if (m != j) {
                term *= (xp - x[m]) / (x[j] - x[m]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    int num_points;
    printf("----------Subash katwal-----------\n");
    printf("Enter the number of data points: ");
    scanf("%d", &num_points);

    float x[num_points], y[num_points];

    /* Inputs */
    printf("Enter coordinates of the data points:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point %d (x%d, y%d): ", i+1, i, i);
        scanf("%f%f", &x[i], &y[i]);
    }

    /* Interpolation point */
    float xp;
    printf("Enter interpolation point (xp): ");
    scanf("%f", &xp);
    /* Lagrange interpolation */
    float interpolated_value = lagrange_interpolation(x, y, num_points, xp);
    printf("Interpolated value at %0.3f is %0.3f\n", xp, interpolated_value);

    return 0;
}
