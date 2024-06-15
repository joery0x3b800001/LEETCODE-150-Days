// Flatten Binary Tree to Linked List

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150

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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        stack<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode *current = nodes.top();
            nodes.pop();

            if (current->right)
                nodes.push(current->right);
            if (current->left)
                nodes.push(current->left);

            if (!nodes.empty())
                current->right = nodes.top();

            current->left = nullptr;
        }
    }
};

// Utility function to print the linked list
void printLinkedList(TreeNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << ", ";
        if (head->right == nullptr)
            return;
        if (head->left == nullptr)
            cout << "null" << ", ";
        head = head->right;
    }
}

int main(int argc, char const *argv[])
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Create an instance of the solution
    Solution solution;

    // Flatten the binary tree
    solution.flatten(root);

    // Print the flattened linked list
    cout << "Flattened Linked List:" << endl;
    printLinkedList(root);

    // Clean up
    // (Skipping the cleanup code for simplicity)

    return 0;
}