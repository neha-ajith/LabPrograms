#include<stdio.h>
struct poly{
    float coef;
    int ex;
}p[10],q[10],r[10];

void add(struct poly p[],struct poly q[],int m,int n){
    int i = 0,j = 0,k = 0;
    while(i<m){
        while(j<n){
            if(p[i].ex == q[j].ex){
                r[k].ex = p[i].ex;
                r[k].coef = p[i].coef + q[j].coef;
                k++;
                j++;
                i++;
            }
            else if(p[i].ex>q[j].ex){
                r[k].ex = p[i].ex;
                r[k].coef = p[i].coef;
                k++;
                i++;
            }
            else if(p[i].ex<q[j].ex){
                r[k].ex = q[j].ex;
                r[k].coef = q[j].coef;
                k++;
                j++;
            }
        }
    }
    while(i<m){
        r[k].coef = p[i].coef;
        r[k].ex = p[i].ex;
        i++;
        k++;
    }
    while(j<n){
        r[k].coef = q[j].coef;
        r[k].ex = q[j].ex;
        j++;
        k++;
    }
    printf("The resultant polynomial is: \n");
    for(i=0;i<k;i++){
        printf("%f %d   ",r[i].coef,r[i].ex);
    }
}

void main(){
    int n1,n2,i;
    printf("Enter the number of terms of the first polynomial: ");
    scanf("%d",&n1);
    printf("Enter the number of terms of the second polynomial: ");
    scanf("%d",&n2);
    printf("The terms of the first polynomial: \n");
    for(i=0;i<n1;i++){
        printf("Enter the coefficient and power: ");
        scanf("%f %d",&p[i].coef,&p[i].ex);
    }
    printf("The terms of the second polynomial: \n");
    for(i=0;i<n2;i++){
        printf("Enter the coefficient and power: ");
        scanf("%f %d",&q[i].coef,&q[i].ex);
    }
    add(p,q,n1,n2);
}