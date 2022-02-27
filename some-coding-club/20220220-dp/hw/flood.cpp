// https://codeforces.com/problemset/problem/1114/D
// Codeforces Contest #1114 D. Flood Fill
// Solution algorithm from editorial, https://codeforces.com/blog/entry/65136
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 3;
unsigned int dp[maxn][maxn][2];
int c[maxn];
void up(unsigned int &i, unsigned int x) { i = min(i, x); }
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i][0] = dp[i][i][1] = 0;

    for (int r = 1; r <= n; r++)
    {
        for (int l = n; l >= 1; l--)
        {
            if (l >= 1)
            {
                up(dp[l - 1][r][0], dp[l][r][0] + (c[l - 1] != c[l]));
                up(dp[l - 1][r][0], dp[l][r][1] + (c[l - 1] != c[r]));
            }
            if (r < n)
            {
                up(dp[l][r + 1][1], dp[l][r][0] + (c[r + 1] != c[l]));
                up(dp[l][r + 1][1], dp[l][r][1] + (c[r + 1] != c[r]));
            }
        }
    }

    cout << min(dp[1][n][0], dp[1][n][1]) << endl;

    return 0;
}
