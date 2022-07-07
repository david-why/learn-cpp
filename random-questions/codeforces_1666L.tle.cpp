// https://codeforces.com/contest/1666/problem/L
// Codeforces Contest #1666 L. Labyrinth
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int par[maxn], flow[maxn];
bool vis[maxn];
int n;
vector<int> con[maxn];
unordered_map<int, unordered_map<int, int>> cap;
unordered_map<int, unordered_map<int, int>> cc;
int gc(int i, int j)
{
    auto it = cap.find(i);
    if (it == cap.end())
        return 0;
    auto jt = it->second.find(j);
    if (jt == it->second.end())
        return 0;
    return jt->second;
}
int doflow(int s, int t)
{
    memset(par, -1, sizeof(par));
    memset(flow, 0, sizeof(flow));
    memset(vis, 0, sizeof(vis));
    flow[s] = 2e9;
    while (true)
    {
        int cur = -1, m = 0;
        for (int i = 1; i <= n; i++)
            if (flow[i] > m && !vis[i])
                m = flow[i], cur = i;
        // cout << "- " << cur << "(" << m << ")" << endl;
        if (m == 0 || cur == -1)
            break;
        vis[cur] = true;
        for (pair<const int, int> &p : cap[cur])
        {
            int nxt = p.first;
            int f = min(flow[cur], p.second);
            if (flow[nxt] < f)
                // cout << "  > upd " << nxt << " from " << cur << " val " << f << endl,
                par[nxt] = cur, flow[nxt] = f;
        }
    }
    return flow[t];
}
vector<int> path[2];
void dfs(int s, int t, int f, int p)
{
    path[p].clear();
    path[p].push_back(t);
    while (t != s)
    {
        cap[par[t]][t] -= f;
        cap[t][par[t]] += f;
        t = par[t];
        path[p].push_back(t);
    }
    reverse(path[p].begin(), path[p].end());
}
int main()
{
    int m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cc[x][y]++;
    }

    bool ok = false;
    for (int t = 1; t <= n; t++)
    {
        if (s == t)
            continue;
        // cout<<"SINK: "<<t<<endl;
        cap = cc;
        int c1 = doflow(s, t);
        if (!c1)
            continue;
        dfs(s, t, c1, 0);
        int c2 = doflow(s, t);
        if (!c2)
            continue;
        dfs(s, t, c2, 1);
        ok = true;
        break;
    }
    if (ok)
    {
        cout << "Possible\n"
             << path[0].size() << "\n";
        for (int i : path[0])
            cout << i << " ";
        cout << "\n"
             << path[1].size() << "\n";
        for (int i : path[1])
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "Impossible" << endl;

    return 0;
}
