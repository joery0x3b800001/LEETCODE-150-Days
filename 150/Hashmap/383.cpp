// Ransom Note

// https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int charMap[26] = {0};
        for (int i = 0; i < magazine.length(); ++i)
        {
            charMap[magazine[i] - 'a'] += 1;
        }

        for (int i = 0; i < ransomNote.length(); ++i)
        {
            if (charMap[ransomNote[i] - 'a'] > 0)
                charMap[ransomNote[i] - 'a'] -= 1;
            else
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string ransomNote = "aa", magazine = "aab";
    cout << sol.canConstruct(ransomNote, magazine) << endl;
    return 0;
}