// https://www.luogu.com.cn/problem/P1616
// Luogu P1616 疯狂的采药

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxt = 1e7 + 7, maxm = 1e4 + 7;

int tim[maxm], val[maxm];
ll dp[maxt];

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> tim[i] >> val[i];

    for (int i = 1; i <= m; i++)
        for (int j = tim[i]; j <= t; j++)
        {
            if (j - tim[i] >= 0)
                dp[j] = max(dp[j], dp[j - tim[i]] + val[i]);
        }

    cout << dp[t] << endl;
    return 0;
}
