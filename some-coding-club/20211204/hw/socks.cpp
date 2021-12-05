// https://codeforces.com/problemset/problem/731/C

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;
int par[maxn], cols[maxn], siz[maxn], tmp[maxn];
unordered_map<int, pair<int, map<int, int>>> mcol;
int root(int i)
{
    return par[i] == i ? i : (par[i] = root(par[i]));
}
void merge(int i, int j)
{
    int a = root(i), b = root(j);
    if (a != b)
    {
        par[a] = b;
        siz[b] += siz[a];
    }
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", cols + i);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        merge(x, y);
    }
    for (int i = 1; i <= n; i++)
        par[i] = root(i);
    for (int i = 1; i <= n; i++)
    {
        int g = par[i];
        auto &p = mcol[g];
        p.first = max(p.first, ++p.second[cols[i]]);
    }
    int ans = 0;
    for (auto &p : mcol)
    {
        ans += siz[p.first] - p.second.first;
    }
    cout << ans << endl;
    return 0;
}
