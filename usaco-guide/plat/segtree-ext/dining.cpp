// https://codeforces.com/contest/1179/problem/C

// let f(c) be count(A[i]>=c) and g(c) be count(B[i]>=c)
// then serge can get max{f>g}(c)
// node value: max(f-g), look for biggest index positive

#include <bits/stdc++.h>

using namespace std;

const int maxn = 300005, maxv = 1e6 + 7;

#define pr int i, int l, int r
#define li (i << 1)
#define ri ((i << 1) + 1)
#define mid ((l + r) >> 1)
#define gl li, l, mid
#define gr ri, mid + 1, r
#define uv() ch[i] = max(ch[li], ch[ri])

int ch[4 * maxv], tag[4 * maxv];

void push_down(int i)
{
    if (!tag[i])
        return;
    ch[li] += tag[i];
    ch[ri] += tag[i];
    tag[li] += tag[i];
    tag[ri] += tag[i];
    tag[i] = 0;
}

void update(int ql, int qr, int v, pr)
{
    if (ql <= l && r <= qr)
    {
        ch[i] += v;
        tag[i] += v;
        return;
    }
    push_down(i);
    if (ql <= mid)
        update(ql, qr, v, gl);
    if (qr > mid)
        update(ql, qr, v, gr);
    uv();
}

int query(pr)
{
    // cout<<"query "<<i<<" "<<l<<","<<r<<" v="<<ch[i]<<endl;
    if (ch[i] <= 0)
        return -1;
    if (l == r)
        return l;
    push_down(i);
    if (ch[ri] > 0)
        return query(gr);
    return query(gl);
}

int test(int p, pr) {
    if (l==r) return ch[i];
    push_down(i);
    if (p<=mid) return test(p, gl);
    return test(p, gr);
}

int a[maxn], b[maxn];

const int N = 1e6;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, a[i], 1, 1, 1, N);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        update(1, b[i], -1, 1, 1, N);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int c, i, x;
        cin >> c >> i >> x;
        if (c == 1)
        {
            if (x > a[i])
                update(a[i] + 1, x, 1, 1, 1, N);
            else if (x < a[i])
                update(x + 1, a[i], -1, 1, 1, N);
            a[i] = x;
        }
        else
        {
            if (x > b[i])
                update(b[i] + 1, x, -1, 1, 1, N);
            else if (x < b[i])
                update(x + 1, b[i], 1, 1, 1, N);
            b[i] = x;
        }
        // for (int z=1;z<=101;z++) cout<<test(z,1,1,N)<<" "; cout<<endl;
        cout << query(1, 1, N) << "\n";
    }
    return 0;
}
