// Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result;

        for (int i = 0; i < m; i++)
        {
            result.push_back(nums1[i]);
        }

        for (int i = 0; i < n; i++)
        {
            result.push_back(nums2[i]);
            sort(result.begin(), result.end());
            nums1 = result;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    int m = 3;

    sol.merge(nums1, m, nums2, n);

    for (int x : nums1)
    {
        cout << x << '\n';
    }

    return 0;
}