#include "Checking.h"

void Checking::createBoard(string difficulty)
{
    int num;
    if (difficulty == "hard")
    {
        num = 25;
    }
    else if (difficulty == "medium")
    {
        num = 35;
    }
    else if (difficulty == "easy")
    {
        num = 45;
    }
    for (int i = 0; i < num; i++)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        if (game_board[row][col] == 0)
        {
            game_board[row][col] = rand() % 9 + 1;
            if (!checkingColumns(game_board) || !checkingRows(game_board) || !checkingSquares(game_board))
            {
                game_board[row][col] = 0;
                i--;
            }
        }
        else
            i--;
    }
}

bool Checking::checkingColumns(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = j + 1; k < 9; k++)
            {
                if (board[i][j] == board[i][k] && board[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Checking::checkingRows(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = j + 1; k < 9; k++)
            {
                if (board[j][i] == board[k][i] && board[j][i] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Checking::checkingSquares(int board[9][9])
{
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    for (int m = k; m < i + 3; m++)
                    {
                        for (int n = l + 1; n < j + 3; n++)
                        {
                            if (board[k][l] == board[m][n] && board[k][l] != 0)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

void Checking::printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << game_board[i][j] << " ";
            if (j == 2 || j == 5)
                cout << "| ";
        }
        cout << endl;
        if (i == 2 || i == 5)
            cout << "---------------------" << endl;
    }
}

void Checking::insertNumber(int row, int col, int value)
{

    if (row < 0 || row > 8 || col < 0 || col > 8 || value < 1 || value > 9)
    {
        cout << "Invalid input, try again!" << endl;
        return;
    }
    else if (game_board[row][col] != 0)
    {
        cout << "You can't change a number that's already there, try again!" << endl;
        return;
    }
    game_board[row][col] = value;
    if (!checkingColumns(game_board) || !checkingRows(game_board) || !checkingSquares(game_board))
    {
        cout << "You can't put that number there, try again!" << endl;
        game_board[row][col] = 0;
        return;
    }
    else
    {
        printBoard();
    }
}

bool Checking::wonGame()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (game_board[i][j] == 0)
            {
                // cout << "Oops, looks like you missed a spot, try again!" << endl;
                return false;
                break;
            }
        }
    }
    // cout << "You won the game!" << endl;
    return true;
}