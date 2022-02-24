// https://codeforces.com/problemset/problem/1207/D
// Codeforces Contest #1207 D. Number Of Permutations
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5, mod = 998244353;
pair<int, int> nums[maxn];
#define A first
#define B second
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
int cnta[maxn], cntb[maxn];
map<pair<int, int>, int> cntab;
int main()
{
    int n;
    cin >> n;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod, inv[i] = inv[i - 1] * finv(i) % mod;
    for (int i = 1; i <= n; i++)
        cin >> nums[i].A >> nums[i].B;
    // ans=all-(sorted by a)-(sorted by b)+(sorted by both a and b)
    // all permutations=n!
    ll ans = fac[n];
    // sorted by a: 1 1 1 2 4 4 5 -> 3!2!
    for (int i = 1; i <= n; i++)
        cnta[nums[i].A]++;
    ll av = 1;
    for (int i = 1; i <= n; i++)
        if (cnta[i])
            av = av * fac[cnta[i]] % mod;
    ans = (ans - av + mod) % mod;
    // sorted by b: same as a
    for (int i = 1; i <= n; i++)
        cntb[nums[i].B]++;
    ll bv = 1;
    for (int i = 1; i <= n; i++)
        if (cntb[i])
            bv = bv * fac[cntb[i]] % mod;
    ans = (ans - bv + mod) % mod;
    // sorted by a and b: same as a
    // but... (3,1)(2,2)(1,3)?
    // sort and go thru first
    sort(nums + 1, nums + 1 + n);
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        if (nums[i].B > nums[i + 1].B)
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        for (int i = 1; i <= n; i++)
            cntab[nums[i]]++;
        ll abv = 1;
        for (auto &p : cntab)
            abv = abv * fac[p.second] % mod;
        ans = (ans + abv) % mod;
    }

    cout << ans << endl;

    return 0;
}
