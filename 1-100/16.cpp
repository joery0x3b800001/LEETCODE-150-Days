// 3Sum Closest
// https://leetcode.com/problems/3sum-closest/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int closestSum = nums[0] + nums[1] + nums[2]; // Initialize closest sum with the sum of first three elements
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sort the array

    for (int i = 0; i < n - 2; ++i)
    {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(target - sum) < abs(target - closestSum))
            {
                closestSum = sum;
            }
            if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return closestSum;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int closestSum = threeSumClosest(nums, target);
    cout << "Closest sum to target: " << closestSum << endl; // Output: Closest sum to target: 2
    return 0;
}