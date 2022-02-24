// https://atcoder.jp/contests/abc154/tasks/abc154_f

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

// ax+by=gcd(a,b)
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
ll finv(ll a)
{
    ll x, y;
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

const int maxn = 2e6 + 5;
ll fac[maxn], inv[maxn];

ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    inv[0] = fac[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[i - 1] * finv(i) % mod;
    }

    ll ans = 0LL;
    for (int i = c1; i <= c2; i++)
        ans = (ans - C(r1 + i, i + 1) + C(r2 + i + 1, i + 1) + mod) % mod;

    cout << ans << endl;
    return 0;
}
