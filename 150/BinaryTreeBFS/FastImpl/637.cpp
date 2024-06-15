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
    vector<pair<double, int>> levelSum(TreeNode *root, int level, vector<pair<double, int>> &sums)
    {
        if (root == nullptr)
            return sums;

        if (level < sums.size())
        {
            sums[level].first += root->val;
            sums[level].second++;
        }
        else
        {
            sums.push_back({root->val, 1});
        }

        levelSum(root->left, level + 1, sums);
        levelSum(root->right, level + 1, sums);

        return sums;
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<pair<double, int>> sums;
        sums = levelSum(root, 0, sums);

        vector<double> averages;
        for (auto sum : sums)
        {
            averages.push_back(sum.first / sum.second);
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