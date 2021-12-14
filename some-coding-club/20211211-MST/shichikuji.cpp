// https://codeforces.com/contest/1245/problem/D

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 3;
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

struct edge
{
    int x, y;
    long long w;
    bool operator<(const edge &e) { return w < e.w; }
} edg[maxn * maxn + maxn];
int ei;
bool a[maxn][maxn];
pair<int, int> pos[maxn];
int k[maxn];
int use[maxn], pl[maxn], con[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> pos[i].first >> pos[i].second;
    for (int i = 1; i <= n; i++)
    {
        edg[ei].x = 0;
        edg[ei].y = i;
        cin >> edg[ei++].w;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j < i; j++)
        {
            edg[ei].x = i;
            edg[ei].y = j;
            edg[ei++].w = (long long)(k[i] + k[j]) * (abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second));
        }
    }

    sort(edg, edg + ei);

    unsigned long long yen = 0;
    int f = 0;
    for (int i = 0; i < ei; i++)
    {
        edge &e = edg[i];
        int x = find(e.x), y = find(e.y);
        if (x == y)
            continue;
        merge(x, y);
        yen += e.w;
        use[f++] = i;
    }

    cout << yen << "\n";
    int v = 0, w = 0;
    for (int i = 0; i < f; i++)
    {
        if (edg[use[i]].x == 0)
            pl[v++] = use[i];
        else
            con[w++] = use[i];
    }
    cout << v << "\n";
    for (int i = 0; i < v; i++)
        cout << edg[pl[i]].y << (i == v - 1 ? "\n" : " ");
    cout << w << "\n";
    for (int i = 0; i < w; i++)
        cout << edg[con[i]].x << " " << edg[con[i]].y << "\n";
    return 0;
}
