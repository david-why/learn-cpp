// https://atcoder.jp/contests/abc235/tasks/abc235_f
// AtCoder ABC235 F Variety of Digits
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5, maxm = 10, mod = 998244353;
ll cnt[maxn][2][1 << maxm], sum[maxn][2][1 << maxm];
char s[maxn];
// unordered_map<int, int> C;
int C[maxm];
void add(ll &a, ll b) { a = (a + b) % mod; }
int main()
{
    int n, m;
    cin >> s >> m;
    n = strlen(s);
    for (int i = 0; i < m; i++)
        cin >> C[i];
    cnt[0][1][0] = 1;

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - '0';
        for (int f = 0; f < 2; f++)
        {
            for (int t = 0; t < (1 << maxm); t++)
            {
                for (int d = 0; d < 10; d++)
                {
                    if (f && d > c)
                        break;
                    int nf = f && d == c;
                    int nt = (t == 0 && d == 0) ? 0 : (t | (1 << d));
                    add(cnt[i + 1][nf][nt], cnt[i][f][t]);
                    add(sum[i + 1][nf][nt], sum[i][f][t] * 10);
                    add(sum[i + 1][nf][nt], cnt[i][f][t] * d);
                }
            }
        }
    }

    ll ans = 0;
    int t = 0;
    for (int i = 0; i < m; i++)
        t |= (1 << C[i]);
    for (int x = 0; x < (1 << maxm); x++)
        if ((x & t) == t)
            add(ans, sum[n][0][x] + sum[n][1][x]);
    cout << ans << endl;

    return 0;
}
