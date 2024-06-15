// Snakes and Ladders

// https://leetcode.com/problems/snakes-and-ladders/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> flattenedBoard(n * n);

        // Flatten the board into a 1D vector for easier manipulation
        flattenBoard(board, flattenedBoard);

        // Perform BFS to find the shortest path
        queue<int> q;
        q.push(1); // Start from position 1
        int steps = 0;

        // Set to keep track of visited positions
        unordered_set<int> visited;
        visited.insert(1);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int position = q.front();
                q.pop();

                if (position == n * n)
                {
                    return steps;
                }

                // Explore all possible moves from the current position
                for (int j = 1; j <= 6; ++j)
                {
                    int nextPos = position + j;
                    if (nextPos > n * n)
                    {
                        break; // Beyond the board
                    }

                    int r = (nextPos - 1) / n;
                    int c = ((r % 2 == 0) ? (nextPos - 1) % n : (n - 1) - ((nextPos - 1) % n));
                    if (flattenedBoard[nextPos - 1] != -1)
                    {
                        nextPos = flattenedBoard[nextPos - 1];
                    }

                    if (visited.find(nextPos) == visited.end())
                    {
                        q.push(nextPos);
                        visited.insert(nextPos);
                    }
                }
            }
            ++steps;
        }

        return -1; // No path found
    }

    void flattenBoard(const vector<vector<int>> &board, vector<int> &flattenedBoard)
    {
        int n = board.size();
        for (int i = n - 1, idx = 0, row = 0; i >= 0; --i, ++row)
        {
            for (int j = 0; j < n; ++j, ++idx)
            {
                flattenedBoard[idx] = board[i][j];
            }
            if (row % 2 == 1)
            {
                reverse(flattenedBoard.begin() + idx - n, flattenedBoard.begin() + idx);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};

    Solution sol;
    cout << "Minimum number of moves: " << sol.snakesAndLadders(board) << endl;

    return 0;
}