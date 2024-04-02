#include <stdio.h>
#include <math.h>

// Define the function f(x, y) representing the ordinary differential equation dy/dx = f(x, y)
float f(float x, float y) {
    return x + y; 
}

// Perform one iteration of Picard's method
float picards_method(float x, float y, float h) {
    return y + h * f(x, y); // Approximation using the formula: y_i+1 = y_i + h * f(x_i, y_i)
}

int main() {
    float x0, y0, h, x_end;
    int N;

    // Input initial values, step size, number of iterations, and end point
    printf("Enter the initial value of x and y: ");
    scanf("%f%f", &x0, &y0);

    printf("Enter the step size (h): ");
    scanf("%f", &h);

    printf("Enter the number of iterations (N): ");
    scanf("%d", &N);

    printf("Enter the end point (x_end): ");
    scanf("%f", &x_end);

    // Perform Picard's method
    float y = y0;
    for (int i = 0; i < N; i++) {
        y = picards_method(x0, y, h);
        x0 += h;
    }

    // Output the final approximation
    printf("The approximation of y(%.3f) using Picard's method after %d iterations is: %.5f\n", x_end, N, y);

    return 0;
}
