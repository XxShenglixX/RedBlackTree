#include "RedBlackTree.h"
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
        (*nodePtr)->left = newNode ;
    else if (newNode->data > (*nodePtr)->data)
        (*nodePtr)->right = newNode ;    
    else
        Throw(ERR_EQUIVALENT_NODE);

}