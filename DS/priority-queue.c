#include<stdio.h>
#define N 5

struct priorityqueue
{
    int data,pno;
}pq[N];
int rear = -1,front = -1;

void insert(int d,int p){
    if(rear == N-1)
        printf("Queue overflow.");
    else if(rear == -1 && front == -1){
        front = 0;
        rear = 0;
        pq[rear].data = d;
        pq[rear].pno = p;
        printf("Element inserted.");
    }
    else{
        rear++;
        pq[rear].data = d;
        pq[rear].pno = p;
        printf("Element inserted.");
    }
}

void delete(){
    if(front == -1 || front == rear)
        printf("Queue underflow.");
    else{
        int i,s = pq[front].pno,sp = front;
        for(i=front;i<=rear;i++){
            if(pq[i].pno<s){
                s = pq[i].pno; 
                sp = i;
            }
        }
        printf("deleting %d",pq[sp].data);
        for(i=sp;i<=rear;i++){
            pq[i]=pq[i+1];
        }
        --rear;
    }
}

void display(){
    int i;
    if(front==-1)
        printf("Queue is empty.");
    else{
        for(i=front;i<=rear;i++)
        printf("%d ",pq[i].data);
    }
}

void main(){
    int rep,ch,d,p;
    do{
        printf("--- Priority Queue Operations ---\n1. Insertion\n2. Deletion\n3. Display\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&d);
                printf("Enter the priority: ");
                scanf("%d",&p);
                insert(d,p);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default: 
                printf("Invalid input!!");
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep == 1);
}
