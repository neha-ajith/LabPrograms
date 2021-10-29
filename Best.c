#include<stdio.h>

void main(){
    int n,i,proc[10],m,mem[10],alloc[10],idx,j;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the size of the processes: ");
    for(i=0;i<n;i++){
        scanf("%d",&proc[i]);
    }
    printf("Enter the number of memory blocks: ");
    scanf("%d",&m);
    printf("Enter the memory blocks: ");
    for(i=0;i<m;i++){
        scanf("%d",&mem[i]);
    }
    for(i=0;i<n;i++){
        alloc[i] = -1;
    }
    for(i=0;i<n;i++){
        idx = -1;
        for(j=0;j<m;j++){
            if(mem[j] >= proc[i]){
                if(idx == -1)
                    idx = j;
                else if(mem[idx] > mem[j]){
                    idx = j;
                }
            }
        }
        
