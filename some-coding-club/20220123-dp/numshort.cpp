// https://atcoder.jp/contests/abc211/tasks/abc211_d
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 2e5 + 5;
void add(ll &a, ll b) { a = (a + b) % mod; }

vector<int> v[maxn];
ll dp[maxn];
int dis[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    dp[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : v[x])
        {
            if (dis[y] == -1)
            {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
            else if (dis[y] == dis[x] - 1)
            {
                add(dp[x], dp[y]);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
