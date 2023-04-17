// http://www.usaco.org/index.php?page=viewproblem2&cpid=231

#include <bits/stdc++.h>

using namespace std;

const int maxn = 500233;

#define mid ((l + r) >> 1)
#define li (i << 1)
#define ri ((i << 1) + 1)
#define gl li, l, mid
#define gr ri, mid + 1, r
// #define uv() ch[i] = get_value(ch[li], ch[ri])
#define uv() ch[i] = get_value(ch[li], ch[ri])//, cout<<"uv "<<i<<" {"<<l<<" "<<r<<"}"<<" {"<<ch[i].mx<<" "<<ch[i].ml<<" "<<ch[i].mr<<"}"<<" {"<<ch[li].mx<<" "<<ch[li].ml<<" "<<ch[li].mr<<"}"<<" {"<<ch[ri].mx<<" "<<ch[ri].ml<<" "<<ch[ri].mr<<"}"<<endl
#define gt() get_tag(ch[i], tag[i]), tag[li] = tag[ri] = tag[i], tag[i] = 0
#define pr int i, int l, int r

struct node
{
    int mx = 1, ml = 1, mr = 1, len = 1;
    node(int a=1,int b=1,int c=1,int d=1):mx(a),ml(b),mr(c), len(d){}
} ch[4 * maxn];
int tag[4 * maxn]; // 1=full, 2=empty

node get_value(const node &a, const node &b)
{
    return node{max({a.mx, b.mx, a.mr + b.ml}), a.ml == a.len ? a.ml + b.ml : a.ml, b.mr == b.len ? b.mr + a.mr : b.mr, a.len + b.len};
}
void get_tag(node &n, int t)
{
    if (t == 1)
        n.mx = n.ml = n.mr = 0;
    else if (t == 2)
        n.mx = n.ml = n.mr = n.len;
}

void push_down(int i)
{
    // if (ri >= maxn) return;
    if (tag[i])//cout<<"push "<<i<<" "<<tag[i]<<endl,
        tag[li] = tag[ri] = tag[i],
        get_tag(ch[li], tag[i]),
        get_tag(ch[ri], tag[i]),  tag[i] = 0;
}

void init(pr)
{
    if (l == r)
        return;
    init(gl);
    init(gr);
    uv();
}

void update(int ql, int qr, int t, pr)
{
    if (l!=r)push_down(i);
    // cout<<"updt "<<ql<<","<<qr<<" "<<t<<" "<<l<<","<<r<<" {"<<ch[i].mx<<" "<<ch[i].ml<<" "<<ch[i].mr<<"}"<<endl;
    if (ql <= l && r <= qr)
    {
        tag[i] = t;
        get_tag(ch[i], t);
        return;
    }
    if (ql <= mid)
        update(ql, qr, t, gl);
    if (qr > mid)
        update(ql, qr, t, gr);
    uv();
}

int find(int len, pr)
{
    if (l!=r)push_down(i);
    // cout<<"find "<<len<<" "<<l<<","<<r<<" {"<<ch[i].mx<<" "<<ch[i].ml<<" "<<ch[i].mr<<"}"<<endl;
    if (l == r)
        return l;
    if (ch[i].mx < len)
        return 0;
    if (ch[li].mx >= len)
        return find(len, gl);
    if (ch[li].mr + ch[ri].ml >= len)
        return mid - ch[li].mr + 1;
    return find(len, gr);
}

int main()
{
#ifndef LOCAL
    freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    init(1, 1, n);
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        char e;
        cin >> e;
        if (e == 'A')
        {
            int s;
            cin >> s;
            int idx = find(s, 1, 1, n);
            // cout<<"ans "<<idx<<endl;
            if (!idx)
                cnt++;
            else
                update(idx, idx + s - 1, 1, 1, 1, n);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            update(l, r, 2, 1, 1, n);
        }
    }
    cout << cnt << endl;
    return 0;
}
