// Best Time to Buy and Sell Stock IV

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1 || k <= 0)
            return 0;

        // If k is large enough, this problem can be treated as the unlimited transactions problem
        if (k >= n / 2)
        {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i)
            {
                if (prices[i] > prices[i - 1])
                {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        // dp[i][j] represents the maximum profit up to day i with at most j transactions
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int t = 1; t <= k; ++t)
        {
            int maxDiff = -prices[0];
            for (int i = 1; i < n; ++i)
            {
                dp[t][i] = max(dp[t][i - 1], prices[i] + maxDiff);
                maxDiff = max(maxDiff, dp[t - 1][i] - prices[i]);
            }
        }

        return dp[k][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    Solution solution;
    cout << solution.maxProfit(k, prices) << endl;
    return 0;
}