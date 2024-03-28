#include <stdio.h>

// Define the function f(x, y) representing the ordinary differential equation dy/dx = f(x, y)
float f(float x, float y) {
    return x*x+ y*y; // Example: dy/dx = x + y
}

// Perform one step of RK4 method
float runge_kutta_step(float x, float y, float h) {
    float k1 = h * f(x, y);
    float k2 = h * f(x + h/2, y + k1/2);
    float k3 = h * f(x + h/2, y + k2/2);
    float k4 = h * f(x + h, y + k3);
    return y + (k1 + 2*k2 + 2*k3 + k4) / 6;
}

int main() {
    float x0, y0, h, x_end;
    int N;

    // Input initial values, step size, number of steps, and end point
    printf("Enter the initial value of x and y: ");
    scanf("%f%f", &x0, &y0);

    printf("Enter the step size (h): ");
    scanf("%f", &h);

    printf("Enter the number of steps (N): ");
    scanf("%d", &N);

    printf("Enter the end point (x_end): ");
    scanf("%f", &x_end);

    // Perform RK4 method
    float y = y0;
    for (int i = 0; i < N; i++) {
        y = runge_kutta_step(x0, y, h);
        x0 += h;
    }

    // Output the final approximation
    printf("The approximation of y(%.3f) using RK4 after %d steps is: %.4f\n", x_end, N, y);

    return 0;
}
