/* ============================== */
/* ===== SJF CPU Scheduling ===== */
/* ============================== */
#include<stdio.h>
int main() {
    // Declare the variables
    int n,i,j,process[100],burstTime[100],waitTime[100],turnTime[100],priority[100],totwt=0,temp;
    float avg=0;

    // Input the initial values
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the burst time for each process: \n");
    for(i=0;i<n;i++) {
        printf(" Burst Time for Process P%d: ",i+1);
        scanf("%d",&burstTime[i]);
        process[i]=i;
    }
    printf("Enter the Priority for each process: \n");
    for(i=0;i<n;i++) {
        printf(" Priority for Process P%d: ",i+1);
        scanf("%d",&priority[i]);
    }

    // Arrange burst times in ascending order of priority
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(priority[i]>priority[j]) {
                // swap burstTime
                temp = burstTime[i];
                burstTime[i]=burstTime[j];
                burstTime[j]=temp;
                // swap process queue
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
                // swap priority
                temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;
            }
        }   
    }

    // Assign waiting times and turn times
    for(i=0;i<n;i++) {
        waitTime[i] = totwt;
        totwt+=burstTime[i];
        turnTime[i] = totwt;
    }

    // Print result
    printf("WAITING TIME \n------------\n");
    for(i=0;i<n;i++) {
        printf("P%d --> %d\n",process[i],waitTime[i]);
    }
    printf("TURN AROUND TIME \n----------------\n");
    for(i=0;i<n;i++) {
        printf("P%d --> %d\n",process[i],turnTime[i]);
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