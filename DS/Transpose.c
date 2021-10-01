#include<stdio.h>
struct mat{
    int row,col,val;
}a[20],b[20];

void create(struct mat a[20],int r,int c){
    int ele,k=1;
    a[0].row = r;
    a[0].col = c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter the matrix element: ");
            scanf("%d",&ele);
            if(ele!=0){
                a[k].row = i;
                a[k].col = j;
                a[k].val = ele;
                k++;
            }
        }
    }
    a[0].val = k-1;
}

void transpose(struct mat a[20]){
    int q = 1,i,j;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
    for(i=0;i<=a[0].col;i++){
        for(j=1;j<=a[0].val;j++){
            if(a[j].col == i){
                b[q].row = a[j].col;
                b[q].col = a[j].row;
                b[q].val = a[j].val;
                q++;
            }
        }
    }
    printf("The transpose of the matrix is:\n");
    for(i=0;i<=q-1;i++)
        printf("%d %d %d\n",b[i].row,b[i].col,b[i].val);
}

void main(){
    int r,c;
    printf("Enter the no of rows: ");
    scanf("%d",&r);
    printf("Enter the no of columns: ");
    scanf("%d",&c);
    create(a,r,c);
    transpose(a);
}