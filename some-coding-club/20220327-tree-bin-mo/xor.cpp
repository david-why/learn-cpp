// https://codeforces.com/problemset/problem/617/E
// Codeforces Contest #617 E. XOR and Favorite Number
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5, B = 300, NUM = maxn / B + 5;
vector<int> q[NUM * NUM];
int a[maxn], L[maxn], R[maxn], cur, cnt[maxn], k, ans[maxn], pre[maxn];
void add(int i)
{
    cur += cnt[i ^ k];
    cnt[i]++;
}
void del(int i)
{
    cnt[i]--;
    cur -= cnt[i ^ k];
}
int main()
{
    int n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
    for (int i = 1; i <= m; i++)
        cin >> L[i] >> R[i], q[L[i] / B * NUM + R[i] / B].push_back(i);

    int l = 1, r = 1;
    add(1);
    for (int i = 0; i < NUM * NUM; i++)
    {
        for (int x : q[i])
        {
            while (r < R[x])
                add(pre[++r]);
            while (l > L[x])
                add(pre[--l]);
            while (r > R[x])
                del(pre[r--]);
            while (l < L[x])
                del(pre[l++]);
            ans[x] = cur;
        }
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;

    return 0;
}
