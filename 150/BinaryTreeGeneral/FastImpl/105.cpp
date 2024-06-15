// Construct Binary Tree from Preorder and Inorder Traversal

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i)
            inorderMap[inorder[i]] = i;

        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> nodes;
        nodes.push(root);

        for (int i = 1; i < preorder.size(); ++i)
        {
            TreeNode *node = new TreeNode(preorder[i]);
            TreeNode *prev = nullptr;

            while (!nodes.empty() && inorderMap[preorder[i]] > inorderMap[nodes.top()->val])
            {
                prev = nodes.top();
                nodes.pop();
            }

            if (prev)
            {
                prev->right = node;
            }
            else
            {
                nodes.top()->left = node;
            }

            nodes.push(node);
        }

        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    // Example preorder and inorder traversal sequences
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Construct the binary tree
    TreeNode *root = solution.buildTree(preorder, inorder);

    // Output the result (Inorder traversal of the combined binary tree)
    std::function<void(TreeNode *)> inorderTraversal = [&](TreeNode *node)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        std::cout << node->val << " ";
        inorderTraversal(node->right);
    };

    // Print the inorder traversal of the constructed binary tree
    cout << "Inorder traversal of the constructed binary tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}