// Best Time to Buy and Sell Stock III

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxProfit(vector<int> &pr)
    {
        int a = -pr[0], b = INT_MIN, c = INT_MIN, d = INT_MIN;
        for (int x = 1; x < pr.size(); x++)
        {
            a = max(a, -pr[x]);
            b = max(b, a + pr[x]);
            c = max(c, b - pr[x]);
            d = max(d, c + pr[x]);
        }
        return max(0, d);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}