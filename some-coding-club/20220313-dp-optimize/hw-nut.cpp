// https://codeforces.com/problemset/problem/1083/E
// Codeforces Contest #1083 E. The Fair Nut and Rectangles
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
ll dp[maxn];
ll slope[maxn], sect[maxn];
struct rect
{
    ll x, y, a;
    bool operator<(const rect &v) { return x < v.x; }
} p[maxn];
int st[maxn];
int sts;
int ptr;
double cross(int i, int j) { return (double)(sect[i] - sect[j]) / (slope[j] - slope[i]); }
void add(int i)
{
    while (ptr + 1 < sts && cross(st[sts - 1], st[sts - 2]) < cross(st[sts - 2], i))
        sts--;
    st[sts++] = i;
}
ll calc(int i, ll x) { return slope[i] * x + sect[i]; }
int find(ll x)
{
    int c = 0;
    for (int k = 20; k >= 0; k--)
    {
        if (c + (1 << k) < sts)
        {
            int t = c + (1 << k);
            if (cross(st[t - 1], st[t]) > x)
                c = t;
        }
    }
    // return c;  FUCK ME
    return st[c];
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].a);
    sort(p + 1, p + 1 + n);

    add(0);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int lin = find(p[i].y);
        dp[i] = dp[lin] + p[i].y * (p[i].x - p[lin].x) - p[i].a;
        slope[i] = -p[i].x;
        sect[i] = dp[i];
        add(i);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
