// Majority Element
// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0];
        int count = 1;

        // Find a candidate for the majority element
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == candidate)
            {
                ++count;
            }
            else
            {
                --count;
                if (count == 0)
                {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }

        // Verify if the candidate is the majority element
        count = 0;
        for (int num : nums)
        {
            if (num == candidate)
            {
                ++count;
            }
        }

        // Return the majority element if it exists, otherwise -1
        return count > nums.size() / 2 ? candidate : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // Example input
    int majority = sol.majorityElement(nums);

    cout << majority << endl;
    return 0;
}