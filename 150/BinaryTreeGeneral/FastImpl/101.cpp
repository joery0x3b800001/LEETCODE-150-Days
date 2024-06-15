// Symmetric Tree

// https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == nullptr && rightNode == nullptr)
            return true;

        if (leftNode == nullptr || rightNode == nullptr)
            return false;

        return (leftNode->val == rightNode->val) &&
               isMirror(leftNode->left, rightNode->right) &&
               isMirror(leftNode->right, rightNode->left);
    }
};

int main(int argc, char const *argv[])
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    // Create an instance of the solution
    Solution sol;

    // Calculate the maximum depth of the binary tree
    int depth = sol.isSymmetric(root);

    // Output the result
    std::cout << "Is Symmetric binary tree: " << (depth == 0 ? "No" : "Yes") << std::endl;

    return 0;
}