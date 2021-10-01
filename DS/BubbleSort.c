#include<stdio.h>
void sort(int ar[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(ar[j]>ar[j+1]){
                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] =  temp;
            }
        }
    }
}