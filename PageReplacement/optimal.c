/* ===================================================== */
/* ======== Optimal Page replacement (16BCE2311) ======= */
/* ===================================================== */

#include<stdio.h>
#include<string.h>
int main() {
    int i,j,k,n,l,count=0,temp=0,rank[100],found=0,max,updated=0;
    char page[100],ip[100];
    printf("Enter the input string: ");
    scanf("%s",ip);
    l=strlen(ip);
    printf("Enter the number of pages: ");
    scanf("%d",&n);

    // Initialize first n elements in page array
    for(i=0;i<n;i++) {
        page[i] = ip[i];
        count++;
    }
    // Check for next l-n elements
    for(i=n;i<l;i++) {
        temp=0;
        // Check for page hit
        for(j=0;j<n;j++) {
            if(ip[i] == page[j]){
                temp=1;
            }
        }

        // If not Page hit
        if(temp==0) {
            // If element of page appears in leftover string, rank them in order of their future appearance
            // Else, Replace that element with the present input symbol
            for(j=0;j<n;j++) {
                found=0;

                for(k=i+1;k<l;k++) {
                    // Element is found in leftover string
                    if(ip[k] == page[j]) {
                        rank[j] = j;
                        found=1;
                        k=l-1;
                    }
                }

                // Element not found in the leftover string
                // Check if that element is count%n
                // if that element is not count%n rank it 99999
                if(found==0) {
                    if(count%n == j) {
                        page[j] = ip[i];
                        j=n-1;
                        count++;
                        updated=1;
                    } else {
                        rank[j] = 99999;
                    }
                }
            }

            // Check the rank of each element and then replace the element with greatest rank
            if(updated==0) {
                max = 0;
                for(j=0;j<n;j++) {
                    if(rank[max]<rank[j])
                        max = j;
                }
                page[max] = ip[i];
                count++;
            }

            // Revert all the temporary variables
            for(j=0;j<n;j++) {
                rank[j] =-1;
            }
            updated=0;
        }
    }

    printf("Number of page faults are: %d",count);
    printf("\nNumber of page hits are: %d\n",l - count);
}
