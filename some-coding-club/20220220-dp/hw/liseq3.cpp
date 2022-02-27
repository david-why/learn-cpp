// https://atcoder.jp/contests/abc237/tasks/abc237_f
// AtCoder ABC237 F |LIS| = 3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5, maxm = 10 + 3, mod = 998244353;
void add(ll &a, ll b) { a = (a + b) % mod; }
// dp[i][x][y][z]: i elements, len=1 minv=x, len=2 minv=y, len=3 minv=z, ans
ll dp[maxn][maxm][maxm][maxm];
int main()
{
    int n, m;
    cin >> n >> m;

    dp[0][m + 1][m + 1][m + 1] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a <= m + 1; a++)
        {
            for (int b = a; b <= m + 1; b++)
            {
                for (int c = b; c <= m + 1; c++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        int nx = a, ny = b, nz = c;
                        if (j <= a)
                            nx = j;
                        else if (j <= b)
                            ny = j;
                        else if (j <= c)
                            nz = j;
                        else
                            continue;
                        add(dp[i + 1][nx][ny][nz], dp[i][a][b][c]);
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int x = 1; x <= m; x++)
        for (int y = x + 1; y <= m; y++)
            for (int z = y + 1; z <= m; z++)
                add(ans, dp[n][x][y][z]);
    cout << ans << endl;

    return 0;
}
