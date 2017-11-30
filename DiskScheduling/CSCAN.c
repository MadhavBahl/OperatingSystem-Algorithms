/* ================================================== */
/* ===== Disk scheduling - C-SCAN (Madhav Bahl) ===== */
/* ================================================== */

#include<stdio.h>
int main() {

    // Declare the variable
    int nc,nt,head,track[100],i,j,dist=0,temp,headPos;

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
        // check whether the requested track lies in the cylinder range
        if(track[i]>=nc || track[i]<0) {
            printf("INVALID INPUT!!! ABORTING!!");
            return(0);
        }
    }
    nt++;
    track[nt] = nc-1;

    // process the requests according to C-SCAN algorithm
    // requests are processed first in right direction
    for(i=0;i<=nt;i++) {
        for(j=i;j<=nt;j++) {
            if(track[i]>track[j]) {
                temp = track[i];
                track[i] = track[j];
                track[j] = temp;
            }
        }
    }
    for(i=0;i<=nt;i++)
        if(track[i] == head){
            headPos = i;
            break;
        }
   dist = (track[nt]-track[headPos])+(track[nt]-0)+(track[headPos-1]-0);
    printf("The head position is: %d \n",track[headPos]);
    printf("The total seek distance is: %d cylinders\n",dist);
}

