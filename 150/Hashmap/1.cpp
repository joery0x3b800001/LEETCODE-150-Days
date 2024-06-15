// Two Sum

// https://leetcode.com/problems/two-sum/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            hashMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (hashMap.find(complement) != hashMap.end() && hashMap[complement] != i)
            {
                return {i, hashMap[complement]};
            }
        }

        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    for (const int &res : result)
    {
        cout << res << endl;
    }
    return 0;
}