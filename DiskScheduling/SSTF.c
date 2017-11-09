/* ================================================ */
/* ===== Disk scheduling - SSTF (Madhav Bahl) ===== */
/* ================================================ */

#include<stdio.h>
int main() {

    // Declare variables
    int i,j,head,track[100],nc,n,diff[100],alloc[100],dist=0,min,temp;

    // Read the  initial values
    printf("Enter the number of cylinders (0 to n-1): n = ");
    scanf("%d",&nc);
    printf("Enter the number of requested tracks: ");
    scanf("%d",&n);
    printf("Enter the current location of pointer head: ");
    scanf("%d",&head);
    temp = head;
    printf("Enter the requested tracks in FIFO orider: \n");
    for(i=0;i<n;i++) {
        scanf("%d",&track[i]);
        // check whether the requested track lies in the cylinder range
        if(track[i]>=nc || track[i]<0) {
            printf("INVALID INPUT!!! ABORTING!!");
            return(0);
        }
    }

    // process the requests according to SSTF algorithm
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(head-track[j] >0) {
                diff[j] = head-track[j];
            } else {
                diff[j] = track[j]-head; 
            }
        }
        min = 0;
        for(j=0;j<n;j++) {
            if(diff[j]<diff[min])
                min = j;
        }
        alloc[i]=track[min];
        head = track[min];
        dist=dist+diff[min];
        track[min]=99999;
    }

    // print the total seek distance and order of request processing
    printf("The requests are processed in the following order: %d -> ",temp);
    for(i=0;i<n;i++) {
        if(i!=n-1) 
            printf("%d -> ",alloc[i]);
        else    
            printf("%d \n",alloc[i]);
    }
    printf("The total seek distance is: %d \n",dist);
}
