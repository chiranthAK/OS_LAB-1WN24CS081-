#include <stdio.h>

void firstFit(int b[], int m, int p[], int n) {
    int i, j;
    printf("\nFirst Fit:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++) {
            if(b[j] >= p[i]) {
                printf("P%d -> B%d\n", i+1, j+1);
                b[j] -= p[i];
                break;
            }
        }
    }
}

void bestFit(int b[], int m, int p[], int n) {
    int i, j, best;
    printf("\nBest Fit:\n");
    for(i=0; i<n; i++) {
        best = -1;
        for(j=0; j<m; j++) {
            if(b[j] >= p[i] && (best == -1 || b[j] < b[best]))
                best = j;
        }
        if(best != -1) {
            printf("P%d -> B%d\n", i+1, best+1);
            b[best] -= p[i];
        }
    }
}

void worstFit(int b[], int m, int p[], int n) {
    int i, j, worst;
    printf("\nWorst Fit:\n");
    for(i=0; i<n; i++) {
        worst = -1;
        for(j=0; j<m; j++) {
            if(b[j] >= p[i] && (worst == -1 || b[j] > b[worst]))
                worst = j;
        }
        if(worst != -1) {
            printf("P%d -> B%d\n", i+1, worst+1);
            b[worst] -= p[i];
        }
    }
}

int main() {
    int m, n, i;
    int block[10], process[10];
    int b1[10], b2[10], b3[10];

    printf("Enter no. of blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    for(i=0; i<m; i++) {
        scanf("%d", &block[i]);
        b1[i] = b2[i] = b3[i] = block[i];
    }

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes:\n");
    for(i=0; i<n; i++)
        scanf("%d", &process[i]);

    firstFit(b1, m, process, n);
    bestFit(b2, m, process, n);
    worstFit(b3, m, process, n);

    return 0;
}

