// https://www.luogu.com.cn/problem/P1122
// Luogu P1122 最大子树和

#include <bits/stdc++.h>

using namespace std;

const int maxn = 16000 + 7;

int dp[maxn];
int b[maxn];

vector<int> con[maxn];

void dfs(int v, int pr)
{
    dp[v] = b[v];
    for (int x : con[v])
    {
        if (x == pr)
            continue;
        dfs(x, v);
        if (dp[x] > 0)
            dp[v] += dp[x];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }

    dfs(1, 0);
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
