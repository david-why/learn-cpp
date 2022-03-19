// https://codeforces.com/problemset/problem/321/E
// Codeforces Contest #321 E. Ciel and Gondolas
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4000 + 5;
unsigned int u[maxn][maxn];
int dp[maxn][maxn];
unsigned int cost(int l, int r)
{
    return (u[r][r] + u[l - 1][l - 1] - u[l - 1][r] - u[r][l - 1]) / 2;
}
void divide(int l, int r, int pl, int pr, int j)
{
    if (l > r)
        return;
    int v = (l + r) / 2, m = pl;
    for (int i = pl; i <= pr; i++)
    {
        unsigned int c = cost(i + 1, v) + dp[i][j - 1];
        if (c < dp[v][j])
            dp[v][j] = c, m = i;
    }
    divide(l, v - 1, pl, m, j);
    divide(v + 1, r, m, pr, j);
}
char buf[maxn * 3];
int main()
{
    int n, k;
    scanf("%d%d\n", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        fgets(buf, sizeof(buf), stdin);
        for (int j = 1; j <= n; j++)
            u[i][j] = buf[j * 2 - 2] - '0' + u[i - 1][j] + u[i][j - 1] - u[i - 1][j - 1];
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for (int j = 1; j <= k; j++)
        divide(1, n, 0, n - 1, j);

    cout << dp[n][k] << endl;

    return 0;
}
