// https://atcoder.jp/contests/abc172/tasks/abc172_e
// AtCoder ABC172 E NEQ
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 5e5 + 5;
ll inv[maxn], fac[maxn];
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
ll A(ll n, ll m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[n - m] % mod;
}
int main()
{
    int n, m;
    cin >> n >> m;
    inv[0] = fac[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        inv[i] = inv[i - 1] * finv(i) % mod;
        fac[i] = fac[i - 1] * i % mod;
    }
    // say A=1 2 ... n, permutation later
    // conditions: Ai!=Bi
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        // C(n,i): nums that are equal  (A=1..n)
        // A(m-i,n-i): perm of rest     (B=1..m)
        ans = ((ans + (i % 2 ? -1 : 1) * C(n, i) % mod * A(m - i, n - i) % mod) % mod + mod) % mod;
    }
    cout << ans * A(m, n) % mod << endl;
    return 0;
}
