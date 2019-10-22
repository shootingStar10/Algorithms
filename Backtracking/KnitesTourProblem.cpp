/*
Knight's tour problem
*/

#include <bits/stdc++.h>

using namespace std;

int isSafe(int board[][8], int i, int j)
{
    if (i >= 0 && i < 8 && j >= 0 && j < 8 && board[i][j] == -1) {
        return true;
    }

    return false;
}

bool solve(int board[][8], int x, int y, int move_cnt, int row[], int colm[])
{
    if (move_cnt == 64) {
        return true;
    }

    for (int k = 0; k < 8; k++) {
        int r = x + row[k];
        int c = y + colm[k];

        if (isSafe(board, r, c) == true) {
            board[r][c] = move_cnt;

            if (solve(board, r, c, move_cnt+1, row, colm) == true) {
                return true;
            } else {
                board[r][c] = -1;
            }
        }
    }

    return false;
}

int main()
{
    int board[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = -1;
        }
    }

    board[0][0] = 0;
    int row[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int colm[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    if (solve(board, 0, 0, 1, row, colm) == false) {
        cout<<"No solution exist."<<endl;
    } else {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout<<board[i][j]<<"\t";
            }

            cout<<endl;
        }
    }

    return 0;
}
