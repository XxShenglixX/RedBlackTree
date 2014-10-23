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
            if (checkNotNull(&(*nodePtr),Left_Right))
            {
                if(colourCheck(&(*nodePtr),Left_Right))
               ;
            }
            _addRedBlackTree(&(*nodePtr)->left,newNode);
            
            if (checkNotNull(&(*nodePtr),LeftLeft))
            {
                if(colourCheck(&(*nodePtr),LeftLeft))
                    {
                        rightRotate(&(*nodePtr));
                        colourFlip(&(*nodePtr),Right);
                    }
            }
            else if (checkNotNull(&(*nodePtr),LeftRight))
            {
                if(colourCheck(&(*nodePtr),LeftRight))
                {
                        leftRightRotate(&(*nodePtr));
                        colourFlip(&(*nodePtr),Right);
                }
            }
        }
    else if (newNode->data > (*nodePtr)->data)
        {
            if (checkNotNull(&(*nodePtr),Left_Right))
            {
                if(colourCheck(&(*nodePtr),Left_Right))
                 ;
            }
            _addRedBlackTree(&(*nodePtr)->right,newNode);
            

             if (checkNotNull(&(*nodePtr),RightRight))
            {
                if(colourCheck(&(*nodePtr),RightRight))
                    {
                        leftRotate(&(*nodePtr));
                        colourFlip(&(*nodePtr),Left);
                    }
            }
            else if (checkNotNull(&(*nodePtr),RightLeft))
            {
                if(colourCheck(&(*nodePtr),RightLeft))
                {
                        rightLeftRotate(&(*nodePtr));
                        colourFlip(&(*nodePtr),Left);
                }
            }
        }
    else
        Throw(ERR_EQUIVALENT_NODE);

}



int checkNotNull(Node **nodePtr,int type)
{
    int result = 0;
    switch(type)
    {
        case LeftLeft:     if ((*nodePtr)->left->left != NULL)
                        result = 1;
                break ;
        case LeftRight:     if ((*nodePtr)->left->right != NULL)
                        result = 1 ;
                break ;
        case RightLeft:     if ((*nodePtr)->right->left != NULL)
                        result = 1;
                break ;
        case RightRight:     if ((*nodePtr)->right->right != NULL)
                        result = 1 ;
                break ;
        case Left_Right:     if (((*nodePtr)->left != NULL) && ((*nodePtr)->right != NULL))
                        result = 1 ;
                break ;
        default : result = 0;
                  break;
    }

    return result ;
}

int colourCheck(Node **nodePtr,int type)
{
    int result = 0;
    switch(type)
    {
        case LeftLeft:  if((*nodePtr)->left->colour == 'r' && (*nodePtr)->left->left->colour == 'r')
                        result = 1;
                        break ;
        case LeftRight: if((*nodePtr)->left->colour == 'r' && (*nodePtr)->left->right->colour == 'r')
                        result = 1 ;
                        break ;
        case RightLeft:  if((*nodePtr)->right->colour == 'r' && (*nodePtr)->right->left->colour == 'r')
                        result = 1;
                        break ;
        case RightRight: if((*nodePtr)->right->colour == 'r' && (*nodePtr)->right->right->colour == 'r') 
                        result = 1 ;
                        break ;
        case Left_Right: if((*nodePtr)->left->colour == 'r' && (*nodePtr)->right->colour == 'r')
                        result = 1 ;
                        break ;                
        default : result = 0;
                  break;
    }

    return result ;
}

void colourFlip(Node **nodePtr,int type)
{
    switch(type)
    {
        case Right: (*nodePtr)->right->colour ='r' ;
                break ;
        case Left: (*nodePtr)->left->colour ='r' ;
                break ;
        case Left_Right: (*nodePtr)->left->colour ='b' ;
                         (*nodePtr)->right->colour ='b' ;
                         (*nodePtr)->colour = 'r' ;       
        default : break ;
    }
}