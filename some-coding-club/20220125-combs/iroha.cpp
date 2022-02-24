// https://atcoder.jp/contests/arc058/tasks/arc058_b

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
    inv[0] = fac[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[i - 1] * finv(i) % mod;
    }

    int h, w, a, b;
    cin >> h >> w >> a >> b;

    ll ans = 0LL;
    for (int x = b + 1; x <= w; x++) // x-1 of right
        ans = (ans + C(x + h - a - 2, h - a - 1) * C(w + a - x - 1, a - 1) % mod) % mod;
    cout << ans << endl;
    return 0;
}
