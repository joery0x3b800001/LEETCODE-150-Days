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
        return construct(grid, 0, grid.size(), 0, grid[0].size());
    }

    Node *construct(vector<vector<int>> &grid, int i_min, int i_max, int j_min, int j_max)
    {
        int val = search(grid, i_min, i_max, j_min, j_max);
        if (val == 2)
        {
            int m = i_max - i_min;
            int n = j_max - j_min;
            Node *curr = new Node(0, false,
                                  construct(grid, i_min, i_min + m / 2, j_min, j_min + n / 2),
                                  construct(grid, i_min, i_min + m / 2, j_min + n / 2, j_min + n),
                                  construct(grid, i_min + m / 2, i_min + m, j_min, j_min + n / 2),
                                  construct(grid, i_min + m / 2, i_min + m, j_min + n / 2, j_min + n));
            return curr;
        }
        else
        {
            return new Node(val, true);
        }
        return NULL;
    }

    int search(vector<vector<int>> &grid, int i_min, int i_max, int j_min, int j_max)
    {
        bool found0 = false;
        bool found1 = false;
        // cout<<"searching "<<i_min<<" <= i < "<<i_max<<", "<<j_min<<" <= j < "<<j_max<<endl;
        for (int i = i_min; i < i_max; i++)
        {
            for (int j = j_min; j < j_max; j++)
            {
                if (grid[i][j] == 1)
                {
                    found1 = true;
                }
                if (grid[i][j] == 0)
                {
                    found0 = true;
                }
            }
        }
        if (found1 && found0)
        {
            return 2;
        }
        // cout<<"returning "<<found1<<endl;
        return found1;
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