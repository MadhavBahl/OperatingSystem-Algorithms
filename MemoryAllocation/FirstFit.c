/* ================================================= */
/* ===== First Fit Memory Allocation Algorithm ===== */
/* ================================================= */
#include<stdio.h>
int main() {
    // Declare Variables
    int nb,blockSize[100],n,jobSize[100],i,j,alloc[100];

    //Input initial values
    printf("Enter the number of available memory blocks: ");
    scanf("%d",&nb);
    printf("Enter the size of each memory block: \n");
    for(i=0;i<nb;i++) {
        printf("Size of block%d: ",i+1);
        scanf("%d",&blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the size of each process: \n");
    for(i=0;i<n;i++) {
        printf("Size of process%d: ",i+1);
        scanf("%d",&jobSize[i]);
    }

    // Put initial values in alloc vector
    for(i=0;i<n;i++) {
        alloc[i] = -1;
    }

    // Allocate the processes
    for(i=0;i<n;i++){
        for(j=0;j<nb;j++) {
            if(blockSize[j]>jobSize[i]) {
                alloc[i]=j;
                j=nb;
                blockSize[j]=0;
            }
        }
    }

    // Print the results
    printf("Process P of {size} is allocated to block of {size} \n");
    for(i=0;i<n;i++) {
        if(alloc[i]!=-1)
            printf("Process %d of %d --> Block %d of %d \n",i+1,jobSize[i],alloc[i]+1,blockSize[alloc[i]]);
        else
            printf("Process %d of %d --> is not allocated \n",i+1,jobSize[i]);
    }
}