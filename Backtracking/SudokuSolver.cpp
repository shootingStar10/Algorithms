#include <bits/stdc++.h>

using namespace std;

bool isSafeRow(vector <vector <char> > &board, int r, int n)
{
    for (int i = 0; i < 9; i++) {
        if (board[r][i] != '.') {
            if (board[r][i] == (n+'0')) {
                return false;
            }
        }
    }

    return true;
}

bool isSafeColumn(vector <vector <char> > &board, int c, int n)
{
    for (int i = 0; i < 9; i++) {
        if (board[i][c] != '.') {
            if (board[i][c] == (n+'0')) {
                return false;
            }
        }
    }

    return true;
}

bool isSafeGrid(vector <vector <char> > &board, int r, int c, int n)
{
    int i, j, x, y;
    bool ch = false;

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            for (x = i; x < i+3; x++) {
                for (y = j; y < j+3; y++) {
                    if (x == r && y == c) {
                        ch = true;
                        break;
                    }
                }

                if (ch == true) break;
            }

            if (ch == true) break;
        }

        if (ch == true) break;
    }

    for (x = i; x < i+3; x++) {
        for (y = j; y < j+3; y++) {
            if (board[x][y] != '.') {
                if (board[x][y] == (n+'0')) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool isSafe(vector <vector <char> > &board, int r, int c, int n)
{
    return isSafeRow(board, r, n) && isSafeColumn(board, c, n) && isSafeGrid(board, r, c, n);
}

bool isUnassigned(vector< vector <char> > & board, int &i, int &j)
{
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector< vector <char> > & board)
{
    int i, j;

    if (isUnassigned(board, i, j) == true) {
        return true;
    }

    for (int n = 1; n <= 9; n++) {
        if (isSafe(board, i, j, n) == true) {
            board[i][j] = (n+'0');

            if (solveSudoku(board) == true) {
                return true;
            }

            board[i][j] = '.';
        }
    }

    return false;
}

int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

   vector <vector <char> > board;

   for (int i = 0; i < 9; i++) {
      vector <char> temp;
      for (int j = 0; j < 9; j++) {
        if (grid[i][j] == 0) {
            temp.push_back('.');
        } else {
            temp.push_back(grid[i][j] + '0');
        }
      }
      board.push_back(temp);
   }

   for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
       }

   bool ch = solveSudoku(board);

   cout<<"\n-------------------------------------------------------------------------------------------------\n";

   if (ch == false) {
    cout<<"No solution exist.";
   } else {
       for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
       }
   }

   return 0;
}
