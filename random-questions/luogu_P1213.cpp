// https://www.luogu.com.cn/problem/P1213
// Luogu P1213 [USACO1.4][IOI1994]时钟 The Clocks
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a1, a2, a3, a4, a5, a6, a7, a8, a9;
bool chk(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9)
{
    if ((a1 + 3 * (c1 + c2 + c4)) % 12 ||
        (a2 + 3 * (c1 + c2 + c3 + c5)) % 12 ||
        (a3 + 3 * (c2 + c3 + c6)) % 12 ||
        (a4 + 3 * (c1 + c4 + c5 + c7)) % 12 ||
        (a5 + 3 * (c1 + c3 + c5 + c7 + c9)) % 12 ||
        (a6 + 3 * (c3 + c5 + c6 + c9)) % 12 ||
        (a7 + 3 * (c4 + c7 + c8)) % 12 ||
        (a8 + 3 * (c5 + c7 + c8 + c9)) % 12 ||
        (a9 + 3 * (c6 + c8 + c9)) % 12)
        return false;
    for (int i = 0; i < c1; i++)
        cout << 1 << " ";
    for (int i = 0; i < c2; i++)
        cout << 2 << " ";
    for (int i = 0; i < c3; i++)
        cout << 3 << " ";
    for (int i = 0; i < c4; i++)
        cout << 4 << " ";
    for (int i = 0; i < c5; i++)
        cout << 5 << " ";
    for (int i = 0; i < c6; i++)
        cout << 6 << " ";
    for (int i = 0; i < c7; i++)
        cout << 7 << " ";
    for (int i = 0; i < c8; i++)
        cout << 8 << " ";
    for (int i = 0; i < c9; i++)
        cout << 9 << " ";
    cout << endl;
    return true;
}
int main()
{
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;
    for (int c1 = 0; c1 < 4; c1++)
        for (int c2 = 0; c2 < 4; c2++)
            for (int c3 = 0; c3 < 4; c3++)
                for (int c4 = 0; c4 < 4; c4++)
                    for (int c5 = 0; c5 < 4; c5++)
                        for (int c6 = 0; c6 < 4; c6++)
                            for (int c7 = 0; c7 < 4; c7++)
                                for (int c8 = 0; c8 < 4; c8++)
                                    for (int c9 = 0; c9 < 4; c9++)
                                        if (chk(c1, c2, c3, c4, c5, c6, c7, c8, c9))
                                            return 0;

    return 0;
}
