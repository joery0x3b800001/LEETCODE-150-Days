// Same Tree

// https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        std::stack<TreeNode *> stack_p, stack_q;
        stack_p.push(p);
        stack_q.push(q);

        while (!stack_p.empty() && !stack_q.empty())
        {
            TreeNode *node_p = stack_p.top();
            stack_p.pop();
            TreeNode *node_q = stack_q.top();
            stack_q.pop();

            if (node_p == nullptr && node_q == nullptr)
                continue;
            if (node_p == nullptr || node_q == nullptr || node_p->val != node_q->val)
                return false;

            stack_p.push(node_p->left);
            stack_p.push(node_p->right);
            stack_q.push(node_q->left);
            stack_q.push(node_q->right);
        }

        return stack_p.empty() && stack_q.empty();
    }
};

int main(int argc, char const *argv[])
{
    // Create first tree
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Create second tree
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Create an instance of the solution
    Solution sol;

    // Check if the trees are the same
    bool same = sol.isSameTree(p, q);

    // Output the result
    std::cout << "Are the trees the same? " << (same ? "Yes" : "No") << std::endl;

    return 0;
}