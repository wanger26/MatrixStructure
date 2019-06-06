#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>


//Defining/Declaring helper methods--------------------------------------
BStree_node *new_node(Key key, Data data);
void recursiveBSTree_insert(BStree_node *bst, Key key, Data data);
Data search(BStree_node *nodepointer, Key key);
void inOrderTraversal (BStree_node *nodepointer);
void free_bstree(BStree_node *bst);
//------------------------------------------------------------------------


BStree bstree_ini(void){
    BStree bst;
    bst= (BStree)malloc(sizeof(BStree_node*));
    *bst=NULL;

    return bst;
}

void bstree_insert(BStree bst, Key key, Data data){
    BStree_node *currentNodePointer= *bst;
    BStree_node *prev=NULL;
    int duplicate=0;

    while (currentNodePointer!=NULL) {

        prev= currentNodePointer;

        if (key_comp(key, currentNodePointer->key) < 0) { //if the key we are looking to insert is smaller then current go left
            currentNodePointer = currentNodePointer->left;
        } else if (key_comp(key, currentNodePointer->key) > 0) { //if the key we are looking to insert is smaller then current go right
            currentNodePointer = currentNodePointer->right;
        }
        else{
            duplicate=1;
            break;
        }
    }

    if (duplicate==0) {
        currentNodePointer = new_node(key, data);

        if (prev == NULL) {
            *bst = currentNodePointer;
        } else if (key_comp(prev->key, currentNodePointer->key) < 0) {
            prev->right = currentNodePointer;
        } else if (key_comp(prev->key, currentNodePointer->key) > 0) {
            prev->left = currentNodePointer;
        }
    }
}

Data bstree_search(BStree bst, Key key){
    return search(*bst, key); //calling on helper method
}

void bstree_traversal(BStree bst){
    inOrderTraversal(*bst); //calling on helper method
}

void bstree_free(BStree bst){
    free_bstree(*bst);//calling on helper method
    free(bst);

}

//----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------Helper Methods ----------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
BStree_node *new_node(Key key, Data data){
    BStree_node* newNode;
    newNode= malloc(sizeof(BStree_node));
    newNode->key=key;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Data search(BStree_node *currentNode, Key key ){
    if (currentNode==NULL){ //if we reach the bottom of the tree the item is not in the tree
        return NULL;
    }
    else {
        if (key_comp(currentNode->key, key)==0){ //if the current key is the key we are looking for
            return currentNode->data;
        }
        else if (key_comp(currentNode->key, key)>0){ //if the current key is larger then the key we are looking for go left
            return search(currentNode->left, key);
        }
        else if (key_comp(currentNode->key, key)<0){ //if the current key is smaller then the key we are looking for go right
            return search(currentNode->right, key);
        }
    }
}

void inOrderTraversal (BStree_node *nodepointer){
    if (nodepointer!=NULL){
        if (nodepointer->left!=NULL){
            inOrderTraversal(nodepointer->left);
        }

        //Visit node
        key_print(nodepointer->key);
        data_print(nodepointer->data);

        if (nodepointer->right!=NULL){
            inOrderTraversal(nodepointer->right);
        }
    }
}

void free_bstree(BStree_node *nodePointer){
    if (nodePointer!=NULL){
        if (nodePointer->left!=NULL){
            free_bstree(nodePointer->left);
        }

        if (nodePointer->right!=NULL){
            free_bstree(nodePointer->right);
        }

        //Visit node
        key_free(nodePointer->key);
        data_free(nodePointer->data);
        free(nodePointer);
    }
}