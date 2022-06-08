// https://www.luogu.com.cn/problem/P1006
// Luogu P1006 [NOIP2008 提高组] 传纸条
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
const int maxn = 50 + 7, mod = 1e9 + 7;
const int maxp = 2 * maxn * maxn + 10;
const int S = maxp - 2, D = maxp - 1;
int par[maxp], dis[maxp];
map<int, map<int, vector<pair<int, int>>>> gr;
bitset<maxp> inq;
void spfa(int source)
{
    queue<int> q;
    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    dis[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        inq[c] = false;
        for (auto &d : gr[c])
        {
            for (auto &x : d.second)
            {
                if (dis[c] + x.first > dis[d.first] && x.second)
                {
                    dis[d.first] = dis[c] + x.first;
                    par[d.first] = c;
                    if (!inq[d.first])
                        q.push(d.first), inq[d.first] = true;
                    break;
                }
            }
        }
    }
}
void dfs(int i)
{
    int p = par[i];
    if (p == -1)
        return;
    for (auto &x : gr[p][i])
    {
        if (!x.second)
            continue;
        x.second--;
        for (auto &y : gr[i][p])
            if (y.first == -x.first)
            {
                y.second++;
                break;
            }
        break;
    }
    dfs(p);
}
int main()
{
    int m, n;
    cin >> m >> n;
    const int t = m * n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            const int p = i * n + j;
            int a;
            cin >> a;
            if (j != n - 1)
                gr[p + t][p + 1].pb(mp(0, 2e9)),
                    gr[p + 1][p + t].pb(mp(0, 0));
            if (i != m - 1)
                gr[p + t][p + n].pb(mp(0, 2e9)),
                    gr[p + n][p + t].pb(mp(0, 0));
            gr[p][p + t].pb(mp(a, 1));
            gr[p + t][p].pb(mp(-a, 0));
            gr[p][p + t].pb(mp(0, 2e9));
            gr[p + t][p].pb(mp(0, 0));
        }

    gr[S][0].pb(mp(0, 2));
    gr[t - 1][D].pb(mp(0, 2e9));

    int ans = 0;
    while (dis[D] != -1)
    {
        spfa(S);
        ans += dis[D];
        dfs(D);
    }

    cout << ans + 1 << endl;

    return 0;
}
