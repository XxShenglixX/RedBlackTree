#ifndef RedBlackTree_H
#define RedBlackTree_H
#include "Node.h"
#include "Direction.h"

void addRedBlackTree(Node **nodePtr, Node *newNode);
void _addRedBlackTree(Node **nodePtr,Node *newNode);

int checkNotNull(Node **nodePtr,int type);
int colourCheck(Node **nodePtr,int type);

void colourFlip(Node **nodePtr,int type);

#endif // RedBlackTree_H
