// Group Anagrams

// https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> keyToAnagrams;

        for (const string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            keyToAnagrams[key].push_back(str);
        }

        for (const auto &[_, anagrams] : keyToAnagrams)
            result.push_back(anagrams);

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (const auto &group : result)
    {
        for (const auto &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}