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
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

    int maxPathSumHelper(TreeNode *node, int &maxSum)
    {
        if (node == NULL)
            return 0;

        // Get the maximum sum of the left and right subtrees
        int leftSum = max(0, maxPathSumHelper(node->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(node->right, maxSum));

        maxSum = max(maxSum, node->val + leftSum + rightSum);

        return node->val + max(leftSum, rightSum);
    }
};

// Helper function to create a binary tree from an array representation
TreeNode *createTreeFromArray(const std::vector<int> &arr, int index)
{
    if (index >= arr.size() || arr[index] == -1)
        return nullptr;

    TreeNode *node = new TreeNode(arr[index]);
    node->left = createTreeFromArray(arr, 2 * index + 1);
    node->right = createTreeFromArray(arr, 2 * index + 2);

    return node;
}

int main(int argc, char const *argv[])
{
    // Example usage
    std::vector<int> treeValues = {1, 2, 3}; // Change tree values accordingly
    TreeNode *root = createTreeFromArray(treeValues, 0);

    Solution sol;
    std::cout << "Maximum path sum: " << sol.maxPathSum(root) << std::endl;
    return 0;
}