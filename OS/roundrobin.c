#include<stdio.h>

void main(){
    int NOP,i,btime[5],n,temp[5],y,atime[5],sum,count,wt,tat;
    float avg_wt,avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d",&NOP);
    y = NOP;
    printf("Enter arrival times: ");
    for(i=0;i<NOP;i++){
        scanf("%d",&atime[i]);
    }
    printf("Enter burst times: ");
    for(i=0;i<NOP;i++){
        scanf("%d",&btime[i]);
        temp[i] = btime[i];
    }
    printf("Enter time quantum for the process: ");
    scanf("%d",&n);
    printf("Process ID \tArrival Time \tBurst Time \tTAT \tWaiting Time\n");
    for(sum=0,i=0;y!=0;){
        if(temp[i] <= n && temp[i] > 0){
            sum+=temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i] > 0){
            sum+=n;
            temp[i]-=n;
        }
        if(temp[i] == 0 && count == 1){
            y--;
            printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", i,atime[i],btime[i],sum-atime[i],sum-atime[i]-btime[i]);
            wt+=sum-atime[i]-btime[i];
            tat+=sum-atime[i];
            count = 0;
        }
        if(y == NOP-1){
            i = 0;
        }
        else if(atime[i+1]<=sum){
            i++;
        }
        else{
            i = 0;
        }
    }
    avg_wt = 1.0*wt/NOP;
    avg_tat = 1.0*tat/NOP;
    printf("Average waiting time: %f\n",avg_wt);
    printf("Average turn around time: %f\n",avg_tat);
}