// Spiral Matrix

// https://leetcode.com/problems/spiral-matrix/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse top row
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);
            top++;

            // Traverse rightmost column
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            right--;

            // Traverse bottom row
            if (top <= bottom)
            {
                for (int i = right; i >= left; --i)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Traverse leftmost column
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }

private:
    vector<int> result;
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = sol.spiralOrder(matrix);
    for (int i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}