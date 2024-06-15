// Binary Search Tree Iterator

// https://leetcode.com/problems/binary-search-tree-iterator/description/?envType=study-plan-v2&envId=top-interview-150

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

class BSTIterator
{
public:
    BSTIterator(TreeNode *root) : tree(root)
    {
        stk.push(tree);
        left = tree->left;
    }

    int next()
    {
        if (hasNext())
        {
            auto node = stk.top();
            stk.pop();
            auto right = node->right;
            if (right)
            {
                left = right->left;
                stk.push(right);
            }
            return node->val;
        }
        return INT_MIN;
    }

    bool hasNext()
    {
        while (true)
        {
            while (left)
            {
                stk.push(left);
                left = left->left;
            }
            if (!stk.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

private:
    TreeNode *tree;
    TreeNode *left;
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);

    cout << "Inorder traversal using iterator: ";
    while (iterator.hasNext())
    {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}