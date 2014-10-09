#include "unity.h"
#include "Rotation.h"
#include <stdio.h>
Node node1,node5,node10,node15;

void setNode(Node *target,Node *left,Node *right,char colour)
{
    target->left = left;
    target->right = right ;
    target->colour = colour ;
}

void resetNode(Node *target,int data)
{
    target->left = NULL;
    target->right = NULL;
    target->colour = 'b';
    target->data = data;
}

void setUp(void)
{
    resetNode(&node1,1);
    resetNode(&node5,5);
    resetNode(&node10,10);
    resetNode(&node15,15);
}

void tearDown(void)
{
}

/*              root
 *               |            root
 *               v             |
 *              10             v
 *             /               5
 *            5    --->      /  \
 *           /              1   10
 *          1
 */
void test_rightRotate_3_nodes()
{
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,&node1,NULL,'b');
    setNode(&node10,&node5,NULL,'b');

    Node *root = &node10;
    
    rightRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
    TEST_ASSERT_EQUAL_PTR(root,&node5);
}

void changeRootByVal(Node *node,Node *newNode)
{
    node = newNode ;
    printf("changeRootByVla : node =%p\n",node);

}


void changeRootByRef(Node **nodePtr,Node *newNode)
{
    *nodePtr = newNode ;
    printf("changeRootByVal : node =%p\n",*nodePtr);

}

void test_changeRootByVal()
{
    Node *root ;
    root = &node10 ;
    
    printf("test changeRootByVal()\n");
    printf("root is node %d with address %x\n",root->data,root);
    changeRootByVal(root,&node5);
    printf("root is node %d with address %x\n",root->data,root);

}

void test_changeRootByRef()
{
    Node *root ;
    root = &node10 ;
    
    printf("test changeRootByRef()\n");
    printf("root is node %d with address %x\n",root->data,root);
    changeRootByVal(&root,&node5);
    printf("root is node %d with address %x\n",root->data,root);

}