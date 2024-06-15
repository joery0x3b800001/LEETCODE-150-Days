// Permutations

// https://leetcode.com/problems/permutations/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, result, current, used);
        return result;
    }

    void backtrack(const vector<int> &nums, vector<vector<int>> &result, vector<int> &current, vector<bool> &used)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!used[i])
            {
                current.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, result, current, used);
                used[i] = false;
                current.pop_back();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    cout << "All permutations of [1, 2, 3] are:" << endl;
    for (const auto &permutation : result)
    {
        cout << "[ ";
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}