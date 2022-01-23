#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int dp[(1 << maxn) + 5][maxn + 5];
unordered_map<int, int> con[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        con[x][y] = w;
        con[y][x] = w;
    }

    for (int s = 0; s < (1 << n); s++)
        for (int i = 0; i < n; i++)
            dp[s][i] = INT_MAX;
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 0;
    for (int s = 0; s < (1 << n); s++)
    {
        for (int i = 0; i < n; i++)
        {
            if (dp[s][i] == INT_MAX)
                continue;
            for (auto &p : con[i])
            {
                if (s & (1 << p.first))
                    continue;
                if (dp[s | (1 << p.first)][p.first] > dp[s][i] + p.second)
                    dp[s | (1 << p.first)][p.first] = dp[s][i] + p.second;
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i]);
    cout << ans << endl;
    return 0;
}
