#include <stdio.h>
#include <math.h>

float f(float x, float y, float yp) {
    return x + y - yp; // Example: dy/dx = x + y - y'
}

// numerical integration using Euler's method
void euler_integration(float x0, float y0, float yp0, float h, int steps, float *y_end) {
    float x = x0, y = y0, yp = yp0;
    for (int i = 0; i < steps; i++) {
        float slope = f(x, y, yp);
        y += h * yp;
        yp += h * slope;
        x += h;
    }
    *y_end = y;
}

float shooting_method(float a, float b, float alpha, float beta, float guess, float h, float tolerance) {
    float y_end, yp_guess = guess;
    int steps = (int)((b - a) / h);
    do {
        euler_integration(a, alpha, yp_guess, h, steps, &y_end);
        yp_guess -= (y_end - beta) / (2 * (b - a)); 
    } while (fabs(y_end - beta) > tolerance);

    return yp_guess;
}

int main() {
    float a, b, alpha, beta, guess, h, tolerance;

    // Ask for user input
    printf("Enter the value of a: ");
    scanf("%f", &a);

    printf("Enter the value of b: ");
    scanf("%f", &b);

    printf("Enter the value of alpha: ");
    scanf("%f", &alpha);

    printf("Enter the value of beta: ");
    scanf("%f", &beta);

    printf("Enter the initial guess for y'(a): ");
    scanf("%f", &guess);

    printf("Enter the step size (h): ");
    scanf("%f", &h);

    printf("Enter the tolerance: ");
    scanf("%f", &tolerance);

    float yp_solution = shooting_method(a, b, alpha, beta, guess, h, tolerance);

    printf("The solution for y'(0) using the shooting method: %.6f\n", yp_solution);

    return 0;
}
