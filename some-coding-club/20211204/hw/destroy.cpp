// https://codeforces.com/problemset/problem/722/C

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;
int nums[maxn], order[maxn];
bool act[maxn];
long long sums[maxn], maxs, ans[maxn];

int par[maxn];
int root(int i)
{
    return par[i] == i ? i : (par[i] = root(par[i]));
}
void merge(int i, int j)
{
    int a = root(i), b = root(j);
    if (a != b)
    {
        par[a] = b;
        sums[b] += sums[a];
        maxs = max(maxs, sums[b]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    for (int i = 1; i <= n; i++)
        cin >> order[i];

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sums[i] = nums[i];
    }

    for (int i = n; i; i--)
    {
        ans[i] = maxs;
        int x = order[i];
        act[x] = true;
        maxs = max(maxs, sums[x]);
        if (act[x + 1])
            merge(x, x + 1);
        if (act[x - 1])
            merge(x, x - 1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}
