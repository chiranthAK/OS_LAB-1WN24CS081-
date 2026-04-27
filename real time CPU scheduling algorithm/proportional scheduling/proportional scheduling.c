#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], remaining[n];
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        printf("P%d Weight: ", i+1);
        scanf("%d", &wt[i]);

        remaining[i] = bt[i];
        total_weight += wt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while (total_weight > 0) {
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                int slice = (wt[i] * tq) / total_weight;
                if (slice <= 0) slice = 1;

                printf("Running P%d for %d units\n", i+1, slice);

                remaining[i] -= slice;

                if (remaining[i] <= 0) {
                    printf("P%d completed\n", i+1);
                    total_weight -= wt[i];
                }
            }
        }
    }

    return 0;
}

