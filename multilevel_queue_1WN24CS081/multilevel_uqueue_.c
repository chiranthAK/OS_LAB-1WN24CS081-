#include <stdio.h>

int main() {
    int ns, nu, i;

    printf("No. of system processes: ");
    scanf("%d", &ns);

    int bt_s[ns], wt_s[ns], tat_s[ns];

    for (i = 0; i < ns; i++) {
        printf("BT of S%d: ", i + 1);
        scanf("%d", &bt_s[i]);
    }

    printf("\nNo. of user processes: ");
    scanf("%d", &nu);

    int bt_u[nu], wt_u[nu], tat_u[nu];

    for (i = 0; i < nu; i++) {
        printf("BT of U%d: ", i + 1);
        scanf("%d", &bt_u[i]);
    }

    wt_s[0] = 0;
    for (i = 1; i < ns; i++)
        wt_s[i] = wt_s[i - 1] + bt_s[i - 1];

    for (i = 0; i < ns; i++)
        tat_s[i] = wt_s[i] + bt_s[i];

    int time = 0;
    for (i = 0; i < ns; i++)
        time += bt_s[i];

    wt_u[0] = time;
    for (i = 1; i < nu; i++)
        wt_u[i] = wt_u[i - 1] + bt_u[i - 1];

    for (i = 0; i < nu; i++)
        tat_u[i] = wt_u[i] + bt_u[i];

    printf("\nSystem Queue:\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < ns; i++)
        printf("S%d\t%d\t%d\t%d\n", i + 1, bt_s[i], wt_s[i], tat_s[i]);

    printf("\nUser Queue:\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < nu; i++)
        printf("U%d\t%d\t%d\t%d\n", i + 1, bt_u[i], wt_u[i], tat_u[i]);

    return 0;
}

