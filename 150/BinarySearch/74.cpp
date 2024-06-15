// Search a 2D Matrix

// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / cols][mid % cols]; // Convert 1D index to 2D coordinates

            if (mid_val == target)
            {
                return true; // Element found
            }
            else if (mid_val < target)
            {
                left = mid + 1; // Search in the right half
            }
            else
            {
                right = mid - 1; // Search in the left half
            }
        }

        return false; // Element not found
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target1 = 3;
    int target2 = 13;

    cout << "Search 3 in the matrix: " << boolalpha << sol.searchMatrix(matrix, target1) << endl;
    cout << "Search 13 in the matrix: " << boolalpha << sol.searchMatrix(matrix, target2) << endl;

    return 0;
}