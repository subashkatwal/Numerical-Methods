#include <stdio.h>
#include <math.h>
#define f(x) 3*pow(x,3)+2*pow(x,2)+3

int main()
{
    float x, h, y_derivative, y_h_add, y_h_sub, y;
    int i;
    printf("-----------Subash Katwal---------\n");
    printf("Enter the value of x to find derivative at : ");
    scanf("%f", &x);

    printf("Enter the value of h: ");
    scanf("%f", &h);

    y = f(x);
    y_h_add = f(x + h);
    y_h_sub = f(x-h);
    y_derivative = (y_h_add - 2*y +y_h_sub) / pow(h, 2);
    printf("The the derivative value of y on x = %.2f is %.2f", x, y_derivative);
}