// https://codeforces.com/problemset/problem/1561/D1
// Codeforces Contest #1561 D1. Up the Strip (simplified version)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e6 + 5;
int mod;
template <typename T>
void add(T &a, ll b) { a = (b + a) % mod; }
int dp[maxn], v[maxn];
int main()
{
    int n;
    cin >> n >> mod;

    // dp[1] = 1;
    // int s = 1, vs = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else
            add(dp[i], 2 * dp[i - 1]);
        for (int j = i + i; j <= n; j += i)
            add(dp[j], mod - dp[i - 1] + dp[i]);
    }

    cout << dp[n] << endl;

    return 0;
}
