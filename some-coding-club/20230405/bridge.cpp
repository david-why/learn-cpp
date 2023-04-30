#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;

unordered_map<int, int> con[maxn];

int dfn[maxn], low[maxn], idx;
int ans;
void tarjan(int i, int p)
{
    dfn[i] = low[i] = ++idx;
    for (auto &pr : con[i])
    {
        int j, w;
        j = pr.first;
        w = pr.second;
        if (!dfn[j])
        {
            tarjan(j, i);
            low[i] = min(low[i], low[j]);
            if (low[j] > dfn[i])
                ans = min(ans, w);
        }
        else if (j != p)
            low[i] = min(low[i], dfn[j]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        for (int i = 1; i <= n; i++)
            con[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            con[u][v] = con[v][u] = con[u][v] ? 1e6 : w;
        }
        idx = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        ans = 1e9;
        tarjan(1, 1);
        bool ok = true;
        for (int i = 2; i <= n; i++)
            if (!dfn[i])
                ok = false;
        if (ok)
            cout << (ans == 1e9 ? -1 : max(ans, 1)) << "\n";
        else
            cout << "0\n";
    }
}
