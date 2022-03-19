// https://codeforces.com/contest/868/problem/F
// Codeforces Contest #868 F. Yet Another Minimization Problem
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5, maxk = 20 + 3;
ll dp[maxn][maxk];
int a[maxn];
ll cnt[maxn], val, L, R;
ll cost(int l, int r)
{
    while (R < r)
        val += cnt[a[++R]]++;
    while (L > l)
        val += cnt[a[L--]]++;
    while (R > r)
        val -= --cnt[a[R--]];
    while (L < l)
        val -= --cnt[a[++L]];
    return val;
}
void divide(int l, int r, int pl, int pr, int j)
{
    if (l > r)
        return;
    int v = (l + r) / 2, m = pl;
    for (int i = pl; i <= pr; i++)
    {
        ll c = cost(i, v) + dp[i][j - 1];
        if (c < dp[v][j])
            dp[v][j] = c, m = i;
    }
    divide(l, v - 1, pl, m, j);
    divide(v + 1, r, m, pr, j);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 1LL << 60;
    dp[0][0] = 0;
    for (int j = 1; j <= k; j++)
    {
        memset(cnt, 0, sizeof(cnt));
        val = 0;
        L = R = 1;
        divide(1, n, 0, n - 1, j);
    }
    cout << dp[n][k] << endl;

    return 0;
}
