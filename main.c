#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float saxpy(float A, float X, float Y);

void saxpy_c(float A, float* X, float* Y, float* Z, int n) {
    for (int i = 0; i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

double measure_kernel_time(void (*kernel)(float, float*, float*, float*, int), float A, float* X, float* Y, float* Z, int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    kernel(A, X, Y, Z, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double measure_kernel_time_assembly(float A, float* X, float* Y, float* Z_assembly, int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < n; i++){
        Z_assembly[i] = saxpy(A, X[i], Y[i]);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main() {


    
    int n;
    printf("input your vector size:");
    scanf_s("%d", &n);
    int vector_size = (1 << n);
    float A = 0;
    float* X = (float*)malloc(vector_size * sizeof(float));
    float* Y = (float*)malloc(vector_size * sizeof(float));
    float* Z = (float*)malloc(vector_size * sizeof(float));
    float* Z_assembly = (float*)malloc(vector_size * sizeof(float));

    int num_iterations = 30;
    double total_time_c = 0.0;
    double total_time_asm = 0.0;

    int check;
    srand(time(NULL));

    for (int i = 0; i < num_iterations; i++) {
        check = 0;
        A = (float)rand() / RAND_MAX;
        for (int j = 0; j < vector_size; j++) {
            X[j] = (float)rand() / RAND_MAX;
            Y[j] = (float)rand() / RAND_MAX;
        }

        double execution_time_c = measure_kernel_time(saxpy_c, A, X, Y, Z, vector_size);

        printf("Result of the first ten elements of vector Z iteration for C (%i):\n", (i+1));
        for (int j = 0; j < 10; j++) {
            printf("%.2f ", Z[j]);
        }

        printf("\n");
        double execution_time_asm = measure_kernel_time_assembly(A, X, Y, Z_assembly, vector_size);
        printf("Result of the first ten elements of vector Z iteration for assembly (%i):\n", (i+1));
        for (int j = 0; j < 10; j++) {
            printf("%.2f ", Z_assembly[j]);
        }

        for (int i = 0; i < vector_size; i++){
            if (Z[i] != Z_assembly[i]) {
                check = 1;
                break;
            }
        }
        if (check == 1) {
            printf("\nthe x86-64 output is not correct");
        }
        else {
            printf("\nthe x86-64 output is correct");
        }
        total_time_c += execution_time_c;
        total_time_asm += execution_time_asm;

        
        printf("\nC execution time: %.6f seconds\n", execution_time_c);
        printf("Assembly execution time: %.6f seconds\n\n", execution_time_asm);
    }

    double average_time_c = total_time_c / num_iterations;
    double average_time_asm = total_time_asm / num_iterations;

    printf("Average execution time (C): %.6f seconds\n", average_time_c);
    printf("Average execution time (Assembly): %.6f seconds\n", average_time_asm);

    free(X);
    free(Y);
    free(Z);

    return 0;
}
