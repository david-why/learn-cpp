// https://codeforces.com/problemset/problem/1633/D
// Codeforces Contest #1633 D. Make Them Equal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5, maxk = 12 * maxn + 5;
int a[maxn], b[maxn], c[maxn], d[maxn];
ll dp[maxk][maxn];
int main()
{
    int t;
    cin >> t;

    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    pair<int, int> p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int x = 1; x <= p.first; x++)
        {
            int y = p.first + p.first / x;
            if (y >= maxn || d[y])
                continue;
            d[y] = p.second + 1;
            q.push(make_pair(y, p.second + 1));
        }
    }

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        for (int i = 1; i <= n; i++)
            a[i] = 1;

        if (k >= 12 * n)
        {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                ans += c[i];
            cout << ans << endl;
        }
        else
        {
            for (int i = 0; i <= k; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dp[i][j] = dp[i][j - 1];
                    if (i >= d[b[j]])
                        dp[i][j] = max(dp[i][j], dp[i - d[b[j]]][j - 1] + c[j]);
                }
            }
            cout << dp[k][n] << endl;
        }
    }

    return 0;
}
