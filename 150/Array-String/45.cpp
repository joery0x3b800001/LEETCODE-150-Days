// Jump Game II
// https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0;
        int curEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd)
            {
                curEnd = farthest;
                jumps++;
            }
        }

        return jumps;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums = {2, 3, 0, 1, 4};

    cout << sol.jump(nums) << endl;

    return 0;
}