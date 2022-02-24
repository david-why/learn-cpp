// https://www.luogu.com.cn/problem/P2822
// REMEMBER:
// 1. C(n,k)=C(n-1,k)+C(n-1,k-1)

#include <bits/stdc++.h>

using namespace std;

int C[2005][2005];
int pre[2005][2005];

int main()
{
    int t, k;
    cin >> t >> k;
    C[0][0] = 1;
    for (int i = 1; i <= 2001; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % k;
    for (int i = 1; i <= 2001; i++)
        for (int j = 1; j <= 2001; j++)
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + (C[i][j] == 0 && j <= i);
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << pre[n + 1][m + 1] << endl;
    }
}
