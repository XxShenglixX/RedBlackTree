#include "unity.h"
#include "Rotation.h"
#include <stdio.h>
Node node1,node5,node6,node7,node8,node10,node11,node12,node13,node15,node20;

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
    resetNode(&node6,6);
    resetNode(&node7,7);
    resetNode(&node8,8);
    resetNode(&node10,10);
    resetNode(&node11,11);
    resetNode(&node12,12);
    resetNode(&node13,13);
    resetNode(&node15,15);
    resetNode(&node20,20);

}

void tearDown(void)
{
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

void xtest_changeRootByVal()
{
    Node *root ;
    root = &node10 ;
    
    printf("test changeRootByVal()\n");
    printf("root is node %d with address %x\n",root->data,root);
    changeRootByVal(root,&node5);
    printf("root is node %d with address %x\n",root->data,root);

}

void xtest_changeRootByRef()
{
    Node *root ;
    root = &node10 ;
    
    printf("test changeRootByRef()\n");
    printf("root is node %d with address %x\n",root->data,root);
    changeRootByVal(&root,&node5);
    printf("root is node %d with address %x\n",root->data,root);

}

/* ________________________________________________________*/

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


/*              root
 *               |            root
 *               v             |
 *              10             v
 *             /  \            5
 *            5    15 --->   /  \
 *           /              1   10
 *          1                    \
 *                               15
 */
void test_rightRotate_4_nodes()
{
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,&node1,NULL,'b');
    setNode(&node15,NULL,NULL,'b');
    setNode(&node10,&node5,&node15,'b');

    Node *root = &node10;
    
    rightRotate(&root);
   
    
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
    
    TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
    
    TEST_ASSERT_EQUAL_PTR(root,&node5);

}

/*              root
 *               |            root
 *               v             |
 *              10             v
 *             /  \            5
 *            5    15 --->   /  \
 *           / \            1   10
 *          1   8              /  \
 *                            8   15
 */
void test_rightRotate_5_nodes()
{
    setNode(&node1,NULL,NULL,'b');
    setNode(&node8,NULL,NULL,'b');
    setNode(&node5,&node1,&node8,'b');
    setNode(&node15,NULL,NULL,'b');
    setNode(&node10,&node5,&node15,'b');
    
    Node *root = &node10;
    
    rightRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node8.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node8.right,NULL);    
    
    
    TEST_ASSERT_EQUAL_PTR(node10.left,&node8);
    TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
    
    TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
    
    TEST_ASSERT_EQUAL_PTR(root,&node5);
}


/**
 * root ->   1
 *            \               5  <- root
 *            5    --->     /  \
 *             \           1    8
 *              8
 */
 void test_leftRotate_3_nodes()
 {
    setNode(&node8,NULL,NULL,'b');
    setNode(&node5,NULL,&node8,'b');
    setNode(&node1,NULL,&node5,'b');
   
    Node *root = &node1;
    
    leftRotate(&root);
 
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL); 
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);    
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,&node8);
    
    TEST_ASSERT_EQUAL_PTR(node8.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node8.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(root,&node5);
 }
 
 
/**
 * root ->   5               10  <- root
 *         /  \             /  \
 *        1   10   --->    5   15
 *             \          /
 *             15        1
 */ 
void test_leftRotate_4_nodes()
{
    setNode(&node1,NULL,NULL,'b');
    setNode(&node15,NULL,NULL,'b');
    setNode(&node10,NULL,&node15,'b');
    setNode(&node5,&node1,&node10,'b');

   
    Node *root = &node5;
    
    leftRotate(&root);
 
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL); 
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,NULL);    
    
    TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
    
    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);

}


/**
 * root ->   5               10  <- root
 *         /  \             /  \
 *        1   10   --->    5    15
 *           /  \        /  \
 *          8   15      1    8
 */
void test_leftRotate_5_nodes()
{
    setNode(&node1,NULL,NULL,'b');
    setNode(&node15,NULL,NULL,'b');
    setNode(&node8,NULL,NULL,'b');
    setNode(&node10,&node8,&node15,'b');
    setNode(&node5,&node1,&node10,'b');

   
    Node *root = &node5;
    
    leftRotate(&root);
 
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL); 
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node8.left,NULL); 
    TEST_ASSERT_EQUAL_PTR(node8.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,&node8);    
    
    TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
    
    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);

}

/*_____________________leftRightRotate__________________________*/



/**
 * root ->   10            10           7  <- root
 *          /             /           /   \
 *         5     --->    7     --->  5    10
 *          \          /
 *           7        5
 */
void test_leftRightRotate_3_nodes()
{
    setNode(&node7,NULL,NULL,'b');
    setNode(&node5,NULL,&node7,'b');
    setNode(&node10,&node5,NULL,'b');

    Node *root = &node10;
    
    leftRightRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.right,NULL);

    TEST_ASSERT_EQUAL_PTR(node7.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node7.right,&node10);

    TEST_ASSERT_EQUAL_PTR(root,&node7);
}

/**
 * root ->   10            10           7  <- root
 *          /             /           /   \
 *         5     --->    7     --->  5    10
 *       /  \          /            /
 *      1    7        5            1
 *                   /
 *                  1
 */
void test_leftRightRotate_4_nodes()
{
    setNode(&node7,NULL,NULL,'b');
    setNode(&node1,NULL,NULL,'b');    
    setNode(&node5,&node1,&node7,'b');
    setNode(&node10,&node5,NULL,'b');

    Node *root = &node10;
    
    leftRightRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.right,NULL);

    TEST_ASSERT_EQUAL_PTR(node7.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node7.right,&node10);

    TEST_ASSERT_EQUAL_PTR(root,&node7);
} 


/**
 * root ->   10                 10                 7 <-root
 *          /  \               /  \               / \
 *         5   15    --->     7   15   --->      5  10
 *       /  \                / \                /  / \
 *      1    7              5   8              1   8 15
 *            \            /
 *             8          1
 */
void test_leftRightRotate_6_nodes()
{
    setNode(&node8,NULL,NULL,'b');
    setNode(&node1,NULL,NULL,'b');
    setNode(&node15,NULL,NULL,'b');
    setNode(&node7,NULL,&node8,'b');
    setNode(&node5,&node1,&node7,'b');
    setNode(&node10,&node5,&node15,'b');

    Node *root = &node10;
    
    leftRightRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);

    TEST_ASSERT_EQUAL_PTR(node8.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node8.right,NULL);

    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,&node8);
    TEST_ASSERT_EQUAL_PTR(node10.right,&node15);

    TEST_ASSERT_EQUAL_PTR(node7.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node7.right,&node10);

    TEST_ASSERT_EQUAL_PTR(root,&node7);
}

/**
 * root ->   10                 10                 7 <-root
 *          /  \               /  \               / \
 *         5   15    --->     7   15   --->      5   10
 *       /  \                / \                / \   \
 *      1    7              5   6              1  6   15
 *          /              / 
 *         6              1
 */
void test_leftRightRotate_6_nodes_()
{
    setNode(&node6,NULL,NULL,'b');
    setNode(&node1,NULL,NULL,'b');
    setNode(&node15,NULL,NULL,'b');
    setNode(&node7,&node6,NULL,'b');
    setNode(&node5,&node1,&node7,'b');
    setNode(&node10,&node5,&node15,'b');

    Node *root = &node10;
    
    leftRightRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node1.right,NULL);

    TEST_ASSERT_EQUAL_PTR(node6.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node6.right,NULL);

    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,&node6);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.right,&node15);

    TEST_ASSERT_EQUAL_PTR(node7.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node7.right,&node10);

    TEST_ASSERT_EQUAL_PTR(root,&node7);
}  


/*___________________rightLeftRotate_________________________________*/


/**
 * root ->   10       10                12  <- root
 *             \       \              /   \
 *             15 --->  12     --->  10    15
 *            /          \
 *           12           15
 */
void test_rightLeftRotate_3_nodes()
{
    setNode(&node12,NULL,NULL,'b');
    setNode(&node15,&node12,NULL,'b');
    setNode(&node10,NULL,&node15,'b');

    Node *root = &node10;
    
    rightLeftRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.right,NULL);

    TEST_ASSERT_EQUAL_PTR(node12.left,&node10);
    TEST_ASSERT_EQUAL_PTR(node12.right,&node15);

    TEST_ASSERT_EQUAL_PTR(root,&node12);
}


/**
 * root ->   10         10                12  <- root
 *             \         \              /   \
 *             15  --->  12     --->  10    15
 *            /  \        \                  \
 *           12  20       15                 20
 *                         \
 *                         20
 */
void test_rightLeftRotate_4_nodes()
{
    setNode(&node12,NULL,NULL,'b');
    setNode(&node20,NULL,NULL,'b');
    setNode(&node15,&node12,&node20,'b');
    setNode(&node10,NULL,&node15,'b');

    Node *root = &node10;
    
    rightLeftRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.right,&node20);

    TEST_ASSERT_EQUAL_PTR(node12.left,&node10);
    TEST_ASSERT_EQUAL_PTR(node12.right,&node15);

    TEST_ASSERT_EQUAL_PTR(root,&node12);
}

/**
 * root ->   10            10                 12  <- root
 *          /  \          / \                /   \
 *         5   15  --->  5   12     --->   10    15
 *            /  \          / \            / \    \
 *           12  20       11   15         5  11   20
 *          /                  \
 *         11                  20
 */
void test_rightLeftRotate_6_nodes()
{
    setNode(&node5,NULL,NULL,'b');
    setNode(&node11,NULL,NULL,'b');
    setNode(&node20,NULL,NULL,'b');
    setNode(&node12,&node11,NULL,'b');
    setNode(&node15,&node12,&node20,'b');
    setNode(&node10,&node5,&node15,'b');

    Node *root = &node10;
    
    rightLeftRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node11.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node11.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node10.right,&node11);
    
    TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node15.right,&node20);

    TEST_ASSERT_EQUAL_PTR(node12.left,&node10);
    TEST_ASSERT_EQUAL_PTR(node12.right,&node15);

    TEST_ASSERT_EQUAL_PTR(root,&node12);
}

/**
 * root ->   10            10                 12  <- root
 *          /  \          / \                /  \
 *         5   15  --->  5   12     --->   10    15
 *            /  \            \           /     / \
 *           12  20           15         5     13 20
 *            \              /  \
 *            13            13  20
 */
void test_rightLeftRotate_6_nodes_()
{
    setNode(&node5,NULL,NULL,'b');
    setNode(&node13,NULL,NULL,'b');
    setNode(&node20,NULL,NULL,'b');
    setNode(&node12,NULL,&node13,'b');
    setNode(&node15,&node12,&node20,'b');
    setNode(&node10,&node5,&node15,'b');

    Node *root = &node10;
    
    rightLeftRotate(&root);
    
    TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node13.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node13.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
    TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
    TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
    
    TEST_ASSERT_EQUAL_PTR(node15.left,&node13);
    TEST_ASSERT_EQUAL_PTR(node15.right,&node20);

    TEST_ASSERT_EQUAL_PTR(node12.left,&node10);
    TEST_ASSERT_EQUAL_PTR(node12.right,&node15);

    TEST_ASSERT_EQUAL_PTR(root,&node12);
}

