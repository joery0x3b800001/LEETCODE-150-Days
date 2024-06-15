// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <iostream>

using namespace std;

string longestPalindrome(string s) {
    int len = s.size();
    if (len < 2) {
        return s;
    }
    int subStrStart = 0, curr = 0, maxLen = 1;
    while (curr < len) {
        if (len - curr <= maxLen / 2) {
            // remaining substring won't give a bigger palindrome
            break;
        }
        int right = curr, left = curr;
        while (right < len - 1 && s[right] == s[right + 1]) {
            right++; // skipping duplicates as 
        }
        curr = right + 1;
        while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
            right++;
            left--;
        }
        if ((right - left + 1) > maxLen) {
            subStrStart = left;
            maxLen = (right - left + 1);
        }
    }
    return s.substr(subStrStart, maxLen);
}

int main(int argc, char const *argv[]){
    string in = "cbbd";

    cout << longestPalindrome(in) << '\n';
    
    return 0;
}