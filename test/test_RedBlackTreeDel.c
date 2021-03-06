#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "Rotations.h"
#include "CustomAssertions.h"
#include "CException.h"
#include "ErrorCode.h"
Node node1,node2,node3,node4,node5,node6,node7,node8,node10,
     node11,node12,node13,node14,node15,node17,node18,node19,
     node20,node22,node25,node30,node40,node50,node60;



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
    resetNode(&node14,14);
    resetNode(&node15,15);
    resetNode(&node17,17);
    resetNode(&node18,18);
    resetNode(&node18,19);
    resetNode(&node20,20);
    resetNode(&node22,22);
    resetNode(&node25,25);
    resetNode(&node30,30);
    resetNode(&node40,40);
    resetNode(&node50,50);
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
















/* ------------------------------case 1 -----------------------------*/
/* ------------------------------case 1 -----------------------------*/
/* ------------------------------case 1 -----------------------------*/
/* ------------------------------case 1 -----------------------------*/

/*
 *         root                root                     root
 *          |     remove 1      |      left rotate       |
 *         v      ----->        v        ----->          v
 *        2(b)                2(b)                     4(b)
 *        / \                //  \                    /   \
 *    1(b)  4(b)               4(b)                 2(b)  5(b)
 *           \                  \
 *          5(r)                 5(r)
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_node_1_4_5()
{


    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node4, NULL, &node5, 'b');
    setNode(&node2, &node1, &node4, 'b');

    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node4,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node5, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
}

/*
 *         root                root      right          root
 *          |     remove 1      |      left rotate       |
 *         v      ----->        v        ----->          v
 *        2(b)                2(b)                      4(b)
 *        / \               //  \                      /   \
 *    1(b)  5(b)               5(b)                 2(b)  5(b)
 *          /                 /
 *         4(r)              4(r)
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_node_1_5_4()
{


    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node4, NULL, 'b');
    setNode(&node4, NULL, NULL, 'r');
    setNode(&node2, &node1, &node5, 'b');

    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node4,root);

    TEST_ASSERT_EQUAL_NODE(&node2,&node5, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
}

/*
 *          root                root                     root
 *           |     remove 7      |       right rotate      |
 *           v      ----->       v        ----->           v
 *         5(b)                 5(b)                     2(b)
 *         / \                 /   \\                   /   \
 *      2(b) 7(b)            2(b)                    1(b)  5(b)
 *     /                     /
 *  1(r)                    1(r)
 */
void test_delRedBlackTree_remove_7_from_tree_with_root_5_and_node_2_1_7()
{
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node2, &node1, NULL, 'b');
    setNode(&node5, &node2, &node7, 'b');


    Node *root = &node5;
    Node *node;

    node = delRedBlackTree(&root, &node7);

    TEST_ASSERT_EQUAL_PTR(&node7,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(&node1,&node5, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);

}

/*
 *          root                root     left             root
 *           |     remove 7      |       right rotate      |
 *           v      ----->       v        ----->           v
 *         5(b)                 5(b)                     2(b)
 *         / \                 /   \\                   /   \
 *      1(b) 7(b)            1(b)                    1(b)  5(b)
 *       \                    \
 *      2(r)                   2(r)
 */
void test_delRedBlackTree_remove_7_from_tree_with_root_5_and_node_1_2_7()
{
    setNode(&node2, NULL, NULL, 'r');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node1, NULL, &node2, 'b');
    setNode(&node5, &node1, &node7, 'b');


    Node *root = &node5;
    Node *node;

    node = delRedBlackTree(&root, &node7);

    TEST_ASSERT_EQUAL_PTR(&node7,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(&node1,&node5, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);

}


/* ------------------------------case 2 -----------------------------*/
/* ------------------------------case 2 -----------------------------*/
/* ------------------------------case 2 -----------------------------*/
/* ------------------------------case 2 -----------------------------*/

/*
 *          root                root                 root
 *           |     remove 1      |                    |
 *           v      ----->       v        ----->      v
 *          2(r)                2(r)                 2(b)
 *         / \                 //   \                  \
 *      1(b) 3(b)                   3(b)               3(r)
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_redroot_2_and_node_1_3()
{
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'r');


    Node *root = &node2;
    Node *node;

    node = _delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(NULL,&node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}


/*
 *          root                root                 root
 *           |     remove 1      |                    |
 *           v      ----->       v        ----->      v
 *          2(b)                2(b)                 2(d)
 *         / \                 //   \                  \
 *      1(b) 3(b)                   3(b)               3(r)
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_blackroot_2_and_node_1_3()
{
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'b');


    Node *root = &node2;
    Node *node;

    node = _delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(NULL,&node3, 'd', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/*
 *          root                root                 root
 *           |     remove 3      |                    |
 *           v      ----->       v        ----->      v
 *          2(b)                2(b)                 2(d)
 *         / \                 /   \\                /
 *      1(b) 3(b)            1(b)                   1(r)
 *
 *
 */
void test_delRedBlackTree_remove_3_from_tree_with_blackroot_2_and_node_3_1()
{
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'b');


    Node *root = &node2;
    Node *node;

    node = _delRedBlackTree(&root, &node3);

    TEST_ASSERT_EQUAL_PTR(&node3,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(&node1,NULL, 'd', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}

/*
 *          root                root
 *           |     remove 3      |
 *           v      ----->       v
 *          2(r)                2(b)
 *         / \                  /
 *      1(b) 3(b)             1(r)
 *
 *
 */
void test_delRedBlackTree_remove_3_from_tree_with_redroot_2_and_node_1_3()
{
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, &node1, &node3, 'r');


    Node *root = &node2;
    Node *node;

    node = _delRedBlackTree(&root, &node3);

    TEST_ASSERT_EQUAL_PTR(&node3,node);
    TEST_ASSERT_EQUAL_PTR(&node2,root);

    TEST_ASSERT_EQUAL_NODE(&node1,NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}



/* ------------------------------case 3 -----------------------------*/
/* ------------------------------case 3 -----------------------------*/
/* ------------------------------case 3 -----------------------------*/
/* ------------------------------case 3 -----------------------------*/


/*
 *          root                root       rotate        root                 root
 *           |     remove 1      |         left           |                    |
 *           v      ----->       v          ---->         v         ---->      v
 *          2(b)                2(b)                    4(b)                 4(b)
 *         / \                //  \                    /   \                /    \
 *      1(b) 4(r)                 4(r)               2(r)  5(b)           2(b)  5(b)
 *          /   \                 /  \             //  \                   \
 *        3(b)  5(b)           3(b) 5(b)              3(b)                3(r)
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_node_1_3_4_5()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node4, &node3, &node5, 'r');
    setNode(&node2, &node1, &node4, 'b');


    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node4,root);

    TEST_ASSERT_EQUAL_NODE(NULL,&node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
    TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);

}


/*
 *          root                root       rotate        root                 root
 *           |     remove 1      |         left           |                    |
 *           v      ----->       v          ---->         v         ---->      v
 *          2(b)                2(b)                    5(b)                 5(b)
 *         / \                //  \                    /   \                /    \
 *      1(b) 5(r)                 5(r)               2(r)  5(b)           3(r)  6(b)
 *          /   \                 /  \             //  \                  / \
 *        3(b)  6(b)           3(b) 6(b)              3(b)             2(b) 4(b)
 *          \                    \                      \
 *         4(r)                  4(r)                  4(r)
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_node_1_3_4_5_6()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node4, NULL, NULL, 'r');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node3, NULL, &node4, 'b');
    setNode(&node5, &node3, &node6, 'r');
    setNode(&node2, &node1, &node5, 'b');


    Node *root = &node2;
    Node *node;

    node = delRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(&node1,node);
    TEST_ASSERT_EQUAL_PTR(&node5,root);

    TEST_ASSERT_EQUAL_NODE(NULL,NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(&node2, &node4, 'r', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(&node3, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);

}



/*
 *
 *            root                 root                      root
 *             /     remove 20      /     rotate left         /
 *            v      ----->        v      --------->         v
 *           15(b)                15(b)                     5(b)
 *          /  \                /   \\                    /   \
 *       5(r)   20(b)        5(r)   NULL               2(b)   15(b)
 *      /  \                /   \                            /
 *   2(b)  7(b)           2(b)  7(b)                       7(r)
 */
void test_delRedBlackTree_remove_20_from_tree_with_root_15_and_node_2_5_7_20()
{

    setNode(&node2, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node5, &node2, &node7, 'r');
    setNode(&node15, &node5, &node20, 'b');
    Node *root = &node15;
    Node *node;


    node = delRedBlackTree(&root, &node20);
    TEST_ASSERT_EQUAL(20 , node->data);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node7);
    TEST_ASSERT_EQUAL(root->data,5);
    TEST_ASSERT_EQUAL_NODE(&node7, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node2, &node15 , 'b', &node5);

}





/*
 *
 *            root                 root                      root                      root
 *             /     remove 20      /       case3             /          case1          /
 *            v      ----->        v      --------->         v         ------->        v
 *           15(b)                15(b)                     5(b)                      5(b)
 *          /  \                /   \\                    /   \                     /    \
 *       5(r)   20(b)        5(r)   NULL               2(b)   15(r)               2(b)   7(r)
 *      /  \                /   \                            /                          /   \
 *   2(b)  7(b)           2(b)  7(b)                       7(b)                      6(b)   15(b)
 *        /                    /                          /
 *      6(r)                 6(r)                       6(r)
 *
 */
void test_delRedBlackTree_remove_20_from_tree_with_root_15_root_and_node_2_5_6_7_20()
{

    setNode(&node2, NULL, NULL, 'b');
    setNode(&node6, NULL, NULL, 'r');
    setNode(&node7, &node6, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node5, &node2, &node7, 'r');
    setNode(&node15, &node5, &node20, 'b');
    Node *root = &node15;
    Node *node;

    node = delRedBlackTree(&root, &node20);
    TEST_ASSERT_EQUAL(20 , node->data);
    TEST_ASSERT_EQUAL(root->data,5);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node6);
    TEST_ASSERT_EQUAL_NODE(&node6, &node15, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(&node2, &node7 , 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);

    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node15);

}



/*------------------------ Remove next larger successor ----------------------------*/
/*------------------------ Remove next larger successor ----------------------------*/
/*------------------------ Remove next larger successor ----------------------------*/
/*------------------------ Remove next larger successor ----------------------------*/
/*
 *          root                      root
 *           |                         |
 *           v      successor 2        v
 *          2(b)     ---->           NULL
 *
 *
 */
void test_removeNextLargerSuccessor_given_root_2_should_return_2()
{
    setNode(&node2, NULL, NULL, 'b');
    Node *root = &node2 ;
    Node *successor ;

    successor = removeNextLargerSuccessor(&root);

    TEST_ASSERT_EQUAL(NULL,root);
    TEST_ASSERT_EQUAL_PTR(&node2,successor);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);

}

/*
 *          root                      root
 *           |                         |
 *           v      successor 1        v
 *          2(b)       ---->          2(b)
 *         /
 *       1(b)
 */
void test_removeNextLargerSuccessor_given_root_2_and_node_1_should_return_1()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, &node1, NULL, 'b');
    Node *root = &node2 ;
    Node *successor ;

    successor = removeNextLargerSuccessor(&root);

    TEST_ASSERT_EQUAL(&node2,root);
    TEST_ASSERT_EQUAL_PTR(&node1,successor);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);

}

/*
 *          root                      root
 *           |                         |
 *           v      successor 1        v
 *          2(b)       ---->          2(b)
 *         /  \                         \
 *       1(r) 3(r)                      3(r)
 */
void test_removeNextLargerSuccessor_given_root_2_and_node_1_3_should_return_1()
{
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node3, NULL, NULL, 'r');
    setNode(&node2, &node1, &node3, 'b');
    Node *root = &node2 ;
    Node *successor ;

    successor = removeNextLargerSuccessor(&root);

    TEST_ASSERT_EQUAL(&node2,root);
    TEST_ASSERT_EQUAL_PTR(&node1,successor);
    TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}



/*
 *          root                      root
 *           |                         |
 *           v      successor 1        v
 *          1(b)      ---->           2(b)
 *            \
 *            2(r)
 */
void test_removeNextLargerSuccessor_given_root_1_and_node_2_should_return_1()
{
    setNode(&node1, NULL, &node2, 'b');
    setNode(&node2, NULL, NULL, 'r');
    Node *root = &node1 ;
    Node *successor ;

    successor = removeNextLargerSuccessor(&root);

    TEST_ASSERT_EQUAL(&node2,root);
    TEST_ASSERT_EQUAL_PTR(&node1,successor);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

/*
 *          root                        root                          
 *           |                           |                             
 *           v        successor 1        v                            
 *           12(b)       ---->          12(b)           
 *          /    \                     /     \                      
 *       5(b)    18(b)              5(b)     18(b)                 
 *      /        /                          /                    
 *   1(r)     13(r)                       13(r)             

 */
 
void test_removeNextLargerSuccessor_given_root_12_and_node_1_5_13_18_should_return_1()
{
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node13, NULL, NULL, 'r');
    setNode(&node5, &node1, NULL,'b');
    setNode(&node18, &node13,NULL,'b');
    setNode(&node12, &node5, &node18, 'b');
    
    Node *root = &node12 ;
    Node *successor ;

    successor = removeNextLargerSuccessor(&root);

    TEST_ASSERT_EQUAL(&node12,root);
    TEST_ASSERT_EQUAL_PTR(&node1,successor);


    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(&node13, NULL, 'b', &node18);
    TEST_ASSERT_EQUAL_NODE(&node5, &node18, 'b', &node12);
}


/*
 *          root                        root                          
 *           |                           |                             
 *           v        successor 1        v                            
 *           12(b)       ---->          12(b)           
 *          /    \                     /     \                      
 *       5(b)    18(b)              5(b)     18(b)                 
 *      /  \     /   \              /  \     /    \                
 *   1(b) 7(b) 13(b) 19(b)        2(b) 7(b) 13(b) 19(b)             
 *     \
 *     2(r)
 */
 
void test_removeNextLargerSuccessor_given_root_12_and_node_1_2_5_7_13_18_19_should_return_1()
{
    setNode(&node2,NULL, NULL, 'r');
    setNode(&node1, NULL, &node2, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node19, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7,'b');
    setNode(&node18, &node13, &node19,'b');
    setNode(&node12, &node5, &node18, 'b');
    
    Node *root = &node12 ;
    Node *successor ;

    successor = removeNextLargerSuccessor(&root);

    TEST_ASSERT_EQUAL(&node12,root);
    TEST_ASSERT_EQUAL_PTR(&node1,successor);

    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
    TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(&node13, &node19, 'b', &node18);
    TEST_ASSERT_EQUAL_NODE(&node5, &node18, 'b', &node12);
}


/** Encounter case 2a on the left child and right child after remove successor
 *
 *          root                        root                           root
 *           |                           |                              ||
 *           v        successor 1        v                              v
 *           12(b)       ---->          12(b)           ---->        12(d)
 *          /    \                    //     \                       /    \
 *       5(b)    18(b)              5(d)     18(b)                 5(b)  18(r)
 *      /  \     /   \                \     /    \                 \     /  \
 *   1(b) 7(b) 13(b) 19(b)           7(r) 13(b) 19(b)             7(r) 13(b) 19(b)
 */
void test_removeNextLargerSuccessor_given_root_12_and_node_1_5_7_13_18_19_should_return_1()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node19, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7,'b');
    setNode(&node18, &node13, &node19,'b');
    setNode(&node12, &node5, &node18, 'b');
    
    Node *root = &node12 ;
    Node *successor ;

    successor = removeNextLargerSuccessor(&root);

    TEST_ASSERT_EQUAL(&node12,root);
    TEST_ASSERT_EQUAL_PTR(&node1,successor);

    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(&node13, &node19, 'r', &node18);
    TEST_ASSERT_EQUAL_NODE(&node5, &node18, 'd', &node12);
}




/** Encounter case 2b on the left child after remove successor
 *
 *      parent's left                      parent's left                   parent's left
 *            |                                  |                               |
 *            v                                  v                               v
 *          12(b)                              12(b)                           12(b)
 *       /         \       successor 1      /         \                     /        \
 *     5(r)       18(r)   ------------>   5(r)       18(r)  ------------> 5(b)       18(r)
 *    /   \       /   \                  //  \       /   \                   \       /   \
 *  1(b) 7(b)  13(b) 19(b)             NULL 7(b)  13(b) 19(b)               7(r)  13(b) 19(b)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_7_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node19, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'r');
    setNode(&node18, &node13, &node20, 'r');
    setNode(&node12, &node5, &node15, 'b');
    
    Node *parent = &node12, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node12, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'r', &node18);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node12);
}





/** Encounter case 2a on the left child and 2b on the right child after remove successor
 *
 *      parent's left                      parent's left                   parent's left                   parent's left
 *            |                                  |                               |                               ||
 *            v                                  v                               v                               v
 *          10(b)                              10(b)                           10(b)                           10(d)
 *       /         \       successor 1      /         \                     //        \                     /        \
 *     5(b)       15(b)   ------------>   5(b)       15(b)  ------------> 5(d)       15(b)  ------------> 5(b)       15(r)
 *    /   \       /   \                  //  \       /   \                   \       /   \                   \       /   \
 *  1(b) 7(b)  13(b) 20(b)             NULL 7(b)  13(b) 20(b)               7(r)  13(b) 20(b)               7(r)  13(b) 20(b)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_7_10_13_15_20_should_remove_successor_1_with_parent_being_black(void)
{
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'd', &node10);
}

/** Encounter case 1a on the left child after remove successor
 *
 *      parent's left                      parent's left                   parent's left
 *            |                                  |                               |
 *            v                                  v                               v
 *          10(b)                              10(b)                           10(b)
 *       /         \       successor 1      /         \                      /        \
 *     5(r)       15(r)   ------------>   5(r)       15(r)  ------------> 7(r)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \
 *  1(b) 7(b)  13(b) 20(b)             NULL 7(b)  13(b) 20(b)          5(b) 8(b)  13(b) 20(b)
 *          \                                  \
 *          8(r)                               8(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_7_8_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node8, NULL, NULL, 'r');
    setNode(&node7, NULL, &node8, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'r');
    setNode(&node15, &node13, &node20, 'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
    TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node7, &node15, 'b', &node10);
}

/** Encounter case 1b on the left child after remove successor
 *
 *      parent's left                      parent's left                   parent's left
 *            |                                  |                               |
 *            v                                  v                               v
 *          10(b)                              10(b)                           10(b)
 *       /         \       successor 1      /         \                      /        \
 *     5(b)       15(b)   ------------>   5(b)       15(b)  ------------> 6(b)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \
 *  1(b) 7(b)  13(b) 20(b)             NULL 7(b)  13(b) 20(b)          5(b) 7(b)  13(b) 20(b)
 *       /                                  /
 *     6(r)                               6(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_6_7_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node6, NULL, NULL, 'r');
    setNode(&node7, &node6, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
    TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'b', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node6, &node15, 'b', &node10);
}

/** Encounter case 3 on the left child after remove successor (with case 2b appear after rotate)
 *
 *      parent's left                      parent's left                   parent's left                        parent's left
 *            |                                  |                               |                                    |
 *            v                                  v                               v                                    v
 *          10(b)                              10(b)                           10(b)                                10(b)
 *       /         \       successor 1      /         \                      /        \                          /        \
 *     5(b)       15(b)   ------------>   5(b)       15(b)  ------------> 7(b)       15(b)   ------------>     7(b)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \                    /   \       /   \
 *  1(b) 7(r)  13(b) 20(b)             NULL 7(r)  13(b) 20(b)          5(r) 8(b)  13(b) 20(b)               5(b) 8(b)  13(b) 20(b)
 *       /  \                               /  \                      //  \                                    \
 *     6(b) 8(b)                          6(b) 8(b)                 NULL 6(b)                                 6(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_6_7_8_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node8, NULL, NULL, 'b');
    setNode(&node7, &node6, &node8, 'r');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
    TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node7, &node15, 'b', &node10);
}

/** Encounter case 3 on the left child after remove successor (with case 1a appear after rotate)
 *
 *      parent's left                      parent's left                   parent's left                        parent's left
 *            |                                  |                               |                                    |
 *            v                                  v                               v                                    v
 *          10(b)                              10(b)                           10(b)                                10(b)
 *       /         \       successor 1      /         \                      /        \                          /        \
 *     4(b)       15(b)   ------------>   4(b)       15(b)  ------------> 7(b)       15(b)   ------------>     7(b)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \                    /   \       /   \
 *  1(b) 7(r)  13(b) 20(b)             NULL 7(r)  13(b) 20(b)          4(r) 8(b)  13(b) 20(b)               5(r) 8(b)  13(b) 20(b)
 *       /  \                               /  \                      //  \                                /   \
 *     5(b) 8(b)                          5(b) 8(b)                 NULL 5(b)                            4(b) 6(b)
 *        \                                  \                              \
 *       6(r)                               6(r)                           6(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_4_5_6_7_8_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node6, NULL, NULL, 'r');
    setNode(&node5, NULL, &node6, 'b');
    setNode(&node8, NULL, NULL, 'b');
    setNode(&node7, &node5, &node8, 'r');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node4, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node4, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
    TEST_ASSERT_EQUAL_NODE(&node4, &node6, 'r', &node5);
    TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node7, &node15, 'b', &node10);
}

