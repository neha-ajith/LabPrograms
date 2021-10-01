#include<stdio.h>
#define CAPACITY 5
int cqueue[CAPACITY],front = -1,rear = -1;

void insert(int ele){
    rear++;
    if(front == -1)
        front = 0;
    if(rear == CAPACITY)
        rear = 0;
    cqueue[rear] = ele;
    printf("Element %d inserted.",ele);    
}

void delete(){
    int ele;
    ele = cqueue[front];
    printf("Element %d deleted.",ele);
    front++;
    if(front == CAPACITY)
        front = 0;
}

void display(){
    int foq = front;
    for(int i = foq;;i++){
        if(i == CAPACITY)
            i = 0;
        else if(i == rear)
            break;
        printf("%d ",cqueue[foq]);
        foq++;
    }
}

void main(){
    int rep,ch,ele;
    do{
        printf("--- Circular Queue Operations ---\n1. Insert\n2. Delete\n3. Display\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                insert(ele);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default: 
                printf("Invalid input!!");
                break;
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep==1);
}