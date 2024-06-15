// Roman to Integer
// https://leetcode.com/problems/roman-to-integer/description/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    // Create a map to store the integer values of Roman numerals
    std::unordered_map<char, int> romanToIntMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    // Initialize the result
    int result = 0;

    // Iterate through the string
    for (int i = 0; i < s.length(); ++i)
    {
        // If the current Roman numeral is part of a subtractive pair
        if (i < s.length() - 1 && romanToIntMap[s[i]] < romanToIntMap[s[i + 1]])
        {
            // Subtract its value from the result
            result -= romanToIntMap[s[i]];
        }
        else
        {
            // Otherwise, add its value to the result
            result += romanToIntMap[s[i]];
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{

    string input = "MCMXCIV";

    cout << romanToInt(input) << '\n';

    return 0;
}