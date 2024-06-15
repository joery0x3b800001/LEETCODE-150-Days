// Lowest Common Ancestor of a Binary Tree

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // If both p and q are found in left and right subtrees,
        // then the current root is the LCA
        if (left && right)
            return root;

        // If only one of p or q is found, return that one
        return left ? left : right;
    }
};

int main(int argc, char const *argv[])
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;

    TreeNode *p = root->left;
    TreeNode *q = root->right;

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);

    if (lca)
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << std::endl;
    else
        std::cout << "One of the nodes is not found or the tree is empty." << std::endl;

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}