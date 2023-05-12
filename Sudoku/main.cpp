#include "Checking.h"
#include "Checking.cpp"

int main()
{
    Checking check;
    int num;
    int row;
    int col;
    string difficulty;

    cout << "Welcome to Sudoku!" << endl;
    cout << "The goal of the game is to fill in the empty spaces with numbers 1-9 such that each row, column, and 3x3 square contains each number exactly once." << endl;
    cout << "You will be prompted to enter a number and the location where you would like to put it." << endl;
    cout << "The first number you enter will be the row, the second number will be the column, and the third number will be the value." << endl;
    cout << "For example, if you wanted to put a 9 in the top left corner, you would enter 0 0 9." << endl;
    cout << "If you enter a number that is already in the row, column, or 3x3 square, you will be prompted to try again." << endl;

    cout << "Good luck!" << endl;

    cout << "There are three difficulty levels: easy, medium, and hard." << endl;
    cout << "Please select one of the difficulty levels above: ";

    cin >> difficulty;

    if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard")
    {
        cout << "Invalid input, please try again." << endl;
        cin >> difficulty;
    }

    check.createBoard(difficulty);
    check.printBoard();

    for (int i = 0; i < 56; i++)
    {
        cout << endl
             << "Please enter a number between 1 and 9 and the location where you would like to put it (in the form x y 9): ";

        cin >> col;
        cin >> row;
        cin >> num;

        check.insertNumber(row, col, num);
    }

    if (check.wonGame())
    {
        cout << "Congratulations! You won!" << endl;
    }
    else
    {
        cout << "You lost!" << endl;
    }

    return 0;
}