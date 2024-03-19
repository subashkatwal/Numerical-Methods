#include <stdio.h>
#include<math.h>

int main() {
    int n, i, j,k;
    float xv, factor,fx[10], x[10], v , p, a[10];

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

    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - 1 - i]);
        }
    }

    v =a[1];

    for (i = 2; i < n; i++) {
        p = 0;
        for (j = 0; j < i; j++) {
            factor=1;
            for(k=0;k<i;k++){
                if(k!=j)
                factor=factor*(xv-x[k]);
            }
            p = p + factor;
        }
        v = v +( a[i] * p);
    }

    printf("The Value of first derivative is: %.3f\n", v);

    return 0;
}