// https://codeforces.com/problemset/problem/1705/A
// Codeforces Contest #1705 A. Mark the Photographer
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define modadd(x, y, mod) ((x) = ((ll)((x) + (y)) % (mod)))
#define CASES     \
    int __t = in; \
    while (__t--)
namespace BIT
{
    template <typename T, size_t mod = SIZE_MAX>
    class BIT
    {
        vector<T> ch;
        int n;

    public:
        BIT(int n = 0) { init(n); }
        void init(int n)
        {
            this->n = n;
            ch.clear();
            ch.resize(n);
        }
        void add(int x, T v)
        {
            for (; x <= n; x += (x & -x))
                modadd(ch[x], v, mod);
        }
        T query(int x)
        {
            T s = 0;
            for (; x; x -= x & (-x))
                modadd(s, ch[x], mod);
            return s;
        }
        T query(int l, int r) { return query(r) - query(l - 1); }
        int find(T v)
        {
            int x = 0;
            for (int i = 63; i >= 0; i--)
                if (x + (1LL << i) <= n && ch[x + (1LL << i)] < v)
                    x += 1LL << i, v -= ch[x];
            return x + 1;
        }
    };
    template <typename T>
    BIT<T> make(int n) { return BIT<T>(n); }
    template <typename T, size_t mod>
    BIT<T, mod> make(int n) { return BIT<T, mod>(n); }
}
namespace SegTree
{
#define li (i * 2)
#define ri (i * 2 + 1)
#define gmid (l + (r - l) / 2)
#define gl li, l, mid
#define gr ri, mid + 1, r
#define gv get_value(ch[li], ch[ri])
    template <bool HasTag>
    struct __cleartag_helper
    {
        template <typename ClearTag, typename Tags>
        static void _help(ClearTag clear_tag, Tags &tags, int i) { clear_tag(tags[i]); }
    };
    template <>
    struct __cleartag_helper<false>
    {
        template <typename... Args>
        static void _help(Args &&...) {}
    };
    template <bool HasTag>
    struct __push_helper
    {
        template <typename UpdateTag, typename ClearTag, typename Ch, typename Tags>
        static void _help(UpdateTag update_tag, ClearTag clear_tag, Ch &ch, Tags &tags, int i)
        {
            update_tag(ch[li], tags[li], tags[i]);
            update_tag(ch[ri], tags[ri], tags[i]);
            clear_tag(tags[i]);
        }
    };
    template <>
    struct __push_helper<false>
    {
        template <typename... Args>
        static void _help(Args &&...) {}
    };
    template <bool HasTag>
    struct __init_helper
    {
        template <typename Tags>
        static void _help(Tags &tags, int n)
        {
            tags.clear();
            tags.resize(4 * n);
        }
    };
    template <>
    struct __init_helper<false>
    {
        template <typename... Args>
        static void _help(Args &&...) {}
    };
    template <bool Replace>
    struct __addone_helper
    {
        template <typename Ch, typename Val>
        static void _help(Ch &ch, int i, const Val &val) { ch[i] = val; }
    };
    template <>
    struct __addone_helper<false>
    {
        template <typename Ch, typename Val>
        static void _help(Ch &ch, int i, const Val &val) { ch[i] += val; }
    };
    struct Empty
    {
    };
    template <typename T, typename Tag = Empty,
              typename GetValue = function<T(const T &, const T &)>,
              typename UpdateTag = function<void(T &, Tag &, const Tag &)>,
              typename ClearTag = function<void(Tag &)>>
    class SegTree
    {
        static constexpr bool has_tag = !is_void<Tag>::value;
        GetValue get_value;
        UpdateTag update_tag;
        ClearTag clear_tag;
        vector<T> ch;
        int n;
        typename conditional<has_tag, vector<Tag>, Empty>::type tags;

        template <typename Array>
        void _build(const Array &arr, bool zero, int i, int l, int r)
        {
            __cleartag_helper<has_tag>::_help(clear_tag, tags, i);
            if (l == r)
            {
                ch[i] = arr[zero ? l - 1 : l];
                return;
            }
            int mid = gmid;
            _build(arr, zero, gl);
            _build(arr, zero, gr);
            ch[i] = gv;
        }
        void _push(int i)
        {
            __push_helper<has_tag>::_help(update_tag, clear_tag, ch, tags, i);
        }
        template <bool Replace>
        void _add_one(int pos, const T &v, int i, int l, int r)
        {
            if (l == r)
            {
                __addone_helper<Replace>::_help(ch, i, v);
                // if (Replace)
                //     ch[i] = v;
                // else
                //     ch[i] += v;
                return;
            }
            _push(i);
            int mid = gmid;
            if (pos < mid)
                _add_one<Replace>(pos, v, gl);
            else
                _add_one<Replace>(pos, v, gr);
            ch[i] = gv;
        }
        void _add_range(int f, int t, const Tag &g, int i, int l, int r)
        {
            if (f <= l && r <= t)
            {
                update_tag(ch[i], tags[i], g);
                return;
            }
            _push(i);
            int mid = gmid;
            if (f <= mid)
                _add_range(f, t, g, gl);
            if (t > mid)
                _add_range(f, t, g, gr);
            ch[i] = gv;
        }
        T _query(int f, int t, int i, int l, int r)
        {
            if (f <= l && r <= t)
                return ch[i];
            _push(i);
            int mid = gmid;
            if (t <= mid)
                return _query(f, t, gl);
            if (f > mid)
                return _query(f, t, gr);
            return get_value(_query(f, t, gl), _query(f, t, gr));
        }
        template <typename Pred>
        int _find(int f, Pred pred, int i, int l, int r)
        {
            if (!pred(ch[i]))
                return -1;
            if (l == r)
                return l;
            int mid = gmid;
            int x = _find(f, pred, gl);
            return x == -1 ? _find(f, pred, gr) : x;
        }

    public:
        SegTree(GetValue get_value, UpdateTag update_tag, ClearTag clear_tag, int n)
            : get_value(get_value), update_tag(update_tag), clear_tag(clear_tag) { init(n); }
        void init(int n)
        {
            this->n = n;
            ch.clear();
            ch.resize(n * 4);
            __init_helper<has_tag>::_help(tags, n);
        }
        template <typename Array>
        void build(const Array &arr, bool zero = true) { _build(arr, zero, 1, 1, n); }
        template <bool Replace = true>
        void add(int i, const T &v) { _add_one<Replace>(i, v, 1, 1, n); }
        void add(int l, int r, const Tag &tag)
        {
            static_assert(has_tag, "No tag, cannot range add");
            _add_range(l, r, tag, 1, 1, n);
        }
        T query(int i) { return _query(i, i, 1, 1, n); }
        T query(int l, int r) { return _query(l, r, 1, 1, n); }
        // find the closest node i > f for which pred(ch[i])=true
        template <typename Pred = function<bool(const T &)>>
        int find(int f, Pred pred) { return _find(f, pred, 1, 1, n); }
    };
#undef li
#undef ri
#undef gmid
#undef gl
#undef gr
    template <typename T, typename Tag = Empty,
              typename GetValue = function<T(const T &, const T &)>,
              typename UpdateTag = function<void(T &, Tag &, const Tag &)>,
              typename ClearTag = function<void(Tag &)>>
    SegTree<T, Tag, GetValue, UpdateTag, ClearTag> make(
        int n, GetValue get_value, UpdateTag update_tag = {},
        ClearTag clear_tag = [](Tag &t)
        { t = {}; })
    {
        return SegTree<T, Tag, GetValue, UpdateTag, ClearTag>(get_value, update_tag, clear_tag, n);
    }

    template <typename T>
    struct SumNode
    {
        T sum;
        int len;
        SumNode(T sum = 0, int len = 1) : sum(sum), len(len) {}
    };
    template <typename T>
    SumNode<T> sum_get_value(const SumNode<T> &a, const SumNode<T> &b)
    {
        return SumNode<T>{a.sum + b.sum, a.len + b.len};
    }
    template <typename T>
    void sum_update_tag(SumNode<T> &val, T &tag, const T &add)
    {
        val.sum += add * val.len;
        tag += add;
    }
    template <typename T = int>
    SegTree<SumNode<T>, T, decltype(sum_get_value<T>), decltype(sum_update_tag<T>)> make_sum(int n)
    {
        return make<SumNode<T>, T>(n, sum_get_value<T>, sum_update_tag<T>);
    }
}
namespace MyIO
{
    class direct_in
    {
    public:
        template <typename T>
        vector<T> v(size_t size)
        {
            vector<T> ve;
            ve.resize(size);
            for (T &v : ve)
                v = *this;
            return ve;
        }
        template <typename T>
        operator T()
        {
            T v;
            cin >> v;
            return v;
        }
        vector<int> vi(size_t size) { return v<int>(size); }
        direct_in &operator()() { return *this; }
        template <typename T, typename... Args>
        direct_in &operator()(T &v, Args &...args)
        {
            v = *this;
            return operator()(args...);
        }
    } in;
#define intp(t, ...) \
    t __VA_ARGS__;   \
    in(__VA_ARGS__);
#define inint(...) intp(int, __VA_ARGS__)
#define inll(...) intp(ll, __VA_ARGS__)
#define invi(sz, nm) vector<int> nm = in.vi(sz)
    class direct_out
    {
    public:
        template <typename T>
        direct_out &operator=(const vector<T> &v)
        {
            for (const T &r : v)
                operator=(r), cout << " ";
            cout << "\n";
            return *this;
        }
        template <typename T>
        direct_out &operator=(const T &v)
        {
            cout << v;
            return *this;
        }
        direct_out &operator=(direct_out &&) = delete;
        direct_out &operator=(const direct_out &) = delete;
        direct_out &operator()() { return *this; }
        template <typename T, typename... Args>
        direct_out &operator()(const T &v, const Args &...args)
        {
            operator=(v);
            return operator()(args...);
        }
    } out;
    const int __magic = []()
    { ios::sync_with_stdio(false); cin.tie(0); return 0; }();
}
namespace Util
{
    template <typename T, typename Callable = function<void(T &, size_t)>>
    vector<T> &suniq(
        vector<T> &v, Callable set_value = [](T &v, size_t i)
                      { v = i; })
    {
        vector<T> s = v;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        for (T &i : v)
            set_value(i, lower_bound(s.begin(), s.end(), i) - s.begin());
        return v;
    }
    template <size_t N>
    class Prime
    {
        vector<bool> np;
        vector<int> p;
        void init()
        {
            np.resize(N + 1);
            for (int i = 2; i <= N; i++)
            {
                if (!np[i])
                    p.push_back(i);
                for (int j : p)
                {
                    int x = i * j;
                    if (x >= N)
                        break;
                    np[x] = true;
                    if (i % j == 0)
                        break;
                }
            }
        }

    public:
        Prime() { init(); }
        bool isprime(int i) const { return !np[i]; }
        int operator[](size_t i) const { return p[i]; }
        size_t size() const { return p.size(); }
        vector<int>::const_iterator begin() const { return p.begin(); }
        vector<int>::const_iterator end() const { return p.end(); }
    };
}
namespace Graph
{
    class Graph
    {
        friend class Tree;
        int n;

    public:
        vector<vector<int>> con;
        Graph(int n = 0) { init(n); }
        void init(int n)
        {
            this->n = n;
            con.clear();
            con.resize(n + 1);
        }
        void addedge(int i, int j, bool directed = false)
        {
            con[i].push_back(j);
            if (!directed)
                con[j].push_back(i);
        }
    };
    class Tree : public Graph
    {
        vector<int> dep;
        vector<vector<int>> jmp;
        int root;
        enum tree_flags : int
        {
            flag_dfs = 1 << 1
        };
        int flag;
        void _do_dfs()
        {
            if (!(flag & flag_dfs))
                jmp.resize(n + 1, vector<int>(20)), dep.resize(n + 1), _dfs(root, 0), flag |= flag_dfs;
        }
        void _dfs(int i, int par)
        {
            dep[i] = dep[par] + 1;
            jmp[i][0] = par;
            for (int j = 1; j < 20; j++)
                jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
            for (int j : con[i])
                if (j != par)
                    _dfs(j, i);
        }

    public:
        Tree(int root, int n = 0) : flag(0) { init(root, n); }
        void init(int root, int n)
        {
            Graph::init(n);
            this->root = root;
        }
        void addedge(int i, int j)
        {
            Graph::addedge(i, j, false);
        }
        int lca(int i, int j)
        {
            _do_dfs();
            if (dep[i] > dep[j])
                swap(i, j);
            for (int k = 19; k >= 0; k--)
                if (dep[jmp[j][k]] >= dep[i])
                    j = jmp[j][k];
            if (i == j)
                return i;
            for (int k = 19; k >= 0; k--)
            {
                if (jmp[i][k] == jmp[j][k])
                    continue;
                i = jmp[i][k];
                j = jmp[j][k];
            }
            return jmp[i][0];
        }
        int par(int i)
        {
            _do_dfs();
            return jmp[i][0];
        }
    };
}
namespace Arithmetic
{
    template <ll mod>
    ll qpowm(ll i, ll p)
    {
        ll ans = 1;
        while (p)
        {
            if (p & 1)
                ans = ans * i % mod;
            i = i * i % mod;
            p >>= 1;
        }
        return ans;
    }
#define qpow Arithmetic::qpowm<mod>
}
namespace Struct
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
using MyIO::in;
using MyIO::out;

// ----- code start -----

int main()
{
    CASES
    {
        inint(n, x);
        invi(n + n, h);
        sort(h.begin(), h.end());
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (h[i + n] < h[i] + x)
                ok = false;
        out(ok ? "yes" : "no", "\n");
    }

    return 0;
}
