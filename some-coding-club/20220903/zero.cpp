// https://codeforces.com/contest/1695/problem/C
// Codeforces Contest #1695 C. Zero Path
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 3;
bitset<maxn * 2 + 2> dp[maxn][2];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ------
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= 1; j++)
                dp[i][j].reset();
        dp[1][0][maxn] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                int a;
                cin >> a;
                dp[j][i % 2] = (a == 1 ? (dp[j - 1][i % 2] >> 1) : (dp[j - 1][i % 2] << 1)) |
                               (a == 1 ? (dp[j][(i + 1) % 2] >> 1) : (dp[j][(i + 1) % 2] << 1));
            }
        cout << (dp[m][n % 2][maxn] ? "YES" : "NO") << "\n";
    }

    return 0;
}
