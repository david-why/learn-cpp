// https://codeforces.com/problemset/problem/1334/B
// Codeforces Contest #1334 B. Middle Class
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
int a[maxn];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        ll s = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], s += a[i];
        sort(a + 1, a + 1 + n, greater<int>());
        int i;
        for (i = n; i; i--)
        {
            if ((double)s / i >= x)
                break;
            s -= a[i];
        }
        cout << i << endl;
    }

    return 0;
}
