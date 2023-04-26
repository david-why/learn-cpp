// http://www.usaco.org/index.php?page=viewproblem2&cpid=495

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100007;

#define pr int i, int l, int r
#define mid ((l + r) >> 1)
#define li (i << 1)
#define ri ((i << 1) + 1)
#define gl li, l, mid
#define gr ri, mid + 1, r
#define gv() ch[i] = get_value(ch[li], ch[ri])

struct node
{
    int a, b, sm, ans;
} ch[4 * maxn];

struct pos
{
    int x, y;
} chk[maxn];
node arr[maxn];

int dis(int a, int b)
{
    return abs(chk[a].x - chk[b].x) + abs(chk[a].y - chk[b].y);
}

ostream &operator<<(ostream &out, const node &n)
{
    return out << "{" << n.a << "," << n.b << "," << n.sm << "," << n.ans << "}";
}

node get_value(const node &l, const node &r)
{
    int d = dis(l.b, r.a);
    int v = min({l.ans + r.sm + d, r.ans + l.sm + d});
    if (l.a != l.b)
        v = min(v, l.sm - dis(l.b, l.b - 1) + dis(l.b - 1, r.a) + r.sm);
    if (r.a != r.b)
        v = min(v, l.sm + dis(l.b, r.a + 1) + r.sm - dis(r.a, r.a + 1));
    node ret = node{l.a, r.b, l.sm + r.sm + d, v};
    // cout << l << " + " << r << " = " << ret << endl;
    return ret;
}

void build(const node *arr, pr)
{
    if (l == r)
    {
        ch[i] = arr[l];
        return;
    }
    build(arr, gl);
    build(arr, gr);
    gv();
}

void update(const node &v, int p, pr)
{
    if (l == r)
    {
        ch[i] = v;
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
    if (ql <= l && r <= qr)
        return ch[i];
    if (qr <= mid)
        return query(ql, qr, gl);
    if (ql > mid)
        return query(ql, qr, gr);
    return get_value(query(ql, mid, gl), query(mid + 1, qr, gr));
}

int main()
{
#ifndef LOCALTEST
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n, q;
    cin >> n >> q;
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++)
        cin >> chk[i].x >> chk[i].y, arr[i].a = arr[i].b = i;
    build(arr, 1, 1, n);
    while (q--)
    {
        char op;
        cin >> op;
        if (op == 'U')
        {
            int i;
            cin >> i;
            cin >> chk[i].x >> chk[i].y;
            update(arr[i], i, 1, 1, n);
            //cout << "-----" << endl;
        }
        else if (op == 'Q')
        {
            int i, j;
            cin >> i >> j;
            node res = query(i, j, 1, 1, n);
            cout << res.ans << "\n";
        }
    }
}
