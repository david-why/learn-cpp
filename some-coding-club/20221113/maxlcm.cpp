#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int a[55], b[55];

int GCD(int *arr, int ign = -1)
{
    int v = arr[ign == 1 ? 2 : 1];
    for (int i = 2; i <= n; i++)
        if (i != ign)
            v = gcd(v, arr[i]);
    return v;
}
ll LCM(int a, int b)
{
    return a * 1ll * b / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    if (n == 1)
    {
        cout << LCM(b[1], a[1]) << endl;
        return 0;
    }
    ll ans = -1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, LCM(gcd(GCD(a, i), b[i]), gcd(GCD(b, i), a[i])));
    cout << ans << endl;
    return 0;
}
