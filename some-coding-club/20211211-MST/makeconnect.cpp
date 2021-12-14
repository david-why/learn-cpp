// https://codeforces.com/contest/1095/problem/F

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2e5 + 3;

ll A[maxn];
struct edge
{
    int x, y;
    ll w;
    bool operator<(const edge &e) { return w < e.w; }
} M[maxn], edg[maxn + maxn];
int ei;

int par[maxn];
int find(int i)
{
    return par[i] == i ? i : (par[i] = find(par[i]));
}
void merge(int i, int j)
{
    par[find(i)] = find(j);
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll mx = LLONG_MAX;
    int x;
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (A[i] < mx)
        {
            mx = A[i];
            x = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != x)
        {
            edg[ei].x = x;
            edg[ei].y = i;
            edg[ei++].w = A[i] + mx;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> edg[ei].x >> edg[ei].y >> edg[ei].w;
        ei++;
    }

    sort(edg, edg + ei);

    int f = 0;
    ll ans = 0;
    for (int i = 0; i < ei && f != n - 1; i++)
    {
        edge &e = edg[i];
        int x = find(e.x), y = find(e.y);
        if (x == y)
            continue;
        ans += e.w;
        f++;
        merge(x, y);
    }

    cout << ans << endl;
    return 0;
}
