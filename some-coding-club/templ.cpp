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
    reader &operator>>(pair<T *, I> p)
    {
        static_assert(!is_pair<T>::value);
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
    template <typename T, typename Alloc>
    reader &operator>>(vector<T, Alloc> &v)
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
    WRITE(size_t, lu)
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
const int maxn = 1e5 + 7, mod = 1e9 + 7;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { madd<mod>(a, b); }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
int main()
{

    return 0;
}