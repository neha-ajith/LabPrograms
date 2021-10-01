#include<stdio.h>
#include<stdlib.h>

int mutex = 1,full = 0,empty = 5,x=0;

int wait(int n){
    return --n;
}

int signal(int n){
    return ++n;
}

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("New element %d produced and added to buffer.\n",x);
    mutex = signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Element %d consumed from buffer.\n",x);
    x--;
}

void main(){
    int ch;
    while(1){
        printf("\n1. Processor\n2. Consumer\n3. Exit\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: if(mutex == 1 && empty!=0)
                        producer();
                    else
                        printf("Buffer is full.\n");
                    break;
            case 2: if(mutex == 1 && full!=0)
                        consumer();
                    else
                        printf("Buffer is empty.\n");
                    break;
            case 3: exit(0);
            break; 
        }
    }
}