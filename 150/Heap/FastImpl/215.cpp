// Kth Largest Element in an Array

// https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &v, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> v1(1e4 + 1, 0);
        vector<int> v2(1e4, 0);
        for (auto i : v)
        {
            if (i < 0)
            {
                v2[abs(i) - 1] += 1;
            }
            else
                v1[abs(i)] += 1;
        }
        // for (int i = 0; i < 7; i++)
        //     cout << v1[i] << " ";
        for (int i = 1e4; i >= 0; i--)
            if (v1[i])
            {
                if (v1[i])
                {
                    k -= v1[i];
                    if (k <= 0)
                        return i;
                }
            }
        for (int i = 0; i < 1e4; i++)
            if (v2[i])
            {
                if (v2[i])
                {
                    k -= v2[i];
                    if (k <= 0)
                        return (-1) * (i + 1);
                }
            }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}