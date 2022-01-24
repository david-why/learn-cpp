// https://codeforces.com/problemset/problem/933/A
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];
int dp[maxn][4];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + (a[i] == k % 2 + 1));

    cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << endl;
    return 0;
}
