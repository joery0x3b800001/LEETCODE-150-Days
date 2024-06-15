#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void kSumHelper(vector<int> &nums, int target, int k, int start,
                vector<int> &current, vector<vector<int>> &result)
{
    if (k == 0 && target == 0)
    {
        result.push_back(current);
        return;
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
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    int target = 0;
    int k = 3;
    vector<vector<int>> result = kSum(nums, target, k);

    cout << "Result:" << endl;
    for (const auto &combination : result)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}