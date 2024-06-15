// Path Sum

// https://leetcode.com/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        stack<pair<TreeNode *, int>> nodes; // stack to store pairs of nodes and their corresponding sums
        nodes.push({root, targetSum});

        while (!nodes.empty())
        {
            TreeNode *node = nodes.top().first;
            int sum = nodes.top().second;
            nodes.pop();

            // If it's a leaf node and the sum equals the target sum, return true
            if (!node->left && !node->right && node->val == sum)
            {
                return true;
            }

            // Push the left and right children along with the updated sum into the stack
            if (node->right)
            {
                nodes.push({node->right, sum - node->val});
            }
            if (node->left)
            {
                nodes.push({node->left, sum - node->val});
            }
        }
        // If no path with the target sum is found, return false
        return false;
    }
};

int main(int argc, char const *argv[])
{
    // Example: Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // Create an instance of the solution
    Solution solution;

    // Check if there exists a root-to-leaf path with the target sum
    bool hasPath = solution.hasPathSum(root, targetSum);

    // Output the result
    if (hasPath)
        cout << "There exists a root-to-leaf path with the sum " << targetSum << endl;
    else
        cout << "There does not exist a root-to-leaf path with the sum " << targetSum << endl;

    // Clean up
    // (Skipping the cleanup code for simplicity)

    return 0;
}