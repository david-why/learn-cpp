// https://codeforces.com/contest/1667/problem/A
// Codeforces Contest #1667 A. Make it Increasing
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 7;
int a[maxn], n;
ll solve(int i)
{
    ll r = 0;
    ll v = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        ll q = (v - 1 - a[j] + 1) / a[j];
        v = (ll)q * a[j];
        r -= q;
    }
    v = 0;
    for (int j = i + 1; j < n; j++)
    {
        ll q = (v + 1 + a[j] - 1) / a[j];
        v = (ll)q * a[j];
        r += q;
    }
    return r;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 2e17;
    for (int i = 0; i < n; i++)
        ans = min(ans, solve(i));

    cout << ans << endl;

    return 0;
}
