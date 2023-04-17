// https://judge.yosupo.jp/problem/point_set_range_composite

// c(ax+b)+d=(ac)x+(bc+d)

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pii;
const int maxn = 500007, mod = 998244353;

#define pr int i, int l, int r
#define li (i<<1)
#define ri ((i<<1)+1)
#define mid ((l+r)>>1)
#define gl li,l,mid
#define gr ri,mid+1,r
#define uv() ch[i] = get_value(ch[li], ch[ri])

pii ch[4 * maxn]; // {a, b}

pii get_value(const pii &a, const pii &b)
{
    return pii{a.first * b.first % mod, (a.second * b.first + b.second) % mod};
}

void init(const pii *arr, pr) {
    if (l==r) {
        ch[i] = arr[l];return;
    }
    init(arr,gl);
    init(arr,gr);
    uv();
}

void update(int p, const pii &v, pr) {
    if (l==r) {ch[i]=v;return;}
    if (p<=mid) update(p,v,gl);
    else update(p,v,gr);
    uv();
}

pii query(int ql, int qr, pr) {
    if (ql<=l && r<=qr) return ch[i];
    if (qr<=mid) return query(ql,qr,gl);
    if (ql>mid) return query(ql,qr,gr);
    return get_value(query(ql,mid,gl),query(mid+1,qr,gr));
}

pii arr[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin>>n>>q;
    for (int i = 1; i <= n; i++) {
        cin >>arr[i].first >>arr[i].second;
    }
    init(arr, 1,1,n);
    while (q--) {
        long long op, a,b,c;
        cin>>op>>a>>b>>c;
        if (op==0) {
            update(a+1,pii{b,c},1,1,n);
        } else {
            pii p = query(a+1,b,1,1,n);
            cout<<(p.first*c%mod+p.second)%mod<<"\n";
        }
    }
    return 0;
}
