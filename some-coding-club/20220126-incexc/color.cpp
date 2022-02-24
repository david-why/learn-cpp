// https://atcoder.jp/contests/abc235/tasks/abc235_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxk = 1e6 + 5;
ll inv[maxk], fac[maxk];
ll qpow(ll i, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
            ans = ans * i % mod;
        i = i * i % mod;
        p >>= 1;
    }
    return ans;
}
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
ll finv(ll i)
{
    ll x, y;
    exgcd(i, mod, x, y);
    return (x % mod + mod) % mod;
}
ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
ll C2(ll n, ll m)
{
    if (n < m)
        return 0;
    ll ans = 1;
    for (ll i = 1; i <= m; i++)
        ans = ans * ((n - m + i) % mod) % mod;
    return ans * inv[m] % mod;
}
int main()
{
    inv[0] = fac[0] = 1;
    for (int i = 1; i < maxk; i++)
    {
        inv[i] = inv[i - 1] * finv(i) % mod;
        fac[i] = fac[i - 1] * i % mod;
    }
    int T;
    cin >> T;
    for (int tst = 1; tst <= T; tst++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        // no need to consider m since k is # of colors
        // A[i]: use color #i
        // if use k colors, ans=m(m-1)^(n-1)
        // ans=(m-|s|)(m-|s|-1)^(n-1)
        ll ans = 0;
        for (int i = 0; i <= k; i++)
            ans = (ans + C(k, i) * (i % 2 ? -1 : 1) * (k - i) % mod * qpow(k - i - 1, n - 1) % mod) % mod;
        cout << "Case #" << tst << ": " << (ans * C2(m, k) % mod + mod) % mod << endl;
    }
    return 0;
}
