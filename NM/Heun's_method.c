#include <stdio.h>

float function(float x, float y)
{
    return (x * x + y);
}

float Heuns(float xi, float yi, float h, float point)
{
     if (h <= 0) {
        printf("Error: Step size must be positive.\n");
        return 0;
    }
    if (xi >= point) {
        printf("Error: Initial value of x must be less than the point at which the functional value is required.\n");
        return 0;
    }
    float y = yi;
   for (float i = xi; i < point; i += h)

    {
float m1 = function(xi, yi);
float m2 = function(xi + h, yi + h * m1);
float y1 = yi + h / 2 * (m1 + m2);
yi = y1;
xi += h;

    }
    return yi;
}
int main()
{
    float xi, yi, h, point;
    printf("Enter the initial values:");
    scanf("%f%f", &xi, &yi);

    printf("Enter the value at which functional value is required :");
    scanf("%f", &point);

    printf("Enter the step size:\n");
    scanf("%f", &h);

    float result = Heuns(xi, yi, h, point);
    printf("The functional value at x=%.3f is %.3f", point, result);
    return 0;
}