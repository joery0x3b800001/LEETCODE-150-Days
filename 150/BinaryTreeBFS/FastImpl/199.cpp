// Binary Tree Right Side View

// https://leetcode.com/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=top-interview-150

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
    void rightSideViewRecursive(TreeNode *root, std::vector<int> &result, int level)
    {
        if (!root)
            return;

        // If the current level is equal to the size of the result vector,
        // it means this is the rightmost node of that level.
        if (level == result.size())
        {
            result.push_back(root->val);
        }

        // Traverse right first to get the right side view
        rightSideViewRecursive(root->right, result, level + 1);
        rightSideViewRecursive(root->left, result, level + 1);
    }

    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> result;
        rightSideViewRecursive(root, result, 0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    std::vector<int> result = solution.rightSideView(root);

    std::cout << "Right side view of the binary tree: ";
    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}