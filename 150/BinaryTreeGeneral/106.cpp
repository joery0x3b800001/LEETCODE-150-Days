// Construct Binary Tree from Inorder and Postorder Traversal

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty() || postorder.empty())
            return nullptr;

        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i)
            inorderMap[inorder[i]] = i;

        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
    }

    TreeNode *buildTreeHelper(vector<int> &inorder, int inStart, int inEnd,
                              vector<int> &postorder, int postStart, int postEnd,
                              unordered_map<int, int> &inorderMap)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);

        int rootIndexInorder = inorderMap[rootVal];
        int numsLeft = rootIndexInorder - inStart;

        root->left = buildTreeHelper(inorder, inStart, rootIndexInorder - 1,
                                     postorder, postStart, postStart + numsLeft - 1, inorderMap);
        root->right = buildTreeHelper(inorder, rootIndexInorder + 1, inEnd,
                                      postorder, postStart + numsLeft, postEnd - 1, inorderMap);

        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    // Example preorder and inorder traversal sequences
    vector<int> preorder = {9, 3, 15, 20, 7};
    vector<int> inorder = {9, 15, 7, 20, 3};

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