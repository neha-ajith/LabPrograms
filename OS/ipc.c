#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
    void *sharedmem;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)1122,1024,0666|IPC_CREAT);
    printf("Key of shared memory: %d\n",shmid);
    sharedmem = shmat(shmid,NULL,0);
    printf("Process attached at: %p\n Enter data to write in shared memory: \n",sharedmem);
    read(0,buff,100);
    strcpy(sharedmem,buff);
    printf("You wrote: %s\n",(char *)sharedmem);
    shmid = shmget((key_t)1122,1024,0666);
    printf("Key of shared memory: %d\n",shmid);
    sharedmem = shmat(shmid,NULL,0);
    printf("Process attached at: %p\n",sharedmem);
    printf("Data written in shared memory: %s\n",(char *)sharedmem);
}