// https://vjudge.net/problem/HDU-6534
// 2019CCPC湖南全国邀请赛（广东省赛、江苏省赛）重现赛 Chika and Friendly Pairs
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 27005;
const int B = 160;
const int NUM = maxn / B + 5;
int n, m, k;
int ch[maxn];
void add2(int x, int v)
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
vector<int> q[NUM * NUM];
int cur, L[maxn], R[maxn], ans[maxn];
int low[maxn], up[maxn], pos[maxn];
int a[maxn], b[maxn], bl;
void add(int i)
{
    cur += query(up[i]) - query(low[i]);
    add2(pos[i], 1);
}
void del(int i)
{
    add2(pos[i], -1);
    cur -= query(up[i]) - query(low[i]);
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        low[i] = lower_bound(b + 1, b + 1 + n, a[i] - k) - b - 1;
        up[i] = upper_bound(b + 1, b + 1 + n, a[i] + k) - b - 1;
        pos[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> L[i] >> R[i];
        int id = L[i] / B * NUM + R[i] / B;
        q[id].push_back(i);
    }

    int l = 1, r = 1;
    add(1);
    for (int i = 0; i < NUM * NUM; i++)
    {
        for (int x : q[i])
        {
            while (r < R[x])
                add(++r);
            while (l > L[x])
                add(--l);
            while (r > R[x])
                del(r--);
            while (l < L[x])
                del(l++);
            ans[x] = cur;
        }
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;

    return 0;
}
