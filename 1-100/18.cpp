// 4Sum
// https://leetcode.com/problems/4sum/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i)
    {
        // Avoid duplicates quadruplets
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; ++j)
        {
            // Avoid duplicate quadruplets
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // Avoid duplicate quadruplets
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
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
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> input = {1, 0, -1, 0, -2, 2};
    int target = 0;

    auto res = fourSum(input, target);

    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}