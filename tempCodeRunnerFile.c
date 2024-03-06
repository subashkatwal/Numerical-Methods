#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define E 0.0001
#define f(x) (3 * x * x - 6 * x + 2)

int main()
{
    float xp, xn, xr, f_xp, f_xn, f_xr;
    float root, Error;
    int i = 0;
    printf("Enter initial guesses for xp and xn :\n");
    scanf("%f%f", &xn, &xp);

    f_xn = f(xn);
    f_xp = f(xp);


    if (f_xn * f_xp == 0)
    {
        root = (f_xn==0)?xn:xp;
        printf("Root is :%f\n",root);
        exit(1);
    }
    else if (f_xn * f_xp > 0)
    {
        printf("No root lies between given intervals.\n");
return 0;   
    }
    do {
    xr = (xn + xp) / 2.0;
    f_xr = f(xr);
    printf("Iterations %d: xn = %f , xp = %f , xr = %f , f(xr) = %f\n ", i++, xn, xp, xr, f_xr);

    if (f_xr == 0 || fabs(xp - xn) / fabs(xn) < E) {
        printf("Root is %f\n", xr);
        break;  // Exit the loop if the root is found or the interval is small enough
    } else if (f_xn * f_xr < 0) {
        xp = xr;  // Update xp because f(xn) and f(xr) have opposite signs
    } else {
        xn = xr;  // Update xn because f(xn) and f(xr) have opposite signs
        f_xn = f_xr;
    }
    Error = fabs(xp - xn) / fabs(xn);
} while (Error > E);
printf("Roots are %f\n", xr);
}
