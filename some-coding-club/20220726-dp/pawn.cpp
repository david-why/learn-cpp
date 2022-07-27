// https://www.luogu.com.cn/problem/P1002
// Luogu P1002 [NOIP2002 普及组] 过河卒

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 50;

ll dp[maxn][maxn];
bool ctl[maxn][maxn];

const int mx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int my[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    n++, m++, x++, y++;
    ctl[x][y] = true;
    for (int i = 0; i < 8; i++)
        if (x + mx[i] > 0 && y + my[i] > 0)
            ctl[x + mx[i]][y + my[i]] = true;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1 + (i == 1); j <= m; j++)
            dp[i][j] = ctl[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
    cout << dp[n][m] << endl;
}
