// https://codeforces.com/contest/1661/problem/C
// Codeforces Contest #1661 C. Water the Trees
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
class reader
{
    template <typename T>
    struct is_pair : public false_type
    {
    };
    template <typename T1, typename T2>
    struct is_pair<pair<T1, T2>> : public true_type
    {
    };

public:
#define READ(typ, iden)        \
    reader &operator>>(typ &v) \
    {                          \
        scanf("%" #iden, &v);  \
        return *this;          \
    }
    READ(char, c)
    READ(int, d)
    READ(ll, lld)
    READ(double, lf)
    READ(unsigned int, u)
    READ(ull, llu)
#undef READ
    reader &operator>>(char *v)
    {
        scanf("%s", v);
        return *this;
    }
    template <typename T, typename I>
    typename enable_if<!is_pair<T>::value, reader &>::type operator>>(pair<T *, I> p)
    {
        while (p.second--)
            operator>>(*p.first++);
        return *this;
    }
    template <typename T1, typename T2, typename I>
    reader &operator>>(pair<pair<T1, T2> *, I> p)
    {
        if (p.second < 0)
        {
            p.second = -p.second;
            for (I i = 0; i < p.second; i++)
                operator>>((p.first + i)->first);
            while (p.second--)
                operator>>((p.first++)->second);
            return *this;
        }
        while (p.second--)
            operator>>(p.first->first),
            operator>>((p.first++)->second);
        return *this;
    }
    template <typename T>
    reader &operator>>(vector<T> &v)
    {
        for (size_t i = 0; i < v.size(); i++)
            operator>>(v[i]);
        return *this;
    }
} in;
class writer
{
public:
#define WRITE(typ, iden)      \
    writer &operator<<(typ v) \
    {                         \
        printf("%" #iden, v); \
        return *this;         \
    }
    WRITE(int, d)
    WRITE(ll, lld)
    WRITE(double, lf)
    WRITE(unsigned int, u)
    WRITE(ull, llu)
    WRITE(const char *, s)
#undef WRITE

    template <typename T1, typename T2>
    writer &operator<<(const pair<T1, T2> &p)
    {
        printf("(");
        operator<<(p.first);
        printf(",");
        operator<<(p.second);
        printf(")");
        return *this;
    }
    writer &operator<<(const string &s) { return operator<<(s.c_str()); }
    template <typename Callable>
    writer &operator<<(Callable func)
    {
        func(*this);
        return *this;
    }
} out;
void nl(writer &wr) { wr << "\n"; }
template <size_t mod, typename T>
void madd(T &a, ll b)
{
    if (mod)
        a = (b + a) % mod;
    else
        a += b;
}
template <size_t maxn, typename T = int, size_t mod = 0>
class segtree
{
    T ch[maxn];
    size_t n;

public:
    segtree(size_t n = 0) : n(n) {}
    void resize(size_t siz) { n = siz; }
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
    size_t find(T v)
    {
        size_t x = 0;
        for (int i = 63; i >= 0; i--)
            if (x + (1 << i) <= n && ch[x + (1 << i)] < v)
                x += 1 << i, v -= ch[x];
        return x + 1;
    }
};
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator maxv(vector<T, Alloc> &v)
{
    typename vector<T, Alloc>::iterator it = v.begin();
    for (typename vector<T, Alloc>::iterator i = v.begin(); i != v.end(); i++)
        if (*it < *i)
            it = i;
    return it;
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator minv(vector<T, Alloc> &v)
{
    typename vector<T, Alloc>::iterator it = v.begin();
    for (typename vector<T, Alloc>::iterator i = v.begin(); i != v.end(); i++)
        if (*i < *it)
            it = i;
    return it;
}
//     Const definitions >>>
const int maxn = 3e5 + 7, mod = 1e9 + 7;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { madd<mod>(a, b); }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
vector<int> h;
ll solve(int m)
{
    ll k1 = 0, k2 = 0;
    for (int i : h)
        k1 += (m - i) % 2, k2 += (m - i) / 2;
    if (k1 > k2)
        return k1 + k1 - 1;
    ll v = (k2 - k1 + 1) / 3;
    k1 += 2 * v;
    k2 -= v;
    return max(k2 + k2, k1 + k1 - 1);
}
int main()
{
    int t;
    in >> t;
    while (t--)
    {
        int n;
        in >> n;
        h.resize(n);
        in >> h;
        int m = *maxv(h);
        out << min(solve(m), solve(m + 1)) << nl;
    }

    return 0;
}
