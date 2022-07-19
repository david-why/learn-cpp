// https://www.luogu.com.cn/problem/P2574
// Luogu P2574 XOR的艺术
#include <bits/stdc++.h>

using namespace std;

namespace SegmentTree
{
    int N;
#define li (i << 1)
#define ri (i << 1 | 1)
#define mid ((L + R) >> 1)
#define lson li, L, mid
#define rson ri, mid + 1, R

    struct EmptyStruct
    {
    };
    template <typename Node, typename Tag = EmptyStruct>
    struct Tree
    {
        using PushUp = function<Node(const Node &, const Node &)>;
        using GetDown = function<void(Node &, Tag &, const Tag &)>;
        using ClearTag = function<void(Tag &tag)>;
        static constexpr bool HasTag = !is_same<Tag, EmptyStruct>::value;
        PushUp push_up;
        GetDown get_down;
        ClearTag clear_tag;
        vector<Node> a;
        vector<Tag> t;
        Tree(PushUp &&push_up, GetDown &&get_down, ClearTag &&clear_tag)
            : push_up(push_up), get_down(get_down), clear_tag(clear_tag),
              a(vector<Node>(4 * N)), t(vector<Tag>(4 * N)) {}
        void build(const vector<Node> &_a, int i = 1, int L = 1, int R = N)
        {
            if (HasTag)
                clear_tag(t[i]);
            if (L == R)
            {
                if (_a.size() == N)
                    a[i] = _a[L - 1];
                else
                    a[i] = _a[L];
                return;
            }
            build(_a, lson);
            build(_a, rson);
            a[i] = push_up(a[li], a[ri]);
        }
        void push_down(int i)
        {
            get_down(a[li], t[li], t[i]);
            get_down(a[ri], t[ri], t[i]);
            clear_tag(t[i]);
        }
        template <bool Cover = true>
        void modify(int pos, const Node &v, int i = 1, int L = 1, int R = N)
        {
            if (L == R)
            {
                if (Cover)
                    a[i] = v;
                else
                    a[i] += v;
                return;
            }
            if (HasTag)
                push_down(i);
            modify(pos, v, lson);
            modify(pos, v, rson);
            a[i] = push_up(a[li], a[ri]);
        }
        void update(int ql, int qr, const Tag &tag, int i = 1, int L = 1, int R = N)
        {
            if (ql <= L && R <= qr)
            {
                get_down(a[i], t[i], tag);
                return;
            }
            if (HasTag)
                push_down(i);
            if (ql <= mid)
                update(ql, qr, tag, lson);
            if (mid < qr)
                update(ql, qr, tag, rson);
            a[i] = push_up(a[li], a[ri]);
        }
        Node query(int ql, int qr, int i = 1, int L = 1, int R = N)
        {
            if (ql <= L && R <= qr)
                return a[i];
            if (HasTag)
                push_down(i);
            if (qr <= mid)
                return query(ql, qr, lson);
            if (ql > mid)
                return query(ql, qr, rson);
            return push_up(query(ql, qr, lson), query(ql, qr, rson));
        }
        Node ask(int pos, int i = 1, int L = 1, int R = N)
        {
            if (L == R)
                return a[i];
            if (HasTag)
                push_down(i);
            if (pos <= mid)
                return ask(pos, lson);
            return ask(pos, rson);
        }
        // >= pos 最近的满足要求的节点
        pair<int, Node> find_next(int pos, function<bool(const Node &)> &satisfy, int i = 1, int L = 1, int R = N)
        {
            pair<int, Node> ret = {-1, Node{}};
            if (satisfy(a[i]))
                return ret;
            if (L == R)
                return {L, a[i]};
            if (pos <= mid)
                ret = find_next(pos, satisfy, lson);
            if (ret.first == -1)
                return find_next(pos, satisfy, rson);
        }
    };

    template <typename Node, typename Tag = void>
    Tree<Node, Tag> make(
        int _N, typename Tree<Node, Tag>::PushUp push_up,
        typename Tree<Node, Tag>::GetDown get_down = {},
        typename Tree<Node, Tag>::ClearTag clear_tag = [](Tag &t)
        { t = {}; })
    {
        N = _N;
        return Tree<Node, Tag>(move(push_up), move(get_down), move(clear_tag));
    }
#undef li
#undef ri
#undef mid
#undef lson
#undef rson
}

using ll = long long;
struct node
{
    int one = 0, zero = 0;
};

node push_up(const node &x, const node &y)
{
    return {x.one + y.one, x.zero + y.zero};
}

void get_down(node &x, int &t, const int &tag)
{
    if (tag)
        swap(x.one, x.zero);
    // x.sum += x.d * tag;
    t ^= tag;
}

const int maxn = 2e5 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<node> a(n);
    for (auto &x : a)
    {
        char c;
        cin >> c;
        if (c == '1')
            x.one = 1;
        else
            x.zero = 1;
    }
    auto st = SegmentTree::make<node, int>(n, push_up, get_down);
    st.build(a);

    while (m--)
    {
        int op, x, y, k;
        cin >> op >> x >> y;
        if (op == 0)
            st.update(x, y, 1);
        else
            cout << st.query(x, y).one << "\n";
        //    cout<<"---- "; for(int i=1;i<=n;i++)cout<<st.query(i,i).sum<<" ";cout<<endl;
    }

    return 0;
}