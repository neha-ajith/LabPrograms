#include<stdio.h>
#include<stdlib.h>

int req[10];

void fcfs(int req[],int n,int head){
    int curr,i,distance,seek = 0;
    for(i=0;i<n;i++){
        curr = req[i];
        distance = abs(head-curr);
        seek += distance;
        head = curr;
    }
    printf("Total seek count is: %d\n",seek);
}

void main(){
    int n,i,head;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the request sequence: ");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter head: ");
    scanf("%d",&head);
    fcfs(req,n,head);
}