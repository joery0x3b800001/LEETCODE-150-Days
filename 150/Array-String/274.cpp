// H-Index
// https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        int hIndex = 0;
        for (int i = 0; i < citations.size(); ++i)
        {
            if (citations[i] >= i + 1)
            {
                hIndex = i + 1;
            }
            else
            {
                break;
            }
        }
        return hIndex;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums = {3, 0, 6, 1, 5};

    cout << sol.hIndex(nums) << endl;

    return 0;
}