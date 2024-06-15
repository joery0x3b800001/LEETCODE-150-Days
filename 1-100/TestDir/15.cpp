// 3Sum
// https://leetcode.com/problems/3sum/description/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            int k = j + 1;
            while ((i != j) && (i != k) && (j != k) && (nums[i] + nums[j] + nums[k] == 0) && k < nums.size())
            {
                if ((nums[i] == 0) && (nums[j] == 0) && (nums[k] == 0))
                {
                    return vector<vector<int>>{{0, 0, 0}};
                }
                result.push_back({nums[i], nums[j], nums[k]});
                ++k;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    
    // 1, 2, -2, 1
    vector<int> input = { 1, -1, -1, 0 };

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