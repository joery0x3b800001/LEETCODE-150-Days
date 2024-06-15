// Median of Two Sorted Arrays

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1)
            return findKth(nums1, 0, nums2, 0, total / 2 + 1);
        else
            return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
    }

private:
    int findKth(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k)
    {
        // If nums1 is exhausted, return the kth element of nums2
        if (start1 >= nums1.size())
            return nums2[start2 + k - 1];
        // If nums2 is exhausted, return the kth element of nums1
        if (start2 >= nums2.size())
            return nums1[start1 + k - 1];
        // If k is 1, return the smaller of the first element of nums1 and nums2
        if (k == 1)
            return min(nums1[start1], nums2[start2]);

        // Get the k/2th element of nums1 and nums2
        int mid1 = (start1 + k / 2 - 1 < nums1.size()) ? nums1[start1 + k / 2 - 1] : INT_MAX;
        int mid2 = (start2 + k / 2 - 1 < nums2.size()) ? nums2[start2 + k / 2 - 1] : INT_MAX;

        // Recursively find the k - k/2th element in the remaining arrays
        if (mid1 < mid2)
            return findKth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
        else
            return findKth(nums1, start1, nums2, start2 + k / 2, k - k / 2);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};

    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}