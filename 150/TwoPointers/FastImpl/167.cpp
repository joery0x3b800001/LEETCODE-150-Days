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

        int sum = numbers[left] + numbers[right];

        while (sum != target)
        {
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            sum = numbers[left] + numbers[right];
        }
        return {left + 1, right + 1};
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> numbers = {2, 7, 11, 15};

    int target = 9;
    vector<int> result = sol.twoSum(numbers, target);
    if (result.size() == 2)
    {
        cout << result[0]  << " " << result[1] << endl;
    }

    return 0;
}