// Valid Palindrome

// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (!isalnum(s[left]) && left < right)
            {
                left++;
            }
            while (!isalnum(s[right]) && left < right)
            {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
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