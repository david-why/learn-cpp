// https://atcoder.jp/contests/abc211/tasks/abc211_d
// AtCoder ABC211 D Number of Shortest paths
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5, mod = 1e9 + 7;
set<int> roads[maxn];
ll dp[maxn];
void add(ll &x, ll i) { x = (x + i) % mod; }
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        roads[x].insert(y);
        roads[y].insert(x);
    }
    vector<int> v;
    set<int> s;
    v.push_back(1);
    dp[1] = 1;
    while (!v.empty())
    {
        s.clear();
        for (int i : v)
        {
            for (int j : roads[i])
            {
                if (dp[j] == 0 || s.find(j) != s.end())
                {
                    add(dp[j], dp[i]);
                    s.insert(j);
                }
            }
        }
        v.assign(s.begin(), s.end());
    }
    cout << dp[n] << endl;
    return 0;
}
