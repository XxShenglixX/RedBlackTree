#ifndef RedBlackTree_H
#define RedBlackTree_H
#include "Node.h"
#include "Direction.h"

void addRedBlackTree(Node **nodePtr, Node *newNode);
void _addRedBlackTree(Node **nodePtr,Node *newNode);

Node *delRedBlackTree(Node **nodePtr,Node *delNode);
Node *_delRedBlackTree(Node **nodePtr,Node *delNode);
Node *removeNextLargerSuccessor(Node **parentPtr);

int isRed(Node **nodePtr);
int isBlack(Node **nodePtr);
int isDoubleBlack(Node **nodePtr,Node *delNode);


int checkNotNull(Node **nodePtr,int type);
int colourCheck(Node **nodePtr,int type);


void changeColour(Node **nodePtr,int colour1,int colour2,int type);

void selectCase(Node **nodePtr, Node *delNode);

int case1Handle_blackSibling_redNephew(Node **nodePtr,int type);
void case2Handle_blackSibling_2blackNephew(Node **nodePtr,int type);
void case3Handle_redSibling(Node **nodePtr,int type);

void colourFlip(Node **nodePtr,int type);

#endif // RedBlackTree_H
