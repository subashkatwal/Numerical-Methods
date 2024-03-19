#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x) {
    return exp(x); // e^x
}

// Function to calculate the normal Simpson's 1/3 rule
float simpsonsOneThird(float lower_val, float upper_val, int interval) {
    float h = (upper_val - lower_val) / interval;
    float sum = 0;

    for (int i = 0; i <= interval; i++) {
        float x = lower_val + i * h;
        if (i == 0 || i == interval) {
            sum += func(x);
        } else if (i % 2 == 1) {
            sum += 4 * func(x);
        } else {
            sum += 2 * func(x);
        }
    }

    return sum * h / 3;
}

// Function to calculate the composite Simpson's 1/3 rule
float compositeSimpsonsOneThird(float lower_val, float upper_val, int interval) {
    float h = (upper_val - lower_val) / interval;
    float sum = func(lower_val) + func(upper_val); // Adding endpoints

    for (int i = 1; i < interval; i++) {
        float x = lower_val + i * h;
        if (i % 2 == 1) {
            sum += 4 * func(x);
        } else {
            sum += 2 * func(x);
        }
    }

    return sum * h / 3;
}

int main() {
    float lower_val, upper_val;
    int interval, method;

    do {
        printf("Enter the lower and upper limits: ");
        scanf("%f %f", &lower_val, &upper_val);
        
        // Consume newline character from the input buffer
        getchar();

        printf("Enter the number of intervals: ");
        scanf("%d", &interval);
        
        // Consume newline character from the input buffer
        getchar();

        printf("Choose the method:\n");
        printf("1. Simpson's 1/3 Rule\n");
        printf("2. Composite Simpson's 1/3 Rule\n");
        printf("3. Exit!\n");
        printf("Enter your choice: ");
        scanf("%d", &method);

        float result;
        switch (method) {
            case 1:
                result = simpsonsOneThird(lower_val, upper_val, interval);
                printf("The value of integration using Simpson's 1/3 Rule is: %f\n", result);
                break;
            case 2:
                result = compositeSimpsonsOneThird(lower_val, upper_val, interval);
                printf("The value of integration using Composite Simpson's 1/3 Rule is: %f\n", result);
                break;
            case 3:
            printf("Exiting the program !");
                exit(0); // Exit the program
            default:
                printf("Invalid choice\n");
                continue; // Continue to next iteration of the loop if choice is invalid
        }

    } while (1);

    return 0;
}