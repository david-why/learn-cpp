#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;

template <typename T, typename GV = function<T(const T &, const T &)>>
class segtree
{
#define li (i << 1)
#define ri ((i << 1) + 1)
#define gl li, l, gmid
#define gr ri, gmid + 1, r
#define gmid ((l + r) >> 1)
#define push(i) (val[i] = get_value(val[li], val[ri]))
    T val[maxn * 4];
    int n;
    GV get_value;

    void _build(const T *ptr, int i, int l, int r)
    {
        if (l == r)
        {
            val[i] = ptr[l];
            return;
        }
        _build(ptr, gl);
        _build(ptr, gr);
        push(i);
    }
    T _query(int ql, int qr, int i, int l, int r)
    {
        if (ql == l && qr == r)
            return val[i];
        if (gmid >= qr)
            return _query(ql, qr, gl);
        if (gmid < ql)
            return _query(ql, qr, gr);
        return get_value(_query(ql, gmid, gl), _query(gmid + 1, qr, gr));
    }

public:
    segtree() : n(1), get_value() {}
    segtree(int n, GV get_value) : n(n), get_value(get_value) {}
    segtree(int n, GV get_value, const T *ptr) : n(n), get_value(get_value) { build(ptr); }
    void init(int n, GV get_value = GV(), const T *ptr = NULL)
    {
        this->n = n;
        this->get_value = get_value;
        if (ptr != NULL)
            build(ptr);
    }
    void build(const T *ptr) { _build(ptr, 1, 1, n); }
    T query(int l, int r) { return _query(l, r, 1, 1, n); }
#undef li
#undef ri
#undef gl
#undef gr
};

struct node
{
    int pn = INT_MIN, px = INT_MIN;
    int nn = INT_MAX, nx = INT_MAX;
    unsigned char has0;
};
ostream &operator<<(ostream &out, const node &x)
{
    return out << "{" << x.pn << "," << x.px << "," << x.nn << "," << x.nx << "," << (x.has0 ? 1 : 0) << "}";
}
segtree<node> bp;
segtree<node> ap;
node a[maxn];
node b[maxn];

node get_value(const node &a, const node &b)
{
    node x = a;
    if (x.pn == INT_MIN)
        x.pn = b.pn;
    if (x.px == INT_MIN)
        x.px = b.px;
    if (x.nn == INT_MAX)
        x.nn = b.nn;
    if (x.nx == INT_MAX)
        x.nx = b.nx;
    if (b.pn != INT_MIN)
        x.pn = min(x.pn, b.pn);
    if (b.px != INT_MIN)
        x.px = max(x.px, b.px);
    if (b.nn != INT_MAX)
        x.nn = max(x.nn, b.nn);
    if (b.nx != INT_MAX)
        x.nx = min(x.nx, b.nx);
    x.has0 |= b.has0;
    // node x{min(a.pn, b.pn), max(a.px, b.px), max(a.nn, b.nn), min(a.nx, b.nx), a.has0 || b.has0};
    // if (x.pn == INT_MIN) x.pn = x.px;
    // if (x.px == INT_MIN) x.px = x.pn;
    // if (x.nn == INT_MAX) x.nn = x.nx;
    // if (x.nx == INT_MAX) x.nx = x.nn;
    return x;
}

int main()
{
    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
            a[i].pn = a[i].px = x;
        else if (x < 0)
            a[i].nn = a[i].nx = x;
        else
            a[i].has0 = true;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
            b[i].pn = b[i].px = x;
        else if (x < 0)
            b[i].nn = b[i].nx = x;
        else
            b[i].has0 = true;
    }
    bp.init(m, get_value, b);
    ap.init(n, get_value, a);
    // for (int i=1;i<=n;i++)cout<<ap.query(i,i)<<endl;
    // for (int i=1;i<=n;i++)cout<<ap.query(1,i)<<" ";cout<<endl;
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        node bq = bp.query(l2, r2), aq = ap.query(l1, r1);
        // cout<<"b" <<bq<<" a"<<aq<<"";
        ll mv = LLONG_MIN;
        for (int x : {aq.nn, aq.nx, aq.pn, aq.px})
        {
            if (x == INT_MIN || x == INT_MAX)
                continue;
            ll mn = LLONG_MAX;
            for (int y : {bq.nn, bq.nx, bq.pn, bq.px})
            {
                if (y == INT_MIN || y == INT_MAX)
                    continue;
                mn = min(mn, (ll)x * y);
            }
            mv = max(mv, mn);
        }
        // cout << "a{" << aq.mn << "," << aq.mx << "," << (aq.has0 ? 1 : 0) << "}b{" << bq.mn << "," << bq.mx << "," << (bq.has0 ? 1 : 0) << "}\n";
        // ll mv = max(min((ll)bq.mn * aq.mx, (ll)bq.mx * aq.mx), min((ll)bq.mn * aq.mn, (ll)bq.mx * aq.mn));
        if (aq.has0)
            mv = max(mv, 0ll);
        cout << mv << "\n";
    }
    return 0;
}
