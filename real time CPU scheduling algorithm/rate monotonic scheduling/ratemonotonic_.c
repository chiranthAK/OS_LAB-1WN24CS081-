#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    float C[n], T[n], U = 0, bound;


    for (int i = 0; i < n; i++) {
        printf("\nTask %d Execution Time: ", i + 1);
        scanf("%f", &C[i]);

        printf("Task %d Period: ", i + 1);
        scanf("%f", &T[i]);

        U += (C[i] / T[i]);
    }

    bound = n * (pow(2, 1.0 / n) - 1);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (T[i] > T[j]) {
                float temp;

                temp = T[i];
                T[i] = T[j];
                T[j] = temp;

                temp = C[i];
                C[i] = C[j];
                C[j] = temp;
            }
        }
    }

    printf("\nCPU Utilization = %.3f\n", U);
    printf("RMS Bound = %.3f\n", bound);

    if (U <= bound)
        printf("Schedulable using RMS (guaranteed)\n");
    else
        printf("May or may not be schedulable (needs further analysis)\n");

    printf("\nPriority Order (Shortest period = Highest priority):\n");
    for (int i = 0; i < n; i++) {
        printf("Priority %d -> Task (C=%.2f, T=%.2f)\n", i + 1, C[i], T[i]);
    }

    return 0;
}
