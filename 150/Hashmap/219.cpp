// Contains Duplicate II

// https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (numToIndex.find(nums[i]) != numToIndex.end() && abs(i - numToIndex[nums[i]]) <= k)
            {
                return true;
            }
            numToIndex[nums[i]] = i;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << sol.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}