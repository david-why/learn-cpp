// https://www.luogu.com.cn/problem/P3366

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;
int par[maxn];

int find(int i)
{
    return par[i] == i ? i : (par[i] = find(par[i]));
}
void merge(int i, int j)
{
    int x = find(i), y = find(j);
    par[x] = y;
}

struct edge
{
    int x, y, z;
    bool operator<(const struct edge &o) { return z < o.z; }
} edg[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < maxn; i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
        cin >> edg[i].x >> edg[i].y >> edg[i].z;

    sort(edg, edg + m);

    int f = 0, ans = 0;
    for (int i = 0; i < m && f != n - 1; i++)
    {
        edge &e = edg[i];
        int x = find(e.x), y = find(e.y);
        if (x == y)
            continue;
        ans += e.z;
        f++;
        merge(x, y);
    }
    if (f == n - 1)
        cout << ans << endl;
    else
        cout << "orz" << endl;
    return 0;
}
