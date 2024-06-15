// Valid Palindrome

// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool isNotAl(char c)
    {
        return isalnum(c) == 0;
    }

    bool isPalindrome(string s)
    {
        int n = s.size();

        s.erase(remove_if(s.begin(), s.end(), isNotAl), s.end());
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);

        n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "A man, a plan, a canal: Panama";

    cout << sol.isPalindrome(s) << endl;
    return 0;
}