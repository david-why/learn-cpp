// https://www.luogu.com.cn/problem/P1908
// Luogu P1908 逆序对
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 6;
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
int a[maxn], b[maxn], pos[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        pos[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (i - 1) /* already inserted */ - query(pos[i]) /* before current number */;
        add(pos[i], 1);
    }

    cout << ans << endl;

    return 0;
}
