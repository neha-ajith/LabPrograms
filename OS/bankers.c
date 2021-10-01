#include<stdio.h>

void main(){
    int n,m,i,j,k,alloc[10][10],max[10][10],need[10][10],flag[10],available[10],fla = 0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the number of resources: ");
    scanf("%d",&m);
    printf("Enter the current allocations:\n");
    for(i=0;i<n;i++){
        printf("Enter current allocations for P%d: ",i);
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the maximum allocations:\n");
    for(i=0;i<n;i++){
        printf("Enter maximum allocations for P%d: ",i);
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    for(i=0;i<n;i++){
        flag[i] = 0;
        for(j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Enter the available instances: ");
    for(i=0;i<m;i++){
        scanf("%d",&available[i]);
    }
    printf("The process sequence is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(flag[i] == 0){
                for(k=0;k<m;k++){
                    if(need[j][k]>available[k]){
                        fla = 1;
                        break;
                    }
                }
                if(fla == 0){
                    for(k=0;k<m;k++){
                        available[k]+= alloc[j][k]; 
                    }
                    flag[i] = 1;
                    printf("P%d ",i);
                }
            }
        }
    }
}