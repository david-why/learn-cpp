#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 105;

int dp[maxn][maxn], c[maxn], dep[maxn];
vector<tuple<int, int, int>> edg;
vector<int> con[maxn];

int n, q;

void init(int i, int p)
{
    dep[i] = dep[p] + 1;
    for (int j : con[i])
        if (j != p)
            init(j, i);
}

void dfs(int i, int p)
{
    for (int j : con[i])
        if (j != p)
            dfs(j, i);
    for (int j : con[i])
        if (j != p)
            for (int k = q; k >= 1; k--)
                for (int v = 0; v <= k - 1; v++)
                    dp[i][k] = max(dp[i][k], dp[i][k - v - 1] + dp[j][v] + c[j]);
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edg.push_back(make_tuple(x, y, w));
        con[x].push_back(y);
        con[y].push_back(x);
    }
    init(1, 0);
    for (auto &t : edg)
    {
        int x, y, w;
        tie(x, y, w) = t;
        if (dep[x] > dep[y])
            swap(x, y);
        c[y] = w;
    }
    // for (int i = 2; i <= n; i++) cout << c[i] << " "; cout << endl;
    dfs(1, 0);
    cout << dp[1][q] << endl;
    return 0;
}
