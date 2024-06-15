// Kth Largest Element in an Array

// https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int quickSelect(vector<int> &nums, int left, int right, int k)
    {
        if (left == right)
            return nums[left];

        // Choose a random pivot index
        int pivotIdx = left + rand() % (right - left + 1);

        pivotIdx = partition(nums, left, right, pivotIdx);

        if (k == pivotIdx)
            return nums[k];
        else if (k < pivotIdx)
            return quickSelect(nums, left, pivotIdx - 1, k);
        else
            return quickSelect(nums, pivotIdx + 1, right, k);
    }

    int partition(vector<int> &nums, int left, int right, int pivotIdx)
    {
        int pivotVal = nums[pivotIdx];
        swap(nums[pivotIdx], nums[right]);

        int storeIdx = left;
        for (int i = left; i < right; ++i)
        {
            if (nums[i] < pivotVal)
            {
                swap(nums[i], nums[storeIdx]);
                ++storeIdx;
            }
        }

        swap(nums[storeIdx], nums[right]);

        return storeIdx;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}