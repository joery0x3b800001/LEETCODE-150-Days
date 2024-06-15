// Test

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size();
    int maxArea = 0;

    while (left < right) {
        maxArea = max(maxArea, min(height[left], height[right]));

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty()) return "";

    string longestPrefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        int j = 0;
        while (j < longestPrefix.length() && j < strs[0].length() && longestPrefix[j] == strs[i][j])
        {
            ++j;
        }

        longestPrefix = longestPrefix.substr(0, j);

        if (longestPrefix.empty()) break;
    }
    return longestPrefix;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
        
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int target = -nums[i];
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            }
            else {
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;

                left++;
                right--;
            }
        }
        return result;
    }
}

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
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

void backtrack(const string& digits, const unordered_map<char, string> &phoneMap, int index, string& current, vector<string> & combinations)
{
    if (index == digits.length())
    {
        combinations.push_back(current);
        return;
    }

    char digit = digits[index];
    string letters = phoneMap.at(digit);

    for (char letter : letters)
    {
        current.push_back(letter);

        backtrack(digits, phoneMap, index + 1, current, combinations);

        current.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty()) return {};

    unordered_map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> combinations;
    string current;

    backtrack(digits, phoneMap, 0, current, combinations);
    return combinations;
}

void kSumHelper(vector<int> &nums, int target, int k, int start,
                vector<int> &current, vector<vector<int>> &result)
{
    if (k == 0 && target == 0) {
        result.push_back(current);
    }

    if (k == 0 || start == nums.size())
    {
        return;
    }

    for (int i = start; i < nums.size(); ++i)
    {
        if (i > start && nums[i] == nums[i - 1])
        {
            continue;
        }

        if (nums[i] <= target)
        {
            current.push_back(nums[i]);
            kSumHelper(nums, target - nums[i], k - 1, i + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<int>> kSum(vector<int> &nums, int target, int k)
{
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());
    kSumHelper(nums, target, k, 0, current, result);
    return result;
}

int main(int argc, char const *argv[])
{

}