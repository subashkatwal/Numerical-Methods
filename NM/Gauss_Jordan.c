#include<stdio.h>
int main(){
    int n, count = 0, i, j, k;
    printf("----------Subash katwal---------\n");
    printf("Enter the order of square matrix: ");
    scanf("%d",&n);

    float matrix[n][n + 1], temp, root[n];
    printf("Enter the element inside the matrix below: \n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n+1; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("The provided Augmented matrix is: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n+1; j++){
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++){
        if (matrix[i][i] == 0){
            for(j = i+1; j<n; j++){
                if (matrix[j][i] != 0){
                    for(k = 0; k<n+1; k++){
                        float temp;
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }
                    break;
                }
                else{
                    count ++;
                }
            }
        }
        if (matrix[i][i] != 1){
            j = i;
            temp = matrix[i][i];
            while (j < n+1){
                matrix[i][j] = matrix[i][j] / temp;
                j++;
            }
        }

        for(j = i+1; j<n; j++){
            temp = matrix[j][i];
            for(k = i; k<n+1; k++){
                matrix[j][k] = matrix[j][k] -(temp * matrix[i][k]);
            }
        }
    }

    for (i = n-1; i>0; i--){
        for (j = i-1; j >= 0; j--){
            temp = matrix[j][i];
            for(k = i; k<n+1; k++){
                matrix[j][k] -= temp * matrix[i][k];
            }
        }
    }

    printf("After solving the Augmented matrix: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }

      printf("Values of x1, x2, and x3:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }
    
}