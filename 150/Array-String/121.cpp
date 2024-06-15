// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = numeric_limits<int>::max();
        int maxProfit = 0;

        for (int price : prices)
        {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    vector<int> prices = {2, 4, 1};

    cout << sol.maxProfit(prices) << endl;

    return 0;
}