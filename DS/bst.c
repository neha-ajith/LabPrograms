#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lc,*rc;
};

struct node* newnode(int key){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->lc = temp->rc = NULL;
    return temp;
}

struct node* insert(struct node* node,int key){
    if(node == NULL)
        return newnode(key);
    
    if(key < node->data)
        node->lc = insert(node->lc,key);
    else if(key > node->data)
        node->rc = insert(node->rc,key);

    return node;
}

void inorder_traversal(struct node* root){
    if(root != NULL){
        inorder_traversal(root->lc);
        printf("%d ",root->data);
        inorder_traversal(root->rc);
    }
}

void preorder_traversal(struct node* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder_traversal(root->lc);
        preorder_traversal(root->rc);
    }
}

void postorder_traversal(struct node* root){
    if(root != NULL){
        postorder_traversal(root->lc);
        postorder_traversal(root->rc);
        printf("%d ",root->data);
    }
}

void main(){
    int rep,ch,d;
    struct node* root = NULL;
    root = insert(root,50); //create root node
    do{
        printf("--- Binary Search Tree ---\n1. Insertion\n2. Deletion\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter data: ");
                scanf("%d",&d);
                insert(root,d);
                break;
            
            case 2:
                printf("Can't delete.");
                break;

            case 3:
                inorder_traversal(root);
                break;

            case 4:
                preorder_traversal(root);
                break;

            case 5:
                postorder_traversal(root);
                break;
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep==1);
}