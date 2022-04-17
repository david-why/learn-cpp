// https://atcoder.jp/contests/abc247/tasks/abc247_f
// AtCoder ABC247 F Cards
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7, mod = 998244353;
void add(ll &a, ll b) { a = (a + b) % mod; }
ll dp[maxn];
bool v[maxn];
pair<int, int> c[maxn];
ll calc(int i)
{
    if (i == 1)
        return 1;
    if (i == 2)
        return 3;
    return (dp[i - 1] + dp[i - 3]) % mod;
}
int main()
{
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i].first);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i].second);

    sort(c + 1, c + 1 + n);

    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i])
            continue;
        int len = 0;
        int cur = i;
        while (!v[cur])
            v[cur] = true, cur = c[cur].second, len++;
        ans = ans * calc(len) % mod;
    }

    cout << ans << endl;

    return 0;
}
