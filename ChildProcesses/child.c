#include<stdio.h>
#include<unistd.h>
int main(){
    int f;
    f=fork();
    printf("Hello World\n");
    if(f==0) {
        printf("\n Child Pid: %d",getpid());
        printf("\n Parent Pid: %d",getppid());
        printf("\n Chld process got terminated! \n");
    } else {
        printf("\n Child Pid: %d",getpid());
        printf("\n Parent Pid: %d",getppid());
    }
    return 0;
}