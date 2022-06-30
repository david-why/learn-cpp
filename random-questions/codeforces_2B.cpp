// https://codeforces.com/contest/2/problem/B
// Codeforces Contest #2 B. The least round way
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int a[maxn][maxn], n;
ll c2[maxn][maxn], c5[maxn][maxn];
bitset<maxn> t2[maxn], t5[maxn];
ll maxpow(ll a, ll b)
{
    if (a == 0)
        return 0;
    ll c = 0, x = b;
    while (a % x == 0)
        x *= b, c++;
    return c;
}
void run(ll (&dp)[maxn][maxn], bitset<maxn> (&istop)[maxn], const int val)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ll p = maxpow(a[i][j], val);
            ll ft = dp[i - 1][j], fl = dp[i][j - 1];
            if ((ft < fl && i != 1) || j == 1)
                istop[i][j] = true, dp[i][j] = ft + p;
            else
                istop[i][j] = false, dp[i][j] = fl + p;
        }
}
void output(bitset<maxn> (&istop)[maxn])
{
    int i = n, j = n;
    string s;
    while (i != 1 || j != 1)
    {
        if (istop[i][j])
            s += 'D', i--;
        else
            s += 'R', j--;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}
int main()
{
    cin >> n;
    int zx = 2e9, zy = 2e9;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                zx = i, zy = j;
        }

    run(c2, t2, 2);
    run(c5, t5, 5);

    ll ans = c2[n][n] < c5[n][n] ? c2[n][n] : c5[n][n];

    if (ans != 0 && zx != 2e9)
    {
        cout << 1 << endl;
        for (int i = 1; i < zx; i++)
            cout << "D";
        for (int i = 1; i < zy; i++)
            cout << "R";
        for (int i = zx; i < n; i++)
            cout << "D";
        for (int i = zy; i < n; i++)
            cout << "R";
        cout << endl;
        return 0;
    }

    cout << ans << endl;
    output(c2[n][n] < c5[n][n] ? t2 : t5);

    return 0;
}
