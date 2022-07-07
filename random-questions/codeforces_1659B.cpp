// https://codeforces.com/contest/1659/problem/B
// Codeforces Contest #1659 B. Bit Flipping
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
char b[maxn];
int ans[maxn];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k >> b;
        char c = k % 2;
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n && k; i++)
            if (b[i] == '0' + c)
                ans[i]++, b[i] ^= 1, k--;
        ans[n - 1] += k;
        if (k % 2)
            b[n - 1] ^= 1;
        for (int i = 0; i < n; i++)
            cout << (char)(b[i] ^ c);
        cout << "\n";
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}
