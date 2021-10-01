#include<stdio.h>
struct mat{
        int col,row,val;
    }a1[20],a2[20],a3[20],el;

void create(struct mat a[],int m1,int n1,int n){
    int i,j;
    for(i=0;i<n;i++){
        printf("Enter the row, column and matrix element: ");
        scanf("%d %d %d",&el.row,&el.col,&el.val);
        if(el.val!=0){
            a[n].row = el.row;
            a[n].col = el.col;
            a[n].val = el.val;
        }
    }
    a[0].row = m1;
    a[0].col = n1;
    a[0].val = n;

}

void add(struct mat a1[],struct mat a2[],int num1,int num2){
    int i = 1,j = 1,k = 1;
    while(i<num1){
        while(j<num2){
            if(a1[i].row == a2[j].row){
                a3[k].row = a1[i].row;
                if(a1[i].col == a2[j].col){
                    a3[k].col = a1[i].col;
                    a3[k].val = a1[i].val + a2[j].val;
                    k++;
                    i++;
                    j++;
                    break;
                }
                else if(a1[i].col < a2[j].col){
                    a3[k].col = a1[i].col;
                    a3[k].val = a1[i].val;
                    k++;
                    i++;
                    break;
                }
                else{
                    a3[k].col = a2[j].col;
                    a3[k].val = a2[j].val;
                    k++;
                    j++;
                }
            }
            else if(a1[i].row < a2[j].row){
                a3[k].row = a1[i].row;
                a3[k].col = a1[i].col;
                a3[k].val = a1[i].val;
                i++;
                k++;
                break;
            }
            else if(a1[i].row > a2[j].row){
                a3[k].row = a2[j].row;
                a3[k].col = a2[j].col;
                a3[k].val = a2[j].val;
                j++;
                k++;
            }
        }
    }
    a3[0].row = a1[0].row;
    a3[0].col = a1[0].col;
    a3[0].val = k-1;
    printf("The resultant sparse matrix is: \n");
    for(i=1;i<k-1;i++){
        printf(" %d %d %d \n",a3[i].row,a3[i].col,a3[i].val);
    }
}

void main(){
    int m1,n1,m2,n2,n,i,num1,num2;
    printf("Enter the number of rows of first sparse matrix: ");
    scanf("%d",&m1);
    printf("Enter the number of columns of the first sparse matrix: ");
    scanf("%d",&n1);
    printf("Enter the number of rows of second sparse matrix: ");
    scanf("%d",&m2);
    printf("Enter the number of columns of the second sparse matrix: ");
    scanf("%d",&n2);
    if(m1==m2 && n1==n2){
        printf("Enter the number of elements of the first matrix:\n");
        scanf("%d",&num1);
        int i,j;
        for(i=0;i<num1;i++){
            printf("Enter the row, column and matrix element: ");
            scanf("%d %d %d",&el.row,&el.col,&el.val);
            if(el.val!=0){
                a1[num1].row = el.row;
                a1[num1].col = el.col;
                a1[num1].val = el.val;
            }
        }
        a1[0].row = m1;
        a1[0].col = n1;
        a1[0].val = num1;
        printf("Enter the elements of the second matrix:\n");
        scanf("%d",&num2);
        for(i=0;i<num2;i++){
            printf("Enter the row, column and matrix element: ");
            scanf("%d %d %d",&el.row,&el.col,&el.val);
            if(el.val!=0){
                a2[num2].row = el.row;
                a2[num2].col = el.col;
                a2[num2].val = el.val;
            }
        }
        a2[0].row = m1;
        a2[0].col = n1;
        a2[0].val = num2;
        int k = 1;
    while(i<num1){
        while(j<num2){
            if(a1[i].row == a2[j].row){
                a3[k].row = a1[i].row;
                if(a1[i].col == a2[j].col){
                    a3[k].col = a1[i].col;
                    a3[k].val = a1[i].val + a2[j].val;
                    k++;
                    i++;
                    j++;
                    break;
                }
                else if(a1[i].col < a2[j].col){
                    a3[k].col = a1[i].col;
                    a3[k].val = a1[i].val;
                    k++;
                    i++;
                    break;
                }
                else{
                    a3[k].col = a2[j].col;
                    a3[k].val = a2[j].val;
                    k++;
                    j++;
                }
            }
            else if(a1[i].row < a2[j].row){
                a3[k].row = a1[i].row;
                a3[k].col = a1[i].col;
                a3[k].val = a1[i].val;
                i++;
                k++;
                break;
            }
            else if(a1[i].row > a2[j].row){
                a3[k].row = a2[j].row;
                a3[k].col = a2[j].col;
                a3[k].val = a2[j].val;
                j++;
                k++;
            }
        }
    }
    a3[0].row = a1[0].row;
    a3[0].col = a1[0].col;
    a3[0].val = k-1;
    printf("The resultant sparse matrix is: \n");
    for(i=1;i<k-1;i++){
        printf(" %d %d %d \n",a3[i].row,a3[i].col,a3[i].val);
    }
    }
    else
        printf("The number of rows and columns of both matrices should be same.");
}
