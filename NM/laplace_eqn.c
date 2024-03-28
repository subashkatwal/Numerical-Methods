#include <stdio.h>
#include <math.h>

#define SIZE 5 // Size of the grid (e.g., 5x5)

// Function to initialize the grid with boundary conditions
void initialize_grid(float grid[SIZE][SIZE]) {
    // Set boundary conditions
    for (int i = 0; i < SIZE; i++) {
        grid[i][0] = 0; // Left boundary
        grid[i][SIZE - 1] = 0; // Right boundary
    }
    for (int j = 0; j < SIZE; j++) {
        grid[0][j] = 100; // Top boundary
        grid[SIZE - 1][j] = 0; // Bottom boundary
    }
}

// Gauss-Seidel iteration function for Laplace's equation
void gauss_seidel_iteration(float grid[SIZE][SIZE]) {
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            // Update the value of grid[i][j] using the Laplace equation
            grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
        }
    }
}

// Function to print the grid
void print_grid(float grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%.2f\t", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float grid[SIZE][SIZE];
    float tolerance = 1e-6;
    int max_iterations = 1000;

    // Initialize the grid with boundary conditions
    initialize_grid(grid);

    // Perform Gauss-Seidel iteration until convergence or maximum iterations reached
    int iterations;
    for (iterations = 0; iterations < max_iterations; iterations++) {
        float max_diff = 0; // Track the maximum difference between new and old values
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                float old_value = grid[i][j];
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
                float diff = fabs(old_value - grid[i][j]);
                if (diff > max_diff) {
                    max_diff = diff;
                }
            }
        }
        // Check for convergence based on the maximum difference
        if (max_diff < tolerance) {
            break;
        }
    }

    printf("Solution after %d iterations:\n", iterations);
    print_grid(grid);

    return 0;
}
