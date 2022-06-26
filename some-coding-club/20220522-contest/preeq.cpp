#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
//     Const definitions >>>
const int maxn = 2e5 + 7, mod = 1e9 + 7, maxe = 2 * maxn;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { a = (b + a) % mod; }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
// pair<int, int> lst[maxn];
int a[maxn], b[maxn];
pair<int, int> que[maxn];
int c[2 * maxn];
bitset<maxe> ab, bb;
int main()
{
    int n, q;
    in >> n;
    in >> make_pair(a + 1, n) >> make_pair(b + 1, n) >> q >> make_pair(que + 1, q);
    memcpy(c + 1, a, n * sizeof(int));
    memcpy(c + n + 1, b, n * sizeof(int));
    sort(c + 1, c + n + 1);
    int m = unique(c + 1, c + n + 1) - c - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(c + 1, c + m + 1, a[i]) - c - 1,
        b[i] = lower_bound(c + 1, c + m + 1, b[i]) - c - 1;
    sort(que, que + q);
    int pb = 0;
    int pa = 0;
    for (int i = 1; i <= q; i++)
    {
        if (pb > que[i].second)
            bb.reset(), pb = 0;
        while (pb < que[i].second)
            bb.set(b[++pb]);
        while (pa < que[i].first)
            ab.set(a[++pa]);
        // cout << "- " << ab << endl << "- " << bb << endl;
        out << (ab == bb ? "Yes" : "No") << nl;
    }

    return 0;
}