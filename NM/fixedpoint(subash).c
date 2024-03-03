// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>


// #define f(x) (x*x -5*x +8)
// #define g(x) (2*x-5)

// int main()
// {
// 	 int step=1, N;
// 	 float x0, x1, e;
// 	 /* Inputs */
// 	 printf("Enter initial guess: ");
// 	 scanf("%f", &x0);
// 	 printf("Enter tolerable error: ");
// 	 scanf("%f", &e);
// 	 printf("Enter maximum iteration: ");
// 	 scanf("%d", &N);
// 	 /* Implementing Fixed Point Iteration */
// 	 printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
// 	 do
// 	 {
// 		  x1 = g(x0);
// 		  printf("%d\t%f\t%f\t%f\t%f\n",step, x0, f(x0), x1, f(x1));
		
// 		  step = step + 1;
		
// 		  if(step>N)
// 		  {
// 			   printf("Not Convergent.");
// 			   exit(0);
// 		  }
		  
// 		  x0 = x1;
		  
// 	 }while( fabs(f(x1)) > e);
	 
// 	 printf("\nRoot is %f", x1);
	
	
// 	 return(0);
// }


//Fixed point iteration 
#include <stdio.h>
#include <math.h>

#define f(x) (1 + 0.5 * sin(x) - x)#define df(x) (0.5 * cos(x) - 1)

int main() {
    float x0, x1, e;
    int step = 1, N;

    /* Inputs */
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);

    /* Implementing Fixed Point Iteration */
    printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do {
        x1 = x0 - f(x0) / df(x0);
        printf("%d\t%f\t%f\t%f\t%f\n", step, x0, f(x0), x1, f(x1));

        step++;

        if (step > N) {
            printf("Not Convergent.");
            return 1;
        }

        if (fabs(x1 - x0) < e) {
            break;
        }

        x0 = x1;

    } while (1);

    printf("\nRoot is %.4f", x1);

    return 0;
}

