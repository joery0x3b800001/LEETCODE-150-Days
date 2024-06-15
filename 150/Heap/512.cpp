// IPO

// https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // Pair capital and profit
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i)
        {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort projects by capital
        sort(projects.begin(), projects.end());

        // Max heap to store available projects sorted by profit
        priority_queue<int> pq;

        int idx = 0;
        for (int i = 0; i < k; ++i)
        {
            // Add all projects with capital less than or equal to W to max heap
            while (idx < projects.size() && projects[idx].first <= w)
            {
                pq.push(projects[idx].second);
                idx++;
            }

            // If there are no available projects, return current capital
            if (pq.empty())
                break;

            // Select project with maximum profit from max heap and update capital
            w += pq.top();
            pq.pop();
        }

        return w;
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