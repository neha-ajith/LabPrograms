#include<stdio.h>

void main(){
    int n,i,proc[10],m,mem[10],alloc[10],j;
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
        for(j=0;j<m;j++){
            if(mem[j] >= proc[i]){
                alloc[i] = j;
                mem[j] -= proc[i];
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i=0;i< n;i++){
        printf("   %d\t\t%d\t\t",i+1,proc[i]);
        if (alloc[i] != -1)
            printf("%d\n",alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}