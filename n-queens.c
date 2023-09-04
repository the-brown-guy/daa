#include <stdio.h>

int safe(int row, int col, int n, int board[][n])
{
    int r = row;
    int c = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col])
        {
            return 0;
        }
        row--;
        col--;
    }

    row = r;
    col = c;

    while (col >= 0)
    {
        if (board[row][col])
        {
            return 0;
        }
        col--;
    }

    row = r;
    col = c;

    while (row < n && col >= 0)
    {
        if (board[row][col])
        {
            return 0;
        }
        row++;
        col--;
    }
    return 1;
}

void solve(int n, int board[][n], int col)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                    printf("%d  ", j + 1); // j+1 for 1 base indeixng.
            }
        }
        printf("\n");
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (safe(row, col, n, board))
        {
            board[row][col] = 1;
            solve(n, board, col + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int board[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    solve(n, board, 0);
}