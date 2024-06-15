// Find Peak Element

// https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // If mid greater than its neighbors, it's a peak
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }

        // left == right is the peak element
        return left;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 1};

    Solution solution;
    cout << solution.findPeakElement(nums) << endl;
    return 0;
}