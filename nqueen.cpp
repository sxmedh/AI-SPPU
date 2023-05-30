#include <iostream>

const int MAX = 100;
int board[MAX][MAX];

bool isSafe(int row, int col, int n)
{
    // Check conflicts in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check conflicts in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check conflicts in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool nQueen(int row, int n)
{
    if (row == n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 1;

            if (nQueen(row + 1, n))
            {
                return true;
            }

            board[row][col] = 0; // Backtrack if solution not found
        }
    }

    return false;
}

void printBoard(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Enter the size of the board: ";
    std::cin >> n;

    if (nQueen(0, n))
    {
        printBoard(n);
    }
    else
    {
        std::cout << "A solution cannot be found." << std::endl;
    }

    return 0;
}
