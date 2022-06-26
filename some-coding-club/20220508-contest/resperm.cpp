// AtCoder ABC223_D Restricted Permutation
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
    WRITE(char, c)
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
    template <typename T>
    writer &operator<<(const vector<T> &v)
    {
        for (const T &x : v)
            operator<<(x), operator<<(" ");
        return *this;
    }
} out;
void nl(writer &wr) { wr << "\n"; }
//     Const definitions >>>
const int maxn = 2e5 + 5, mod = 1e9 + 7;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { a = (b + a) % mod; }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
int num[maxn];
vector<int> con[maxn];
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    int n, m;
    in >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        in >> a >> b;
        con[a].push_back(b);
        num[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (num[i] == 0)
            pq.push(i);

    vector<int> ans;
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        ans.push_back(x);
        for (int i : con[x])
            if (--num[i] == 0)
                pq.push(i);
    }
    if (ans.size() == n)
        out << ans << nl;
    else
        out << -1 << nl;

    return 0;
}