// https://atcoder.jp/contests/abc252/tasks/abc252_c
// AtCoder ABC252 C Slot Strategy
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
    writer &operator<<(void (*func)(writer &))
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
//     Const definitions >>>
const int maxn = 100 + 2, mod = 1e9 + 7;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { madd<mod>(a, b); }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
ll getdig(ll a, int dig)
{
    while (dig++ != 9)
        a /= 10;
    return a % 10;
}
int main()
{
    int n;
    in >> n;
    vector<ll> reel(n);
    in >> reel;

    int ans = INT_MAX;
    for (int k = 0; k < 10; k++)
    {
        int t;
        int f = 0;
        bitset<maxn> used;
        for (t = 0;; t++)
        {
            int d = t % 10;
            for (int i = 0; i < n; i++)
            {
                if (used[i])
                    continue;
                if (getdig(reel[i], d) == k)
                {
                    used[i] = true;
                    f++;
                    break;
                }
            }
            if (f == n)
                break;
        }
        upmin(ans, t);
    }

    out << ans << nl;

    return 0;
}