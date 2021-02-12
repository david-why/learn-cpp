#include <iostream>
#include <cstring>

using namespace std;

bool canPlace[8][8] = {
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true}};
int places[8];
int ans = 0;

void queens(int row)
{
    if (row == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int index = 0; index < 8; index++)
            {
                if (places[i] != index)
                    cout << ". ";
                else
                    cout << "Q ";
            }
            cout << "\n";
        }
        cout << "\n";
        ans++;
        return;
    }
    for (int column = 0; column < 8; column++)
    {
        if (canPlace[row][column])
        {
            bool before[8][8];
            memcpy(before, canPlace, 64);
            for (int r = 0; r < 8; r++)
            {
                canPlace[r][column] = false;
            }
            for (int c = 0; c < 8; c++)
            {
                canPlace[row][c] = false;
            }
            for (int r = row, c = column; r < 8 && c < 8; r++, c++)
            {
                canPlace[r][c] = false;
            }
            for (int r = row, c = column; r >= 0 && c < 8; r--, c++)
            {
                canPlace[r][c] = false;
            }
            for (int r = row, c = column; r < 8 && c >= 0; r++, c--)
            {
                canPlace[r][c] = false;
            }
            for (int r = row, c = column; r >= 0 && c >= 0; r--, c--)
            {
                canPlace[r][c] = false;
            }
            places[row] = column;
            queens(row + 1);
            memcpy(canPlace, before, 64);
        }
    }
}

int main()
{
    queens(0);
    cout << ans << endl;
    return 0;
}
