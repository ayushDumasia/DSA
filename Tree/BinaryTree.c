#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;


node *create(int val){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(node **root , int val){
    if(*root == NULL){
        *root = create(val);
        return ;
    }

    if(val < (*root)->data){
        insert(&((*root)->left),val);
    }
    else if(val > (*root)->data){
        insert(&((*root)->right),val);
    }
    else {
        printf("Value Already Exists");
    }
}

void preOrder(node *root){
    if(root == NULL){
        return;
    }

    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

void inOrder(node *root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void display(node *root){
    if(root == NULL){
        return;
    }

    display(root->left);
    printf("%d ",root->data);
    display(root->right);
}




int main(){
    node *root = NULL;

    insert(&root,5);
    insert(&root,1);
    insert(&root,3);
    insert(&root,0);
    insert(&root,6);
    insert(&root,4);
    insert(&root,2);
    insert(&root,8);
    insert(&root,7);
    insert(&root,9);

    printf("PreOrder");
    preOrder(root);
    printf("InOrder");
    inOrder(root);
    printf("postOrder");
    postOrder(root);


return 0;
}