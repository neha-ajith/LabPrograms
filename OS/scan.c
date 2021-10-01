#include<stdio.h>
#include<stdlib.h>

void main(){
    int queue[25],n,headposition,i,j,k,seek=0,maxrange,difference,temp,queue1[20],queue2[20],temp1=0,temp2=0;
    printf("Enter the maximum range of Disk: ");
    scanf("%d",&maxrange);
    printf("Enter the number of queue requests: ");
    scanf("%d",&n);
    printf("Enter the initial head position: ");
    scanf("%d",&headposition);
   printf("Enter the disk positions to be read(queue): ");
    for(i=1;i<=n;i++){
        scanf("%d",&temp);  
        if(temp>headposition){
            queue1[temp1]=temp; 
            temp1++; 
        }
        else{   
            queue2[temp2]=temp; 
            temp2++;
        }
    }
    for(i=0;i<temp1-1;i++){
        for(j=i+1;j<temp1;j++){
            if(queue1[i]>queue1[j]){
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    for(i=0;i<temp2-1;i++){
        for(j=i+1;j<temp2;j++){
            if(queue2[i]<queue2[j]){
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }    
    for(i=1,j=0;j<temp1;i++,j++){
        queue[i]=queue1[j]; 
    }
    queue[i]=maxrange;
    for(i=temp1+2,j=0;j<temp2;i++,j++){
        queue[i]=queue2[j];
    }
    queue[i]=0;
    queue[0]=headposition;
    for(j=0; j<=n; j++) {   
        difference = abs(queue[j+1]-queue[j]);
        seek = seek + difference;
    }
    printf("Total Seek Time= %d\n", seek);
    
}