// calculate sum{i=l..r}(a[i]) while a[i] changes
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 4;
int ch[maxn], n;
void add(int x, int v) // a[x]+=v
{
    for (int i = x; i <= n; i += i & (-i))
        ch[i] += v;
}
int query(int x) // sum{i=0..}
{
    int s = 0;
    for (int i = x; i; i -= i & (-i))
        s += ch[i];
    return s;
}
int main()
{
    int q;
    cin >> n >> q;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            add(x, y);
        else
            cout << query(y) - query(x - 1) << endl;
    }

    return 0;
}
