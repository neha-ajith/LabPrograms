#include<stdio.h>

void main(){
    int n,i,j,req[10],qb = 0,cap,c = 0,set[5],pfault,flag = 0,val;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the request sequence: ");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter the capacity: ");
    scanf("%d",&cap);
    for(i=0;i<n;i++){
        if(c<cap){
            set[c] = req[i];
            c++;
            pfault++;
        }
        else{
            for(j=0;j<cap;j++){
                if(set[j] == req[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                val = req[qb];
                qb++;
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
    printf("Number of page faults: %d\n",pfault);
}