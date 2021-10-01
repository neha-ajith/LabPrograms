#include<stdio.h>

void waitingtime(int btime[],int wtime[],int n){
    int i;
    wtime[0] = 0;
    for(i=1;i<n;i++)
        wtime[i] = wtime[i-1] + btime[i-1];
}

void tatime(int tat[],int btime[],int wtime[],int n){
    int i;
    for(i=0;i<n;i++)
        tat[i] = btime[i] + wtime[i];
}

void avgtime(int btime[],int n){
    int wtime[n],tat[n],i,avgwtime = 0,avgtatime = 0;
    waitingtime(btime,wtime,n);
    tatime(tat,btime,wtime,n);
    printf("Process Burst Waiting Turn Around\n");
    for(i=0;i<n;i++){
        avgwtime += wtime[i];
        avgtatime += tat[i];
        printf("%d \t %d \t %d \t %d\n",i,btime[i],wtime[i],tat[i]);
    }
    printf("Average waiting time: %f\n",(float)avgwtime/(float)n);
    printf("Average turn around time: %f\n",(float)avgtatime/(float)n);
}

void sort(int btime[],int priority[],int n){
    int i,j,temp1,temp2;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(priority[j]>priority[j+1]){
                temp1 = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp1;
                
                temp2 = btime[j];
                btime[j] = btime[j+1];
                btime[j+1] = temp2;
            }
        }
    }
}

void main(){
    int btime[5],priority[5],n,i;
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    printf("Enter the burst times: ");
    for(i=0;i<n;i++){
        scanf("%d",&btime[i]);
    }
    printf("Enter the priorities: ");
    for(i=0;i<n;i++){
        scanf("%d",&priority[i]);
    }
    sort(btime,priority,n);
    avgtime(btime,n);
}