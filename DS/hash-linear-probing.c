#include <stdio.h>
#define size 5
int arr[size];
void initialtable(){
    int i;
    for (i = 0; i < size; i++)
        arr[i] = -1;
}
void insert(int value){
    int key;
    key = value % size;{
        if (arr[key] == -1){
            arr[key] = value;
            printf("The element is inserted..");
        }
        else{
            key = (key + 1) % size;
            while (arr[key] == -1){
                printf("collision occured.Hence linear probing needed!!\n");
                arr[key] = value;
                printf("Element is inserted..");
            }
        }
    }
}
void delete (int value){
    int key;
    key = value % size;
    if (arr[key] == value){
        arr[key] = -1;
        printf("The element is deleted.");
    }
    else{
        printf("No element is at this position");
    }
}
void search(int value){
    int key;
    key = value % size;
    if (arr[key] == value){
        printf("The element is found at position %d", key);
    }
    else{
        printf("The element is not found");
    }
}
void print(){
    int i;
    printf("The elements are :");
    for (i = 0; i < size; i++)
        printf("%d\t", arr[i]);
}
void main(){
    int ch, c, a, b, value;
    int k;
    initialtable();
    do{
        printf("operations on hashtable..");
        printf("\nselect from the following..");
        printf("\n1.insert element to hashtable\n2.delete element from hashtable\n3.search for an element in hashtable\n4.print elements of hashtable\n");
        printf("Enter your choice :");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            insert(value);
            printf("\n");
            break;
        case 2:
            printf("Enter the element to be deleted :");
            scanf("%d", &value);
            delete (value);
            printf("\n");
            break;
        case 3:
            printf("Enter the element to be searched :");
            scanf("%d", &value);
            search(value);
            printf("\n");
            break;
        case 4:
            print();
            printf("\n");
            break;
        default:
            printf("Please enter a valid number!");
            break;
        }
        printf("Do you want to continue?(1 for yes and 0 for no) :");
        scanf("%d", &k);
    } while (k == 1);
}
