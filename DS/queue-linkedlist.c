#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *front,*rear;

void enqueue(){
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&val);
    ptr->data = val;
    if(front == NULL){
        front = ptr;
        rear = ptr;
        front->link = NULL;
        rear->link = NULL;
    }
    else{
        rear->link = ptr;
        rear = ptr;
        rear->link = NULL;
    }
    printf("Element inserted.");
}

void dequeue(){
    struct node *ptr;
    if(front == NULL)
        printf("Queue empty!!");
    else{
        ptr = front;
        front = front->link;
        free(ptr);
        printf("Element deleted.");
    } 
}

void display(){
    struct node *ptr;
    if(front == NULL)
        printf("Empty queue!!");
    else{
        ptr = front;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}

void main(){
    int rep,ch;
    do{
        printf("--- Queue using Linkedlist ---\n1. Enqueue\n2. Dequeue\n3. Display\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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