// http://www.usaco.org/index.php?page=viewproblem2&cpid=646

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;
vector<int> con[maxn];
int seq[maxn], pos[maxn];
bool ans[maxn];

int par[maxn], gsize[maxn];
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
        gsize[b] += gsize[a];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
        pos[seq[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        gsize[i] = 1;
    }
    for (int i = n; i; i--)
    {
        int x = seq[i];
        for (int c : con[x])
        {
            if (pos[c] > i)
                merge(c, x);
        }
        ans[i] = gsize[root(x)] == n - i + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << (ans[i] ? "YES" : "NO") << endl;
    return 0;
}
