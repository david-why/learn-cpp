// https://www.luogu.com.cn/problem/P2015
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define bte(x) x.begin(), x.end()
#define sortv(v) sort(bte(v))
#define mvtp(sz, nm, tp) vector<tp> nm(sz)
#define mvi(sz, nm) mvtp(sz, nm, int)
#define mvll(sz, nm) mvtp(sz, nm, ll)
#define mvb(sz, nm) mvtp(sz, nm, bool)
#define frv(n, i) for (int i = 1; i <= n; i++)
#define fri(n) frv(n, i)
#define frj(n) frv(n, j)
#define cim const int maxn
#define ctn continue
#define inint(...)   \
    int __VA_ARGS__; \
    in(__VA_ARGS__)
#define CASES     \
    int __t = in; \
    while (__t--)
namespace __util
{
    template <typename T>
    struct __func_t : public __func_t<decltype(&T::operator())> // https://stackoverflow.com/a/7943765
    {
    };
    template <typename T, typename C, typename... Args>
    struct __func_t<T (C::*)(Args...) const> : public __func_t<T (*)(Args...)>
    {
    };
    template <typename T, typename... Args>
    struct __func_t<T (*)(Args...)>
    {
        typedef T return_type;
        typedef tuple<Args...> args;
        typedef function<T(Args...)> function_type;
        typedef T (*funcptr_type)(Args...);
    };
    template <typename Functor>
    class function_t
    {
        typename __func_t<Functor>::function_type func;

    public:
        typedef typename __func_t<Functor>::function_type function_type;
        typedef typename __func_t<Functor>::args args;
        typedef typename __func_t<Functor>::return_type return_type;
        typedef typename __func_t<Functor>::funcptr_type funcptr_type;
        function_t(Functor f) : func(f) {}
        template <typename... Args>
        return_type operator()(Args... args) { return func(forward<Args>(args)...); }
    };
}
namespace simple_io
{
    class input_wrapper
    {
        istream &is;
        template <typename Tuple, size_t Idx>
        struct __tuple_input
        {
            static void __input(istream &is, Tuple &t)
            {
                __tuple_input<Tuple, Idx - 1>::__input(is, t);
                is >> get<Idx>(t);
            }
        };
        template <typename Tuple>
        struct __tuple_input<Tuple, 0>
        {
            static void __input(istream &is, Tuple &t) { is >> get<0>(t); }
        };
        template <typename T, typename Func, typename Args, typename Done>
        struct __inputter
        {
        };
        template <typename T, typename Func, typename Args, typename... Done>
        struct __inputter<T, Func, Args, tuple<Done...>>
        {
            typedef typename tuple_element<tuple_size<tuple<Done...>>::value, Args>::type next_t;
            typedef tuple<Done..., next_t> nextdone_t;
            static T input(input_wrapper &in, Func func, Done... args)
            {
                return __inputter<T, Func, Args, nextdone_t>::input(in, func, args..., in);
            }
        };
        template <typename T, typename Func, typename... Args>
        struct __inputter<T, Func, tuple<Args...>, tuple<Args...>>
        {
            static T input(input_wrapper &, Func func, Args... args)
            {
                return func(args...);
            }
        };
        struct __sf_helper
        {
            input_wrapper &in;
            long long n;
            template <typename Int>
            typename enable_if<is_integral<Int>::value, __sf_helper>::type operator+(Int v) { return __sf_helper{in, n + v}; }
            template <typename Int>
            typename enable_if<is_integral<Int>::value, __sf_helper>::type operator-(Int v) { return __sf_helper{in, n - v}; }
            template <typename Function>
            typename enable_if<!is_integral<Function>::value, input_wrapper &>::type operator+(Function v)
            {
                typedef typename enable_if<!is_integral<Function>::value, void>::type __check_int;
                return in + make_pair(n, v);
            }
            template <typename Function>
            typename enable_if<!is_integral<Function>::value, input_wrapper &>::type operator-(Function v)
            {
                typedef typename enable_if<!is_integral<Function>::value, void>::type __check_int;
                return in + make_pair(n, v);
            }
        };

    public:
        input_wrapper(istream &s) : is(s)
        {
        }
        input_wrapper &operator()() { return *this; }
        template <typename T, typename... Args>
        input_wrapper &operator()(T &val, Args &...args)
        {
            val = operator T();
            return operator()(args...);
        }
        template <typename T, typename... Args>
        input_wrapper &operator()(pair<T *, int> &&val, Args &...args)
        {
            for (int i = 0; i < val.second; i++)
                operator()(val.first[i]);
            return operator()(args...);
        }
        template <typename... TupleTypes, typename... Args>
        input_wrapper &operator()(tuple<TupleTypes &...> &&val, Args &...args)
        {
            __tuple_input<tuple<TupleTypes &...>, tuple_size<tuple<TupleTypes &...>>::value - 1>::__input(is, val);
            return operator()(args...);
        }
        template <typename T>
        operator T()
        {
            T val;
            is >> val;
            return val;
        }
        template <typename T>
        input_wrapper &operator-(T &val) { return operator()(val); }
        template <typename T>
        input_wrapper &operator-(T &&val) { return operator()(forward<T &&>(val)); }
        template <typename Int, typename Functor>
        input_wrapper &f(Int in_size, Functor func) { return *this + make_pair(in_size, func); }
        __sf_helper operator+(long long n) { return __sf_helper{*this, n}; }
        template <typename Int, typename Functor>
        input_wrapper &operator+(pair<Int, Functor> tp)
        {
            Int in_size = tp.first;
            __util::function_t<Functor> func = tp.second;
            while (in_size--)
                __inputter<typename __util::function_t<Functor>::return_type, __util::function_t<Functor>, typename __util::function_t<Functor>::args, tuple<>>::input(*this, func);
            return *this;
        }
        template <typename Iter, typename Functor>
        input_wrapper &operator+(tuple<Iter, Iter, Functor> tp)
        {
            Iter first = get<0>(tp), last = get<1>(tp);
            __util::function_t<Functor> func = get<2>(tp);
            for (; first < last; ++first)
                *first = __inputter<typename __util::function_t<Functor>::return_type, __util::function_t<Functor>, typename __util::function_t<Functor>::args, tuple<>>::input(*this, func);
            return *this;
        }
    } in(cin);
    template <typename T>
    class nls
    {
    public:
        const vector<T> &v;
        nls(const vector<T> &val) : v(val) {}
    };
    class output_wrapper
    {
        ostream &os;
        template <typename T>
        struct __output
        {
            static void output(ostream &os, const T &val) { os << val; }
        };
        template <typename U>
        struct __output<vector<U>>
        {
            static void output(ostream &os, const vector<U> &val)
            {
                typename vector<U>::const_iterator it = val.begin();
                __output<U>::output(*it++);
                for (; it != val.end(); ++it)
                    os << " ", __output<U>::output(os, *it);
            }
        };
        template <typename... Args>
        struct __output<tuple<Args...>>
        {
            template <typename T, size_t I>
            struct __helper
            {
                static void recur(ostream &os, const tuple<Args...> &val)
                {
                    __helper<T, I - 1>::recur(os, val);
                    os << " " << get<I>(val);
                }
            };
            template <typename T>
            struct __helper<T, 0>
            {
                static void recur(ostream &os, const tuple<Args...> &val)
                {
                    os << get<0>(val);
                }
            };
            static void output(ostream &os, const tuple<Args...> &val)
            {
                __helper<void, tuple_size<tuple<Args...>>::value - 1>::recur(os, val);
            }
        };
        template <typename U>
        struct __output<nls<U>>
        {
            static void output(ostream &os, const nls<U> &val)
            {
                typename vector<U>::const_iterator it = val.v.begin();
                __output<U>::output(*it++);
                for (; it != val.v.end(); ++it)
                    os << "\n", __output<U>::output(os, *it);
            }
        };

    public:
        output_wrapper(ostream &s) : os(s)
        {
        }
        output_wrapper &operator()() { return *this; }
        template <typename T, typename... Args>
        output_wrapper &operator()(const T &val, const Args &...args)
        {
            __output<T>::output(os, val);
            return operator()(args...);
        }
        template <typename T>
        output_wrapper &operator-(const T &val) { return operator()(val); }
        template <typename T>
        output_wrapper &operator+(const T &val) { return operator()(val); }
    } out(cout);
    const int __magic = []()
    { ios::sync_with_stdio(false); cin.tie(0); return 0; }();
    const char *const nl = "\n";
}
namespace segtree
{
#define li (i << 1)
#define ri ((i << 1) + 1)
#define gl li, l, gm
#define gr ri, gm + 1, r
#define gm ((l + r) >> 1)
#define pu() ch[i] = gv(ch[li], ch[ri])
    template <size_t maxn, typename T>
    class segtree
    {
        typedef function<T(const T &, const T &)> get_value_t;
        T ch[maxn * 4];
        int n;
        get_value_t gv;
        void _build(const T *arr, int i, int l, int r)
        {
            if (l == r)
            {
                ch[l] = arr[i];
                return;
            }
            _build(arr, gl);
            _build(arr, gr);
            pu();
        }
        void _set(int p, const T &v, int i, int l, int r)
        {
            if (l == p)
            {
                ch[l] = v;
                return;
            }
            if (gm >= p)
                _set(p, v, gl);
            else
                _set(p, v, gr);
            pu();
        }
        T _get(int ql, int qr, int i, int l, int r)
        {
            if (ql == l && qr == r)
                return ch[i];
            if (gm >= qr)
                return _get(ql, qr, gl);
            else if (gm < ql)
                return _get(ql, qr, gr);
            return gv(_get(ql, gm, gl), _get(gm + 1, qr, gr));
        }

    public:
        segtree() : n(0) {}
        segtree(int n, get_value_t get_value) : n(n), gv(get_value) {}
        segtree(int n, const T *arr, get_value_t get_value) : n(n), gv(get_value) { build(arr); }
        segtree(const vector<T> &v, get_value_t get_value) : n(v.size()), gv(get_value) { build(--v.data()); }
        void assign(int n, get_value_t get_value) { this->n = n, gv = get_value; }
        void build(const T *arr) { _build(arr, 1, 1, n); }
        void set(int i, const T &v) { _set(i, v, 1, 1, n); }
        T get(int l, int r) { return _get(l, r, 1, 1, n); }
    };
#undef li
#undef ri
#undef gl
#undef gr
#undef gm
#undef pu
}
namespace tree
{
    template <size_t maxn>
    class tree
    {
        int pa[maxn][20];
        int dep[maxn];
        int rt, n;
        int _dfs(int v, int p)
        {
            pa[v][0] = p, dep[v] = dep[p] + 1;
            for (int i = 1; i < 20; i++)
                pa[v][i] = pa[pa[v][i - 1]][i - 1];
            int tot = 1, mx = 0;
            for (int x : con[v])
                if (x != p)
                {
                    int ns = _dfs(x, v);
                    tot += ns;
                    mx = max(mx, ns);
                }
            mx = max(mx, n - tot);
            if (mx <= n / 2)
            {
                if (cent.first == 0)
                    cent.first = v;
                else
                    cent.second = v;
                if (cent.second && cent.second < cent.first)
                    swap(cent.first, cent.second);
            }
            return tot;
        }

    public:
        vector<int> con[maxn];
        pair<int, int> cent;
        tree(int root = 1, int n = 1) : rt(root), n(n) {}
        void add_edge(int i, int j) { con[i].pb(j), con[j].pb(i); }
        int root() const { return rt; }
        void root(int new_root) { rt = new_root; }
        int size() const { return n; }
        void resize(int newsize) { n = newsize; }
        void init() { _dfs(rt, 0); }
        int jump(int v, int k) const
        {
            for (int i = 19; i >= 0; i--)
                if (k >= 1 << i)
                    v = pa[v][i], k -= 1 << i;
            return v;
        }
        int lca(int u, int v) const
        {
            if (dep[u] > dep[v])
                swap(u, v);
            for (int i = 19; i >= 0; i--)
                if (dep[v] - dep[u] >= 1 << i)
                    v = pa[v][i];
            if (u == v)
                return u;
            for (int i = 19; i >= 0; i--)
                if (pa[u][i] != pa[v][i])
                    u = pa[u][i], v = pa[v][i];
            return pa[u][0];
        }
        int dis(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
        int depth(int u) const { return dep[u]; }
        pair<int, vector<int>> path(int u, int v) const
        {
            vector<int> path;
            int x = lca(u, v);
            for (; u != x; u = pa[u][0])
                path.pb(u);
            path.pb(x);
            vector<int> path2;
            for (; v != x; v = pa[v][0])
                path2.pb(v);
            path.insert(path.end(), path2.rbegin(), path2.rend());
            return mp(dep[u] + dep[v] - 2 * dep[x], path);
        }
        template <typename Func>
        typename enable_if<is_same<typename __util::function_t<Func>::args, tuple<int, int, const vector<int> *>>::value, typename __util::function_t<Func>::return_type>::type run_dp(Func dfs, int root = -1) const { return dfs(root < 0 ? rt : root, 0, con); }
        template <typename Func>
        typename enable_if<is_same<typename __util::function_t<Func>::args, tuple<int, int, const tree &>>::value, typename __util::function_t<Func>::return_type>::type run_dp(Func dfs, int root = -1) const { return dfs(root < 0 ? rt : root, 0, *this); }
    };
    template <size_t maxn, typename T = int>
    class weighted_tree
    {
        tree<maxn> tr;
        T val[maxn], csum[maxn];
        void _dfs(int i, int p, const vector<int> con[])
        {
            csum[i] = val[i];
            for (int j : con[i])
                if (j != p)
                    _dfs(j, i, con), csum[i] += csum[j];
        }
        template <typename Functor>
        auto _dfs_wrap(Functor dfs, typename enable_if<is_same<typename __util::function_t<Functor>::args, tuple<int, int, const vector<int> *>>::value, int>::type = 0)
        {
            return [dfs](int i, int p, const vector<int> con[])
            { return dfs(i, p, con); };
        }
        template <typename Functor>
        auto _dfs_wrap(Functor dfs, typename enable_if<is_same<typename __util::function_t<Functor>::args, tuple<int, int, const vector<int> *, const T *>>::value, int>::type = 0)
        {
            return [dfs, this](int i, int p, const vector<int> con[])
            { return dfs(i, p, con, val); };
        }
        template <typename Functor>
        auto _dfs_wrap(Functor dfs, typename enable_if<is_same<typename __util::function_t<Functor>::args, tuple<int, int, const vector<int> *, const T *, const T *>>::value, int>::type = 0)
        {
            return [dfs, this](int i, int p, const vector<int> con[])
            { return dfs(i, p, con, val, csum); };
        }

    public:
        weighted_tree(int root = 1, int n = 1, T *arr = NULL) : tr(root, n)
        {
            if (arr != NULL)
                memcpy(val, arr, sizeof(T) * (n + 1));
        }
        T &value(int idx) { return val[idx]; }
        void add_edge(int i, int j) { tr.add_edge(i, j); }
        int root() const { return tr.root(); }
        void root(int new_root) { tr.root(new_root); }
        int size() const { return tr.size(); }
        void resize(int newsize) { tr.resize(newsize); }
        void init()
        {
            tr.init();
            tr.run_dp(function<void(int, int, const vector<int> *)>(bind(&weighted_tree::_dfs, this, placeholders::_1, placeholders::_2, placeholders::_3)));
        }
        int jump(int v, int k) const { return tr.jump(v, k); }
        int lca(int u, int v) const { return tr.lca(u, v); }
        int dis(int u, int v) const { return tr.dis(u, v); }
        int depth(int u) const { return tr.depth(u); }
        pair<int, vector<int>> path(int u, int v) const { return tr.path(u, v); }
        template <typename Func>
        auto run_dp(Func dfs, int root = -1) { return tr.run_dp(_dfs_wrap(dfs)); }
    };
}
namespace fenwick
{
    template <size_t maxn, typename T = int>
    class fenwick
    {
        T ch[maxn];
        int n;

    public:
        fenwick(int n = 0) : n(n) {}
        void add(int i, int v)
        {
            for (; i <= n; i += i & -i)
                ch[i] += v;
        }
        int get(int r)
        {
            int ans = 0;
            for (; r >= 0; r -= r & -r)
                ans += ch[r];
            return ans;
        }
        int get(int l, int r) { return get(r) - get(l - 1); }
    };
}
namespace mono_queue
{
    template <typename T, typename Comp = less<T>, typename Container = deque<pair<size_t, T>>> // default: find max
    class mono_queue
    {
        Container q;
        size_t n, m, idx;
        Comp comp;

    public:
        mono_queue() : q(), n(0), m(0), idx(0) {}
        mono_queue(size_t n, size_t m) : q(), n(n), m(m), idx(0) {}
        void init(size_t n, size_t m) { this->n = n, this->m = m; }
        T &add(const T &value)
        {
            while (!q.empty() && comp(q.back().second, value))
                q.pop_back();
            q.push_back(mp(idx, value));
            while (!q.empty() && q.front() < idx - m + 1)
                q.pop_front();
            idx++;
            return q.front();
        }
        T &query() { return q.front(); }
    };
}
namespace modular
{
    template <typename T = ll>
    constexpr T exgcd(T a, T b, T &x, T &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        T d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
    template <size_t mod, typename T = ll>
    constexpr T finv(T a)
    {
        T x, y;
        exgcd(a, mod, x, y);
        return (x + mod) % mod;
    }
    template <size_t N, size_t mod, typename T = ll>
    class static_inv
    {
    public:
        T inv[N + 1], minv[N + 1];
        constexpr static_inv()
        {
            inv[1] = minv[1] = 1;
            for (T i = 2; i <= N; i++)
                inv[i] = finv<mod, T>(i), minv[i] = minv[i - 1] * inv[i] % mod;
        }
    };
}

using namespace simple_io;

const int maxn = 105;

struct node
{
    int v, n;
    node &operator+=(const node &o)
    {
        v += o.v, n += o.n;
        return *this;
    }
};

tree::weighted_tree<maxn, node> tr;
int dp[maxn][maxn]; // dp[i][j]: i is root, j edges total, max value
vector<tuple<int, int, int>> edg;
int n, q;

void dfs(int i, int p, const vector<int> con[], const node val[], const node csum[])
{
    for (int j : con[i])
        if (j != p)
            dfs(j, i, con, val, csum);
    const node &x = csum[i];
    // dp[i][1] = x.v;
    for (int j = 1; j <= min(q, x.n); j++)
        for (int u : con[i])
        {
            if (u == p)
                ctn;
            const node &y = csum[u], &z = val[u];
            for (int k = 0; k < min(j, y.n); k++)
                dp[i][j] = max(dp[i][j], dp[i][j - 1 - k] + dp[u][k] + z.v);
        }
    // out-"- "-mt(i,p,dp[i][1],dp[i][2])-nl;
}

int main()
{
    in(n, q);
    tr.resize(n);
    tr.root(1);
    in + n - 1 + [](int x, int y, int w)
    { tr.add_edge(x, y); edg.pb(mt(x, y, w)); };
    tr.init();
    for (auto &t : edg)
    {
        int x, y, w;
        tie(x, y, w) = t;
        if (tr.depth(y) < tr.depth(x))
            swap(x, y);
        // assert(tr.depth(x) == tr.depth(y) - 1);
        tr.value(y) = node{w, 1};
    }
    tr.init();
    tr.run_dp(dfs);
    out-dp[1][q]-nl;

    return 0;
}
