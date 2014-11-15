#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "Rotations.h"
#include "CustomAssertions.h"
#include "CException.h"
#include "ErrorCode.h"
Node node1,node4,node5,node6,node7,node8,node10,node11,node12,node13,node15,node18,node20,node22,node30,node40,node60;



void setUp(void)
{
    resetNode(&node1,1);
    resetNode(&node4,4);
    resetNode(&node5,5);
    resetNode(&node6,6);
    resetNode(&node7,7);
    resetNode(&node8,8);
    resetNode(&node10,10);
    resetNode(&node11,11);
    resetNode(&node12,12);
    resetNode(&node13,13);
    resetNode(&node15,15);
    resetNode(&node18,18);
    resetNode(&node20,20);
    resetNode(&node22,22);
    resetNode(&node30,30);
    resetNode(&node40,40);
    resetNode(&node60,60);
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
 *     |      add 13      |
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

/*    root               root
 *     |      add 20      |       
 *     v      --->        v       
 *   10(b)               10(b)            
 *    /                  /  \
 *   5(r)            5(r)   20(r)
 *                                 
 *                    
 *
 */
void test_addRedBlackTree_add_20_to_tree_with_root_10_and_inter_5()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node20,NULL,NULL,'r');
    setNode(&node10,&node5,NULL,'b');

    Node *root = &node10 ;
    

    
    addRedBlackTree(&root,&node20);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node20);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node20,'b',&node10);

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


/*    root               root                   root                      root
 *     |      add 1       |     left rotate      |     right rotate        |
 *     v      --->        v       ---->          v       ---->             v
 *   10(b)               10(b)                 10(b)                      7(b)
 *   /                  /                      /                        /  \
 * 5(r)                5(r)                  7(r)                    5(r) 10(r) 
 *                      \                   /
 *                       7(r)             5(r)
 *
 */
void test_addRedBlackTree_add_7_to_tree_with_root_10_and_inter_5()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,&node5,NULL,'b');
    setNode(&node7,NULL,NULL,'r');

    Node *root = &node10 ;
      
    addRedBlackTree(&root,&node7);
    
    TEST_ASSERT_EQUAL_PTR(root,&node7);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node10,'b',&node7);


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
 *    5(r)   15(r)          5(r) 15(r)       5(b) 15(b)         5(b)  15(b)
 *                          /                 /                 /
 *                        1(r)              1(r)               1(r)
 */
void test_addRedBlackTree_add_1_to_tree_with_5_10_15_nodes()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node15,NULL,NULL,'r');
    setNode(&node10,&node5,&node15,'b');
    setNode(&node1,NULL,NULL,'r');

    Node *root = &node10 ;
    
    _addRedBlackTree(&root,&node1);

    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node1);
    TEST_ASSERT_EQUAL_NODE(&node1,NULL,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node15);

    
}

/*        root                  root             root                root             
 *         |                     |                |                   |
 *         v         add 1       v                v                   v
 *        10(b)       --->     10(b)   --->     10(b)    --->      10(r)
 *       /   \                /   \             /  \               /  \
 *    5(r)   15(r)          5(r) 15(r)       5(b) 15(b)         5(b)  15(b)
 *                           \                \                 \
 *                          7(r)              7(r)               7(r)
 */
void test_addRedBlackTree_add_7_to_tree_with_5_10_15_nodes()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node15,NULL,NULL,'r');
    setNode(&node10,&node5,&node15,'b');
    setNode(&node7,NULL,NULL,'r');

    Node *root = &node10 ;
    
    _addRedBlackTree(&root,&node7);

    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node7);
    TEST_ASSERT_EQUAL_NODE(NULL,&node7,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node15);

    
}


/*        root                  root             root                root             
 *         |                     |                |                   |
 *         v         add 12      v                v                   v
 *        10(b)       --->     10(b)   --->     10(b)    --->      10(r)
 *       /   \                /   \             /  \               /  \
 *    5(r)   15(r)          5(r) 15(r)       5(b) 15(b)         5(b)  15(b)
 *                               /                /                   /
 *                             12(r)            12(r)                12(r)
 */
void test_addRedBlackTree_add_12_to_tree_with_5_10_15_nodes()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node15,NULL,NULL,'r');
    setNode(&node10,&node5,&node15,'b');
    setNode(&node12,NULL,NULL,'r');

    Node *root = &node10 ;
    
    _addRedBlackTree(&root,&node12);

    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node12);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(&node12,NULL,'b',&node15);

    
}

/*        root                  root             root                root             
 *         |                     |                |                   |
 *         v         add 18      v                v                   v
 *        10(b)       --->     10(b)   --->     10(b)    --->      10(r)
 *       /   \                /   \             /  \               /  \
 *    5(r)   15(r)          5(r) 15(r)       5(b) 15(b)         5(b)  15(b)
 *                                 \               \                    \
 *                                18(r)           18(r)                  18(r)
 */
void test_addRedBlackTree_add_18_to_tree_with_5_10_15_nodes()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node15,NULL,NULL,'r');
    setNode(&node10,&node5,&node15,'b');
    setNode(&node18,NULL,NULL,'r');

    Node *root = &node10 ;
    
    _addRedBlackTree(&root,&node18);

    TEST_ASSERT_EQUAL_PTR(root,&node10);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node18);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,&node18,'b',&node15);

    
}


/*           root                  root             root                          
 *            |                     |                |                   
 *            v         add 7      v                 v                   
 *          20(b)       --->     20(b)   --->      20(b)   
 *          /   \                /   \             /  \              
 *      10(b)   22(b)          10(b) 22(b)      10(r) 22(b)       
 *       /  \                  /  \              /  \          
 *    5(r) 15(r)            5(r)  15(r)       5(b)  15(b)             
 *                            \                 \
 *                            7(r)             7(r)
 *
 *
 */
void test_addRedBlackTree_add_7_to_tree_with_5_10_15_20_22nodes()
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node7,NULL,NULL,'r');
    setNode(&node15,NULL,NULL,'r');
    setNode(&node22,NULL,NULL,'b');
    setNode(&node10,&node5,&node15,'b');
    setNode(&node20,&node10,&node22,'b');
    

    Node *root = &node20 ;
    
    addRedBlackTree(&root,&node7);

    TEST_ASSERT_EQUAL_PTR(root,&node20);
    
    TEST_ASSERT_EQUAL_NODE(NULL,&node7,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node7);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node15);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(&node10,&node22,'b',&node20);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node22);

    
}


/*           root                          root                                root
 *            |                             |                                   |
 *            v                add 7        v                                   v
 *           20(b)              --->       20(b)                --->          20(b)
 *         /       \                     /       \                          /       \
 *       4(r)     40(r)                4(r)     40(r)                    4(b)       40(b)
 *      /  \      /   \               /  \       /  \                    /  \       /   \
 *   1(b) 10(b) 30(b) 60(b)         1(b) 10(b) 30(b) 60(b)             1(b) 10(r) 30(b) 60(b)
 *        /  \                          /  \                               /   \
 *      5(r) 15(r)                    5(r) 15(r)                         5(b) 15(b)
 *                                      \                                  \
 *                                      7(r)                              7(r)
 */
void test_addRedBlackTree_add_7_to_tree_with_1_4_5_10_15_20_30_40_60nodes()
{
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,NULL,NULL,'r');
    setNode(&node7,NULL,NULL,'r');
    setNode(&node15,NULL,NULL,'r');
    setNode(&node30,NULL,NULL,'b');
    setNode(&node60,NULL,NULL,'b');
    setNode(&node10,&node5,&node15,'b');
    setNode(&node40,&node30,&node60,'r');
    setNode(&node4,&node1,&node10,'r');
    setNode(&node20,&node4,&node40,'b');
    

    Node *root = &node20 ;
    
    addRedBlackTree(&root,&node7);

    TEST_ASSERT_EQUAL_PTR(root,&node20);
    
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node1);
    TEST_ASSERT_EQUAL_NODE(&node1,&node10,'b',&node4);
    TEST_ASSERT_EQUAL_NODE(NULL,&node7,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node7);
    TEST_ASSERT_EQUAL_NODE(&node5,&node15,'r',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node15);
    TEST_ASSERT_EQUAL_NODE(&node4,&node40,'b',&node20);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node30);
    TEST_ASSERT_EQUAL_NODE(&node30,&node60,'b',&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node60);

    
}
