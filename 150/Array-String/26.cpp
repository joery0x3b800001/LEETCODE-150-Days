// Remove Duplicates from Sorted Array

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;
        for (int num : nums)
        {
            st.insert(num);
        }

        copy(st.begin(), st.end(), nums.begin());

        return st.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int res = sol.removeDuplicates(nums);

    cout << res << "\n\n";

    for (int i = 0; i < nums.size() - res; i++) {
        cout << nums[i] << ',';
    }
}