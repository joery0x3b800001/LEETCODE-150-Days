// Convert Sorted Array to Binary Search Tree

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        return buildBST(nums, 0, nums.size() - 1);
    }

    TreeNode *buildBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        return root;
    }
};

// Utility function to print inorder traversal of BST
void printInorder(TreeNode *root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sol.sortedArrayToBST(nums);
    cout << "Inorder traversal of the constructed BST: ";
    printInorder(root);
    cout << endl;
    return 0;
}