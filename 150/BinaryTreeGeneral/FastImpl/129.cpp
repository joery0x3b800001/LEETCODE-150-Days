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
        if (!root) return 0;

        stack<pair<TreeNode*, int>> nodes; // stack to store pairs of nodes and their corresponding sums
        nodes.push({root, root->val}); // start with the root node and its value as the initial sum
        int totalSum = 0;

        while (!nodes.empty())
        {
            TreeNode* node = nodes.top().first;
            int currentSum = nodes.top().second;
            nodes.pop();

            // If it's a leaf node, add the current sum to the total sum
            if (!node->left && !node->right)
            {
                totalSum += currentSum;
            }

            // Push the left and right children along with the updated sum onto the stack
            if (node->right)
            {
                nodes.push({node->right, currentSum * 10 + node->right->val});
            }

            if (node->left) {
                nodes.push({node->left, currentSum * 10 + node->left->val});
            }
        }

        return totalSum;
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