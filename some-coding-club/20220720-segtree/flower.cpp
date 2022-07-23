// https://vjudge.net/problem/HDU-4614
// HDU 2614 Vases and Flowers
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
            if (r < f)
                return -1;
            if (l == r)
                return pred(ch[i]) ? l : -1;
            _push(i);
            int mid = gmid;
            if (l >= f)
                return pred(ch[i]) ? _find(f, pred, gl) : _find(f, pred, gr);
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
        // find the closest node i >= f for which pred(ch[i])=true
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
    auto make_sum(int n)
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
            *this = v;
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
}
using MyIO::in;
using MyIO::out;

// ----- code start -----

struct node
{
    int c0, c1;
    node(int c0 = 1, int c1 = 0) : c0(c0), c1(c1) {}
};

node get_value(const node &a, const node &b)
{
    return node{a.c0 + b.c0, a.c1 + b.c1};
}

void update_tag(node &a, int &tag, int add)
{
    if (add == 0)
        return;
    if (add == 1)
        a.c1 += a.c0, a.c0 = 0;
    if (add == -1)
        a.c0 += a.c1, a.c1 = 0;
    tag = add;
}

int main()
{
    int t = in;
    while (t--)
    {
        int n = in, m = in;
        auto st = SegTree::make<node, int>(n, get_value, update_tag);
        while (m--)
        {
            int k, a, b;
            in(k, a, b);
            a++;
            if (k == 1)
            {
                int l = st.find(a, [](const node &n)
                                { return n.c0 > 0; });
                if (l == -1)
                    out("Can not put any one.\n");
                else
                {
                    int c = 0;
                    auto satisfy = [&](const node &n)
                    {
                        if (c + n.c0 >= b)
                            return true;
                        c += n.c0;
                        return false;
                    };
                    int r = st.find(a, satisfy);
                    if (r == -1)
                    {
                        b = c, c = 0;
                        r = st.find(a, satisfy);
                    }
                    out(l - 1, " ", r - 1, "\n");
                    st.add(l, r, 1);
                }
            }
            else
            {
                b++;
                out(st.query(a, b).c1, "\n");
                st.add(a, b, -1);
            }
        }
        out("\n");
    }

    return 0;
}
