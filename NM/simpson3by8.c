#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x) {
    return exp(x); // e^x
}

// Function to calculate the normal Simpson's 3/8 rule
float simpsonsThreeEighth(float lower_val, float upper_val, int interval) {
    float h = (upper_val - lower_val) / interval;
    float sum = 0;

    for (int i = 0; i <= interval; i++) {
        float x = lower_val + i * h;
        if (i == 0 || i == interval) {
            sum += func(x);
        } else if (i % 3 == 0) {
            sum += 2 * func(x);
        } else {
            sum += 3 * func(x);
        }
    }

    return 3 * h * sum / 8;
}

// Function to calculate the composite Simpson's 3/8 rule
float compositeSimpsonsThreeEighth(float lower_val, float upper_val, int interval) {
    float h = (upper_val - lower_val) / interval;
    float sum = func(lower_val) + func(upper_val); // Adding endpoints

    for (int i = 1; i < interval; i++) {
        float x = lower_val + i * h;
        if (i % 3 == 0) {
            sum += 2 * func(x);
        } else {
            sum += 3 * func(x);
        }
    }

    return 3 * h * sum / 8;
}

int main() {
    float lower_val, upper_val;
    int interval, method;

    do {
        printf("Enter the lower and upper limits: ");
        scanf("%f %f", &lower_val, &upper_val);
        
        getchar();

        printf("Enter the number of intervals: ");
        scanf("%d", &interval);
        
        
        getchar();

        printf("Choose the method:\n");
        printf("1. Simpson's 3/8 Rule\n");
        printf("2. Composite Simpson's 3/8 Rule\n");
        printf("3. Exit!\n");
        printf("Enter your choice: ");
        scanf("%d", &method);

        float result;
        switch (method) {
            case 1:
                result = simpsonsThreeEighth(lower_val, upper_val, interval);
                printf("The value of integration using Simpson's 3/8 Rule is: %f\n", result);
                break;
            case 2:
                result = compositeSimpsonsThreeEighth(lower_val, upper_val, interval);
                printf("The value of integration using Composite Simpson's 3/8 Rule is: %f\n", result);
                break;
            case 3:
                exit(0); 
            default:
                printf("Invalid choice\n");
                continue; 
        }

    } while (1);

    return 0;
}
