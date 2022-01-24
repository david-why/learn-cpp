// https://www.luogu.com.cn/problem/P1653?contestId=58741

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 3, maxm = 400000 + 3;
int par[maxn];
unordered_set<int> gr[maxn];
int find(int i) { return par[i] == i ? i : (par[i] = find(par[i])); }
void merge(int i, int j, bool b = false)
{
    int x = find(i), y = find(j);
    if (x != y)
    {
        par[x] = y;
        if (!b)
        {
            gr[y].insert(gr[x].begin(), gr[x].end());
            gr[x].clear();
        }
    }
}

struct
{
    int to;
    bool rel;
} hold[maxn][2];
int ord[maxm][2];
int ans[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        gr[i].insert(i);
        cin >> hold[i][0].to >> hold[i][1].to;
        hold[i][0].rel = false;
        hold[i][1].rel = false;
        ans[i] = -1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ord[i][0] >> ord[i][1];
        ord[i][1]--;
        hold[ord[i][0]][ord[i][1]].rel = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!hold[i][0].rel && hold[i][0].to != -1)
            merge(i, hold[i][0].to);
        if (!hold[i][1].rel && hold[i][1].to != -1)
            merge(i, hold[i][1].to);
    }

    for (int i = m; i >= 1; i--)
    {
        int x = ord[i][0], h = ord[i][1], y = hold[x][h].to;
        int p = find(x), q = find(y);
        int one = find(1);
        if (p == q)
            continue;
        if (p == one)
            for (int j : gr[q])
                ans[j] = i - 1;
        if (q == one)
            for (int j : gr[p])
                ans[j] = i - 1;
        merge(p, q, p == one || q == one);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}
