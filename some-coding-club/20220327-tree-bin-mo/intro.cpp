#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 233;
int a[maxn];
int ch[maxn], n;
void add(int x, int v)
{
    for (; x <= n; x += x & (-x))
        ch[x] += v;
}
int query(int x)
{
    int s = 0;
    for (; x; x -= x & (-x))
        s += ch[x];
    return s;
}
int find(int v)
{
    int x = 0;
    for (int i = 20; i >= 0; i--)
        if (x + (1 << i) <= n && ch[x + (1 << i)] <= v)
            x += 1 << i, v -= ch[x];
    return x;
}
int main()
{
    int q;
    cin >> n >> q;
    while (q--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            int y;
            cin >> y;
            add(x, y);
        }
        else
            cout << find(x) << endl;
    }

    return 0;
}
