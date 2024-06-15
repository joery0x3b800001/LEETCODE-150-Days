// Two Sum II - Input Array Is Sorted

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> numbers1 = {2, 7, 11, 15};
    vector<int> numbers2 = {2, 3, 4};

    for (int i : sol.twoSum(numbers2, 6))
    {
        cout << i << endl;
    }

    return 0;
}