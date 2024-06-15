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
    BSTIterator(TreeNode *root)
    {
        pushAllLeft(root);
    }

    int next()
    {
        TreeNode *topNode = nodeStack.top();
        nodeStack.pop();
        pushAllLeft(topNode->right);
        return topNode->val;
    }

    bool hasNext()
    {
        return !nodeStack.empty();
    }

private:
    stack<TreeNode *> nodeStack;

    void pushAllLeft(TreeNode *root)
    {
        while (root != nullptr)
        {
            nodeStack.push(root);
            root = root->left;
        }
    }
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