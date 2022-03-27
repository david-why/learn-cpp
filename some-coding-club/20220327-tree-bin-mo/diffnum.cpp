// given seq a_i, q queries, find # of different numbers in a_[l,r]
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 233;
int ch[maxn], n;
void add(int x, int v)
{
    for (; x <= n; x += x & -x)
        ch[x] += v;
}
int query(int x)
{
    int s = 0;
    for (; x; x -= x & -x)
        s += ch[x];
    return s;
}
int a[maxn];
int nxt[maxn], last[maxn];
int l[maxn], r[maxn];
vector<int> que[maxn];
int ans[maxn];
bool v[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i; i--)
    {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> l[i] >> r[i];
        que[l[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        if (!v[a[i]])
            v[a[i]] = 1, add(i, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int x : que[i])
            ans[x] = query(r[x]);
        add(i, -1);
        if (nxt[i])
            add(nxt[i], 1);
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;

    return 0;
}
