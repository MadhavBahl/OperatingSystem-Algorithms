#include<stdio.h>
int main(){
int i,j,n,m,safeSeq[100],avail[100];
int max[100][100],alloc[100][100],need[100][100];
printf("Enter the number of processes: ");
scanf("%d",&n);
printf("Enter the number of different types of resources: ");
scanf("%d",&m);
printf("Enter the \'Available\' Vector: \n");
for(i=0;i<m;i++){
printf("Resource %d: ",i+1);
scanf("%d",&avail[i]);
}
printf("Enter the \'MAX\' matrix: \n");
for(i=0;i<n;i++){
for(j=0;j<m;j++){
printf("ELEMENT %d,%d: ",i+1,j+1);
scanf("%d",&max[i][j]);
}
}
printf("Enter the \'Allocation\' matrix: \n");
for(i=0;i<n;i++){
for(j=0;j<m;j++){
printf("ELEMENT %d,%d: ",i+1,j+1);
scanf("%d",&alloc[i][j]);
need[i][j]=max[i][j]alloc[
i][j];
}
}
printf("Avail Vector: ");
for(i=0;i<m;i++)
printf("%d ",avail[i]);
printf("\nMAX matrix: \n");
for(i=0;i<n;i++){
for(j=0;j<m;j++){
printf("%d ",max[i][j]);
}
printf("\n");
}
printf("ALLOCATION matrix: \n");
for(i=0;i<n;i++){
for(j=0;j<m;j++){
printf("%d ",alloc[i][j]);
}
printf("\n");
}
printf("NEED matrix: \n");
for(i=0;i<n;i++){
for(j=0;j<m;j++){
printf("%d ",need[i][j]);
}
printf("\n");
}
int k,finish[100],flag=0,flagVector=0,endFlag=1;
for(i=0;i<n;i++)
finish[i]=0;
for(i=0;i<n;i++)
safeSeq[i]=1;
while(flag==0){
for(i=0;i<n;i++){
if(finish[i]==1){
//continue
}
else{
flagVector=1;
for(j=0;j<m;j++){
if(need[i][j]>=avail[j])
flagVector=0;
}
if(flagVector==0)
{
//continue
}
else{
finish[i]=1;
for(k=0;k<n;k++)
if(safeSeq[k]==1){
safeSeq[k]=i;
break;
}
safeSeq[i]=i;
for(k=0;k<m;k++){
avail[k]+=alloc[i][k];
}
}
}
}
for(i=0;i<n;i++){
if(finish[i]==1)
endFlag=0;
}
if(endFlag==1){
printf("The system is not in a SAFE STATE");
return 0;
}
flag=1;
for(i=0;i<n;i++)
if(finish[i]==0)
flag=0;
}
printf("\nThe safe sequence is: ");
for(i=0;i<n;i++)
printf("P%d >
",safeSeq[i]);
return 0;
}