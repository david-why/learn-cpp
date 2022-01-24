// https://vjudge.net/contest/478114#problem/A
#include <bits/stdc++.h>

using namespace std;

const int maxn = 18 + 1;
typedef long long ll;
// dp[s]=possibility of s happening (1=dead,0=alive)
double dp[1 << 18];
double a[maxn][maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    dp[0] = 1;
    for (int s = 1; s < (1 << n); s++)
    {
        int x = __builtin_popcount(s);
        for (int j = 0; j < n; j++) // to be eaten
        {
            if (!(s & (1 << j)))
                continue;
            for (int k = 0; k < n; k++) // the mean eater
            {
                if (s & (1 << k))
                    continue;
                // select 2 fish from x+1 total, fixed order
                dp[s] += dp[s - (1 << j)] * a[k][j] / ((x + 1) * x / 2);
            }
        }
    }

    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++)
        cout << dp[(1 << n) - 1 - (1 << i)] << (i == n - 1 ? "\n" : " ");
    return 0;
}
