// https://atcoder.jp/contests/arc068/tasks/arc068_c
// AtCoder ARC068 C Snuke Line
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 6, maxm = 1e5 + 6;
int ch[maxm], m;
void add(int x, int v)
{
    for (int i = x; i <= m; i += i & (-i))
        ch[i] += v;
}
int query(int x)
{
    int s = 0;
    for (int i = x; i; i -= i & (-i))
        s += ch[i];
    return s;
}
int l[maxn], r[maxn];
vector<int> bu[maxm];
int main()
{
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", l + i, r + i);
        bu[r[i] - l[i] + 1].push_back(i);
    }

    int longer = n;
    for (int i = 1; i <= m; i++)
    {
        int ans = longer;
        for (int j = i; j <= m; j += i)
            ans += query(j);
        printf("%d\n", ans);
        for (int j : bu[i])
        {
            longer--;
            add(l[j], 1);
            add(r[j] + 1, -1);
        }
    }

    return 0;
}
