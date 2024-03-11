#include <stdio.h>
#define f1(x, y, z) (2*y-z+11)/6
#define f2(x, y, z) (2*x-2*z+5)/7
#define f3(x, y, z) (x+2*y+1) / 5

double absolute(double e1, double e2)
{
    if (e1 < e2)
    {
        return e2 - e1;
    }
    return e1 - e2;
}

int main()
{
    double error;
    printf("----------Subash Katwal---------\n");
    printf("Enter the allowed error: ");
    scanf("%lf", &error);

    double x0 = 0, y0 = 0, z0 = 0, e1, e2, e3;
    int count = 1;
    do
    {
        double x1 = f1(x0, y0, z0);
        double y1 = f2(x1, y0, z0);
        double z1 = f3(x1, y1, z0);

        e1 = absolute(x1, x0);
        e2 = absolute(y1, y0);
        e3 = absolute(z1, z0);

        x0 = x1;
        y0 = y1;
        z0 = z1;

        printf("%d\t%.2f\t%.2f\t%.2f\n", count, x1, y1, z1);
        count++;

    } while (e1 > error && e2 > error && e3 > error);

    printf("x = %0.2f, y = %.2f, z = %.2f", x0, y0, z0);
    return 0;
}
