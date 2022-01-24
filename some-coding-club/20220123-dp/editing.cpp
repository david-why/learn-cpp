// https://www.luogu.com.cn/problem/P2758
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 5;
int dp[maxn][maxn];

char a[maxn], b[maxn];

int main()
{
    cin >> a + 1 >> b + 1;
    size_t n = strlen(a + 1), m = strlen(b + 1);

    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i] != b[j])});

    cout << dp[n][m] << endl;
    return 0;
}
