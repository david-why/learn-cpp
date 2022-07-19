// https://www.luogu.com.cn/problem/P3373
// Luogu P3373 【模板】线段树 2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define modadd(x, y, mod) ((x) = ((ll)((x) + (y)) % (mod)))
namespace BIT
{
    template <typename T, size_t mod = SIZE_MAX>
    class BIT
    {
        vector<T> ch;
        int n;

    public:
        BST(int n = 0) { init(n); }
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
    template <typename T, typename Tag = void,
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
        struct Empty
        {
        };
        typename conditional<has_tag, vector<Tag>, Empty>::type tags;

        template <typename Array>
        void _build(const Array &arr, bool zero, int i, int l, int r)
        {
            if (has_tag)
                clear_tag(tags[i]);
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
            if (!has_tag)
                return;
            update_tag(ch[li], tags[li], tags[i]);
            update_tag(ch[ri], tags[ri], tags[i]);
            clear_tag(tags[i]);
        }
        void _add_one(int pos, const T &v, bool repl, int i, int l, int r)
        {
            if (l == r)
            {
                if (repl)
                    ch[i] = v;
                else
                    ch[i] += v;
                return;
            }
            _push(i);
            int mid = gmid;
            if (pos < mid)
                _add_one(pos, v, gl);
            else
                _add_one(pos, v, gr);
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
            if (has_tag)
            {
                tags.clear();
                tags.resize(n * 4);
            }
        }
        template <typename Array>
        void build(const Array &arr, bool zero = true) { _build(arr, zero, 1, 1, n); }
        void add(int i, const T &v, bool replace = true) { _add_one(i, v, replace, 1, 1, n); }
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
    template <typename T, typename Tag = void,
              typename GetValue = function<T(const T &, const T &)>,
              typename UpdateTag = function<void(T &, Tag &, const Tag &)>,
              typename ClearTag = function<void(Tag &)>>
    SegTree<T, Tag, GetValue, UpdateTag, ClearTag> make(
        int n, GetValue get_value, UpdateTag update_tag,
        ClearTag clear_tag = [](Tag &t)
        { t = {}; })
    {
        return SegTree<T, Tag, GetValue, UpdateTag, ClearTag>(get_value, update_tag, clear_tag, n);
    }
}
namespace MyIO
{
#define IN(type)    \
    operator type() \
    {               \
        type v;     \
        cin >> v;   \
        return v;   \
    }
    class direct_in
    {
    public:
        IN(int);
        IN(unsigned int);
        IN(ll);
        IN(ull);
        IN(double);
        IN(float);
        IN(size_t);
        IN(string);
        template <size_t N>
        IN(bitset<N>);
        template <typename T>
        vector<T> v(size_t size)
        {
            vector<T> ve;
            ve.resize(size);
            for (T &v : ve)
                v = *this;
            return ve;
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
#undef IN
#define OUT(type)                 \
    direct_out &operator=(type v) \
    {                             \
        cout << v;                \
        return *this;             \
    }
#define OUTR(type)                       \
    direct_out &operator=(const type &v) \
    {                                    \
        cout << v;                       \
        return *this;                    \
    }
    class direct_out
    {
    public:
        OUT(int);
        OUT(unsigned int);
        OUT(ll);
        OUT(ull);
        OUT(double);
        OUT(float);
        OUT(size_t);
        OUT(const char *);
        OUTR(string);
        template <size_t N>
        OUTR(bitset<N>);
        template <typename T>
        direct_out &operator=(const vector<T> &v)
        {
            for (const T &r : v)
                operator=(r), cout << " ";
            cout << "\n";
            return *this;
        }
        direct_out &operator=(direct_out &&) = delete;
        direct_out &operator=(const direct_out &) = delete;
        direct_out &operator()() { return *this; }
        template <typename T, typename... Args>
        direct_out &operator()(const T &v, Args &...args)
        {
            *this = v;
            return operator()(args...);
        }
    } out;
    const int __magic = []()
    { ios::sync_with_stdio(false); cin.tie(0); return 0; }();
}
using MyIO::in;
using MyIO::out;

// ----- code start -----

int n, m, p;
struct Node
{
    int val, d;
    Node(int val = 0, int d = 1) : val(val), d(d) {}
};
struct Tag
{
    ll mul = 1, add = 0;
};

Node get_value(const Node &a, const Node &b)
{
    return {(a.val + b.val) % p, a.d + b.d};
}
// tag=(a,b) add=(c,d): c(ak+b)+d = (ac)k+(bc+d)
void update_tag(Node &node, Tag &tag, const Tag &add)
{
    node.val = (add.mul * node.val % p + add.add * node.d) % p;
    tag.mul = tag.mul * add.mul % p;
    tag.add = (tag.add * add.mul % p + add.add) % p;
}

int main()
{
    in(n, m, p);
    vector<int> v = in.vi(n);
    auto st = SegTree::make<Node, Tag>(n, get_value, update_tag);
    st.build(v);

    while (m--)
    {
        int op, l, r;
        in(op, l, r);
        if (op == 1)
            st.add(l, r, Tag{(ll)in, 0});
        else if (op == 2)
            st.add(l, r, Tag{1, (ll)in});
        else
            out(st.query(l, r).val, "\n");
    }

    return 0;
}
