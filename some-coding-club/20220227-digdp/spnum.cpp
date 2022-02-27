// https://codeforces.com/problemset/problem/914/C
// Codeforces Contest #914 C. Travelling Salesman and Special Numbers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9 + 7;
template <typename T>
void add(T &a, T b) { a = (a + b) % mod; }
char s[maxn];
ll dp[maxn][2][maxn];
ll f[maxn];
int main()
{
    int n, k;
    cin >> s >> k;
    n = strlen(s);

    if (k == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    if (k == 1)
    {
        cout << n - 1 << endl;
        return 0;
    }

    f[1] = 0;
    for (int i = 2; i <= 1000; i++)
        f[i] = f[__builtin_popcount(i)] + 1;

    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int f = 0; f < 2; f++)
        {
            for (int j = 0; j <= n; j++)
            {
                int c = s[i] - '0';
                for (int d = 0; d < 2; d++)
                {
                    if (f && d > c)
                        break;
                    int nf = f && d == c;
                    if (d == 0)
                        add(dp[i + 1][nf][j], dp[i][f][j]);
                    else
                        add(dp[i + 1][nf][j + 1], dp[i][f][j]);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= 1000; i++)
        if (k == f[i] + 1)
            add(ans, dp[n][0][i] + dp[n][1][i]);
    cout << ans << endl;

    return 0;
}
