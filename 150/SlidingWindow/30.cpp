// Substring with Concatenation of All Words

// https://leetcode.com/problems/substring-with-concatenation-of-all-words/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> cnt;
        for (auto &w : words)
        {
            ++cnt[w];
        }
        int m = s.size(), n = words.size(), k = words[0].size();
        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            unordered_map<string, int> cnt1;
            int l = i, r = i;
            int t = 0;
            while (r + k <= m)
            {
                string w = s.substr(r, k);
                r += k;
                if (!cnt.count(w))
                {
                    cnt1.clear();
                    l = r;
                    t = 0;
                    continue;
                }
                ++cnt1[w];
                ++t;
                while (cnt1[w] > cnt[w])
                {
                    string remove = s.substr(l, k);
                    l += k;
                    --cnt1[remove];
                    --t;
                }

                if (t == n)
                {
                    ans.push_back(l);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> result = sol.findSubstring(s, words);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}