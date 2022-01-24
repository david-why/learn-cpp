// https://vjudge.net/contest/478114#problem/C, AC
#include <bits/stdc++.h>

using namespace std;

// y=ax^2+bx (a<0)
struct line
{
    double a, b;
    line(double x1, double y1, double x2, double y2) : a((x1 * y2 - x2 * y1) / (x1 * x2 * x2 - x1 * x1 * x2)), b((x1 * x1 * y2 - x2 * x2 * y1) / (x1 * x1 * x2 - x1 * x2 * x2)) {}
    bool online(double x, double y) { return abs(a * x * x + b * x - y) < 1e-6; }
};

const int maxn = 18 + 1;
int dp[1 << maxn];
unsigned char isok[1 << maxn];
double pos[maxn][2];
int lines[maxn][maxn];
int n;

#define equ(a, b) (abs((a) - (b)) < 1e-6)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> dp[0];
        for (int i = 0; i < n; i++)
            cin >> pos[i][0] >> pos[i][1];
        for (int s = 1; s < (1 << n); s++)
            dp[s] = 2e9;
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                line li(pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
                lines[i][j] = 0;
                if (li.a >= 0)
                    continue;
                for (int k = 0; k < n; k++)
                    if (li.online(pos[k][0], pos[k][1]))
                        lines[i][j] |= (1 << k);
            }
        }
        for (int s = 0; s < (1 << n); s++)
        {
            int j;
            for (j = 0; j < n; j++)
                if (!(s & (1 << j)))
                    break;
            dp[s | (1 << j)] = min(dp[s | (1 << j)], dp[s] + 1);
            for (int k = 0; k < n; k++)
                dp[s | lines[j][k]] = min(dp[s | lines[j][k]], dp[s] + 1);
        }
        cout << dp[(1 << n) - 1] << endl;
    }
    return 0;
}
