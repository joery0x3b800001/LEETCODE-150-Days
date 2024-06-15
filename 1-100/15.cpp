// 3Sum
// https://leetcode.com/problems/3sum/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();

    // Sorting the array to easily avoid duplicates
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i)
    {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = -nums[i]; // searches for the negative of a number, i.e nums[i] = 1 => -nums[i] = 1
        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                // Found a triplet
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> input = {-1, 0, 1, 2, -1, -4};

    auto res = threeSum(input);

    for (auto x : res)
    {
        for (int i = 0; i < x.size(); ++i)
        {
            cout << x[i] << ", ";
        }
        cout << endl;
    }
}