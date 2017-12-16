/* ===================================================== */
/* ========= LRU Page replacement (16BCE2311) ========== */
/* ===================================================== */

#include<stdio.h>
#include<string.h>
int main() {
    // Read the string and number of pages
    char ip[100],page[100];
    int n,l,i,j,w,k,count=0,recentNo[100],hit=0,temp=1,min;
    printf("Enter the input string: ");
    scanf("%s",ip);
    l = strlen(ip);
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    // check each symbol in the string for a page hit
    for(i=0;i<n;i++) {
        page[i]=ip[i];
        recentNo[i] = -1;
        count++;
    }

    // Checking pages after the n pages are full
    for(i=n;i<l;i++) {

        // Look for page hit
        for(j=0;j<n;j++) {
            if(page[j] == ip[i]) {
                hit++;
                temp=0;
            }
        }

        // if not a page hit, search all the past symbols for the page symbols
        if(temp == 1) {

            // Find the position in recently used
            for(j=0;j<n;j++) {
                for(k=i-1;k>=0;k--) {
                    if(page[j]==ip[k]) {
                        recentNo[i] = k;
                        k=0;
                    }
                }
            }

            // Find the min in the recentNo
            min = 0;
            for(j=0;j<n;j++) {
                if(recentNo[min]>recentNo[j])
                    min = j;
            }

            // Assign the least recently used page with the new value
            page[min] = ip[i];
            count++;

        }

        // Revert all temporary variables to their original values
        temp=1;
        for(j=0;j<n;j++) {
            recentNo[i] = -1;
        }
    }

    // Display the result
    printf("The number of page faults are: %d\n",count);
    printf("The number of page hits are: %d\n",l - count);
}
