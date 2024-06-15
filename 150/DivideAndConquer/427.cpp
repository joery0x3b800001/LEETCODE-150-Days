// Construct Quad Tree

// https://leetcode.com/problems/construct-quad-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return buildQuadTree(grid, 0, 0, n - 1, n - 1);
    }

    Node *buildQuadTree(vector<vector<int>> &grid, int x1, int y1, int x2, int y2)
    {
        if (x1 == x2 && y1 == y2)
        {
            return new Node(grid[x1][y1] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }

        int mx = (x1 + x2) / 2;
        int my = (y1 + y2) / 2;

        Node *topLeft = buildQuadTree(grid, x1, y1, mx, my);
        Node *topRight = buildQuadTree(grid, x1, my + 1, mx, y2);
        Node *bottomLeft = buildQuadTree(grid, mx + 1, y1, x2, my);
        Node *bottomRight = buildQuadTree(grid, mx + 1, my + 1, x2, y2);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            return new Node(topLeft->val, true, nullptr, nullptr, nullptr, nullptr);
        }
        else
        {
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
};

// Utility function to print the quad tree
void printQuadTree(Node *root)
{
    if (root)
    {
        cout << root->val << " ";
        if (!root->isLeaf)
        {
            printQuadTree(root->topLeft);
            printQuadTree(root->topRight);
            printQuadTree(root->bottomLeft);
            printQuadTree(root->bottomRight);
        }
    }
}

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0}};

    Node *root = sol.construct(grid);

    cout << "Quad Tree representation:" << endl;
    printQuadTree(root);
    cout << endl;

    return 0;
}