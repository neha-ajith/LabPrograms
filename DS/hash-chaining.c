#include <stdio.h>
#include <stdlib.h>
#define size 5
struct node{
    int data;
    struct node *next;
};
struct node *list[size];
void initialtable(){
    int i;
    for (i = 0; i < size; i++)
        list[i] = NULL;
}
void insert(int value){
    int key;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    key = (3 * value) % size;
    if (list[key] == NULL){
        list[key] = newnode;
    }
    else{
        struct node *temp = list[key];
        while (temp->next){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void print(){
    int i, temp;
    printf("The elements are :");
    printf("\n");
    for (i = 0; i < size; i++){
        struct node *temp = list[i];
        printf("chain[%d]-->", i);
        while (temp){
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void main(){
    int k, ch, value;
    initialtable();
    do{
        printf("\nselect from the following\n1.insert eleemnts\n2.print the elements\n");
        printf("Enter your choice :");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            print();
            printf("\n");
            break;
        default:
            printf("enter a valid number");
            break;
        }
        printf("Do you want to continue?(1 for yes and 0 for no) :");
        scanf("%d", &k);
    } while (k == 1);
}
