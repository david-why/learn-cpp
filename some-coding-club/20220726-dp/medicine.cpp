// https://www.luogu.com.cn/problem/P1048
// Luogu P1048 [NOIP2005 普及组] 采药

#include <bits/stdc++.h>

using namespace std;

const int maxt = 1000 + 7, maxm = 100 + 7;

int tim[maxm], val[maxm];
int dp[maxt];

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> tim[i] >> val[i];

    for (int i = 1; i <= m; i++)
        for (int j = t; j >= tim[i]; j--)
            dp[j] = max(dp[j], dp[j - tim[i]] + val[i]);

    cout << dp[t] << endl;
    return 0;
}
