// https://codeforces.com/problemset/problem/699/C
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;
// 0=gym, 1=contest
bool open[maxn][2];
int dp[maxn][3];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        open[i][0] = x >> 1;
        open[i][1] = x & 1;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        if (open[i][0]) // gym is open
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
        else
            dp[i][0] = dp[i][2];
        if (open[i][1])
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        else
            dp[i][1] = dp[i][2];
    }

    cout << n - max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    return 0;
}
