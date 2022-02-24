// https://codeforces.com/contest/1017/problem/B
// Codeforces Contest #1017 B. The Bits
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    bitset<100005> a, b;
    cin >> a >> b;
    // Rules for switching:
    // 1. 0's switch with 1's
    // 2. 00<->10 / 00<->11 / 01<->10 / 10<->01 / 10<->00 / 11<->00
    ll z = 0, a1 = 0, b1 = 0, ab = 0;
    for (int i = 0; i < n; i++)
        if (a[i])
            if (b[i])
                ab++;
            else
                a1++;
        else if (b[i])
            b1++;
        else
            z++;
    ll ans = 0;
    ans += z * a1;
    ans += z * ab;
    ans += b1 * a1;
    ans += a1 * b1;
    ans += a1 * z;
    ans += ab * z;
    cout << ans / 2 << endl;

    return 0;
}
