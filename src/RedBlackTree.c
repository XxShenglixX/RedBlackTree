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
                    colourFlip(&(*nodePtr),Left_Right);
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
                    colourFlip(&(*nodePtr),Left_Right);
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

Node *delRedBlackTree(Node **nodePtr,Node *delNode)
{
    Node *node = _delRedBlackTree(nodePtr, delNode);
    
     
    if( *nodePtr != NULL)
        (*nodePtr)->colour = 'b';
        
    return node;
}

Node *_delRedBlackTree(Node **nodePtr,Node *delNode)
{
    Node *node = *nodePtr ;
    
    if ( delNode->data == (*nodePtr)->data )
        *nodePtr = NULL ;
    
    else if ( delNode->data < (*nodePtr)->data )
    {
        if (checkNotNull(&(*nodePtr),Left))
            node = _delRedBlackTree(&(*nodePtr)->left,delNode);
        else
            Throw(ERR_NODE_UNAVAILABLE);
    }
    
    else if ( delNode->data > (*nodePtr)->data )
    {
        if (checkNotNull(&(*nodePtr),Right))
            node = _delRedBlackTree(&(*nodePtr)->right,delNode);
        else
            Throw(ERR_NODE_UNAVAILABLE);
    }
   
    if ( *nodePtr != NULL)
    {
        if ( (!checkNotNull(&(*nodePtr),Left)) && (checkNotNull(&(*nodePtr),Right)) ) // Parent with missing left 
        {
            if(colourCheck(&(*nodePtr),DEL_Right)) //check right child colour
                colourFlip(&(*nodePtr),DEL_Right); //if right is black , change it to red and parent to black
            else //right child is red , left rotation needed
            {
                if (checkNotNull(&(*nodePtr),RightLeft))
                {
                    leftRotate(&(*nodePtr));
                    colourFlip(&(*nodePtr),DEL_LeftRight);
                }
            }
        }
    
        else if ( (checkNotNull(&(*nodePtr),Left)) && (!checkNotNull(&(*nodePtr),Right)) ) // Parent with missing right
        {
            if(colourCheck(&(*nodePtr),DEL_Left)) //check left child colour
                colourFlip(&(*nodePtr),DEL_Left); // if left is black , change it to red and parent to black
            else //left child is red , right rotation needed
            {
                if (checkNotNull(&(*nodePtr),LeftRight) )
                {
                    rightRotate(&(*nodePtr));
                    colourFlip(&(*nodePtr),DEL_RightLeft);
                }
            }
        }
    
    }
    return node ;
}
















int checkNotNull(Node **nodePtr,int type)
{
    int result = 0;
    switch(type)
    {
        case Left:      if ((*nodePtr)->left != NULL)
                        result = 1;
                        break;
        case Right:      if ((*nodePtr)->right != NULL)
                        result = 1;
                        break;                        
        case LeftLeft:  if ((*nodePtr)->left->left != NULL)
                        result = 1;
                        break ;
        case LeftRight: if ((*nodePtr)->left->right != NULL)
                        result = 1 ;
                        break ;
        case RightLeft: if ((*nodePtr)->right->left != NULL)
                        result = 1;
                        break ;
        case RightRight:if ((*nodePtr)->right->right != NULL)
                        result = 1 ;
                        break ;
        case Left_Right:if (((*nodePtr)->left != NULL) && ((*nodePtr)->right != NULL))
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
        case LeftLeft:      if((*nodePtr)->left->colour == 'r' && (*nodePtr)->left->left->colour == 'r')
                            result = 1;
                            break ;
        case LeftRight:     if((*nodePtr)->left->colour == 'r' && (*nodePtr)->left->right->colour == 'r')
                            result = 1 ;
                            break ;
        case RightLeft:     if((*nodePtr)->right->colour == 'r' && (*nodePtr)->right->left->colour == 'r')
                            result = 1;
                            break ;
        case RightRight:    if((*nodePtr)->right->colour == 'r' && (*nodePtr)->right->right->colour == 'r') 
                            result = 1 ;
                            break ;
        case Left_Right:    if((*nodePtr)->left->colour == 'r' && (*nodePtr)->right->colour == 'r')
                            result = 1 ;
                            break ;
        case DEL_Left:      if((*nodePtr)->left->colour == 'b')
                            result = 1 ;
                            break ;
        case DEL_Right:     if((*nodePtr)->right->colour == 'b')
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
        case Right:         (*nodePtr)->right->colour ='r' ;
                            break ;
        case Left:          (*nodePtr)->left->colour ='r' ;
                            break ;
        case Left_Right:    (*nodePtr)->left->colour ='b' ;
                            (*nodePtr)->right->colour ='b' ;
                            (*nodePtr)->colour = 'r' ; 
                            break ;
        case DEL_Left:      (*nodePtr)->left->colour ='r' ;
                            (*nodePtr)->colour ='b' ;
                            break ;
        case DEL_Right:     (*nodePtr)->right->colour ='r' ;
                            (*nodePtr)->colour ='b' ;
                            break ;
        case DEL_LeftRight: (*nodePtr)->left->right->colour = 'r';
                            break ;
        case DEL_RightLeft: (*nodePtr)->right->left->colour = 'r';
                            break ;
        default : break ;
    }
}