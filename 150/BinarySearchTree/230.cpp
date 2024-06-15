// Kth Smallest Element in a BST

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/?envType=study-plan-v2&envId=top-interview-150

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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;
        TreeNode *current = root;
        int count = 0;
        int result;

        while (current != NULL || !st.empty())
        {
            while (current != NULL)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            count++;

            if (count == k)
            {
                result = current->val;
                break;
            }

            current = current->right;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    int k = 1;
    cout << "The " << k << "th smallest element is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}