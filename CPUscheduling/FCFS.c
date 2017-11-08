/* ================================= */
/* ====== FCFS Disk Scheduling ===== */
/* ================================= */
#include<stdio.h>
int main() {
    int n,i,j,burstTime[100],waitTime[100],turnTime[100],totwt=0;
    float avg=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the burst time for each process: \n");
    for(i=0;i<n;i++) {
        waitTime[i] = totwt;
        printf(" Burst Time for Process P%d: ",i+1);
        scanf("%d",&burstTime[i]);
        totwt+=burstTime[i];
        turnTime[i] = totwt;
    }

    printf("WAITING TIME \n------------\n");
    for(i=0;i<n;i++) {
        printf("P%d --> %d\n",i+1,waitTime[i]);
    }
    printf("TURN AROUND TIME \n----------------\n");
    for(i=0;i<n;i++) {
        printf("P%d --> %d\n",i+1,turnTime[i]);
    }

    for(i=0;i<n;i++) {
        avg+=waitTime[i];
    }
    printf("The Average Waiting Time Is: %f\n",avg/n);
    avg=0;

    for(i=0;i<n;i++) {
        avg+=turnTime[i];
    }
    printf("The Average Turnaround Time Is: %f\n",avg/n);
    avg=0;
    return 0;
}