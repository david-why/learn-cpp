// https://atcoder.jp/contests/abc154/tasks/abc154_e
// AtCoder ABC154 E Almost Everywhere Zero
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5, maxk = 3 + 5;
ll dp[maxn][2][maxk];
template <typename T>
void add(T &a, T b) { a = a + b; }
char s[maxn];
int main()
{
    int n, k;
    cin >> s >> k;
    n = strlen(s);
    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int f = 0; f < 2; f++)
        {
            for (int j = 0; j <= k; j++)
            {
                int c = s[i] - '0';
                for (int d = 0; d < 10; d++)
                {
                    if (f && d > c)
                        break;
                    int nf = f && d == c;
                    if (d == 0)
                        add(dp[i + 1][nf][j], dp[i][f][j]);
                    else if (j != k)
                        add(dp[i + 1][nf][j + 1], dp[i][f][j]);
                }
            }
        }
    }

    cout << dp[n][0][k] + dp[n][1][k] << endl;

    return 0;
}
