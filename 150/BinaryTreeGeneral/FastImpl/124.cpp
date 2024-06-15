// Binary Tree Maximum Path Sum

// https://leetcode.com/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-interview-150

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
    int as(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int l = as(root->left, ans);
        if (l < 0)
            l = 0;
        int r = as(root->right, ans);
        if (r < 0)
            r = 0;
        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        as(root, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    cout << "Maximum path sum: " << sol.maxPathSum(root) << endl;

    return 0;
}