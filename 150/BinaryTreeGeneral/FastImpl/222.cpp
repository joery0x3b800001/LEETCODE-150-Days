// Count Complete Tree Nodes

// https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=study-plan-v2&envId=top-interview-150

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
    int countNodes(TreeNode *root)
    {
        return root == NULL ? 0 : countNodes(root->left) + countNodes(root->right) + 1;
    }
};

static inline auto _ = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out", std::ios::out | std::ios::binary);
    out.rdbuf()->pubsetbuf(nullptr, 256);
    std::string s;
    std::noskipws(std::cin);
    while (std::getline(std::cin, s))
    {
        int count = 0;
        bool inNum = false;
        for (char c : s)
        {
            if (std::isdigit(c) != 0)
            {
                if (!inNum)
                {
                    ++count;
                    inNum = true;
                }
            }
            else
            {
                inNum = false;
            }
        }
        out << count << '\n';
    }
    std::skipws(std::cin);
    out.flush();
    exit(0);
    return 0;
}();

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);

    Solution solution;

    cout << solution.countNodes(root) << endl;

    return 0;
}
