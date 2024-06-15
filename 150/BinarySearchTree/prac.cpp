#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getMinimumDiference(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *current = root;
    TreeNode *prev = nullptr;
    int minDiff = numeric_limits<int>::max();

    while (current || !st.empty())
    {
        while (current)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        if (prev != nullptr)
        {
            minDiff = min(minDiff, current->val - prev->val);
        }

        prev = current;

        current = current->right;
    }

    return minDiff;
}

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
    vector<int> nodes = {1, 0, 48, -1, -1, 12, 49}; // Example input: [1,null,3,2]
    TreeNode *root = createTree(nodes, 0);

    int minDiff = getMinimumDiference(root);

    cout << "Minimum Absolute Difference: " << minDiff << endl;

    return 0;
}