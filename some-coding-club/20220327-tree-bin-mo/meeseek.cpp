// https://codeforces.com/problemset/problem/786/C
// Codeforces Contest #786 C. Till I Collapse
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
int ch[maxn], n;
void add(int x, int v)
{
    for (; x <= n; x += x & -x)
        ch[x] += v;
}
int query(int x)
{
    int s = 0;
    for (; x; x -= x & -x)
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
int nxt[maxn], last[maxn];
int a[maxn];
vector<int> q[maxn];
bool v[maxn];
int ans[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], q[1].push_back(i);

    for (int i = n; i; i--)
        nxt[i] = last[a[i]], last[a[i]] = i;
    for (int i = 1; i <= n; i++)
        if (!v[a[i]])
            v[a[i]] = true, add(i, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int x : q[i])
        {
            ans[x]++;
            int r = find(x);
            q[r + 1].push_back(x);
        }
        add(i, -1);
        if (nxt[i])
            add(nxt[i], 1);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << (i == n ? '\n' : ' ');

    return 0;
}
