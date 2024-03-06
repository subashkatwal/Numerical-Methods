
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 50

int main() {
    int i, n;
    float x[MAX_SIZE], y[MAX_SIZE], sx = 0, s_lgy = 0, sxy = 0, sx2 = 0;
    float a, b;
    int choice;

    printf("----------Subash Katwal---------\n");
    printf("Enter the number of data points:\n");
    scanf("%d", &n);

    printf("Enter the data points (x y):\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    while (1) { // Infinite loop until break
        // Reset summation variables
        sx = 0;
        s_lgy = 0;
        sxy = 0;
        sx2 = 0;

        // Calculate summations
        for (i = 0; i < n; i++) {
            sx += x[i];
            s_lgy += log(y[i]);
            sxy += x[i] * log(y[i]);
            sx2 += x[i] * x[i];
        }

        // Ask for equation type
        printf("Choose the equation type:\n");
        printf("1. y = ax^b\n");
        printf("2. y = ae^(bx)\n");
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0)
            break; // Exit the loop if the user chooses to exit

        // Perform the chosen calculation
        switch(choice) {
            case 1:
                b = ((n * sxy) - (sx * s_lgy)) / ((n * sx2) - (sx * sx));
                a = exp((s_lgy - b * sx) / n);
                printf("The equation in the form y = ax^b is: y = %.2f * x^%.3f\n", a, b);
                break;
            case 2:
                b = ((n * sxy) - (sx * s_lgy)) / ((n * sx2) - (sx * sx));
                a = exp((s_lgy - b * sx) / n);
                printf("The equation in the form y = ae^(bx) is: y = %.4f * exp(%.3f * x)\n", a, b);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
