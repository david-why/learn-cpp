// https://codeforces.com/contest/597/problem/C
// Codeforces Contest #597 C. Subsequences
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 7, maxk = 10 + 2;
ll ch[maxn], n;
void add(ll x, ll v)
{
    for (ll i = x; i <= n; i += i & (-i))
        ch[i] += v;
}
ll query(ll x)
{
    ll s = 0;
    for (ll i = x; i; i -= i & (-i))
        s += ch[i];
    return s;
}
ll a[maxn];
// dp[i][j]=sum{k=0..i-1 and a[k]<a[i]}(dp[i][j-1])
ll dp[maxn][maxk];
int main()
{
    ll k;
    cin >> n >> k;
    k++;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], dp[i][1] = 1;

    for (ll j = 2; j <= k; j++)
    {
        memset(ch, 0, sizeof(ch));
        for (ll i = 1; i <= n; i++)
        {
            dp[i][j] = query(a[i] - 1);
            add(a[i], dp[i][j - 1]);
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += dp[i][k];
    cout << ans << endl;

    return 0;
}
