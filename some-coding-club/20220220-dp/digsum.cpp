// https://atcoder.jp/contests/dp/tasks/dp_s
// AtCoder DP S Digit Sum
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e4 + 5;
void add(ll &a, ll b) { a = (a + b) % mod; }
ll dp[maxn][2][110];
char s[maxn];
int main()
{
    cin >> s;
    int n = strlen(s);
    int d;
    cin >> d;
    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int f = 0; f < 2; f++)
        {
            for (int j = 0; j < d; j++)
            {
                int c = s[i] - '0';
                for (int k = 0; k < 10; k++)
                {
                    if (f && k > c)
                        break;
                    int r = (j + k) % d;
                    int nf = f && k == c;
                    add(dp[i + 1][nf][r], dp[i][f][j]);
                }
            }
        }
    }

    cout << (dp[n][0][0] + dp[n][1][0] + mod - 1) % mod << endl;

    return 0;
}
