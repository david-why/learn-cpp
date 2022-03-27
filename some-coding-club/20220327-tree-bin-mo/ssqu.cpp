// https://www.luogu.com.cn/problem/P2709
// Luogu P2709 小B的询问
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 5;
const int B = 256;
const int NUM = maxn / B + 5;
vector<int> q[NUM * NUM];
int cnt[maxn], cur, a[maxn], L[maxn], R[maxn], ans[maxn];
void add(int i)
{
    cnt[a[i]]++;
    cur = cur - (cnt[a[i]] - 1) * (cnt[a[i]] - 1) + cnt[a[i]] * cnt[a[i]];
}
void del(int i)
{
    cnt[a[i]]--;
    cur = cur - (cnt[a[i]] + 1) * (cnt[a[i]] + 1) + cnt[a[i]] * cnt[a[i]];
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
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
