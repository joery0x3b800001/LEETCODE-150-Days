// N-Queens II

// https://leetcode.com/problems/n-queens-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<int> positions(n, -1); // positions[i] represents the columns of the queen placed in row i
        solveNQueens(count, positions, 0);
        return count;
    }

    void solveNQueens(int &count, vector<int> &positions, int row)
    {
        int n = positions.size();
        if (row == n)
        {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if (isValid(positions, row, col))
            {
                positions[row] = col;
                solveNQueens(count, positions, row + 1);
                positions[row] = -1; // backtrack
            }
        }
    }

    bool isValid(const vector<int> &positions, int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            if (positions[i] == col || abs(row - i) == abs(col - positions[i]))
            {
                return false; // Same column or diagonal
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 4;
    cout << "Total number of distinct solutions to the N-Queens problem for n = " << n << ": " << sol.totalNQueens(n) << endl;
    return 0;
}