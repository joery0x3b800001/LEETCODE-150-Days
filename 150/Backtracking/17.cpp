// Letter Combinations of a Phone Number

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void backtrack(const string &digits, const unordered_map<char, string> &phoneMap, int index, string &current, vector<string> &combinations)
    {
        // Base case: If the current combination has the same length as digits, add it to combinations
        if (index == digits.length())
        {
            combinations.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        char digit = digits[index];
        string letters = phoneMap.at(digit);

        // Try each letter for the current digit
        for (char letter : letters)
        {
            // Append the current letter to the current combination
            current.push_back(letter);
            // Recur with the updated combination and move to the next digit
            backtrack(digits, phoneMap, index + 1, current, combinations);
            // Backtrack by removing the last letter to try the next one
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        // Mapping of digits to their respective letters
        unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        vector<string> combinations;
        string current;

        backtrack(digits, phoneMap, 0, current, combinations);

        return combinations;
    }
};

int main(int argc, char const *argv[])
{
    string digits = "23";
    Solution solution;

    vector<string> result = solution.letterCombinations(digits);
    for (const auto& x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}