// Validate Binary Search Tree

// https://leetcode.com/problems/validate-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150/

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
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        stack<TreeNode *> st;
        TreeNode *prev = nullptr;

        while (root != nullptr || !st.empty())
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (prev != nullptr && root->val <= prev->val)
                return false;

            prev = root;
            root = root->right;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    if (sol.isValidBST(root))
        cout << "The binary tree is a valid BST." << endl;
    else
        cout << "The binary tree is not a valid BST." << endl;

    return 0;
}