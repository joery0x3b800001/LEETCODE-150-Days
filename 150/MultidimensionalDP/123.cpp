// Best Time to Buy and Sell Stock III

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;

        // Initialize the maximum profits arrays for two transactions
        vector<int> maxProfitFirst(n, 0);
        vector<int> maxProfitSecond(n, 0);

        // Forward pass: calculate maximum profit for the first transaction
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfitFirst[i] = max(maxProfitFirst[i - 1], prices[i] - minPrice);
        }

        // Backward pass: calculate maximum profit for the second transaction
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            maxPrice = max(maxPrice, prices[i]);
            maxProfitSecond[i] = max(maxProfitSecond[i + 1], maxPrice - prices[i]);
        }

        int maxProfit = 0;
        // Combine the profits of the first and second transactions
        for (int i = 0; i < n; ++i)
        {
            maxProfit = max(maxProfit, maxProfitFirst[i] + maxProfitSecond[i]);
        }

        return maxProfit;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}