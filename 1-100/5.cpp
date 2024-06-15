// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <iostream>
#include <string>

#define N 1005

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    // Create a table to store whether substrings are palindromes
    bool dp[N][N] = {false};
    
    // Initialize variables to store the longest palindrome and its length
    int maxLen = 1;
    int start = 0;
    
    // Single character substrings are palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }
    
    // Check for substrings of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLen = 2;
            start = i;
        }
    }
    
    // Check for substrings of length greater than 2
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxLen) {
                    maxLen = len;
                    start = i;
                }
            }
        }
    }
    
    // Extract the longest palindrome substring
    return s.substr(start, maxLen);
}

int main(int argc, char const *argv[]){
    string in = "cbbd";

    cout << longestPalindrome(in) << '\n';
    
    return 0;
}