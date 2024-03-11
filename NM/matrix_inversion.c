#include <stdio.h>
int main()
{
    int n, count = 0, i, j, k;
    printf("----------Subash Katwal---------\n");
    printf("Enter the order of square matrix: ");
    scanf("%d", &n);

    float matrix[n][2*n], temp, root[n];
    printf("Enter the element inside the matrix below: \n");
    for (i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }
    for(i = 0; i<n; i++){
        for(j = n; j<(2*n); j++){
            if(j-i == n){
                matrix[i][j] = 1;
            }else{
                matrix[i][j] = 0;
            }
        }
    }

    printf("The provided Augmented matrix is: \n");
    for (i = 0; i < n; i++){
        for (int j = 0; j < 2*n; j++){
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < n; i++)
    {
        if (matrix[i][i] == 0)
        {
            for (j = i + 1; j < n; j++)
            {
                if (matrix[j][i] != 0)
                {
                    for (k = 0; k < 2*n; k++)
                    {
                        float temp;
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }
                    break;
                }
                else
                {
                    count++;
                }
            }
        }
        if (matrix[i][i] != 1)
        {
            j = i;
            temp = matrix[i][i];
            while (j < 2*n)
            {
                matrix[i][j] = matrix[i][j] / temp;
                j++;
            }
        }

        for (j = i + 1; j < n; j++)
        {
            temp = matrix[j][i];
            for (k = i; k < 2*n; k++)
            {
                matrix[j][k] = matrix[j][k] - (temp * matrix[i][k]);
            }
        }
    }

    for (i = n - 1; i > 0; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            temp = matrix[j][i];
            for (k = i; k < 2*n; k++)
            {
                matrix[j][k] -= temp * matrix[i][k];
            }
        }
    }

    printf("After solving the Augmented matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}