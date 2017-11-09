/* ================================================ */
/* ===== Best Fit Memory Allocation Algorithm ===== */
/* ================================================ */
#include<stdio.h>
int main() {
    // Declare Variables
    int nb,blockSize[100],n,jobSize[100],i,j,alloc[100],avail[100],min;

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

	//	Initialize alloc vector to -1 and avail to 99999
	for(i=0;i<n;i++) {
		alloc[i]=-1;
	}
	for(i=0;i<nb;i++){
        avail[i]=9999;
	}

	// Check for each process the blocks available
	for(i=0;i<n;i++) {
		for(j=0;j<nb;j++) {
			if(blockSize[j]>jobSize[i]){
				avail[j]=blockSize[j]-jobSize[i];
			}
		}
		min=0;
		for(j=0;j<nb;j++) {
			if(avail[min]>avail[j]) {
				min=j;
			}
		}
		alloc[i]=min;
		if(avail[min]>=9999){
			alloc[i]=-1;
		}
		blockSize[min]=-1;
		//	Initialize avail to 99999
		for(j=0;j<n;j++) {
			avail[j]=9999;
		}
	}

    // Print the results
    printf("Process P of {size} is allocated to block \n");
    for(i=0;i<n;i++) {
        if(alloc[i]!=-1)
            printf("Process %d of %d --> Block %d\n",i+1,jobSize[i],alloc[i]+1);
        else
            printf("Process %d of %d --> is not allocated \n",i+1,jobSize[i]);
    }
}
