// https://atcoder.jp/contests/abc215/tasks/abc215_e
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5, mod = 998244353;
int dp[maxn][10][(1 << 10) + 5];
char str[maxn];

void add(int &i, int j) { i = ((long long)i + j) % mod; }

int main()
{
    int n;
    cin >> n >> (str + 1);

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        int t = str[i + 1] - 'A';
        for (int j = 0; j < 10; j++)
        {
            for (int s = 0; s < (1 << 10); s++)
            {
                add(dp[i + 1][j][s], dp[i][j][s]);
                if (!(s & (1 << t)))
                    add(dp[i + 1][t][s | (1 << t)], dp[i][j][s]);
                else if (j == t)
                    add(dp[i + 1][j][s], dp[i][j][s]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
        for (int s = 1; s < (1 << 10); s++)
            add(ans,dp[n][i][s]);
    cout << ans << endl;
    return 0;
}
