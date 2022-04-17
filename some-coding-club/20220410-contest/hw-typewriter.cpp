// https://atcoder.jp/contests/abc246/tasks/abc246_f
// AtCoder ABC246 F typewriter
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 18, maxl = 1e9 + 7, mod = 998244353;
char buf[32];
int s[maxn];
ll qpow(ll a, ll b)
{
    ll ans = 1LL;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main()
{
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> buf;
        int x = strlen(buf);
        for (int j = 0; j < x; j++)
            s[i] |= 1 << (buf[j] - 'a');
    }

    ll ans = 0;
    for (int t = 1; t < (1 << n); t++)
    {
        int cnt = __builtin_popcount(t);
        int v = (1 << 26) - 1;
        for (int i = 0; i < n; i++)
            if (t & (1 << i))
                v &= s[i + 1];
        int c = __builtin_popcount(v);
        ans = (ans + (cnt % 2 ? 1 : -1) * qpow(c, l) + mod) % mod;
    }

    cout << ans << endl;

    return 0;
}
