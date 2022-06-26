// https://atcoder.jp/contests/abc250/tasks/abc250_d
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
const int maxp = 1e6 + 5, mod = 1e9 + 7;
const ll maxn = 1e18 + 5;
// <<< Const definitions
template <typename T>
void add(T &a, ll b) { a = (b + a) % mod; }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }
// -=-=-=-=-=-=-=-=-=-=-=-
bitset<maxp> nprm;
vector<ll> prm;
void findprm()
{
    for (ll i = 2; i < maxp; i++)
        if (!nprm[i])
            for (ll j = i + i; j < maxp; j += i)
                nprm[j] = true;
    for (ll i = 2; i < maxp; i++)
        if (!nprm[i])
            prm.push_back(i);
}
bool isprm(ll i)
{
    return !nprm[i];
}
int main()
{
    findprm();
    ll n;
    in >> n;

    ll ans = 0;
    for (ll q = 3; q < maxp && q * q * q < n; q++)
    {
        if (!isprm(q))
            continue;
        ll qqq = q * q * q;
        ll pm = min(q - 1, n / qqq);
        auto it = upper_bound(prm.begin(), prm.end(), pm);
        ll a = it - prm.begin();
        ans += a;
    }
    out << ans << nl;

    return 0;
}