#include <gtest/gtest.h>
#include "testing-utils.h"
#include "bt-bfs.h"

using namespace TestingUtils;

namespace BTBFS
{
    class BTFSTests : public testing::Test
    {
    public:
    protected:
        BinaryTree::BinaryTree<int> tree;

        void SetUp() override
        {
            tree.root = new Node<int>{
                1,
                new Node<int>{
                    2,
                    new Node<int>{
                        4,
                        nullptr,
                        nullptr},
                    new Node<int>{
                        5,
                        nullptr,
                        nullptr}},
                new Node<int>{
                    3,
                    new Node<int>{
                        6,
                        nullptr,
                        nullptr},
                    new Node<int>{
                        7,
                        nullptr,
                        nullptr}}};
        }
    };

    TEST_F(BTFSTests, BTBFS_IsCorrect)
    {
        EXPECT_TRUE(btBFS(tree, 3));
        EXPECT_TRUE(btBFS(tree, 7));
        EXPECT_FALSE(btBFS(tree, -1));
    }
}