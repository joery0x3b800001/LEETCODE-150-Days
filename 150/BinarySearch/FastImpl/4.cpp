// Median of Two Sorted Arrays

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        // std::ios::sync_with_stdio(0);
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int n = (n1 + n2);
        int leftSize = (n + 1) / 2;
        int lo = 0, hi = n1;
        while (lo <= hi)
        {
            int mid1 = (lo + hi) / 2;
            int mid2 = leftSize - mid1;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
            int l1 = (mid1 - 1 >= 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 - 1 >= 0) ? nums2[mid2 - 1] : INT_MIN;
            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                hi = mid1 - 1;
            else
                lo = mid1 + 1;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};

    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}