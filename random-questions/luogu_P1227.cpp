// https://www.luogu.com.cn/problem/P1227
// Luogu P1227 [JSOI2008] 完美的对称
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e4 + 5;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;

    sort(pos.begin(), pos.end());

    double mx = 2e9, my = 2e9;
    auto l = pos.begin(), r = --pos.end();
    while (l <= r)
    {
        if (mx == 2e9)
            mx = (r->first + l->first) / 2.0, my = (r->second + l->second) / 2.0;
        else if (mx != (r->first + l->first) / 2.0 || my != (r->second + l->second) / 2.0)
        {
            cout << "This is a dangerous situation!" << endl;
            return 0;
        }
        ++l, --r;
    }
    printf("V.I.P. should stay at (%.01lf,%.01lf).\n", mx, my);

    return 0;
}
