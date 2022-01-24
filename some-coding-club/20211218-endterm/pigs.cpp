// https://www.luogu.com.cn/problem/CF1548C?contestId=58741

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 3, MOD = 1e9 + 7;

ll fac[maxn * 3], inv[maxn * 3];

ll exgcd(ll a, ll b, ll &x, ll &y) // ax+by=gcd(a,b), find x,y
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll finv(ll i) // inv(x) * x % MOD = 1
{
    ll x, y;
    exgcd(i, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}
ll C(int n, int m)
{
    if (m > n)
        return 0;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 3 * n; i++)
        fac[i] = fac[i - 1] * i % MOD;
    for (int i = 1; i <= 3 * n; i++)
        inv[i] = inv[i - 1] * finv(i) % MOD;
    for (; q; q--)
    {
        int x;
        scanf("%d", &x);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + C(3 * i, x) % MOD) % MOD;
        cout << ans << endl;
    }
}
