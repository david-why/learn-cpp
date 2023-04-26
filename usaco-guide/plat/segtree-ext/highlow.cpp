// http://www.usaco.org/index.php?page=viewproblem2&cpid=577

#include <bits/stdc++.h>

using namespace std;

const int maxn = 50007;

struct node
{
    int els, bes, done;
} ch[8 * maxn];

ostream&operator<<(ostream&out,const node&n){return out<<"{"<<n.els<<","<<n.bes<<","<<n.done<<"}";}

node get_value(const node &a, const node &b)
{
    int mch = min(a.els, b.bes);
    return node{a.els + b.els - mch, a.bes + b.bes - mch, a.done + b.done + mch};
}

#define mid ((l + r) >> 1)
#define li (i << 1)
#define ri ((i << 1) + 1)
#define gl li, l, mid
#define gr ri, mid + 1, r
#define pr int i, int l, int r
#define gv() ch[i] = get_value(ch[li], ch[ri])

void init()
{
    memset(ch, 0, sizeof(ch));
}

void update(const node &v, int p, pr)
{
    if (l == r)
    {
        ch[i] = v;
        return;
    }
    if (p <= mid)
        update(v, p, gl);
    else
        update(v, p, gr);
    gv();
}

node query(int ql, int qr, pr)
{
    if (ql <= l && r <= qr)
        return ch[i];
    if (qr <= mid)
        return query(ql, qr, gl);
    if (ql > mid)
        return query(ql, qr, gr);
    return get_value(query(ql, mid, gl), query(mid + 1, qr, gr));
}

int lt[maxn], rt[maxn];

int main()
{
#ifndef LOCALTEST
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n;
    cin >> n;
    vector<int> els;
    bitset<2*maxn> inels;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        els.push_back(x);
        inels[x] = true;
    }
    vector<int> bes;
    for (int i = 2*n; i >= 1;i--)
        if (!inels[i])
            bes.push_back(i);
    init();
    for (int i = 1;i<=n;i++) {
        update(node{1,0,0},els[i-1],1,1,2*n);
        update(node{0,1,0},bes[i-1],1,1,2*n);
    // cout<<query(1,n,1,1,n)<<endl;
        lt[i] =query(1,n,1,1,n).done;
    }
    init();
    int ans = 0;
// cout<<"--------\n";
    for (int i=n;i>=1;i--){
        update(node{0,1,0},els[i-1],1,1,2*n);
        update(node{1,0,0},bes[i-1],1,1,2*n);
    // cout<<query(1,n,1,1,n)<<endl;
        rt[i] =query(1,n,1,1,n).done;
    }
    // for(int i=0;i<n;i++)cout<<lt[i]<<" ";cout<<endl;
    // for(int i=0;i<n;i++)cout<<rt[i]<<" ";cout<<endl;
    for(int i=0;i<=n;i++){
        ans=max(ans,lt[i]+rt[i+1]);
    }
    cout<<ans<<"\n";
    return 0;
}
