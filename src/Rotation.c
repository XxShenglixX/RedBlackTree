#include "Rotation.h"
#include "Node.h"
#include <stdio.h>
void rightRotate(Node **nodePtr)
{
    Node *newRoot, *temp = NULL ;
    
    newRoot = (*nodePtr)->left; //retrieve left subchild of the initial root and store to newRoot
    if (newRoot->right != NULL) // check whether the newRoot have right subchild
        temp = newRoot->right ; //if yes then store it to temp
    
    newRoot->right = *nodePtr ; //right subchild of newRoot point to initial root ;
    
    (*nodePtr)->left = temp ; //put temp to left of initial root
    
    
    *nodePtr = newRoot ; // newRoot is officially the root now
  
}

void leftRotate(Node **nodePtr)
{
    Node *newRoot, *temp = NULL ;
    
    newRoot = (*nodePtr)->right; //retrieve right subchild of the initial root and store to newRoot
    if (newRoot->left != NULL) // check whether the newRoot have left subchild
        temp = newRoot->left ; //if yes then store it to temp
    
    newRoot->left = *nodePtr ; //left subchild of newRoot point to initial root ;
    
    (*nodePtr)->right = temp ; //put temp to right of initial root
    
    
    *nodePtr = newRoot ; // newRoot is officially the root now
  


}

void leftRightRotate(Node **nodePtr)
{
    leftRotate(&(*nodePtr)->left); //left rotate the left child of initial root 1st
    rightRotate(&(*nodePtr));

}
void rightLeftRotate(Node **nodePtr)
{
    rightRotate(&(*nodePtr)->right); //right rotate the right child of initial root 1st
    leftRotate(&(*nodePtr));

}
