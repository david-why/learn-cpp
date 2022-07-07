// https://codeforces.com/contest/1666/problem/L
// Codeforces Contest #1666 L. Labyrinth
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
bool vis[maxn];
int n, m, s;
int par[maxn], dep[maxn];
vector<int> con[maxn], rev[maxn];
void dfs(int v, int d)
{
    vis[v] = true;
    dep[v] = d;
    for (int x : con[v])
        if (!vis[x])
            par[x] = v, dfs(x, d + 1);
}
int sametree(int a, int b)
{
    if (a == s || b == s)
        return 1;
    while (dep[a] < dep[b])
        b = par[b];
    while (dep[a] > dep[b])
        a = par[a];
    while (true)
    {
        if (a == b)
            return dep[a];
        a = par[a], b = par[b];
    }
}
void output(int x, int t)
{
    vector<int> a;
    a.push_back(t);
    while (x != s)
        a.push_back(x), x = par[x];
    a.push_back(s);
    cout << a.size() << "\n";
    for (vector<int>::reverse_iterator it = a.rbegin(); it != a.rend(); it++)
        cout << *it << " ";
    cout << "\n";
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
        rev[y].push_back(x);
    }

    dfs(s, 0);

    for (int t = 1; t <= n; t++)
    {
        if (t == s || par[t] == 0)
            continue;
        int p = par[t];
        // if (p == s)
        //     continue;
        int f = 0;
        for (int x : rev[t])
        {
            if (x == p || !(x == s || par[x]))
                continue;
            if (!sametree(x, p) || (x == s && p != s) || (p == s && !sametree(x, t)))
            {
                f = x;
                break;
            }
        }
        // cout << "- " << t << " " << p << " " << f << " (" << par[f] << ")" << endl;
        if (f)
        {
            cout << "Possible\n";
            output(p, t);
            output(f, t);
            return 0;
        }
    }

    cout << "Impossible" << endl;
    return 0;
}
