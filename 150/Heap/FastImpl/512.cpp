// IPO

// https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        ios_base::sync_with_stdio(false);
        int ans = w;
        priority_queue<int> maxheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        for (int i = 0; i < profits.size(); i++)
        {
            if (capital[i] <= w)
                maxheap.push(profits[i]);
            else
                minheap.push({capital[i], profits[i]});
        }
        while (k-- && (!maxheap.empty() || !minheap.empty()))
        {
            while (!minheap.empty() && minheap.top().first <= ans)
            {
                maxheap.push(minheap.top().second);
                minheap.pop();
            }
            if (!maxheap.empty())
            {
                ans += maxheap.top();
                maxheap.pop();
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    Solution solution;
    cout << solution.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}