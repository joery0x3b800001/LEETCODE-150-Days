#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> rows, cols;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for (int i = 0; i < rows.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[rows[i]][j] = 0;
            }
        }

        for (int j = 0; j < cols.size(); j++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][cols[j]] = 0;
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