// Lowest Common Ancestor of a Binary Tree

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        stack<TreeNode *> stack;
        parent[root] = nullptr;
        stack.push(root);

        // Traverse the tree to build parent pointers using iterative DFS
        while (!parent.count(p) || !parent.count(q))
        {
            TreeNode *node = stack.top();
            stack.pop();
            if (node->left)
            {
                parent[node->left] = node;
                stack.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                stack.push(node->right);
            }
        }

        // Find ancestors of node p
        unordered_map<TreeNode *, bool> ancestors;
        while (p)
        {
            ancestors[p] = true;
            p = parent[p];
        }

        // Find the first ancestor of node q which is also an ancestor of p
        while (!ancestors.count(q))
        {
            q = parent[q];
        }

        return q;
    }
};

int main(int argc, char const *argv[])
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;

    TreeNode *p = root->left;
    TreeNode *q = root->left->right->right;

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);

    if (lca)
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << std::endl;
    else
        std::cout << "One of the nodes is not found or the tree is empty." << std::endl;

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}