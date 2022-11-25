#include <bits/stdc++.h>

using namespace std;
const int maxn = 2501;

typedef long long ll;

int n, m, k;
ll a[maxn];
vector<int> con[maxn];
int dis[maxn][maxn];
void bfs(int s, int dis[])
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
        if (i != s)
            dis[i] = 1e9;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for (int x : con[c])
            if (dis[x] > dis[c] + 1)
                dis[x] = dis[c] + 1, q.push(x);
    }
}

int mx[maxn][3];
int main()
{
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        bfs(i, dis[i]);
    for (int i = 2; i <= n; i++)
    {
        if (dis[1][i] > k + 1)
            continue;
        for (int j = 2; j <= n; j++)
        {
            if (i == j || dis[i][j] > k + 1)
                continue;
            vector<int> v{mx[j][0], mx[j][1], mx[j][2], i};
            sort(v.begin(), v.end(), [](int x, int y)
                 { return a[x] > a[y]; });
            memcpy(mx[j], v.data(), sizeof(int) * 3);
        }
    }

    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (dis[i][j] > k + 1)
                continue;
            for (int x : mx[i])
            {
                if (x == j || x == 0)
                    continue;
                for (int y : mx[j])
                {
                    if (y == x || y == i || y == 0)
                        continue;
                    ans = max(ans, a[i] + a[j] + a[x] + a[y]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
