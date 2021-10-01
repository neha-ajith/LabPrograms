#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY],top = -1;

void push(int ele){
    top++;
    if(top>=CAPACITY){
        printf("Stack overflow!!");
    }
    else{
        stack[top] = ele;
        printf("Element pushed.");
    }
}

void pop(){
    if(top == -1){
        printf("Stack is empty!!");
    }
    else{
        printf("%d popped.",stack[top]);
        top--;
    }
}

void display(){
    int tos = top;
    if(tos == -1){
        printf("Empty stack.");
    }
    else{
        while(tos>-1){
            printf("%d ",stack[tos]);
            tos-=1;
        }
    }
}

void main(){
    int rep,ch,n,i,ele;
    do{
        printf("--- Stack Operations ---\n 1. Push\n 2. Pop\n 3. Display\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter the element to be pushed: ");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
        printf("\n Do you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep == 1);
}