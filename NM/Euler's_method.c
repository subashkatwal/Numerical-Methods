#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float function(float x, float y) {
    return (x*x + y*y);
}

void Euler(float x0, float y0, float x[], float result[], float h, int iterations) {
    float y = y0;
    for (int i = 0; i < iterations; i++) {
        result[i] = y;
        x[i] = x0;
        y = y + h * function(x0, y);
        x0 += h;
    }
}

int main() {
    float x0, y0, x[100], result[100], h;
    int iterations;
    printf("Enter the initial value of x and y respectively:\n");
    scanf("%f%f", &x0, &y0);

    printf("Enter the step size:\n");
    scanf("%f", &h);

    printf("Enter the number of iterations:\n");
    scanf("%d", &iterations);

    Euler(x0, y0, x, result, h, iterations);

    for (int i = 0; i < iterations; i++) {
        printf("The function at x=%.3f is %.3f\n ", x[i], result[i]);
    }
    return 0;
}
