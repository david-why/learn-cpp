// https://cses.fi/problemset/task/1143

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;

int ch[4 * maxn];

#define pr int i, int L, int R
#define mid ((L + R) >> 1)
#define li (i << 1)
#define gl li, L, mid
#define ri ((i << 1) + 1)
#define gr ri, mid + 1, R
#define uv() ch[i] = get_value(ch[li], ch[ri])

int get_value(int l, int r)
{
    return max(l, r);
}

void init(int *arr, pr)
{
    if (L == R)
    {
        ch[i] = arr[L];
        return;
    }
    init(arr, gl);
    init(arr, gr);
    uv();
}

int find(int v, pr)
{
    // cout << "find " << v << " " << i << " " << L << " " << R << " " << ch[i] << endl;
    if (ch[i] < v)
        return 1e9;
    if (L == R)
        return L;
    int t = find(v, gl);
    if (t != 1e9) return t;
    return find(v, gr);
}

int query(int ql, int qr, pr) {
    if (ql==L&&qr==R) return ch[i];
    if (qr <= mid) return query(ql,qr,gl);
    if (ql > mid) return query(ql, qr, gr);
    return get_value(query(ql,mid,gl), query(mid+1,qr,gr));
}

void update(int v, int p, pr)
{
    if (L == R)
    {
        ch[i] += v;
        return;
    }
    if (p <= mid)
        update(v, p, gl);
    else
        update(v, p, gr);
    uv();
}

int h[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    init(h, 1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        // cout << endl << "!" << query(1, n,1,1,n) << endl;
        int r;
        cin >> r;
        int p = find(r, 1, 1, n);
        if (p == 1e9)
            cout << 0 << " ";
        else
            cout << p << " ", update(-r, p, 1, 1, n);
    }
    return 0;
}
