#include <iostream>
#include <cstring>
#define QUEENS 8

using namespace std;

bool canPlace[QUEENS][QUEENS] /* = {
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true}}*/
    ;
int places[QUEENS];
int ans = 0;

void queens(int row)
{
    if (row == QUEENS)
    {
        /*
        for (int i = 0; i < QUEENS; i++)
        {
            for (int index = 0; index < QUEENS; index++)
            {
                if (places[i] != index)
                    cout << ". ";
                else
                    cout << "Q ";
            }
            cout << "\n";
        }
        cout << "\n";
        */
        ans++;
        return;
    }
    for (int column = 0; column < QUEENS; column++)
    {
        if (canPlace[row][column])
        {
            bool before[QUEENS][QUEENS];
            memcpy(before, canPlace, sizeof(bool) * QUEENS * QUEENS);
            for (int r = 0; r < QUEENS; r++)
            {
                canPlace[r][column] = false;
            }
            for (int c = 0; c < QUEENS; c++)
            {
                canPlace[row][c] = false;
            }
            for (int r = row, c = column; r < QUEENS && c < QUEENS; r++, c++)
            {
                canPlace[r][c] = false;
            }
            for (int r = row, c = column; r >= 0 && c < QUEENS; r--, c++)
            {
                canPlace[r][c] = false;
            }
            for (int r = row, c = column; r < QUEENS && c >= 0; r++, c--)
            {
                canPlace[r][c] = false;
            }
            for (int r = row, c = column; r >= 0 && c >= 0; r--, c--)
            {
                canPlace[r][c] = false;
            }
            places[row] = column;
            queens(row + 1);
            memcpy(canPlace, before, sizeof(bool) * QUEENS * QUEENS);
        }
    }
}

int main()
{
    for (int r = 0; r < QUEENS; r++)
        for (int c = 0; c < QUEENS; c++)
            canPlace[r][c] = true;
    queens(0);
    cout << ans << endl;
    return 0;
}
