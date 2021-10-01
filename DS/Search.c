#include<stdio.h>
#include<stdlib.h>

// Function to read elements of an array.
int read(int a[]){
    int n,i;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    return n;
}

// Function for linear search.
void lsearch(int a[],int n){
    int s,i,f=0;
    printf("Enter the element to be searched: ");
    scanf("%d",&s);
    for(i=0;i<n;i++){
        if(a[i]==s){
            printf("Element %d found at position %d.",a[i],i+1);
            f=1;
        }
    }
    if(f==0)
       printf("Element not found.");
}

// Function for binary search.
void binary(int a[],int n){
    printf("Sorting the given array...");
    int i,j,temp,r,l=0,u=n-1,m=0,f=0;
    // Bubble sort the elements before performing binary search
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("\nEnter the required element: ");
    scanf("%d",&r);
    while(l<=u){
        m = (l+u)/2;
        if(r<a[m])
           u = m-1;
        if(a[m]<r)
           l = m+1;
        if(a[m]==r){
            printf("The element %d is found in position %d.",a[m],m+1);
            f = 1;
            break;
        }
    }
    if(f==0){
        printf("Element not found.");
    }
}

void main(){
    int choice,a[20],n,op;
    n = read(a);
    do{
        printf("1. Linear Search \n2. Binary Search \n Enter your choice.");
        scanf("%d",&choice);
        switch(choice){
            case 1: lsearch(a,n);
            break;
            
            case 2: binary(a,n);
            break;
            
            default: printf("Wrong Input!");
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&op);
    }while(op == 1);
}
    
    