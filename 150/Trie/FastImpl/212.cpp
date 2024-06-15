// Word Search II

// https://leetcode.com/problems/word-search-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool dfs(int i, int r, int c, vector<vector<char>> &board, int rows, int cols, string &word, int len)
    {
        char ch = board[r][c];
        if (word[i] != ch)
            return false;
        i++;
        if (i == len)
            return true;
        board[r][c] = '$';

        bool res = false;
        if (c + 1 < cols)
            res = dfs(i, r, c + 1, board, rows, cols, word, len);
        if (!res && r + 1 < rows)
            res = dfs(i, r + 1, c, board, rows, cols, word, len);
        if (!res && c > 0)
            res = dfs(i, r, c - 1, board, rows, cols, word, len);
        if (!res && r > 0)
            res = dfs(i, r - 1, c, board, rows, cols, word, len);
        board[r][c] = ch;

        return res;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int rows = board.size();
        int cols = board[0].size();
        int cells = rows * cols;
        vector<string> res;

        array<vector<pair<int, int>>, 26> vecp;
        array<int, 26> countWord;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                vecp[board[r][c] - 'a'].push_back({r, c});
            }
        }

        int start = 0;
        int end = 0;
        bool reversed = false;
        for (auto word : words)
        {
            if (word.length() > cells)
                continue;
            if (word.front() == 'a')
                start++;
            if (word.back() == 'a')
                end++;
        }

        if (start > end)
        {
            reversed = true;
            for (int i = 0; i < words.size(); i++)
            {
                if (words[i].length() > cells)
                    continue;
                reverse(words[i].begin(), words[i].end());
            }
        }

        for (auto word : words)
        {
            int len = word.length();
            if (len > cells)
                continue;

            countWord.fill(0);

            bool found = true;
            for (auto c : word)
                if (++countWord[c - 'a'] > vecp[c - 'a'].size())
                {
                    found = false;
                    break;
                }
            if (!found)
                continue;

            for (auto p : vecp[word.front() - 'a'])
                if (dfs(0, p.first, p.second, board, rows, cols, word, len))
                {
                    if (reversed)
                        reverse(word.begin(), word.end());
                    res.push_back(word);
                    break;
                }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};

    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> result = sol.findWords(board, words);

    for (const string &word : result)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}