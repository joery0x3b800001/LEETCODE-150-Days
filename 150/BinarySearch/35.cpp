// Search Insert Position

// https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid; // Element found, return its index
            }
            else if (nums[mid] < target)
            {
                left = mid + 1; // Search in the right half
            }
            else
            {
                right = mid; // Search in the left half
            }
        }

        // Element not found, return the index where it would be inserted
        return left;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 4;

    Solution solution;
    cout << solution.searchInsert(nums, target) << endl;
    return 0;
}