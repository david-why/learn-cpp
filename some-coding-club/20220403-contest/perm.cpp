// https://codeforces.com/problemset/problem/1326/C
// Codeforces Contest #1326 C. Permutation Partitions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200007, mod = 998244353;
int n, k, a[maxn], p[maxn];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        if (a[i] > n - k)
            p[n - a[i] + 1] = i;
    }

    ll x = 0;
    for (int i = 1; i <= k; i++)
        x += n - i + 1;
    sort(p + 1, p + k + 1);

    ll ans = 1;
    for (int i = 1; i < k; i++)
        ans = ans * (p[i + 1] - p[i]) % mod;
    cout << x << " " << ans << endl;

    return 0;
}
