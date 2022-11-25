// https://codeforces.com/contest/1679/problem/D
// Codeforces Contest #1679 D. Toss a Coin to Your Graph...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int n, m, a[maxn], b[maxn];
vector<int> con[maxn];
bool vis[maxn];
ll k;
// starting from i, max a[i]<=v, k steps, is it possible?
bool dfs(int v, int i, ll k, int s)
{
    if (k == 0)
        return true;
    if (vis[i])
        return true;
    if (i < s)
        return false;
    vis[i] = true;
    bool ret = false;
    for (int j : con[i])
    {
        if (a[j] > v)
            continue;
        if (dfs(v, j, k - 1, s))
        {
            ret = true;
            goto end;
        }
    }
end:
    vis[i] = false;
    return ret;
}
bool check(int v)
{
    for (int i = 1; i <= n; i++)
        if (a[i] <= v && dfs(v, i, k - 1, i))
            return true;
    return false;
}
int main()
{
    scanf("%d%d%lld", &n, &m, &k);
    int mi = 2e9;
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), b[i] = a[i], mi = min(mi, a[i]);
    if (k == 1)
    {
        cout << mi << endl;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        con[x].push_back(y);
    }

    sort(b + 1, b + n + 1);

    int l = 1, r = n;
    int ans = 1e9;
    while (l <= r)
    {
        int x = (r - l) / 2 + l, mid = b[x];
        if (check(mid))
        {
            ans = mid;
            r = x - 1;
        }
        else
            l = x + 1;
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;

    return 0;
}
