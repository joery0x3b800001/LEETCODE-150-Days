// Valid Sudoku

// https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Check rows
        for (int i = 0; i < 9; ++i)
        {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.' && rowSet.find(board[i][j]) != rowSet.end())
                    return false;
                rowSet.insert(board[i][j]);
            }
        }

        // Check columns
        for (int j = 0; j < 9; ++j)
        {
            unordered_set<char> colSet;
            for (int i = 0; i < 9; ++i)
            {
                if (board[i][j] != '.' && colSet.find(board[i][j]) != colSet.end())
                    return false;
                colSet.insert(board[i][j]);
            }
        }

        // Check 3x3 sub-grids
        for (int block = 0; block < 9; ++block)
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
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<char>> board =
            {{'5','3','.','.','7','.','.','.','.'}
            ,{'6','.','.','1','9','5','.','.','.'}
            ,{'.','9','8','.','.','.','.','6','.'}
            ,{'8','.','.','.','6','.','.','.','3'}
            ,{'4','.','.','8','.','3','.','.','1'}
            ,{'7','.','.','.','2','.','.','.','6'}
            ,{'.','6','.','.','.','.','2','8','.'}
            ,{'.','.','.','4','1','9','.','.','5'}
            ,{'.','.','.','.','8','.','.','7','9'}};

    cout << sol.isValidSudoku(board) << endl;
    return 0;
}