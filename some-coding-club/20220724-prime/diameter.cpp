#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;

unordered_map<int, int> con[maxn];

int dis[maxn], dep[maxn], jmp[maxn][20];

void dfs(int i, int par)
{
    dep[i] = dep[par] + 1;
    jmp[i][0] = par;
    for (int j = 0; j < 20; j++)
        jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
    for (const pair<int, int> &p : con[i])
    {
        if (p.first == par)
            continue;
        dis[p.first] = dis[i] + p.second;
        dfs(p.first, i);
    }
}

int lca(int i, int j)
{
    if (dep[i] < dep[j])
        swap(i, j);
    for (int k = 19; k >= 0; k--)
        if (dep[jmp[i][k]] >= dep[j])
            i = jmp[i][k];
    for (int k = 19; k >= 0; k--)
        if (jmp[i][k] != jmp[j][k])
            i = jmp[i][k], j = jmp[j][k];
    return jmp[i][0];
}

int dist(int i, int j) { return dis[i] + dis[j] - 2 * dis[lca(i, j)]; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        con[x][y] = w;
    }
    dfs(1, 0);
    int p = 1;
    int m = -1, A, B;
    for (int i = 2; i <= n; i++)
    {
        int d = dist(i, p);
        if (d > m)
            m = d, A = i;
    }
    m = -1;
    for (int i = 1; i <= n; i++)
    {
        if (i == A)
            continue;
        int d = dist(A, i);
        if (d > m)
            m = d, B = i;
    }
    cout << A << " " << B << " " << m << "\n";
}
