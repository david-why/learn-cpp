// http://codeforces.com/contest/1665/problem/D
// Codeforces Contest #1665 D. GCD Guess
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x = 0, j = 0;
        for (int i = 0; i < 30; i++)
        {
            cout << "? " << (1 << i) - x << " " << (1 << i) + (1 << (i + 1)) - x << endl;
            cin >> j;
            if (j & (1 << (i + 1)))
                x += 1 << i;
        }
        cout << "! " << x << endl;
    }

    return 0;
}
