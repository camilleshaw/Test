#ifndef CHECKING_H
#define CHECKING_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const int ROW_SIZE = 9;
const int COL_SIZE = 9;
const int BACKGROUND = 0;

class Checking
{
public:
    Checking()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                game_board[i][j] = 0;
            }
        }
    }
    ~Checking()
    {
    }

    void createBoard(string difficulty);

    bool checkingColumns(int board[9][9]);

    bool checkingRows(int board[9][9]);

    bool checkingSquares(int board[9][9]);

    void printBoard();

    void insertNumber(int row, int col, int value);

    bool wonGame();

protected:
    int game_board[9][9];
};

#endif