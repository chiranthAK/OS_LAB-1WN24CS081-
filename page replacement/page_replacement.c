#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f, i, j, k, faults;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    faults = 0;
    int index = 0;
    for(i = 0; i < f; i++) frame[i] = -1;

    printf("\nFIFO:\n");
    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }

        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Page Faults = %d\n", faults);

    int time[10], count = 0;
    faults = 0;

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU:\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
            }
        }

        if(!found) {
            int pos = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;
        }

        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Page Faults = %d\n", faults);

    faults = 0;
    for(i = 0; i < f; i++) frame[i] = -1;

    printf("\nOptimal:\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos = -1, farthest = i;

            for(j = 0; j < f; j++) {
                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }

                if(k == n) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
            faults++;
        }

        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n", faults);

    return 0;
}

