#include "RedBlackTree.h"
#include "Rotation.h"
#include "CException.h"
#include "ErrorCode.h"
#include <stdio.h>

void addRedBlackTree(Node **nodePtr, Node *newNode)
{
    _addRedBlackTree(nodePtr,newNode);
    (*nodePtr)->colour = 'b';

}

void _addRedBlackTree(Node **nodePtr, Node *newNode)
{
    if (*nodePtr == NULL)
        {
            *nodePtr = newNode;
            return ;
        }

        
    if(newNode->data < (*nodePtr)->data)
        {
            _addRedBlackTree(&(*nodePtr)->left,newNode);
            if ((*nodePtr)->left->left != NULL)
            {
                if((*nodePtr)->left->colour == 'r' && (*nodePtr)->left->left->colour)
                {    
                    rightRotate(&(*nodePtr));
                }   
            } 
        }
    else if (newNode->data > (*nodePtr)->data)
        _addRedBlackTree(&(*nodePtr)->right,newNode);    
    else
        Throw(ERR_EQUIVALENT_NODE);

   
    
        
}