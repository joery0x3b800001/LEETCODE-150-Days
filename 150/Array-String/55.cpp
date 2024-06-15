// Jump Game
// https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i + nums[i] >= lastPos)
            {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << sol.canJump(nums) << endl;

    return 0;
}