// https://cses.fi/problemset/task/2206

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;

#define mid ((l + r) >> 1)
#define li (i << 1)
#define ri ((i << 1) + 1)
#define gl li, l, mid
#define gr ri, mid + 1, r
#define pr int i, int l, int r
#define gv() ch[i] = min(ch[li], ch[ri])

class segtree
{
    int ch[4 * maxn];
    int n;
    void _build(int *arr, pr)
    {
        if (l == r)
        {
            ch[i] = arr[l];
            return;
        }
        _build(arr, gl);
        _build(arr, gr);
        gv();
    }
    void _update(int v, int p, pr)
    {
        if (l == r)
        {
            ch[i] = v;
            return;
        }
        if (p <= mid)
            _update(v, p, gl);
        else
            _update(v, p, gr);
        gv();
    }
    int _query(int ql, int qr, pr)
    {
        if (ql <= l && r <= qr)
            return ch[i];
        if (qr <= mid)
            return _query(ql, qr, gl);
        if (ql > mid)
            return _query(ql, qr, gr);
        return min(_query(ql, mid, gl), _query(mid + 1, qr, gr));
    }

public:
    segtree(int n = 0) : n(n) {}
    void resize(int n) { this->n = n; }
    void build(int *arr, int n) { resize(n), _build(arr, 1, 1, n); }
    void update(int v, int p) { _update(v, p, 1, 1, n); }
    int query(int l, int r) { return _query(l, r, 1, 1, n); }
};

segtree lt, rt;
int p1[maxn], p2[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> p1[i];
        p2[i] = p1[i] + i;
        p1[i] -= i;
    }
    lt.build(p1, n);
    rt.build(p2, n);
    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int k, x;
            cin >> k >> x;
            lt.update(x - k, k);
            rt.update(x + k, k);
        }
        else if (op == 2)
        {
            int k;
            cin >> k;
            cout << min(lt.query(1, k) + k, rt.query(k, n) - k) << "\n";
        }
    }
    return 0;
}
