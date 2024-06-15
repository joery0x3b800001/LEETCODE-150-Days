// Remove Element
// https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0; // Variable to count non-removed elements

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                // If the current element is not equal to val,
                // move it to the front of the array
                nums[count++] = nums[i];
            }
        }

        return count; // Return the count of non-removed elements
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