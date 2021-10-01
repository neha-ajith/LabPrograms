#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *root;

void inend(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of the node: ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root == NULL){
        root = temp;
        printf("New element inserted.");
    }
    else{
        struct node *p;
        p = root;
        while(p->link!=NULL)
            p = p->link;
        p->link = temp;
        printf("New element inserted.");
    }
}

void inbeg(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of the node: ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root == NULL)
        root = temp;
    else{
        temp->link = root;
        root = temp;
    }
    printf("New element inserted.");
}

void inspec(){
    struct node *temp,*p;
    int i,n;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position of the new node: ");
    scanf("%d",&n);
    printf("Enter data of the node: ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(n==0){
        temp->link = root;
        root = temp;
    }
    else{
        for(i=0,p = root;i<n-1;i++){
            p = p->link;
            if(p==NULL){
                printf("\nPosition not found\n");
                return;
            }
        }
        temp->link =p->link ;
        p->link=temp;
    }
    printf("New element inserted.");
}

void delbeg(){
    if(root == NULL)
        printf("Empty linked list.");
    else{
        root = root->link;
        printf("Element deleted.");
    }
}

void delend(){
    struct node *p1,*p = root;
    if(root == NULL)
        printf("Empty linked list.");
    else if(root->link ==NULL){
        p = root;
        root = NULL;
    }
    else{
        p = root;
        while(p->link!=NULL){
            p1 = p;
            p = p->link;
        }
        p1->link = NULL;
        printf("Element deleted.");
    }
}

void delspec(){
    int i,pos;
    struct node *temp,*ptr;
    if(root==NULL){
        printf("\nThe List is Empty:\n");
        exit(0);
    }
    else{
        printf("\nEnter the position of the node to be deleted: ");
        scanf("%d",&pos);
        pos-=1;
        if(pos==0){
            ptr=root;
            root=root->link ;
            printf("\nThe deleted element is:%d\t",ptr->data  );
            free(ptr);
        }
        else{
            ptr=root;
            for(i=0; i<pos; i++){
                temp=ptr;
                ptr=ptr->link ;
                if(ptr==NULL){
                    printf("\nPosition not Found:\n");
                    return;
                }
            }
            temp->link =ptr->link ;
            printf("\nThe deleted element is:%d\t",ptr->data );
            free(ptr);
        }
    }
}

void display(){
    if(root == NULL)
        printf("Empty linked list.");
    else{
        struct node *p = root;
        while(p!=NULL){
            printf("%d ",p->data);
            p = p->link;
        }
    }
}

void main(){
    int rep,ch;
    do{
        printf("--- Linked List Operations ---\n1. Display\n2. Insert at Beginning\n3. Insert at End\n4. Insert at a specified Position\n5. Delete from Beginning\n6. Delete from End\n7. Delete from a specified Position\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                display();
                break;
            case 2:
                inbeg();
                break;
            case 3:
                inend();
                break;
            case 4:
                inspec();
                break;
            case 5:
                delbeg();
                break;
            case 6:
                delend();
                break;
            case 7:
                delspec();
                break;
        }
        printf("\nDo you want to continue?(1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep==1);
}