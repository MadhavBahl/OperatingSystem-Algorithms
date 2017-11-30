#include<stdio.h>
#include<sys/types.h>
int main() {
    printf("\n MODEL NAME : \n");
    system("cat /proc/cpuinfo | grep 'model name' ");
    system("cat /proc/cpuinfo | grep 'model' ");
    printf("\n VENDOR ID: ");
    system("cat /proc/cpuinfo | grep vendor_id ");

    return 0;
}