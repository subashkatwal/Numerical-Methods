#include <stdio.h>
#include <math.h>
#define f(x) 3 * pow(x, 2) + 2

int main()
{
    float x, h, y_derivative, y_h, y;
    int i;
    printf("-----------Subash Katwal---------\n");
    printf("Enter the value of x : ");
    scanf("%f", &x);

    printf("Enter the value of h: ");
    scanf("%f", &h);

    y = f(x);
    y_h = f(x - h);
    y_derivative = (y - y_h) / h;
    printf("The the derivative value of y on x = %.2f is %.2f", x, y_derivative);
}