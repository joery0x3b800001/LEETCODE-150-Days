// Find Minimum in Rotated Sorted Array

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        // If the array is not rotated, the minuimum element is nums[0]
        if (nums[left] <= nums[right])
            return nums[left];

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // If nums[mid] > nums[right], the minimum element is in the right half
            if (nums[mid] > nums[right])
                left = mid + 1;
            // Otherwise, the minimum element is in the left half or at mid
            else
                right = mid;
        }

        // The minimum element is at left
        return nums[left];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {11, 13, 15, 17};

    Solution solution;
    cout << solution.findMin(nums) << endl;
    return 0;
}