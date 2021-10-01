#include<stdio.h>
#include<stdlib.h>

void main(){
    int size,n,i,j,temp,head,left[10],right[10],temp1 = 1,temp2 = 1,distance,seek = 0;
    printf("Enter the disk size: ");
    scanf("%d",&size);
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the request sequence: ");
    left[0] = 0;
    right[0] = size;
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp<head){
            left[temp1] = temp;
            temp1++;
        }
        else{
            right[temp2] = temp;
            temp2++;
        }
    }
    printf("Enter head position: ");
    scanf("%d",&head);
    //sort left array
    for(i=0;i<temp1-1;i++){
        for(j=0;j<temp1-i-1;j++){
            if(left[j]>left[j+1]){
                temp = left[j];
                left[j] = left[j+1];
                left[j+1] = temp;
            }
        }
    }
    //sort right array
    for(i=0;i<temp2-1;i++){
        for(j=0;j<temp2-i-1;j++){
            if(right[j]>right[j+1]){
                temp = right[j];
                right[j] = right[j+1];
                right[j+1] = temp;
            }
        }
    }
    for(i=0;i<temp2;i++){
        distance = abs(head - right[i]);
        seek += distance;
        head = right[i];
    }
    head = 0;
    seek += size;
    for(i=0;i<temp1;i++){
        distance = abs(head - left[i]);
        seek += distance;
        head = left[i];
    }
    printf("Total seek: %d\n",seek);
}