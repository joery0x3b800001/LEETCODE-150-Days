// Max Points on a Line

// https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &p)
    {
        if (p.size() == 1)
            return 1;

        int mx = 0;
        int cnt0;
        double M[301];
        for (int i = 0; i < p.size(); i++)
        {
            cnt0 = 0;
            int n = 0;
            for (int j = i + 1; j < p.size(); j++)
            {
                if (p[j][0] == p[i][0])
                    cnt0++;
                else
                {
                    M[n++] = (double)(p[j][1] - p[i][1]) / (p[j][0] - p[i][0]);
                }
            }
            sort(M, M + n);
            int k = 1, cnt = 1;

            while (k < n)
            {
                if (M[k] == M[k - 1])
                {
                    cnt++;
                }
                else
                {
                    mx = max(mx, cnt);
                    cnt = 1;
                }
                k++;
            }
            mx = max(mx, cnt0);
            mx = max(mx, cnt);
            // cout<<endl;
        }
        return mx + 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

    Solution solution;
    cout << solution.maxPoints(points) << endl;
    return 0;
}