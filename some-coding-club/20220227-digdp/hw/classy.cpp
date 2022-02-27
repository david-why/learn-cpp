// https://codeforces.com/problemset/problem/1036/C
// Codeforces Contest #1036 C. Classy Numbers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 18 + 5;
void add(ll &a, ll b) { a = a + b; }
ll dp[maxn][2][4];
ll cs[maxn];
char s[maxn], u[maxn];
bool isclassy(const char *str)
{
    int n = strlen(str) - 1;
    int cnt = 0;
    for (; n >= 0; n--)
    {
        if (str[n] != '0')
        {
            cnt++;
            if (cnt > 3)
                return false;
        }
    }
    return true;
}
ll run(const char *str)
{
    int n = strlen(str);
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++)
    {
        int c = str[i] - '0';
        for (int f = 0; f < 2; f++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int d = 0; d < 10; d++)
                {
                    if ((f && d > c) || (j == 3 && d))
                        break;
                    int nf = f && d == c;
                    if (d)
                        add(dp[i + 1][nf][j + 1], dp[i][f][j]);
                    else
                        add(dp[i + 1][nf][j], dp[i][f][j]);
                }
            }
        }
    }
    ll ans = 0;
    for (int f = 0; f < 2; f++)
        for (int j = 0; j < 4; j++)
            add(ans, dp[n][f][j]);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s >> u;
        cout << run(u) - run(s) + isclassy(s) << endl;
    }

    return 0;
}
