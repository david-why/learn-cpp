// https://cses.fi/problemset/task/1190

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 7;

struct node
{
    ll sm, ls, rs, ts;
} ch[4 * maxn];

node get_value(const node &a, const node &b)
{
    node res;
    res.sm = a.sm + b.sm;
    res.ls = max(a.ls, a.sm + b.ls);
    res.rs = max(b.rs, b.sm + a.rs);
    res.ts = max({a.ts, b.ts, a.rs + b.ls});
    return res;
}

#define pr int i, int l, int r
#define mid ((l + r) >> 1)
#define li (i << 1)
#define ri ((i << 1) + 1)
#define gl li, l, mid
#define gr ri, mid + 1, r
#define gv() ch[i] = get_value(ch[li], ch[ri])

void build(ll *arr, pr)
{
    if (l == r)
    {
        ch[i].ls = ch[i].rs = ch[i].ts = max(0ll, arr[l]);
        ch[i].sm = arr[l];
        return;
    }
    build(arr, gl);
    build(arr, gr);
    gv();
}

void update(ll v, int p, pr)
{
    if (l == r)
    {
        ch[i].ls = ch[i].rs = ch[i].ts = max(0ll, v);
        ch[i].sm = v;
        return;
    }
    if (p <= mid)
        update(v, p, gl);
    else
        update(v, p, gr);
    gv();
}

node query(int ql, int qr, pr)
{
    if (l <= ql && qr <= r)
        return ch[i];
    if (qr <= mid)
        return query(ql, qr, gl);
    if (ql > mid)
        return query(ql, qr, gr);
    return get_value(query(ql, mid, gl), query(mid + 1, qr, gr));
}

ll a[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(a, 1, 1, n);
    while (m--)
    {
        int k, x;
        cin >> k >> x;
        update(x, k, 1, 1, n);
        cout << query(1, n, 1, 1, n).ts << "\n";
    }
    return 0;
}
