// Find K Pairs with Smallest Sums

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;

        auto cmp = [&](pair<int, int> &a, pair<int, int> &b)
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < min(k, (int)nums1.size()); ++i)
        {
            pq.push({i, 0});
        }

        while (k-- > 0 && !pq.empty())
        {
            auto idx_pair = pq.top();
            pq.pop();
            result.push_back({nums1[idx_pair.first], nums2[idx_pair.second]});
            if (idx_pair.second + 1 < nums2.size())
            {
                pq.push({idx_pair.first, idx_pair.second + 1});
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    Solution solution;
    vector<vector<int>> result = solution.kSmallestPairs(nums1, nums2, k);
    cout << "[ ";
    for (const auto &num : result)
    {
        cout << "[ ";
        for (const auto &x : num)
        {
            cout << x << " ";
        }
        cout << "]";
    }
    cout << " ]\n";
    return 0;
}