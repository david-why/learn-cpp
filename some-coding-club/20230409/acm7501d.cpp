// https://www.luogu.com.cn/problem/P8435
#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 233;

vector<int> con[maxn];

int dfn[maxn], low[maxn], idx;
int ans[maxn];
void tarjan(int i, int p)
{
    dfn[i] = low[i] = ++idx;
    for (int j : con[i])
    {
        if (!dfn[j])
        {
            tarjan(j, i);
            low[i] = min(low[i], low[j]);
            if (low[j] >= dfn[i])
                ans[i]++;
        }
        else
            low[i] = min(low[i], dfn[j]);
    }
    if (p) ans[i]++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        con[u].push_back(v);
        con[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, 0), cnt++;
    for (int i = 1; i <= n; i++)
        cout << cnt + ans[i] - 1 << " ";
    cout << "\n";
    return 0;
}
