// https://codeforces.com/problemset/problem/1307/D
// Codeforces Contest #1307 D. Cow and Fields
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int n, m, k;
int a[maxn];
// dijkstra
vector<int> con[maxn];
unsigned int dist1[maxn], distn[maxn];
pair<unsigned int, int> d1a[maxn], dna[maxn];
bool vis[maxn];
void dijkstra(int start, unsigned int *dist)
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dist[i] = 3e9;
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int now = pq.top().second;
        pq.pop();
        if (vis[now])
            continue;
        vis[now] = true;
        for (int v : con[now])
        {
            unsigned int d = dist[now] + 1;
            if (dist[v] > d)
            {
                dist[v] = d;
                pq.push(make_pair(d, v));
            }
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        con[x].push_back(y);
        con[y].push_back(x);
    }

    dijkstra(1, dist1);
    dijkstra(n, distn);

    sort(a + 1, a + 1 + n, [](int i, int j)
         { return dist1[i] < dist1[j]; });
    int ans = 0;
    for (int i = 1; i < k; i++)
    {
        int x = a[i], y = a[i + 1];
        int d = min(dist1[x] + distn[y], dist1[y] + distn[x]) + 1;
        if (d > dist1[n])
            d = dist1[n];
        ans = max(ans, d);
    }

    return 0;
}
