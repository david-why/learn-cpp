// https://atcoder.jp/contests/abc208/tasks/abc208_e
// AtCoder ABC208 E Digit Products
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 18 + 5, maxk = 1e9 + 7;
void add(ll &a, ll b) { a = a + b; }
map<ll, ll> dp[maxn][2][2];
char s[maxn];
int main()
{
    cin >> s;
    int n = strlen(s);
    int k;
    cin >> k;
    dp[0][1][1][1] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int f = 0; f < 2; f++)
        {
            for (int z = 0; z < 2; z++)
            {
                for (auto &p : dp[i][f][z])
                {
                    int c = s[i] - '0';
                    for (int d = 0; d < 10; d++)
                    {
                        if (f && d > c)
                            break;
                        int nf = f && d == c, nz = z && d == 0;
                        ll r = nz ? 1 : p.first * d;
                        add(dp[i + 1][nf][nz][r], p.second);
                    }
                }
            }
        }
    }

    ll ans = -1;
    for (int f = 0; f < 2; f++)
    {
        for (int z = 0; z < 2; z++)
        {
            for (auto &p : dp[n][f][z])
            {
                if (p.first > k)
                    break;
                add(ans, p.second);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
