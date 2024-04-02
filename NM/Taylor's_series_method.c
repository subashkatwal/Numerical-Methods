#include <stdio.h>
#include <math.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
    
// Partial derivative with respect to x
float partial_derivative_x(float x, float y) {
    return 2 * x + y;
}


float taylor_series(float x, float y, float h, int n) {
    float result = y;
    for (int i = 1; i <= n; i++) {
        float deriv_x = partial_derivative_x(x, y);
        result += deriv_x * h / factorial(i);
        x += h;
        y = result;
    }
    return result;
}

int main() {
    float x, y, h, x_eval;
    int n;
    printf("Enter the initial values of x and y: ");
    scanf("%f%f", &x, &y);

    printf("Enter the step size: ");
    scanf("%f", &h);

    printf("Enter the number of steps: ");
    scanf("%d", &n);

    printf("Enter the value of x at which y is to be evaluated: ");
    scanf("%f", &x_eval);

  
    float result = taylor_series(x, y, h, n);

  
    printf("The result of y(%.3f) is: %.3f\n", x_eval, result);

    return 0;
}
