#include <stdio.h>
#include <math.h>

float func(float x) {
    return exp(x); // e^x
}

// Function to calculate the normal trapezoidal rule
float normalTrapezoidalRule(float lower_val, float upper_val, int interval) {
    float h = (upper_val - lower_val) / interval;
    float v = 0.0f;

    for (int i = 0; i < interval; i++) {
        float x0 = lower_val + i * h;
        float x1 = x0 + h;
        v += (func(x0) + func(x1)) / 2 * h; // Trapezoidal rule formula
    }

    return v;
}

// Function to calculate the composite trapezoidal rule
float compositeTrapezoidalRule(float lower_val, float upper_val, int interval) {
    float h = (upper_val - lower_val) / interval;
    float v = (func(lower_val) + func(upper_val)) / 2; // First and last terms in the formula

    for (int i = 1; i < interval; i++) {
        float x = lower_val + i * h;
        v += func(x); // Add function value for each subinterval
    }

    v *= h; // Multiply by h
    return v;
}

int main() {
    float lower_val, upper_val;
    int interval, method;

    do {
        printf("Enter the lower and upper limits: ");
        scanf("%f %f", &lower_val, &upper_val);

        printf("Enter the number of intervals: ");
        scanf("%d", &interval);

        printf("Choose the method:\n");
        printf("1. Normal Trapezoidal Rule\n");
        printf("2. Composite Trapezoidal Rule\n");
        printf("Enter your choice: ");
        scanf("%d", &method);

        float result;
        switch (method) {
            case 1:
                result = normalTrapezoidalRule(lower_val, upper_val, interval);
                break;
            case 2:
                result = compositeTrapezoidalRule(lower_val, upper_val, interval);
                break;
            default:
                printf("Invalid choice\n");
                continue; // Continue to next iteration of the loop if choice is invalid
        }

        printf("The value of integration is: %f\n", result);

        printf("Do you want to continue? (1: Yes, 0: No): ");
        scanf("%d", &method);
    } while (method == 1);

    return 0;
}