#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
    int pid,pidfork;
    pid = getpid();
    printf("ID of parent process: %d\n",pid);
    fork();
    pidfork = getpid();
    printf("ID of forked process: %d\n",pidfork);
    exit(0);
}
