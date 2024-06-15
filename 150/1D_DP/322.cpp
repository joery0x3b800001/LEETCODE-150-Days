// Coin Change

// https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Initialize dp array with maximum value as INT_MAX
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case

        // Iterate through all amounts from 1 to amount
        for (int i = 1; i <= amount; ++i)
        {
            // Iterate through all coins
            for (int j = 0; j < coins.size(); ++j)
            {
                // If the coin value is less than or equal to the amount
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                {
                    // Update dp[i] with the minimum of current value and dp[i - coin] + 1
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution solution;
    cout << solution.coinChange(coins, amount) << endl;
    return 0;
}