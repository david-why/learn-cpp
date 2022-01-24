// https://vjudge.net/contest/478114#problem/B
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e5 + 5;
ll dp[maxn][10];
const char chokudai[] = " chokudai";
void add(ll &i, ll x) { i = (i + x) % mod; }

int main()
{
    string s;
    cin >> s;
    size_t n = s.length();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= 8; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == chokudai[j])
                add(dp[i][j], dp[i - 1][j - 1]);
        }
    }

    cout << dp[n][8] << endl;
    return 0;
}
