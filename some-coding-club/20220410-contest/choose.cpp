// https://atcoder.jp/contests/abc245/tasks/abc245_c
// AtCoder ABC245 C Choose Elements
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int a[maxn], b[maxn];
int *ls[2] = {a, b};
bool dp[maxn][2];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);

    dp[1][0] = dp[1][1] = true;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int *lst = ls[j];
            for (int m = 0; m < 2; m++)
                if (dp[i - 1][m] && abs(ls[m][i - 1] - lst[i]) <= k)
                    dp[i][j] = true;
        }
    }

    cout << ((dp[n][0] || dp[n][1]) ? "Yes" : "No") << endl;

    return 0;
}
