#include<stdio.h>
#define CAPACITY 5
int queue[CAPACITY],rear = -1,front = -1;

void insert(int ele){
    rear++;
    if(rear>=CAPACITY){
        printf("Queue is full!");
    }
    else{
        if(front == -1)
            front = 0;
        queue[rear] = ele;
        printf("Element %d inserted.",ele);
    }
}

void delete(){
    if(front>rear){
        printf("Queue is empty.");
    }
    else{
        printf("Element %d deleted.",queue[front]);
        front++;
    }
}

void display(){
    int foq = front;
    if(foq>rear){
        printf("Queue is empty.");
    }
    else{
        while(foq<=rear){
            printf("%d ",queue[foq]);
            foq++;
        }
    }
}

void main(){
    int rep,ch,ele;
    do{
        printf("--- Queue Operations ---\n1. Insert\n2. Delete\n3. Display\n Enter your choice: ");
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
            default: printf("Invalid input!");
            break;
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep == 1);
}