//Secant method
#include<stdio.h>
#include<math.h>

float f(float x)
{
    return(2*x*x +4*x-10); // f(x)= x^3-4
}

int main()
{
    float x0, x1, x2, e;
    int count=0, n;
    
    printf("\nEnter the initial guesses x0 and x1:\n");
    scanf("%f%f", &x0, &x1);
    
    printf("Enter the value of allowed error and maximum number of iterations:\n");
    scanf("%f %d", &e, &n);
    
    printf("\n Iteration\t x0\t\t x1\t\t f(x0)\t\t f(x1)\t\t Error\n");
    
    do
    {
        x2 = (x0*f(x1) - x1*f(x0)) / (f(x1) - f(x0));
        float Error = fabs((x2 - x1) / x2);
        
        printf("     %d\t\t %.3f\t\t %.3f\t\t %.3f\t\t %.3f\t\t %.3f\n", count, x0, x1, f(x0), f(x1), Error);
        
        x0 = x1;
        x1 = x2;
        count++;
        
        if(count == n)
            break;
    } while(fabs(f(x2)) > e);
    
    printf("\n The required solution is %.2f\n", x2);
    return 0;
}
