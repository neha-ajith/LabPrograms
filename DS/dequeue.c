#include<stdio.h>
#define N 5
int f = -1,r = -1,dq[N];

void enqueuefront(int ele){
    if((f==0 && r == N-1) || f == r+1){
        printf("Queue is full.");
    }
    else if(f == -1 && r == -1){
        f = 0;
        r = 0;
        dq[f] = ele;
    }
    else if(f == 0){
        f = N-1;
        dq[f] = ele;
    }
    else{
        f--;
        dq[f] = ele;
    }
}

void enqueuerear(int ele){
    if((f==0 && r == N-1) || f == r+1){
        printf("Queue is full.");
    }
    else if(f == -1 && r == -1){
        f = 0;
        r = 0;
        dq[r] = ele;
    }
    else if(r == N-1){
        r = 0;
        dq[r] =  ele;
    }
    else{
        r++;
        dq[r] = ele;
    }
}

void display(){
    int i = f;
    while(i!=r){
        printf("%d ",dq[i]);
        i = (i+1) % N;
    }
    printf("%d",dq[r]);
}

void dequeuefront(){
    if(f == 1 && r == -1)
        printf("Empty queue!!");
    else if(f == r){
        printf("%d deleted.",dq[f]);
        f = -1;
        r = -1;
    }
    else if(f == N-1){
        printf("%d deleted.",dq[f]);
        f = 0;
    }
    else{
        printf("%d deleted.",dq[f]);
        f++;
    }
}

void dequeuerear(){
    if(f == 1 && r == -1)
        printf("Empty queue!!");
    else if(f == r){
        printf("%d deleted.",dq[r]);
        f = -1;
        r = -1;
    }
    else if(r = 0){
        printf("%d deleted.",dq[r]);
        r = N-1;
    }
    else{
        printf("%d deleted.",dq[r]);
        r--;
    }
}

void main(){
    int rep,ch,ele;
    do{
        printf("--- Dequeue Operations ---\n1. Insert from front\n2. Insert from rear\n3. Delete from front\n4. Delete from rear\n5. Display\n Enter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                enqueuefront(ele);
                printf("Element %d inserted.",ele);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                enqueuerear(ele);
                printf("Element %d inserted.",ele);
                break;
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                display();
                break;
            default: 
                printf("Invalid input!!");
                break;
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep == 1);
}