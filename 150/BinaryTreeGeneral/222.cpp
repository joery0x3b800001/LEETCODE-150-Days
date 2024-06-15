// Count Complete Tree Nodes

// https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = 0, rightHeight = 0;
        TreeNode *leftNode = root, *rightNode = root;

        while (leftNode)
        {
            leftHeight++;
            leftNode = leftNode->left;
        }

        while (rightNode)
        {
            rightNode++;
            rightNode = rightNode->right;
        }

        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1; // Full binary tree
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);

    Solution solution;

    cout << solution.countNodes(root) << endl;

    return 0;
}