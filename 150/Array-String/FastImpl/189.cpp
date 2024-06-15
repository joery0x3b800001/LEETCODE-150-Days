// Rotate Array
// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n; // in case k is greater than n

        // Handle the case where k is 0 or multiple of n
        if (k == 0 || k == n)
            return;

        int count = 0;
        for (int start = 0; count < n; ++start)
        {
            int current = start;
            int prev = nums[start];
            do
            {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                ++count;
            } while (start != current);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol.rotate(nums, k);

    for (int num : nums)
    {
        cout << num << ", ";
    }

    return 0;
}