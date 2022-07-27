// https://www.luogu.com.cn/problem/P1091
// Luogu P1091 [NOIP2004 提高组] 合唱队形

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int dp1[maxn], dp2[maxn];
int t[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];

    for (int i = 1; i <= n; i++)
    {
        dp1[i] = 1;
        for (int j = 1; j < i; j++)
            if (t[j] < t[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
    }
    for (int i = n; i >= 1; i--)
    {
        dp2[i] = 1;
        for (int j = n; j > i; j--)
            if (t[j] < t[i])
                dp2[i] = max(dp2[i], dp2[j] + 1);
    }

    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp1[i] + dp2[i] - 1);
    cout << n - ans << endl;
    return 0;
}
