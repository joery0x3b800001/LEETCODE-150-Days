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
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i)
            inorder_map[inorder[i]] = i;

        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inorder_map);
    }

    TreeNode *build(vector<int> &preorder, int pre_start, int pre_end,
                    vector<int> &inorder, int in_start, int in_end,
                    unordered_map<int, int> &inorder_map)
    {
        if (pre_start == pre_end)
            return nullptr;

        int root_val = preorder[pre_start];
        TreeNode *root = new TreeNode(root_val);

        int root_index_inorder = inorder_map[root_val];
        int left_subtree_size = root_index_inorder - in_start;

        root->left = build(preorder, pre_start + 1, pre_start + 1 + left_subtree_size,
                           inorder, in_start, root_index_inorder, inorder_map);

        root->right = build(preorder, pre_start + 1 + left_subtree_size, pre_end,
                            inorder, root_index_inorder + 1, in_end, inorder_map);

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