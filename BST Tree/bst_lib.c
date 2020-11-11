#include <stdio.h>
#include <stdlib.h>
#include <bst.h>

node* treeNewNode(int key){
    node* new = (node*)malloc(sizeof(node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;

    return new;
}

node* treeInsert(node* root, int key){
    if(root == NULL)
        return treeNewNode(key);
    if(root->key > key)
        root->left = treeInsert(root->left, key);
    else
        root->right = treeInsert(root->right, key);
    return root;
}

void treePrevisit(node* root){

    if(root != NULL){
        printf("%d-> ", root->key);
        treePrevisit(root->left);
        treePrevisit(root->right);
    }
}


void treeInvisit(node* root){

    if(root != NULL){
        treeInvisit(root->left);
        printf("%d-> ", root->key);
        treeInvisit(root->right);
    }
}

void treePostvisit(node* root){

    if(root != NULL){
        treePostvisit(root->left);
        treePostvisit(root->right);
        printf("%d-> ", root->key);
    }
}
