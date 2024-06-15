// Game of Life

// https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        // Define the eight possible directions to check neighbors
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        // Iterate through each cell
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int liveNeighbors = 0;

                // Count live neighbors
                for (auto &dir : directions)
                {
                    int x = i + dir.first;
                    int y = j + dir.second;

                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == -1))
                    {
                        liveNeighbors++;
                    }
                }

                // Apply rules based on liveNeighbors
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                {
                    board[i][j] = -1; // Mark as 1 -> 0
                }
                else if (board[i][j] == 0 && liveNeighbors == 3)
                {
                    board[i][j] = 2; // Mark as 0 -> 1
                }
            }
        }

        // Convert -1 to 0 and 2 to 1
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == -1)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    sol.gameOfLife(board);
    for (const auto &row : board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}