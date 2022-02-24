// https://codeforces.com/problemset/problem/451/E

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

ll inv[25];
ll f[25];

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

// n!/(n-m)!m! = n(n-1)(n-2)...(n-m+1)/m!
ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    ll ans = 1;
    for (ll i = 1; i <= m; i++)
        ans = ans * ((n - m + i) % mod) % mod * inv[i] % mod;
    return ans;
}

int main()
{
    inv[0] = 1;
    for (int i = 1; i <= 22; i++)
        inv[i] = finv(i);

    ll n;
    ll s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> f[i];

    ll ans = 0;
    for (int t = 0; t < (1 << n); t++)
    {
        int c = 0;
        // for each i of s, a[i]>f[i]
        // a[1]+a[2]+...+a[n]=s  {a[i] \memberof N}
        // thus a[i]+a[2]+...+a[n]=s-|t|(f[i]+1)+n
        // C(s-|t|(f[i]+1)+n-1,n-1)
        ll N = s + n - 1;
        for (int i = 0; i < n; i++)
        {
            if (t & (1 << i))
            {
                c++;
                N -= f[i] + 1;
            }
        }
        ans = ((ans + (c % 2 ? -1 : 1) * C(N, n - 1)) % mod + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
