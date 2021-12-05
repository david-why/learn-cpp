// https://atcoder.jp/contests/abc154/tasks/abc154_f

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int exgcd(int a, int b, int &x, int &y) // ax+by=gcd(a,b), find x,y
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
int finv(int i) // inv(x) * x % MOD = 1
{
    int x, y;
    exgcd(i, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}
#define maxn 2000007
ll fac[maxn], inv[maxn];
ll C(int n, int m)
{
    if (m > n)
        return 0;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int main()
{
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int n = r2 + c2 + 1;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
    for (int i = 1; i <= n; i++)
        inv[i] = inv[i - 1] * finv(i) % MOD;
    int ans = 0;
    for (int i = r1; i <= r2; i++)
        ans = (ans - C(i + c1, i + 1) + C(i + c2 + 1, i + 1) + MOD) % MOD;
    cout << ans << endl;
    return 0;
}
