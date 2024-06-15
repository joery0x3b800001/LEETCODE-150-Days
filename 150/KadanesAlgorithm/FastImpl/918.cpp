// Maximum Sum Circular Subarray

// https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        int mx = INT_MIN;
        int cu = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cu = cu + nums[i];
            mx = max(cu, mx);
            if (cu < 0)
            {
                cu = 0;
            }
        }
        return mx;
    }

    int f1(vector<int> &nums)
    {
        int mx = 0;
        int mi = INT_MAX;
        int cu = 0;
        int mie = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            mie = max(mie, nums[i]);
            cu = cu + nums[i];
            mx = mx + nums[i];
            mi = min(mi, cu);
            if (cu > 0)
            {
                cu = 0;
            }
        }
        if (mi > 0)
        {
            return mx;
        }
        else if (mi == mx)
        {
            return mie;
        }
        return mx - mi;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        return max(f1(nums), maxSubArray(nums));
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> A = {1, -2, 3, -2};
    cout << "Maximum sum of a circular subarray: " << sol.maxSubarraySumCircular(A) << endl;
    return 0;
}