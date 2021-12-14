// https://www.luogu.com.cn/problem/P4047

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 3;

int par[maxn];
int find(int i)
{
    return par[i] == i ? i : (par[i] = find(par[i]));
}
void merge(int i, int j)
{
    int x = find(i), y = find(j);
    par[x] = y;
}

pair<int, int> pos[maxn];
struct edge
{
    int x, y;
    double w;
    bool operator<(const edge &x) { return w < x.w; }
} edg[maxn * maxn / 2];
int ei;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        par[i] = i;
    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            edg[ei].x = i, edg[ei].y = j, edg[ei].w = sqrt((pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second)), ei++;
    sort(edg, edg + ei);
    int g = n, i;
    for (i = 0; g > k; i++)
    {
        int x = find(edg[i].x), y = find(edg[i].y);
        if (x == y)
            continue;
        merge(x, y);
        g--;
    }
    for (;; i++)
    {
        if (find(edg[i].x) != find(edg[i].y))
        {
            printf("%.2f\n", edg[i].w);
            return 0;
        }
    }
}
