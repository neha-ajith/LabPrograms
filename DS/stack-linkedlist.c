#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *root;

void push(){
    struct node *ptr;
    int val;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("Memory overloaded.");
    else{
        printf("Enter data of the node: ");
        scanf("%d",&val);
        if(root == NULL){
            ptr->data = val;
            ptr->link = NULL;
            root = ptr;
        }
        else{
            ptr->data = val;
            ptr->link = root;
            root = ptr;
        }
        printf("Element pushed.");
    }
}

void pop(){
    struct node *ptr;
    if(root == NULL)
        printf("Stack underflow.");
    else{
        ptr = root;
        root = root->link;
        free(ptr);
        printf("Item popped.");
    }
}

void display(){
    int i;
    struct node *ptr = root;
    if(ptr == NULL)
        printf("Empty stack!!");
    else{
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}

void main(){
    int rep,ch;
    do{
        printf("--- Stack using Linkedlist ---\n1. Push\n2. Pop\n3. Display\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
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