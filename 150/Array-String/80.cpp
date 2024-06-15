// Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            int temp = nums[j];
            int count = 0; // Count the occurrences of the current element

            // Copy at most two occurrences of the current element to the array
            while (j < nums.size() && temp == nums[j] && count < 2)
            {
                nums[i] = temp;
                i++;
                j++;
                count++;
            }

            // Move to the next element
            while (j < nums.size() && temp == nums[j])
            {
                j++;
            }
        }
        return i;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};

    int res = sol.removeDuplicates(nums);

    cout << res << "\n\n";

    for (int i = 0; i < nums.size() - res; ++i)
    {
        cout << nums[i] << '\n';
    }
}