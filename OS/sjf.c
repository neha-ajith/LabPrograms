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

void avgtime(int proc[],int btime[],int n){
    int wtime[n],tat[n],i,avgwtime = 0,avgtatime = 0;
    waitingtime(btime,wtime,n);
    tatime(tat,btime,wtime,n);
    printf("Process Burst Waiting Turn Around\n");
    for(i=0;i<n;i++){
        avgwtime += wtime[i];
        avgtatime += tat[i];
        printf("%d \t %d \t %d \t %d\n",proc[i],btime[i],wtime[i],tat[i]);
    }
    printf("Average waiting time: %f\n",(float)avgwtime/(float)n);
    printf("Average turn around time: %f\n",(float)avgtatime/(float)n);
}

void sortbtime(int btime[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(btime[j]>btime[j+1]){
                temp = btime[j];
                btime[j] = btime[j+1];
                btime[j+1] = temp;
            }     
        }
    }
}

void main(){
    int proc[] = {1,2,3};
    int btime[] = {8,5,12};
    int n = sizeof proc/sizeof proc[0];
    sortbtime(btime,n);
    avgtime(proc,btime,n);
}