/* ========================================= */
/* ========= FIFO Page replacement ========= */
/* ========================================= */

#include<stdio.h>
#include<string.h>
int main()
{
    int n,l,i,j,count=0,temp=1;
    char page[100],sent[100];
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("Enter then input string: ");
    scanf("%s",sent);
    l=strlen(sent);
    for(i=0;i<l;i++) {
        for(j=0;j<n;j++)
            if(sent[i] == page[j])
                temp=0;
        if(temp==1)
        {
            page[count%n] = sent[i];
            count++;
        }
        temp=1;
    }
    printf("The number of page faults are: %d",count);
    printf("\nThe number of page hits are: %d",l - count);
}