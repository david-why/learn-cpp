// https://www.luogu.com.cn/problem/P1057
#include <bits/stdc++.h>

using namespace std;

const int maxn = 30 + 5;
int dp[maxn][maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int l = j - 1, r = (j + 1) % n;
            if (l < 0)
                l += n;
            dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
        }
    }
    cout << dp[m][0] << endl;
    return 0;
}
