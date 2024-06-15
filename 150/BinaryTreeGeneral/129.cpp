// Sum Root to Leaf Numbers

// https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150

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
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }

    int dfs(TreeNode *node, int currentSum)
    {
        if (!node)
            return 0;

        currentSum = currentSum * 10 + node->val;

        // If it's leaf node, return the current sum
        if (!node->left && !node->right)
        {
            return currentSum;
        }

        // Recursively compute the sum of root-to-leaf numbers
        int leftSum = dfs(node->left, currentSum);
        int rightSum = dfs(node->right, currentSum);

        return leftSum + rightSum;
    }
};

int main(int argc, char const *argv[])
{
    // Example: Input: root = [1,2,3]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Create an instance of the solution
    Solution solution;

    // Compute the sum of root-to-leaf numbers
    int sum = solution.sumNumbers(root);

    // Output the result
    cout << "Sum of root-to-leaf numbers: " << sum << endl;

    // Clean up
    // (Skipping the cleanup code for simplicity)

    return 0;
}