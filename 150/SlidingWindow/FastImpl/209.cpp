#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int min_window = std::numeric_limits<int>::max();
        int l = 0;
        int r = 0;
        int sum = 0;
        while (r < nums.size())
        {
            sum += nums[r++];
            while (sum >= target)
            {
                min_window = std::min(r - l, min_window);
                sum -= nums[l++];
            }
        }
        return min_window != std::numeric_limits<int>::max() ? min_window : 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << sol.minSubArrayLen(target, nums) << endl;

    nums = {1, 4, 4};
    target = 4;
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}