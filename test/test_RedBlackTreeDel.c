#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "Rotation.h"
#include "CustomAssertions.h"
#include "CException.h"
#include "ErrorCode.h"
Node node1,node2,node3,node4,node5,node6,node7,node8,node10,node11,node12,node13,node15,node18,node20,node22,node30,node40,node60;



void setUp(void)
{
    resetNode(&node1,1);
    resetNode(&node2,2);
    resetNode(&node3,3);
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


/*
 *   root
 *     |    remove 5
 *     v      ----->   Throw ERR_NODE_UNAVAILABLE
 *    1(b)
 *
 */
void test_delRedBlackTree_remove_5_from_tree_with_root_1_should_throw_error()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    Node *node ;
    Node *root = &node1;

    Try
    {
        node = delRedBlackTree(&root, &node5);
        TEST_FAIL_MESSAGE("Expected ERR_NODE_UNAVAILABLE to be thrown. But receive none");
    }
    Catch(err)
    {
        TEST_ASSERT_EQUAL_PTR(&node1, root);
        TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    }
}



/*
 *    root                root
 *     |     remove 1      |
 *     v      ----->       v
 *    1(b)               NULL
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_1_root_should_point_to_NULL()
{

    setNode(&node1, NULL, NULL, 'b');
    Node *root = &node1;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(NULL,root);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);

}


/*
 *    root                root
 *     |     remove 2      |
 *     v      ----->       v
 *    1(b)               1(b)
 *     \
 *     2(r)
 *
 */
void test_delRedBlackTree_remove_2_from_tree_with_root_1_root_should_point_to_1()
{

    setNode(&node2, NULL, NULL, 'r');
    setNode(&node1, NULL, &node2, 'b');
    Node *root = &node1;
    Node *node;

    node = delRedBlackTree(&root, &node2);

    TEST_ASSERT_EQUAL_PTR(&node2,node);
    TEST_ASSERT_EQUAL_PTR(&node1,root);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);

}


/*
 *      root                root
 *       |     remove 1      |
 *       v      ----->       v
 *     2(b)                2(b)
 *     / \                   \
 * 1(r)  3(r)               3(r)
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_leftchild_1_red()
{
    setNode(&node3, NULL, NULL, 'r');
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node2, &node1, &node3, 'b');
   
    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);
    TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/*
 *      root                root
 *       |     remove 3      |s
 *       v      ----->       v
 *     2(b)                2(b)
 *     / \                  /
 * 1(r)  3(r)             1(r)
 *
 */
void test_delRedBlackTree_remove_3_from_tree_with_root_2_and_leftchild_1_red()
{
    setNode(&node3, NULL, NULL, 'r');
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node2, &node1, &node3, 'b');
   
    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node3);

    TEST_ASSERT_EQUAL_PTR(&node3,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);
    TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}


/*
 *      root                root
 *       |     remove 1      |
 *       v      ----->       v
 *     2(b)                2(b)
 *     / \                   \
 * 1(b)  3(b)               3(r)
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_leftchild_1_black()
{
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'b');
   
    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);
    TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}

/*
 *      root                root
 *       |     remove 3      |
 *       v      ----->       v
 *     2(b)                2(b)
 *     / \                  /
 * 1(b)  3(b)             1(r)
 *
 */
void test_delRedBlackTree_remove_3_from_tree_with_root_2_and_leftchild_1_black()
{
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'b');
   
    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node3);

    TEST_ASSERT_EQUAL_PTR(&node3,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);
    TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
}

/*
 *         root                root
 *          |     remove 1      |
 *         v      ----->       v
 *        2(b)                5(b)
 *        / \                /   \
 *    1(b)  5(r)           2(b)  6(b)
 *         /  \             \
 *       3(b) 6(b)         3(r)
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_node_1_3_5_6()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node5, &node3, &node6, 'r');
    setNode(&node2, &node1, &node5, 'b');
   
    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node5,root);

    TEST_ASSERT_EQUAL_NODE(NULL,&node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
    TEST_ASSERT_EQUAL_NODE(&node2,&node6,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
}


/*
 *         root                root
 *          |     remove 3      |
 *         v      ----->        v
 *        2(b)                2(b)
 *        / \                /    \  
 *    1(b)  5(r)           1(b)  5(b)
 *         /  \                    \
 *       3(b) 6(b)                6(r)
 */
void test_delRedBlackTree_remove_3_from_tree_with_root_2_and_node_1_3_5_6()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node5, &node3, &node6, 'r');
    setNode(&node2, &node1, &node5, 'b');
   
    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node3);

    TEST_ASSERT_EQUAL_PTR(&node3,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(&node1,&node5, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL,&node6,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/*
 *         root                root
 *          |     remove 6      |
 *         v      ----->        v
 *        2(b)                2(b)
 *        / \                /    \  
 *    1(b)  5(r)           1(b)  5(b)
 *         /  \                   /
 *       3(b) 6(b)              3(r)
 */
void test_delRedBlackTree_remove_6_from_tree_with_root_2_and_node_1_3_5_6()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node5, &node3, &node6, 'r');
    setNode(&node2, &node1, &node5, 'b');
   
    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node6);

    TEST_ASSERT_EQUAL_PTR(&node6,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(&node1,&node5, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(&node3,NULL,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}


/*
 *          root                root
 *           |     remove 7      |
 *           v      ----->       v
 *         5(b)                 2(b)
 *         / \                 /    \  
 *      2(r) 7(b)            1(b)   5(b)
 *     /  \                         /
 *  1(b) 3(b)                     3(r)
 */
void test_delRedBlackTree_remove_7_from_tree_with_root_5_and_node_1_2_3_7()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'r');
    setNode(&node5, &node2, &node7, 'b');

   
    Node *root = &node5;
    Node *node;

    node = delRedBlackTree(&root, &node7);

    TEST_ASSERT_EQUAL_PTR(&node7,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(&node1,&node5, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(&node3,NULL,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/*
 *          root                root
 *           |     remove 1      |
 *           v      ----->       v
 *         5(b)                 5(b)
 *         / \                 /    \  
 *      2(r) 7(b)            2(b)   7(b)
 *     /  \                    \
 *  1(b) 3(b)                  3(r)
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_5_and_node_1_2_3_7()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'r');
    setNode(&node5, &node2, &node7, 'b');

   
    Node *root = &node5;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node5,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL,&node3,'b',&node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/*
 *          root                root
 *           |     remove 3      |
 *           v      ----->       v
 *         5(b)                 5(b)
 *         / \                 /    \  
 *      2(r) 7(b)            2(b)   7(b)
 *     /  \                  /
 *  1(b) 3(b)               1(r)
 */
void test_delRedBlackTree_remove_3_from_tree_with_root_5_and_node_1_2_3_7()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'r');
    setNode(&node5, &node2, &node7, 'b');

   
    Node *root = &node5;
    Node *node;

    node = delRedBlackTree(&root, &node3);

    TEST_ASSERT_EQUAL_PTR(&node3,node);
    TEST_ASSERT_EQUAL_PTR(&node5,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(&node1,NULL,'b',&node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}



/*------------------------ 4 nodes ----------------------------*/
/*------------------------ 4 nodes ----------------------------*/
/*------------------------ 4 nodes ----------------------------*/
/*------------------------ 4 nodes ----------------------------*/

/*
 *          root                         root
 *           |          remove 1         |
 *           v            ----->         v
 *          4(b)                        4(b) 
 *         /    \                      /    \ 
 *      2(r)     6(r)              2(b)     6(r) 
 *     /   \     /   \               \     /   \   
 *  1(b)  3(b) 5(b) 7(b)             3(r) 5(b) 7(b)
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_4_and_node_1_2_3_5_6_7()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    
    setNode(&node2, &node1, &node3, 'r');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node4, &node2, &node6, 'b');

   
    Node *root = &node4;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node4,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node6, 'b', &node4);
    
    TEST_ASSERT_EQUAL_NODE(NULL,&node3,'b',&node2);
    TEST_ASSERT_EQUAL_NODE(&node5,&node7,'r',&node6);
    
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}


/*
 *          root                         root
 *           |          remove 3         |
 *           v            ----->         v
 *          4(b)                        4(b) 
 *         /    \                      /    \ 
 *      2(r)     6(r)              2(b)     6(r) 
 *     /   \     /   \              /      /   \   
 *  1(b)  3(b) 5(b) 7(b)          1(r)   5(b) 7(b)
 */
void test_delRedBlackTree_remove_3_from_tree_with_root_4_and_node_1_2_3_5_6_7()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    
    setNode(&node2, &node1, &node3, 'r');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node4, &node2, &node6, 'b');

   
    Node *root = &node4;
    Node *node;

    node = delRedBlackTree(&root, &node3);

    TEST_ASSERT_EQUAL_PTR(&node3,node);
    TEST_ASSERT_EQUAL_PTR(&node4,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node6, 'b', &node4);
    
    TEST_ASSERT_EQUAL_NODE(&node1,NULL,'b',&node2);
    TEST_ASSERT_EQUAL_NODE(&node5,&node7,'r',&node6);
    
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}


/*
 *          root                         root
 *           |          remove 5         |
 *           v            ----->         v
 *          4(b)                        4(b) 
 *         /    \                      /    \ 
 *      2(r)     6(r)              2(b)     6(b) 
 *     /   \     /   \            /   \       \   
 *  1(b)  3(b) 5(b) 7(b)        1(b)  3(b)    7(r)
 */
void test_delRedBlackTree_remove_5_from_tree_with_root_4_and_node_1_2_3_5_6_7()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    
    setNode(&node2, &node1, &node3, 'r');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node4, &node2, &node6, 'b');

   
    Node *root = &node4;
    Node *node;

    node = delRedBlackTree(&root, &node5);

    TEST_ASSERT_EQUAL_PTR(&node5,node);
    TEST_ASSERT_EQUAL_PTR(&node4,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node6, 'b', &node4);
    
    TEST_ASSERT_EQUAL_NODE(&node1,&node3,'r',&node2);
    TEST_ASSERT_EQUAL_NODE(NULL,&node7,'b',&node6);
    
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
}


/*
 *          root                         root
 *           |          remove 7         |
 *           v            ----->         v
 *          4(b)                        4(b) 
 *         /    \                      /    \ 
 *      2(r)     6(r)              2(b)     6(b) 
 *     /   \     /   \            /   \     /   
 *  1(b)  3(b) 5(b) 7(b)        1(b)  3(b) 5(r)
 */
void test_delRedBlackTree_remove_7_from_tree_with_root_4_and_node_1_2_3_5_6_7()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    
    setNode(&node2, &node1, &node3, 'r');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node4, &node2, &node6, 'b');

   
    Node *root = &node4;
    Node *node;

    node = delRedBlackTree(&root, &node7);

    TEST_ASSERT_EQUAL_PTR(&node7,node);
    TEST_ASSERT_EQUAL_PTR(&node4,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node6, 'b', &node4);
    
    TEST_ASSERT_EQUAL_NODE(&node1,&node3,'r',&node2);
    TEST_ASSERT_EQUAL_NODE(&node5,NULL,'b',&node6);
    
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
}