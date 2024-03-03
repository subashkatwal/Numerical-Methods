
#include<stdio.h>

int main() {
    int i, n, x[15], y[15], sx=0, sy=0, sxy=0, sx2=0;
    float a, b;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Give the data points (x,y): \n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for(i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2 += x[i] * x[i];
    }
    printf("Calculation table for fitting line : \n");
    printf("\n");
    printf("S.N \t\t x\t\t y\t\t x*x\t\t x*y\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, x[i], y[i], x[i] * x[i], x[i] * y[i]);
    }

    
    // Print the sum values
    printf("Sum\t\t %d\t\t %d\t\t %d\t\t %d\n", sx, sy, sx2, sxy);

    b = (n * sxy - sx * sy) / (float)(n * sx2 - sx * sx);

    a = (sy - b * sx) / (float)n;

    printf("The values of parameters are:\n");
    printf("Slope (b)     : %.1f\n", b);
    printf("Intercept (a) : %.1f\n", a);

    printf("The equation is: y = %.1f x + %.1f\n", b, a);

    return 0;
}
