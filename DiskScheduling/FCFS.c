/* ================================================ */
/* ===== Disk scheduling - FCFS (Madhav Bahl) ===== */
/* ================================================ */

#include<stdio.h>
int main() {

    // Variable declaration
    int nc,nt,head,track[100],i,j,distance=0;

    // Read the initial values
    printf("Enter the number of cylinders (0 to n-1): n = ");
    scanf("%d",&nc);
    printf("Enter the number of requested tracks: ");
    scanf("%d",&nt);
    printf("Enter the current location of pointer head: ");
    scanf("%d",&head);
    track[0] = head;
    printf("Enter the requested tracks in FIFO orider: \n");
    for(i=1;i<=nt;i++) {
        scanf("%d",&track[i]);
    }

    // Display the order in which requested tracks are processed
    printf("The equested tracks are processed in order: %d -> ",head);
    for(i=1;i<=nt;i++) {
        if(i!=nt)
            printf("%d -> ",track[i]);
        else
            printf("%d \n",track[i]);
    }

    // find the seek distance
    for(i=0;i<nt;i++) {
        if(track[i]>track[i+1]) {
            distance+=track[i]-track[i+1];
        } else {
            distance+=track[i+1]-track[i];
        }
    }

    // Display the result
    printf("The total seek distance is %d cylinders\n",distance);
}
