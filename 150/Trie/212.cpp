// Word Search II

// https://leetcode.com/problems/word-search-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;
    string word;

    TrieNode() : children(26), word("") {}
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children[c - 'a'])
            {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->word = word;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie trie;
        for (string word : words)
        {
            trie.insert(word);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(board, i, j, trie.root, result);
            }
        }

        return result;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<string> &result)
    {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a'])
        {
            return;
        }

        node = node->children[c - 'a'];
        if (!node->word.empty())
        {
            result.push_back(node->word);
            node->word = ""; // Avoid duplicate results
        }

        board[i][j] = '#'; // Mark as visited
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto [dx, dy] : dirs)
        {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
            {
                dfs(board, x, y, node, result);
            }
        }
        board[i][j] = c; // Restore the character
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