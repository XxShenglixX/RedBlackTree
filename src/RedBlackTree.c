#include "RedBlackTree.h"
#include "Rotations.h"
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

Node *_delRedBlackTreex(Node **nodePtr,Node *delNode)
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
        if (delNode->data < (*nodePtr)->data)
        {
            if (isDoubleBlack(&(*nodePtr)->left,node) && isBlack(&(*nodePtr)->left))
            {
                if(checkNotNull(&(*nodePtr),Right))
                {
                    if(isRed(&(*nodePtr)->right))
                        case3Handle_redSibling(&(*nodePtr),Right) ;

                    else if(!(case1Handle_blackSibling_redNephew(&(*nodePtr),Right)))
                        case2Handle_blackSibling_2blackNephew(&(*nodePtr),Right);
                }
            }

        }
        else
        {
            if (isDoubleBlack(&(*nodePtr)->right,node) && isBlack(&(*nodePtr)->right))
            {
                if(checkNotNull(&(*nodePtr),Left));
                {
                    if(isRed(&(*nodePtr)->left))
                        case3Handle_redSibling(&(*nodePtr),Left);

                    else if(!(case1Handle_blackSibling_redNephew(&(*nodePtr),Left)))
                        case2Handle_blackSibling_2blackNephew(&(*nodePtr),Left);
                }
            }
        }
    }
    return node ;
}


int case1Handle_blackSibling_redNephew(Node **nodePtr,int type)
{
    int colourChangeDecision = 0 ;

    if (type == Right)
    {
        if(checkNotNull(&(*nodePtr),RightRight))
        {
            if ( isRed(&(*nodePtr)->right->right))
            {
                leftRotate(&(*nodePtr));
                colourChangeDecision = 1;
            }
        }

        else if (checkNotNull(&(*nodePtr),RightLeft))
        {
            if (isRed(&(*nodePtr)->right->left))
            {
                rightLeftRotate(&(*nodePtr));
                colourChangeDecision = 1;
            }
        }
    }

    else if (type == Left)
    {
        if(checkNotNull(&(*nodePtr),LeftLeft))
        {
            if ( isRed(&(*nodePtr)->left->left))
            {
                rightRotate(&(*nodePtr));
                colourChangeDecision = 1;
            }
        }

        else if (checkNotNull(&(*nodePtr),LeftRight))
        {
            if (isRed(&(*nodePtr)->left->right))
            {
                leftRightRotate(&(*nodePtr));
                colourChangeDecision = 1;
            }
        }
    }

    if (colourChangeDecision)
    {
        if (type == Right)
        {
            changeColour(&(*nodePtr),(*nodePtr)->left->colour,0,Self); //New parent takes colour of previous left parents
            changeColour(&(*nodePtr),'b','b',Left_Right);    //Force both child to black
        }
        else if (type == Left)
        {
            changeColour(&(*nodePtr),(*nodePtr)->right->colour,0,Self); //New parent takes colour of previous right parents
            changeColour(&(*nodePtr),'b','b',Left_Right);    //Force both child to black

        }
    }

    return colourChangeDecision ;
}

void case2Handle_blackSibling_2blackNephew(Node **nodePtr,int type)
{

    if (isRed(&(*nodePtr))) //parent is red
        changeColour(&(*nodePtr),'b',0,Self); //parent to black
    else
        changeColour(&(*nodePtr),'d',0,Self); //parent to double black

    if (type == Right)
        changeColour(&(*nodePtr),'r',0,Right); //Force right child to red
    else if (type == Left)
        changeColour(&(*nodePtr),'r',0,Left); //Force left child to red

}

void case3Handle_redSibling(Node **nodePtr,int type)
{
    if (type == Right) //Right not NULL
    {
        leftRotate(&(*nodePtr));
        changeColour(&(*nodePtr),'r',0,Left); //Force left child to red first
        if(!(case1Handle_blackSibling_redNephew(&(*nodePtr)->left,Right)))
            case2Handle_blackSibling_2blackNephew(&(*nodePtr)->left,Right);
    }

    else if (type == Left)
    {
        rightRotate(&(*nodePtr));
        changeColour(&(*nodePtr),'r',0,Right); //Force right child to red first
        if(!(case1Handle_blackSibling_redNephew(&(*nodePtr)->right,Left)))
            case2Handle_blackSibling_2blackNephew(&(*nodePtr)->right,Left);

    }

}

Node *removeNextLargerSuccessor(Node **parentPtr)
{
    Node *successor = *parentPtr, *storeRight;

    if (checkNotNull(&(*parentPtr),Left))
            successor = removeNextLargerSuccessor(&(*parentPtr)->left);

    else
    {
        if (checkNotNull(&(*parentPtr),Right))
        {
            *parentPtr = (*parentPtr)->right ; // replace parent with right child
            changeColour(&(*parentPtr),'b',0,Self); // flip parent colour to black
        }
        else
            *parentPtr = NULL ;

    }


    return successor ;
}


int isRed(Node **nodePtr)
{
    if (*nodePtr != NULL)
    {
        if ((*nodePtr)->colour == 'r')
            return 1 ;
    }

    return 0 ;
}

int isBlack(Node **nodePtr)
{
    if (*nodePtr != NULL)
    {
        if ((*nodePtr)->colour == 'b')
            return 1 ;
        else
            return 0 ;
    }

    return 1 ;
}





/**
* Note: x == not possible
*	node		removed node		return
*	---------------------------------------
*	NULL			NULL			  x
*	NULL			red			  	  0
*	NULL			black			  1
*	NULL			double black	  x
*	red				NULL			  x
*	red				red			  	  0
*	red				black			  0
*	red				double black	  x
*	black			NULL			  x
*	black			red			  	  0
*	black			black			  0
*	black			double black	  x
*	double black	NULL			  x
*	double black	red			  	  1
*	double black	black			  1
*	double black	double black	  x
*/

int isDoubleBlack(Node **nodePtr,Node *delNode)
{
    if ( !checkNotNull(&(*nodePtr),Self) && isBlack(&delNode))
        return 1 ;
    else if ( checkNotNull(&(*nodePtr),Self) && (*nodePtr)->colour == 'd' && ( isBlack(&delNode) || isRed(&delNode) ))
        return 1 ;
    else
        return 0;
}

void changeColour(Node **nodePtr,int colour1,int colour2,int type)
{
    Node *node1 = *nodePtr ;

    switch(type)
    {
        case Self   :       (*nodePtr)->colour = colour1 ;
                            break ;
        case Left   :       (*nodePtr)->left->colour = colour1 ;
                            break ;
        case Right  :       (*nodePtr)->right->colour = colour1 ;
                            break ;
        case Left_Right :   (*nodePtr)->left->colour = colour1 ;
                            (*nodePtr)->right->colour = colour2 ;
                            break ;
        default :           break ;
    }
}





int checkNotNull(Node **nodePtr,int type)
{
    int result = 0;
    switch(type)
    {
        case Self:      if ((*nodePtr) != NULL)
                        result = 1;
                        break;
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