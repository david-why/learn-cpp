// https://atcoder.jp/contests/abc245/tasks/abc245_e
// AtCoder ABC245 E Wrapping Chocolate
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
pair<int, int> a[maxn], b[maxn];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].second);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i].first);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i].second);

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    multiset<int> s;
    int j = m;
    for (int i = n; i >= 1; i--)
    {
        while (j && b[j].first >= a[i].first)
            s.insert(b[j--].second);
        multiset<int>::iterator k = s.lower_bound(a[i].second);
        if (k == s.end())
        {
            cout << "No" << endl;
            return 0;
        }
        s.erase(k);
    }
    cout << "Yes" << endl;

    return 0;
}
