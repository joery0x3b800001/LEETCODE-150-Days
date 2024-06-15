// Set Matrix Zeroes

// https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Arrays to mark which rows and columns need to be zeroed
        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);

        // Marks rows and columns containing 0s
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        // Set entire rows to 0
        for (int i = 0; i < rows; ++i)
        {
            if (zeroRows[i])
            {
                for (int j = 0; j < cols; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set entire columns to 0
        for (int j = 0; j < cols; ++j)
        {
            if (zeroCols[j])
            {
                for (int i = 0; i < rows; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    sol.setZeroes(matrix);
    for (const auto &row : matrix)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}