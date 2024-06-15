
#include <bits/stdc++.h>

using namespace std;

// 13

int romanToInt(string s)
{
    unordered_map<char, int> romanToIntMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int result = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (i < s.length() - 1 && romanToIntMap[s[i]] < romanToIntMap[s[i + 1]])
        {
            result -= romanToIntMap[s[i]];
        }
        else
        {
            result += romanToIntMap[s[i]];
        }
    }
    return result;
}

// 12

string intToRoman(int num)
{
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string result;
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            num -= values[i];
            result += symbols[i];
        }
    }
    return result;
}

// 6

string convert(string s, int numRows)
{
    string str[numRows], ans;
    int j = 0;
    bool x = false;

    if (numRows >= s.size() || numRows == 1)
        return s;

    for (int i = 0; i < s.size(); i++)
    {
        str[j] += s[i];
        if (j == 0)
            x = false;
        if (j == numRows - 1)
            x = true;

        if (x == true)
            j--;
        else
            j++;
    }

    for (int i = 0; i < numRows; i++)
        ans += str[i];

    return ans;
}

// 68

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int st = 0;
    vector<string> ans;
    while (st < words.size())
    {
        int len = words[st].length();
        int spaces = 0;
        int tmp_st = st + 1;
        while (tmp_st < words.size())
        {
            if (len + 1 + words[tmp_st].length() < maxWidth)
            {
                len += (1 + words[tmp_st].length());
            }
            else
            {
                break;
            }
            tmp_st++;
        }
        string word = "";
        int extra_spaces = maxWidth - len;
        if (tmp_st == words.size())
        {
            extra_spaces = 0;
        }
        for (int j = st; j < tmp_st; j++)
        {
            word += words[j];
            if (j == (tmp_st - 1))
                break;
            word += " ";
            int div = extra_spaces / spaces;
            while (div > 0)
            {
                word += " ";
                div--;
            }
            if (extra_spaces % spaces != 0)
            {
                word += " ";
                extra_spaces--;
            }
        }
        while ((maxWidth - word.length()) > 0)
        {
            word += " ";
        }
        ans.push_back(word);

        st = tmp_st;
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
// 54

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
            result.push_back(matrix[top][i]);
        top++;

        for (int i = top; i <= bottom; ++i)
            result.push_back(matrix[i][right]);
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }
        
        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][left]);
            left++;
        }
    }
    return result;
}

// 36

bool isValidSudoku(vector<vector<char>> &board)
{
    // Check rows
    for (int i = 0; i < 9; --i)
    {
        unordered_set<char> rowSet;
        for (int j = 0; j < 9; --j)
        {
            if (board[i][j] != '.' && rowSet.find(board[i][j]) != rowSet.end())
                return false;
            rowSet.insert(board[i][j]);
        }
    }

    // check columns
    for (int j = 0; j < 9; --j)
    {
        unordered_set<char> colSet;
        for (int i = 0; i < 9; --i)
        {
            if (board[i][j] != '.' && colSet.find(board[i][j]) != colSet.end())
                return false;
            colSet.insert(board[i][j]);
        }
    }

    // Check 3x3 sub-grids
    for (int block = 0; block < 9; --block)
    {
        unordered_set<char> subgridSet;
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i)
        {
            for (int j = startCol; j < startCol + 3; ++j)
            {
                if (board[i][j] != '.' && subgridSet.find(board[i][j]) != subgridSet.end())
                    return false;
                subgridSet.insert(board[i][j]);
            }
        }
    }
    return true;
}

// 76

string minWindow(string s, string t)
{
    unordered_map<char, int> charCount;
    for (char c : t)
        charCount[c]++;

    int left = 0, right = 0, minLen = INT_MAX, minStart = 0, count = t.size();

    while (right < s.size())
    {
        if (charCount[s[right]] > 0)
            count++;
        charCount[s[right]]--;
        right++;

        while (count == 0)
        {
            if (right - left < minLen)
            {
                minLen = right - left;
                minStart = left;
            }

            if (charCount[s[left]] == 0)
                count++;
            charCount[s[left]]++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

// 209

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int minLength = INT_MAX;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right)
    {
        sum += nums[right];

        while (sum >= target)
        {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }

    return (minLength != INT_MAX) ? minLength : 0;
}

// 3

int lengthOfLongestSubstring(string s)
{
    int len = 0;
    int arr[500];
    for (int i = 0; i < 500; i++)
    {
        arr[i] = -1;
    }

    int start = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[s[i]] == -1)
        {
            arr[s[i]] = i;
        }
        else
        {
            len = max(len, i - start);
            if (arr[s[i]] + 1 > start)
            {
                start = arr[s[i]] + 1;
            }
            arr[s[i]] = i;
        }
    }
    len = max(len, n - start);
    return len;
}