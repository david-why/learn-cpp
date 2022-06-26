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
const int maxn = 1e6 + 7, mod = 1e9 + 7;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { a = (b + a) % mod; }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
char str[maxn];
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define max3(x, y, z) (max(max((x), (y)), (z)))
int main()
{
    int t;
    in >> t;
    while (t--)
    {
        in >> str;
        int n = strlen(str);
        vector<int> cnt(3);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cnt[str[i] - '1'] = i + 1;
            if (cnt[0] && cnt[1] && cnt[2])
                ans = min(ans, max3(cnt[0], cnt[1], cnt[2]) - min3(cnt[0], cnt[1], cnt[2]) + 1);
        }
        out << (ans == INT_MAX ? 0 : ans) << nl;
    }

    return 0;
}