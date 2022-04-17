// https://codeforces.com/problemset/problem/1307/C
// Codeforces Contest #1307 C. Cow and Message
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
char s[maxn];
int n;
ll dp[26][27];
int main()
{
    cin >> s;
    n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        for (int j = 0; j < 26; j++)
            dp[j][c] += dp[j][26];
        dp[c][26]++;
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j <= 26; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;

    return 0;
}
