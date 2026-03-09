#include <stdio.h>

int main()
{
    int n,i,choice;
    int at[20],bt[20],rt[20];
    int wt[20]={0},tat[20]={0},done[20]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Arrival Time P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }

    printf("\n1. SJF Non Preemptive\n2. SJF Preemptive\nEnter choice: ");
    scanf("%d",&choice);

    int time=0,completed=0,remain=n;
    float awt=0,atat=0;

    if(choice==1)
    {
        while(completed<n)
        {
            int min=-1;

            for(i=0;i<n;i++)
                if(at[i]<=time && done[i]==0)
                    if(min==-1 || bt[i]<bt[min])
                        min=i;

            if(min==-1)
            {
                time++;
                continue;
            }

            wt[min]=time-at[min];
            time+=bt[min];

            tat[min]=wt[min]+bt[min];

            done[min]=1;
            completed++;

            awt+=wt[min];
            atat+=tat[min];
        }
    }

    else if(choice==2)
    {
        while(remain!=0)
        {
            int smallest=-1;

            for(i=0;i<n;i++)
                if(at[i]<=time && rt[i]>0)
                    if(smallest==-1 || rt[i]<rt[smallest])
                        smallest=i;

            if(smallest==-1)
            {
                time++;
                continue;
            }

            rt[smallest]--;
            time++;

            if(rt[smallest]==0)
            {
                remain--;

                tat[smallest]=time-at[smallest];
                wt[smallest]=tat[smallest]-bt[smallest];

                awt+=wt[smallest];
                atat+=tat[smallest];
            }
        }
    }

    printf("\nProcess\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\n",i+1,wt[i],tat[i]);

    printf("\nAverage WT = %.2f",awt/n);
    printf("\nAverage TAT = %.2f",atat/n);

    return 0;
}
