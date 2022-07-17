// http://acm.hdu.edu.cn/showproblem.php?pid=5792
// HDU 5792 World is Exploding
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
template <size_t mod, typename T>
void madd(T &a, ll b)
{
    if (mod)
        a = (b + a) % mod;
    else
        a += b;
}
template <typename T = int, typename Idx = int, size_t mod = 0>
class segtree
{
    vector<T> ch;
    Idx n;

public:
    segtree(Idx n = 0) { init(n); }
    void init(Idx n)
    {
        this->n = n;
        ch.clear();
        ch.resize(n);
    }
    void add(int x, T v)
    {
        for (; x <= n; x += (x & -x))
            madd<mod>(ch[x], v);
    }
    T query(int x)
    {
        T s = 0;
        for (; x; x -= x & (-x))
            madd<mod>(s, ch[x]);
        return s;
    }
    T sum(int l, int r) { return query(r) - query(l - 1); }
    Idx find(T v)
    {
        Idx x = 0;
        for (int i = 63; i >= 0; i--)
            if (x + (1LL << i) <= n && ch[x + (1LL << i)] < v)
                x += 1LL << i, v -= ch[x];
        return x + 1;
    }
};
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator maxup(vector<T, Alloc> &v) { return max(v.begin(), v.end()); }
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator minup(vector<T, Alloc> &v) { return min(v.begin(), v.end()); }
//     Const definitions >>>
const int maxn = 50000 + 7, mod = 1e9 + 7;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { madd<mod>(a, b); }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
int a[maxn], b[maxn];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        memcpy(b, a, sizeof(a[0]) * (n + 1));
        sort(b + 1, b + n + 1);
        int bn = unique(b + 1, b + n + 1) - b - 1;
        for (int i = 1; i <= n; i++)
            a[i] = lower_bound(b + 1, b + bn + 1, a[i]) - b;

        vector<int> ca(n + 1), cb(n + 1), cc(n + 1), cd(n + 1);
        segtree<> bt(bn + 1);
        for (int i = 1; i <= n; i++)
        {
            ca[i] = bt.query(a[i] - 1);
            cb[i] = i - bt.query(a[i] - 1) - 1;
            bt.add(a[i], 1);
        }

        bt.init(bn + 1);
        for (int i = n; i >= 1; i--)
        {
            cd[i] = bt.query(a[i] - 1);
            cc[i] = n - i - bt.query(a[i] - 1);
            bt.add(a[i], 1);
        }

        // 如何满足abcd互不相同？
    }

    return 0;
}