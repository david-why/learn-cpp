#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 2e5 + 7;
const ll lim = 1 << 30;

int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            a[x] = y;
        }
        else if (op == 2)
        {
            if (y > x + 60)
            {
                cout << "Too large\n";
                continue;
            }
            ll mx = 1, c = 1;
            for (int i = x; i <= y; i++)
            {
                if (a[i] > 0)
                    mx = max(mx, c *= a[i]);
                else
                    c = 1;
                if (mx > lim)
                    break;
            }
            if (mx > lim)
                cout << "Too large\n";
            else
                cout << mx << "\n";
        }
    }
}
