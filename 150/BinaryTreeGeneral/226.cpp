// Invert Binary Tree

// https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
};

int main(int argc, char const *argv[])
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Create an instance of the solution
    Solution sol;

    // Invert the binary tree
    TreeNode *invertedRoot = sol.invertTree(root);

    // Output the result (Inorder traversal of the inverted tree)
    std::cout << "Inverted Tree (Inorder traversal): ";
    std::function<void(TreeNode *)> printInorder = [&](TreeNode *node)
    {
        if (node == nullptr)
            return;
        printInorder(node->left);
        std::cout << node->val << " ";
        printInorder(node->right);
    };
    printInorder(invertedRoot);
    std::cout << std::endl;

    return 0;
}