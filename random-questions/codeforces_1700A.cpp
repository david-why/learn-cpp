// https://codeforces.com/contest/1700/problem/A
// Codeforces Contest #1700 A. Optimal Path
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << m * (m - 1) / 2 + (m + n * m) * n / 2 << endl;
    }

    return 0;
}
