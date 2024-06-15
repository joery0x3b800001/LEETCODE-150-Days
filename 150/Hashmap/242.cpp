// Valid Anagram

// https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "rat";
    string t = "car";
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}