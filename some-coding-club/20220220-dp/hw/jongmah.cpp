// https://codeforces.com/problemset/problem/1110/D
// Codeforces Contest #1110 D. Jongmah
// Solution algorithm from https://www.luogu.com.cn/problem/solution/CF1110D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int dp[maxn][3][3];
int num[maxn];
int read()
{
    int x;
    cin >> x;
    return x;
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        num[read()]++;
    for (int i = 1; i <= m; i++)
        for (int t1 = 0; t1 < 3; t1++)
            for (int t2 = 0; t2 < 3; t2++)
                for (int t3 = 0; t3 < 3; t3++)
                    if (num[i] >= t1 + t2 + t3)
                        dp[i][t2][t3] = max(dp[i][t2][t3], dp[i - 1][t1][t2] + (num[i] - t1 - t2 - t3) / 3 + t3);
    cout << dp[m][0][0] << endl;
    return 0;
}
