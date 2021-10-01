#include<stdio.h>
void main(){
    int n,ar[20],i,s,f = 0;
    printf("\n --- Linear Search ---\nEnter the number of array elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&s);
    for(i=0;i<n;i++){
        if(ar[i] == s){
            printf("Element %d found in position %d.",s,i+1);
            f = 1;
        }
    }
    if(f == 0){
        printf("Element not found.");
    }
}