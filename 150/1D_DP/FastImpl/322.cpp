// Coin Change

// https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// top down recursion
//  dp - if amount == 0 return 0, sort in descen. if amount < min return -1,
//  increase i till coins[i] > amount, initialize dp with amount+1 with size amount+1
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        sort(coins.begin(), coins.end(), [](int &a, int &b)
             { return a > b; });
        if (amount < coins[coins.size() - 1])
            return -1;
        int i = 0;
        while (coins[i] > amount)
            i++;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
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