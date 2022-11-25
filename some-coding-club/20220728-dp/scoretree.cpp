// https://www.luogu.com.cn/problem/P1040
// Luogu P1040 [NOIP2003 提高组] 加分二叉树

#include <bits/stdc++.h>

using namespace std;

const int maxn = 33;

unsigned int d[maxn];
unsigned int dp[maxn][maxn];
int cut[maxn][maxn];

void dfs(int l, int r)
{
    if (l == r)
        return;
    if (l == r - 1)
    {
        cout << l << " ";
        return;
    }
    cout << cut[l][r] << " ";
    dfs(l, cut[l][r]);
    dfs(cut[l][r] + 1, r);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i], dp[i][i + 1] = d[i];

    for (int len = 2; len <= n; len++)
        for (int l = 1, r = 1 + len; r <= n + 1; l++, r++)
            for (int k = l, v = (k == l ? 1 : dp[l][k]) * (k == r - 1 ? 1 : dp[k + 1][r]) + d[k]; k < r; k++, v = (k == l ? 1 : dp[l][k]) * (k == r - 1 ? 1 : dp[k + 1][r]) + d[k])
                if (v > dp[l][r])
                    dp[l][r] = v, cut[l][r] = k;

    cout << dp[1][n + 1] << endl;
    dfs(1, n + 1);
    cout << endl;

    return 0;
}
