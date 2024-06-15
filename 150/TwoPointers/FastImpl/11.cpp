// Container with Most Water

// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int ans = 0, i = 0, j = height.size() - 1, res = 0;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                res = height[i] * (j - i);
                i++;
            }
            else
            {
                res = height[j] * (j - i);
                j--;
            }
            if (res > ans)
                ans = res;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << sol.maxArea(height) << endl;

    return 0;
}