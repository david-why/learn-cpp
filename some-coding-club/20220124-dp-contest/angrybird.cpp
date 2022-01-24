// https://vjudge.net/contest/478114#problem/C, 85 pts
#include <bits/stdc++.h>

using namespace std;

// y=ax^2+bx (a<0)
struct line
{
    double a, b;
    line(double x1, double y1, double x2, double y2) : a((x1 * y2 - x2 * y1) / (x1 * x2 * x2 - x1 * x1 * x2)), b((x1 * x1 * y2 - x2 * x2 * y1) / (x1 * x1 * x2 - x1 * x2 * x2)) {}
    bool online(double x, double y) { return abs(a * x * x + b * x - y) < 1e-8; }
};

const int maxn = 18 + 1;
int dp[1 << maxn];
unsigned char isok[1 << maxn];
double pos[maxn][2];
int n;

bool chk(int v)
{
    if (__builtin_popcount(v) <= 1)
        return true;
    int i1, i2 = -1;
    for (i1 = 0; i1 < n; i1++)
    {
        if (v & (1 << i1))
        {
            if (i2 >= 0)
                break;
            i2 = i1;
        }
    }
    line li(pos[i1][0], pos[i1][1], pos[i2][0], pos[i2][1]);
    if (li.a >= 0)
        return false;
    for (i2 = i1 + 1; i2 < n; i2++)
        if (v & (1 << i2))
            if (!li.online(pos[i2][0], pos[i2][1]))
                return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> dp[0];
        for (int i = 0; i < n; i++)
            cin >> pos[i][0] >> pos[i][1];
        for (int s = 0; s < (1 << n); s++)
            isok[s] = chk(s);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++)
        {
            if (isok[s])
            {
                dp[s] = 1;
                continue;
            }
            dp[s] = 2e9;
            for (int x = s; x; x = (x - 1) & s) // iterate subset
            {
                if (isok[s - x])
                    dp[s] = min(dp[s], dp[x] + 1);
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }
    return 0;
}
