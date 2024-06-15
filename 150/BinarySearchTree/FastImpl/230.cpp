// Kth Smallest Element in a BST

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/?envType=study-plan-v2&envId=top-interview-150

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
    void inorderT(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;

        inorderT(root->left, inorder);
        inorder.push_back(root->val);
        inorderT(root->right, inorder);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderT(root, inorder);
        return inorder[k - 1];
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    int k = 1;
    cout << "The " << k << "th smallest element is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}