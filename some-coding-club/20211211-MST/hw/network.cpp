// https://www.luogu.com.cn/problem/P2820

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 3;

int par[maxn];
int find(int i) { return par[i] == i ? i : (par[i] = find(par[i])); }
void merge(int i, int j) { par[find(i)] = find(j); }

struct edge
{
    int x, y, w;
    bool operator<(const edge &e) { return w < e.w; }
} edg[maxn * maxn];

int main()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> edg[i].x >> edg[i].y >> edg[i].w;
        sum += edg[i].w;
    }

    sort(edg, edg + k);

    for (int i = 0; i < n; i++)
        par[i] = i;
    for (int i = 0; i < k; i++)
    {
        edge &e = edg[i];
        int x = find(e.x), y = find(e.y);
        if (x == y)
            continue;
        merge(x, y);
        sum -= e.w;
    }

    cout << sum << endl;
    return 0;
}
