// https://www.luogu.com.cn/problem/P1063
// Luogu [NOIP2006 提高组] 能量项链

#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;

int dp[maxn * 2][maxn * 2];
int a[maxn * 2];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i];

    for (int len = 2; len <= n; len++)
        for (int l = 1, r = l + len; r <= n + n; l++, r++)
            for (int k = l + 1; k < r; k++)
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);

    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][i + n]);
    cout << ans << endl;
    return 0;
}
