// Minimum Absolute Difference in BST

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/?envType=study-plan-v2&envId=top-interview-150

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
    int minDiff = INT_MAX;
    void inOrder(TreeNode *root, TreeNode *&prev)
    {
        if (!root)
            return;

        inOrder(root->left, prev);
        if (prev != NULL)
        {
            minDiff = min(minDiff, abs(root->val - prev->val));
        }
        prev = root;
        inOrder(root->right, prev);
    }

    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *prev = NULL;
        inOrder(root, prev);
        return minDiff;
    }
};

// Helper function to create a binary tree
TreeNode *createTree(vector<int> &nodes, int i)
{
    if (i >= nodes.size() || nodes[i] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[i]);
    root->left = createTree(nodes, 2 * i + 1);
    root->right = createTree(nodes, 2 * i + 2);

    return root;
}

int main(int argc, char const *argv[])
{
    vector<int> nodes = {1, 0, 48, -1, -1, 12, 49}; // Example input: [1,null,3,2]
    TreeNode *root = createTree(nodes, 0);

    Solution solution;
    int minDiff = solution.getMinimumDifference(root);

    cout << "Minimum Absolute Difference: " << minDiff << endl;

    return 0;
}