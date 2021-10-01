#include<stdio.h>

void main(){
    int n,i,j,req[10],cap,set[5],c = 0,pfault = 0,q[10],qb = 0,qf = 0,flag = 0,val;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the page sequence: ");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter the capacity of the memory: ");
    scanf("%d",&cap);
    for(i=0;i<n;i++){
        if(c<cap){
           set[c] = req[i];
           c++; 
           pfault++;
           q[qb] = req[i];
           qb++;
        }
        else{
            for(j=0;j<cap;j++){
                if(set[j] == req[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                val = q[qf];
                qf++;
                for(j=0;j<cap;j++){
                    if(set[j] == val){
                        set[j] = req[i];
                        pfault++;
                        break;
                    }
                }
            }
        }
    }
    printf("The number of page faults is: %d\n",pfault);
}