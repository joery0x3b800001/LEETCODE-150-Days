// Remove Element
// https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// int curr_pos = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == val) nums[i] = -1;
//             else nums[curr_pos++] = nums[i];
//         }
//         return curr_pos;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        vector<int> b;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != val)
            {
                b.push_back(nums[i]);
            }
        }
        copy(b.begin(), b.end(), nums.begin());
        return b.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int res = sol.removeElement(nums, val);

    cout << res << "\n";

    for (int i = 0; i < nums.size() - res; i++)
    {
        cout << nums[i] << ",";
    }
}