// Word Pattern

// https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        std::unordered_map<char, std::string> charToWordMap;
        std::unordered_map<std::string, char> wordToCharMap;

        size_t wordStart = 0;
        for (size_t i = 0; i <= s.size(); ++i)
        {
            // If we reach the end of the string or find a space
            if (i == s.size() || s[i] == ' ')
            {
                std::string word = s.substr(wordStart, i - wordStart);
                wordStart = i + 1;

                // If the pattern has ended but there are still words in s, return false
                if (pattern.empty())
                    return false;

                char currentChar = pattern.front();
                pattern.erase(0, 1);

                // Check if the current character-word pair is consistent with the mapping
                if (charToWordMap.find(currentChar) == charToWordMap.end() &&
                    wordToCharMap.find(word) == wordToCharMap.end())
                {
                    charToWordMap[currentChar] = word;
                    wordToCharMap[word] = currentChar;
                }
                else
                {
                    if (charToWordMap[currentChar] != word || wordToCharMap[word] != currentChar)
                        return false;
                }
            }
        }

        // If there are still characters in the pattern, return false
        return pattern.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << sol.wordPattern(pattern, s) << endl;
    return 0;
}