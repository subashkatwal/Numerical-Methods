// //

// #include <stdio.h>

// float factorial(int n) {
//     float fact = 1;
//     for (int i = 2; i <= n; i++) {
//         fact *= i;
//     }
//     return fact;
// }

// float newton_forward_interpolation(float x[], float y[], int n, float xp) {
//     float result = y[0];
//     float term = 1.0;
//     float h = x[1] - x[0];
//     float u = (xp - x[0]) / h;

//     for (int i = 1; i < n; i++) {
//         term *= (u - i + 1) / i;
//         result += term * y[i];
//     }
//     return result;
// }

// float newton_backward_interpolation(float x[], float y[], int n, float xp) {
//     float result = y[n - 1];
//     float term = 1.0;
//     float h = x[1] - x[0];
//     float u = (xp - x[n - 1]) / h;

//     for (int i = 1; i < n; i++) {
//         term *= (u + i - 1) / i;
//         result += term * y[n - 1 - i];
//     }
//     return result;
// }

// int main() {
//     int num_points;
//     printf("Enter the number of data points: ");
//     scanf("%d", &num_points);

//     float x[num_points], y[num_points];

//     /* Inputs */
//     printf("Enter coordinates of the data points:\n");
//     for (int i = 0; i < num_points; i++) {
//         printf("Point %d (x%d, y%d): ", i+1, i, i);
//         scanf("%f%f", &x[i], &y[i]);
//     }

//     /* Interpolation point */
//     float xp;
//     printf("Enter interpolation point (xp): ");
//     scanf("%f", &xp);

//     /* Choose interpolation type */
//     int interpolation_type;
//     printf("Choose interpolation type:\n");
//     printf("1. Newton's Forward Interpolation\n");
//     printf("2. Newton's Backward Interpolation\n");
//     printf("Enter your choice: ");
//     scanf("%d", &interpolation_type);

//     /* Perform interpolation based on the chosen type */
//     float interpolated_value;
//     switch (interpolation_type) {
//         case 1:
//             interpolated_value = newton_forward_interpolation(x, y, num_points, xp);
//             printf("Interpolated value using Newton's Forward Interpolation at %0.3f is %0.3f\n", xp, interpolated_value);
//             break;
//         case 2:
//             interpolated_value = newton_backward_interpolation(x, y, num_points, xp);
//             printf("Interpolated value using Newton's Backward Interpolation at %0.3f is %0.3f\n", xp, interpolated_value);
//             break;
//         default:
//             printf("Invalid choice! Please choose 1 or 2 for interpolation type.\n");
//     }

//     return 0;
// }


// #include <stdio.h>

// float factorial(int n)
// {
//     float fact = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         fact *= i;
//     }
//     return fact;
// }

// float newton_forward_interpolation(float x[], float y[], int n, float xp)
// {
//     float result = y[0];
//     float term = 1.0;
//     float h = x[1] - x[0];
//     float u = (xp - x[0]) / h;

//     for (int i = 1; i < n; i++)
//     {
//         term *= (u - i + 1) / i;
//         result += term * y[i];
//     }
//     return result;
// }

// float newton_backward_interpolation(float x[], float y[], int n, float xp)
// {
//     float result = y[n - 1];
//     float term = 1.0;
//     float h = x[1] - x[0];
//     float u = (xp - x[n - 1]) / h;

//     for (int i = 1; i < n; i++)
//     {
//         term *= (u + i - 1) / i;
//         result += term * y[n - 1 - i];
//     }
//     return result;
// }

// int main()
// {
//     int num_points;
//     printf("Enter the number of data points: ");
//     scanf("%d", &num_points);

//     float x[num_points], y[num_points];

//     /* Inputs */
//     printf("Enter coordinates of the data points:\n");
//     for (int i = 0; i < num_points; i++)
//     {
//         printf("Point %d (x%d, y%d): ", i + 1, i, i);
//         scanf("%f%f", &x[i], &y[i]);
//     }

//     /* Interpolation point */
//     float xp;
//     printf("Enter interpolation point (xp): ");
//     scanf("%f", &xp);

//     /* Choose interpolation type */
//     int interpolation_type;
//     while (1)
//     {
//         printf("\nChoose interpolation type:\n");
//         printf("1. Newton's Forward Interpolation\n");
//         printf("2. Newton's Backward Interpolation\n");
//         printf("Enter your choice: ");
//         scanf("%d", &interpolation_type);

//         /* Perform interpolation based on the chosen type */
//         float interpolated_value;

//         switch (interpolation_type)
//         {
//             while(interpolation_type == 1 && interpolation_type == 2)
//             {
//             case 1:
//                 interpolated_value = newton_forward_interpolation(x, y, num_points, xp);
//                 printf("Interpolated value using Newton's Forward Interpolation at %0.3f is %0.3f\n", xp, interpolated_value);
//                 return 0;
//             case 2:
//                 interpolated_value = newton_backward_interpolation(x, y, num_points, xp);
//                 printf("Interpolated value using Newton's Backward Interpolation at %0.3f is %0.3f\n", xp, interpolated_value);
//                 return 0;
//             default:
//                 printf("Invalid choice! Please choose 1 or 2 for interpolation type.\n");
//             }
//         }
//     }
//     return 0;
// }

#include <stdio.h>

float factorial(int n)
{
    float fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

float newton_forward_interpolation(float x[], float y[], int n, float xp)
{
    float result = y[0];
    float term = 1.0;
    float h = x[1] - x[0];
    float u = (xp - x[0]) / h;

    for (int i = 1; i < n; i++)
    {
        term *= (u - i + 1) / i;
        result += term * y[i];
    }
    return result;
}

float newton_backward_interpolation(float x[], float y[], int n, float xp)
{
    float result = y[n - 1];
    float term = 1.0;
    float h = x[1] - x[0];
    float u = (xp - x[n - 1]) / h;

    for (int i = 1; i < n; i++)
    {
        term *= (u + i - 1) / i;
        result += term * y[n - 1 - i];
    }
    return result;
}

int main()
{
    int num_points;
     printf("----------Subash katwal-----------\n");
    printf("Enter the number of data points: ");
    scanf("%d", &num_points);

    float x[num_points], y[num_points];

    /* Inputs */
    printf("Enter coordinates of the data points:\n");
    for (int i = 0; i < num_points; i++)
    {
        printf("Point %d (x%d, y%d): ", i + 1, i, i);
        scanf("%f%f", &x[i], &y[i]);
    }

    /* Interpolation point */
    float xp;

    /* Choose interpolation type */
    int interpolation_type;
    do
    {
        printf("\nEnter interpolation point (xp): ");
        scanf("%f", &xp);

        printf("\nChoose interpolation type:\n");
        printf("1. Newton's Forward Interpolation\n");
        printf("2. Newton's Backward Interpolation\n");
        printf("Enter your choice (or any other number to exit): ");
        scanf("%d", &interpolation_type);

        /* Perform interpolation based on the chosen type */
        float interpolated_value;

        switch (interpolation_type)
        {
        case 1:
            interpolated_value = newton_forward_interpolation(x, y, num_points, xp);
            printf("Interpolated value using Newton's Forward Interpolation at %0.3f is %0.3f\n", xp, interpolated_value);
            break;
        case 2:
            interpolated_value = newton_backward_interpolation(x, y, num_points, xp);
            printf("Interpolated value using Newton's Backward Interpolation at %0.3f is %0.3f\n", xp, interpolated_value);
            break;
        default:
            printf("Exiting the program...\n");
            return 0;
        }
    } while (1); 

    return 0;
}
