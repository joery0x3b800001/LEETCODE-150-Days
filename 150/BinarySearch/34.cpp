// Find First and Last Position of Element in Sorted Array

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int first = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target)
            {
                if (nums[mid] == target)
                    first = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return first;
    }

    int findLast(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int last = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target)
            {
                if (nums[mid] == target)
                    last = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return last;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution solution;
    vector<int> res = solution.searchRange(nums, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}