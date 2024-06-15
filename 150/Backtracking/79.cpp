// Word Search

// https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty())
        {
            return false;
        }

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (backtrack(board, word, visited, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>> &board, const string &word, vector<vector<bool>> &visited, int i, int j, int index)
    {
        if (index == word.size())
        {
            return true; // All characters of the word are found
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
        {
            return false; // Out of bounds or character doesn't match
        }

        visited[i][j] = true; // Mark current cell as visited

        // Explore neighboring cells
        bool found = backtrack(board, word, visited, i + 1, j, index + 1) ||
                     backtrack(board, word, visited, i - 1, j, index + 1) ||
                     backtrack(board, word, visited, i, j + 1, index + 1) ||
                     backtrack(board, word, visited, i, j - 1, index + 1);

        visited[i][j] = false; // Reset visited status for backtracking

        return found;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "Word 'ABCCED' exists: " << boolalpha << sol.exist(board, word1) << endl;
    cout << "Word 'SEE' exists: " << boolalpha << sol.exist(board, word2) << endl;
    cout << "Word 'ABCB' exists: " << boolalpha << sol.exist(board, word3) << endl;

    return 0;
}