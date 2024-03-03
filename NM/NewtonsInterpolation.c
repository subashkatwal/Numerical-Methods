#include <stdio.h>

float divided_difference(float x[], float y[], int n, int i, int j) {
    if (j == i) {
        return y[i];
    } else {
        return (divided_difference(x, y, n, i+1, j) - divided_difference(x, y, n, i, j-1)) / (x[j] - x[i]);
    }
}

float newton_interpolation(float x[], float y[], int n, float xp) {
    float result = y[0];
    float term = 1.0;
    for (int i = 1; i < n; i++) {
        term *= (xp - x[i-1]);
        result += divided_difference(x, y, n, 0, i) * term;
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

    /* Newton's divided difference interpolation */
    float interpolated_value = newton_interpolation(x, y, num_points, xp);
    printf("Interpolated value at %0.3f is %0.3f\n", xp, interpolated_value);

    return 0;
}

