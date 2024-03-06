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


// Newtons Raphson method

// #include<stdio.h>
// #include<math.h>
// #define e 2.71828
// #define f(x) (cos(x) + 2*sin(x)+ x*x)

// int main(){
//        float x0 ,x1,E,x2,Error;
    

//     printf("Enter two initial guesses : \n");
//     scanf("%f%f",&x0, &x1);
//     printf(" Enter precision :");
//     scanf("%f",&E);
//     //derivative f(x )
//     float f_x0=x0;
// float f_x1=x1;
// do{
//     x2= x1- ((f(x1)*(x1-x0))/ (f(x1)-f(x0)));
//    //Absolute error ko lagi
//     Error=fabs(x2-x1)/fabs(x2);
//     printf(" Iterations are : \n x0 = %.5f, x1 = %.5f, x2 = %.5f , f(x2) = %.5f , Error = %.5f \n", x0 , x1, x2, f(x2),Error);
//     if (Error>E){
//         x0=x1;
//         x1=x2;
//     }
//     else{
//         printf("Roots is :%.2f\n ",x2);
//         break;
//     }
//     }while(1);
// return 0;
// }


// #include<stdio.h>
// #include<math.h>
// #define f(x) pow(x, 2) - 3
// #define g(x) 2*x

// int main(){
//     float x0, E, x2, Error;
//     printf("Enter initial guesses : \n");
//     scanf("%f",&x0);
//     printf(" Enter precision :");
//     scanf("%f",&E);

// do{
//     float c, d, e;
//     c = f(x0);
//     d = g(x0);
//     e = (c/d);
    
//     x2 = x0 - e;
//     printf("%.2f", x2);


//     // printf("\n%.5f", x0);
//    //Absolute error ko lagi
//     Error=x0-x2;
//     printf(" Iterations are : \nx2 = %.5f , f(x2) = %.5f , Error = %.5f \n", x2, f(x2),Error);
//     if (Error>E){
//         x0=x2;
//     }
//     else{
//         printf("Roots is :%.2f\n ",x2);
//         break;
//     }
//     }while(1);
// return 0;
// }


// #include <stdio.h>
// #include <math.h>

// #define e 2.71828
// #define f(x) (cos(x) + 2*sin(x) + x*x)

// int main() {
//     float x0, x1, E, x2, Error;

//     printf("Enter two initial guesses: \n");
//     scanf("%f%f", &x0, &x1);

//     // Check that initial guesses are distinct
//     if (x0 == x1) {
//         printf("Please enter distinct initial guesses.\n");
//         return 1;
//     }

//     printf("Enter precision: ");
//     scanf("%f", &E);

//     do {
//         x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - f(x0)));

//         // Absolute error calculation
//         Error = fabs(x2 - x1);

//         printf("Iteration: x0 = %.5f, x1 = %.5f, x2 = %.5f, f(x2) = %.5f, Error = %.5f\n", x0, x1, x2, f(x2), Error);

//         if (Error < E) {
//             printf("Root found: %.5f\n", x2);
//             break;
//         }

//         x0 = x1;
//         x1 = x2;
//     } while (1);

//     return 0;
// }


 