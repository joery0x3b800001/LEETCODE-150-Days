// Average of Levels in Binary Tree

// https://leetcode.com/problems/average-of-levels-in-binary-tree/?envType=study-plan-v2&envId=top-interview-150

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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> averages;
        if (!root)
            return averages;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            double sum = 0;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            averages.push_back(sum / size);
        }
        return averages;
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
    vector<double> result = solution.averageOfLevels(root);

    cout << "Average of levels: ";
    for (double avg : result)
    {
        cout << avg << " ";
    }
    cout << endl;

    return 0;
}