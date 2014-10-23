#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "Rotation.h"
#include "CustomAssertions.h"
#include "CException.h"
#include "ErrorCode.h"
Node node1,node5,node6,node7,node8,node10,node11,node12,node13,node15,node20,node40;



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
    resetNode(&node40,40);
}

void tearDown(void)
{
}

/*    root               root
 *     |     add 10       |
 *     v      --->        v
 *   NULL               10(b)
 */
void test_addRedBlackTree_add_10_to_empty_tree(void)
{
    setNode(&node10,NULL,NULL,'r');
    Node *root = NULL ;
    
    addRedBlackTree(&root,&node10);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node10);
    //TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
    //TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
    //TEST_ASSERT_EQUAL('b',node10.colour);

}

/*    root               root
 *     |      add 5       |
 *     v      --->        v
 *   10(b)               10(b)
 *                       /
 *                     5(r)
 */
void test_addRedBlackTree_add_5_to_tree_with_root_10(void)
{
    setNode(&node10,NULL,NULL,'b');
    setNode(&node5,NULL,NULL,'r');
    Node *root = &node10 ;
    
    addRedBlackTree(&root,&node5);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(&node5,NULL,'b',&node10);
    //TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    //TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
    //TEST_ASSERT_EQUAL('b',node10.colour);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
    //TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    //TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    //TEST_ASSERT_EQUAL('r',node10.colour);

}

/*    root               root
 *     |      add 5       |
 *     v      --->        v
 *   10(b)               10(b)
 *                         \
 *                         13(r)
 */
void test_addRedBlackTree_add_13_to_tree_with_root_10(void)
{
    setNode(&node10,NULL,NULL,'b');
    setNode(&node13,NULL,NULL,'r');
    Node *root = &node10 ;
    
    addRedBlackTree(&root,&node13);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,&node13,'b',&node10);
    //TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    //TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
    //TEST_ASSERT_EQUAL('b',node10.colour);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node13);
    //TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    //TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    //TEST_ASSERT_EQUAL('r',node10.colour);

}



/*    root               root                           root
 *     |      add 1       |          right rotate        |
 *     v      --->        v          ---->               v
 *   10(b)               10(b)                          5(b)
 *   /                  /                              /  \
 * 5(r)                5(r)                         1(r) 10(r) 
 *                    /             
 *                   1(r)        
 *
 */
void test_addRedBlackTree_add_1_to_tree_with_root_10_and_inter_5()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,&node5,NULL,'b');
    setNode(&node1,NULL,NULL,'r');

    Node *root = &node10 ;
      
    addRedBlackTree(&root,&node1);
    
    TEST_ASSERT_EQUAL_PTR(root,&node5);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node1);
    TEST_ASSERT_EQUAL_NODE(&node1,&node10,'b',&node5);


}



/*    root               root
 *     |      add 5       |       
 *     v      --->        v       
 *   10(b)               10(b)            
 *    \                  /  \
 *    20(r)          5(r)   20(r)
 *                                 
 *                    
 *
 */
void test_addRedBlackTree_add_5_to_tree_with_root_10_and_inter_20()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node20,NULL,NULL,'r');
    setNode(&node10,NULL,&node20,'b');

    Node *root = &node10 ;
    

    
    addRedBlackTree(&root,&node5);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node20);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node20,'b',&node10);

}


/*    root               root                     root
 *     |      add 5       |       left rotate      |
 *     v      --->        v           --->         v
 *   10(b)               10(b)                   20(b)
 *    \                    \                     /   \
 *    20(r)               20(r)              10(r)  40(r)
 *                          \       
 *                         40(r)
 *
 */
void test_addRedBlackTree_add_40_to_tree_with_root_10_and_inter_20()
{
    setNode(&node20,NULL,NULL,'r');
    setNode(&node40,NULL,NULL,'r');
    setNode(&node10,NULL,&node20,'b');

    Node *root = &node10 ;
    

    
    addRedBlackTree(&root,&node40);
    
    TEST_ASSERT_EQUAL_PTR(root,&node20);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node40);
    TEST_ASSERT_EQUAL_NODE(&node10,&node40,'b',&node20);

}

/*    root               root                      root                  root
 *     |      add 5       |       right rotate      |    left rotate      |
 *     v      --->        v           --->          v        --->         v
 *   10(b)               10(b)                   10(b)                   15(b)
 *    \                    \                       \                    /    \
 *    20(r)               20(r)                    15(r)             10(r)  20(r)
 *                        /                         \
 *                      15(r)                       20(r)
 *
 */
void test_addRedBlackTree_add_15_to_tree_with_root_10_and_inter_20()
{
    setNode(&node15,NULL,NULL,'r');
    setNode(&node20,NULL,NULL,'r');
    setNode(&node10,NULL,&node20,'b');

    Node *root = &node10 ;
    

    
    addRedBlackTree(&root,&node15);
    
    TEST_ASSERT_EQUAL_PTR(root,&node15);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node20);
    TEST_ASSERT_EQUAL_NODE(&node10,&node20,'b',&node15);

}

/* ____________________4 nodes ____________________ */
/* ____________________4 nodes ____________________ */
/* ____________________4 nodes ____________________ */
/* ____________________4 nodes ____________________ */
/* ____________________4 nodes ____________________ */



/*        root                  root             root                root             
 *         |                     |                |                   |
 *         v         add 1       v                v                   v
 *        10(b)       --->     10(b)   --->     10(b)    --->      10(r)
 *       /   \                /   \             /  \               /  \
 *    5(r)   15(r)          5(r) 15(r)       5(b) 15(r)         5(b)  15(r)
 *                          /                 /                 /
 *                        1(r)              1(r)               1(r)
 */
void test_addRedBlackTree_add_1_to_tree_with_5_10_15_nodes()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,NULL,NULL,'r');
    setNode(&node15,&node5,&node15,'b');
    setNode(&node1,NULL,NULL,'r');

    Node *root = &node10 ;
    
    _addRedBlackTree(&root,&node1);

    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node1);
    TEST_ASSERT_EQUAL_NODE(&node1,NULL,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node15);

    
}

/*        root                  root             root                root             
 *         |                     |                |                   |
 *         v         add 1       v                v                   v
 *        10(b)       --->     10(b)   --->     10(b)    --->      10(r)
 *       /   \                /   \             /  \               /  \
 *    5(r)   15(r)          5(r) 15(r)       5(b) 15(r)         5(b)  15(r)
 *                           \                \                 \
 *                          7(r)              7(r)               7(r)
 */
void xtest_addRedBlackTree_add_7_to_tree_with_5_10_15_nodes()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,NULL,NULL,'r');
    setNode(&node15,&node5,&node15,'b');
    setNode(&node1,NULL,NULL,'r');

    Node *root = &node10 ;
    
    _addRedBlackTree(&root,&node1);

    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node1);
    TEST_ASSERT_EQUAL_NODE(&node1,NULL,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node15);

    
}




