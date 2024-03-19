#include <stdio.h>
#include<math.h>

int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}

int main() {
    int n, i, j,k;
    float xv, fx[10], x[10], h, u, v,t1,t2, p, a[10];

    printf("Enter the number of points:");
    scanf("%d", &n);

    printf("Enter the value at which derivative is required:");
    scanf("%f", &xv);

    for (i = 0; i < n; i++) {
        printf("Values of X and f(X) at i = %d\n", i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    for (i = 0; i < n; i++)
        a[i] = fx[i];

    for (i = n-1; i>0;i--) {
        for (j = 0; j < i; j++) {
            a[j] = a[j + 1] - a[j];
        }
    }

    h = x[1] - x[0];
    u = (xv - x[n - 1]) / h;
    p = 1;
    v = a[n - 2];

//calculating derivative
    for (i = 2; i < n; i++)
    {
        t1 = 1;
        for (k = 2; k <= i; k++)
        {
            t1 = t1 * (u + k - 2);
        }
        t2 = (u + i - 1) * p;
        p = (t1 + t2);
        v = v + (a[n-i-1] * (t1 + t2)) / fact(i);
    }
    v = v / h;

    printf("The Value of first derivative   is: %f\n", v);

    return 0;
}
