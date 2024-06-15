// Surrounded Regions

// https://leetcode.com/problems/surrounded-regions/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty() || board[0].empty())
            return;

        int numRows = board.size();
        int numCols = board[0].size();

        // Mark border 'O's and its adjacent 'O's as 'T'
        for (int i = 0; i < numRows; ++i)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }
            if (board[i][numCols - 1] == 'O')
            {
                dfs(board, i, numCols - 1);
            }
        }

        for (int j = 0; j < numCols; ++j)
        {
            if (board[0][j] == 'O')
            {
                dfs(board, 0, j);
            }
            if (board[numRows - 1][j] == 'O')
            {
                dfs(board, numRows - 1, j);
            }
        }

        // Flip remaining 'O's to 'X' and restore 'T's to 'O'
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>> &board, int row, int col)
    {
        int numRows = board.size();
        int numCols = board[0].size();

        if (row < 0 || row >= numRows || col < 0 || col >= numCols || board[row][col] != 'O')
            return;

        board[row][col] = 'T'; // Mark as visited

        // Explore neighbors
        dfs(board, row - 1, col); // Up
        dfs(board, row + 1, col); // Down
        dfs(board, row, col - 1); // Left
        dfs(board, row, col + 1); // Right
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    Solution sol;
    sol.solve(board);

    cout << "Modified board:" << endl;
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}