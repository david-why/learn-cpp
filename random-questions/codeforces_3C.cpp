// http://codeforces.com/contest/3/problem/C
// Codeforces Contest #3 C. Tic-tac-toe
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char board[3][4];
#define S(x, y, z)                              \
    if ((x) == (c) && (y) == (c) && (z) == (c)) \
    v++
int win(char c)
{
    int v = 0;

    S(board[0][0], board[0][1], board[0][2]);
    S(board[1][0], board[1][1], board[1][2]);
    S(board[2][0], board[2][1], board[2][2]);

    S(board[0][0], board[1][0], board[2][0]);
    S(board[0][1], board[1][1], board[2][1]);
    S(board[0][2], board[1][2], board[2][2]);

    S(board[0][0], board[1][1], board[2][2]);
    S(board[0][2], board[1][1], board[2][0]);

    return v;
}
int main()
{
    for (int i = 0; i < 3; i++)
        cin >> board[i];

    int x = 0, o = 0, e = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            (board[i][j] == '0' ? o : (board[i][j] == 'X' ? x : e))++;
    int xw = win('X'), ow = win('0');

    if ((xw && ow) || (x - o != 0 && x - o != 1) || (ow && x > o) || (xw && x == o))
        cout << "illegal" << endl;
    else if (xw)
        cout << "the first player won" << endl;
    else if (ow)
        cout << "the second player won" << endl;
    else if (!e)
        cout << "draw" << endl;
    else if (x == o)
        cout << "first" << endl;
    else
        cout << "second" << endl;

    return 0;
}
