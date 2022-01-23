#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
int dp[maxn + 5][(1 << maxn) + 5];
int sums[(1 << maxn)];
int nums[maxn];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sums[i] += nums[j];
    for (int i = 0; i <= n; i++)
        for (int s = 0; s < (1 << n); s++)
            dp[i][s] = INT_MAX;

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        for (int s = 0; s < (1 << n); s++)
            // for (int x = 0; x < (1 << n); x++)
            //     if (s & x == x) // x is subset of s?
            for (int x = s; x; x = (x - 1) & s) // iterate subset of s
                dp[i][s] = min(dp[i][s], max(sums[x], dp[i - 1][s - x]));

    cout << dp[k][(1 << n) - 1] << endl;
    return 0;
}

// (a+b)^n=\sum(k=0,n){C(n,k)*a^k*b^(n-k)}
