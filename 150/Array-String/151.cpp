// Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        string temp = "";
        for (char c : s)
        {
            if (c == ' ')
            {
                if (!temp.empty())
                {
                    words.push_back(temp);
                    temp.clear();
                }
            }
            else
            {
                temp.push_back(c);
            }
        }

        if (!temp.empty())
        {
            words.push_back(temp);
        }

        reverse(words.begin(), words.end());

        string ans;
        for (string word : words)
        {
            ans += word + ' ';
        }
        if (!ans.empty())
        {
            ans.pop_back();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s1 = "the sky is blue";
    string s2 = "a good   example";
    string s3 = "  hello world  ";

    cout << sol.reverseWords(s2) << endl;
    return 0;
}