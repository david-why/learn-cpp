// https://www.luogu.com.cn/problem/P1966
// Luogu P1966 [NOIP2013 提高组] 火柴排队
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5, mod = 1e8 - 3;
int ch[maxn], n;
void add(int x, int v)
{
    for (int i = x; i <= n; i += i & (-i))
        ch[i] += v;
}
int query(int x)
{
    int s = 0;
    for (int i = x; i; i -= i & (-i))
        s += ch[i];
    return s;
}
pair<int, int> a[maxn], b[maxn];
int c[maxn], pos[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i].first, b[i].second = i;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
        pos[a[i].second] = b[i].second;

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + (i - 1) - query(pos[i])) % mod;
        add(pos[i], 1);
    }

    cout << ans << endl;

    return 0;
}
