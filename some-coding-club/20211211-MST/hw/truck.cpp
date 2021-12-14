// https://www.luogu.com.cn/problem/P1967

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 3, maxm = 5e4 + 3, maxq = 3e4 + 3;
unordered_set<int> qs[maxn];
int ans[maxq];

int par[maxn];
int find(int i)
{
    return par[i] == i ? i : (par[i] = find(par[i]));
}
void merge(int i, int j, int w)
{
    int x = find(i), y = find(j);
    if (qs[x].size() > qs[y].size())
        swap(x, y);
    unordered_set<int> &s1 = qs[x], &s2 = qs[y];
    for (unordered_set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        int v = *it;
        unordered_set<int>::iterator jt = s2.find(v);
        if (jt != s2.end())
        {
            ans[v] = w;
            s2.erase(jt);
        }
        else
        {
            s2.insert(v);
        }
    }
    s1.clear();
    par[x] = y;
}

int main()
{
    int n, m, q;
    scanf("%d%d", &n, &m);
    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        pq.push({w, x, y});
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        qs[x].insert(i);
        qs[y].insert(i);
        ans[i] = -1;
    }

    for (int i = 1; i <= n; i++)
        par[i] = i;

    int f = 0;
    while (f < n - 1 && !pq.empty())
    {
        int w, x, y;
        tie(w, x, y) = pq.top();
        pq.pop();
        x = find(x), y = find(y);
        if (x == y)
            continue;
        merge(x, y, w);
        f++;
    }

    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i]);

    return 0;
}
