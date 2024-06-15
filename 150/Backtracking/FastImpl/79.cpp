// Word Search

// https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int m, n;

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));

        if (word.length() > m * n)
            return false;

        // Count the number of characters in both board and word
        // Return False if count of any characters in word > count of the character in board
        vector<int> count(58);
        vector<int> countWord(58);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count[board[i][j] - 'A']++;
            }
        }

        for (int i = 0; i < word.length(); i++)
        {
            countWord[word[i] - 'A']++;

            if (countWord[word[i] - 'A'] > count[word[i] - 'A'])
            {
                return false;
            }
        }

        // Start the search from lower frequency of characters, to minimize the loop
        if (count[word[0] - 'A'] > count[word.back() - 'A'])
            reverse(word.begin(), word.end());

        // DFS Starts here
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, used, 0, i, j))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &used, int pos, int i, int j)
    {
        // Return conditions
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[pos] || used[i][j])
        {
            return false;
        }

        if (pos == word.length() - 1)
        {
            return true;
        }

        // Recursive algorithm starts here
        bool found = false;
        used[i][j] = true;

        // Search upward
        found |= dfs(board, word, used, pos + 1, i - 1, j);

        // Search downward
        found |= dfs(board, word, used, pos + 1, i + 1, j);

        // Search leftward
        found |= dfs(board, word, used, pos + 1, i, j - 1);

        // Search rightward
        found |= dfs(board, word, used, pos + 1, i, j + 1);

        used[i][j] = false;
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