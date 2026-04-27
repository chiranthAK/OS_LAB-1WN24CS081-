#include <stdio.h>

struct Process {
    int id, at, bt, dt, rt, completed;
};

int main() {
    int n, t = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i+1;
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &p[i].at);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &p[i].bt);
        printf("P%d Deadline: ", i+1);
        scanf("%d", &p[i].dt);

        p[i].rt = p[i].bt;
        p[i].completed = 0;
    }

    while (completed < n) {
        int idx = -1, min_deadline = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && !p[i].completed && p[i].dt < min_deadline) {
                min_deadline = p[i].dt;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].rt--;
            if (p[idx].rt == 0) {
                p[idx].completed = 1;
                completed++;
                printf("P%d completed at time %d\n", p[idx].id, t+1);
            }
        }
        t++;
    }

    return 0;
}


