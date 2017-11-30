#include<stdio.h>
#include<unistd.h>
int main() {
    int f;
    f=fork();
    printf("Hello World!");
    if(f==0) {
        printf("\n Process id of child: %d",getpid());
        printf("\n Process id of parent: %d",getppid());
        printf("\n Child Process Just Got Over");
    } else {
        sleep(20);
        printf("\n Process id of child: %d",getpid());
        printf("\n Process id of parent: %d",getppid());
    }
    return 0;
}