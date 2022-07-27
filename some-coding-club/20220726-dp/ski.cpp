// https://www.luogu.com.cn/problem/P1434
// Luogu P1434 [SHOI2002] 滑雪

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100 + 7;

int a[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    int r, c;
    cin >> r >> c;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> a[i][j], pq.push({a[i][j], {i, j}});

    int ans = 0;

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int h = p.first;
        int i = p.second.first, j = p.second.second;
        int &v = dp[i][j];
        if (j > 1 && h > a[i][j - 1])
            v = max(v, dp[i][j - 1]);
        if (j < c && h > a[i][j + 1])
            v = max(v, dp[i][j + 1]);
        if (i > 1 && h > a[i - 1][j])
            v = max(v, dp[i - 1][j]);
        if (i < r && h > a[i + 1][j])
            v = max(v, dp[i + 1][j]);
        v++;
        ans = max(ans, v);
    }

    cout << ans << endl;
    return 0;
}
