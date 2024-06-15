// Binary Tree Zigzag Level Order Traversal

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            stack<int> tempStack;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                if (leftToRight)
                {
                    level.push_back(node->val);
                }
                else
                {
                    tempStack.push(node->val);
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (!leftToRight)
            {
                while (!tempStack.empty())
                {
                    level.push_back(tempStack.top());
                    tempStack.pop();
                }
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};

// Helper function to create a binary tree
TreeNode *createTree(vector<int> &nodes, int i)
{
    if (i >= nodes.size() || nodes[i] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[i]);
    root->left = createTree(nodes, 2 * i + 1);
    root->right = createTree(nodes, 2 * i + 2);

    return root;
}

int main(int argc, char const *argv[])
{
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7}; // Example input: [3,9,20,null,null,15,7]
    TreeNode *root = createTree(nodes, 0);

    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    cout << "Zigzag level order traversal: " << endl;
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}