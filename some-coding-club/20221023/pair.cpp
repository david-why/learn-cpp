// http://codeforces.com/problemset/problem/359/D
// Codeforces Contest #359 D. Pair of Numbers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
int l[maxn], r[maxn], a[maxn];
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        l[i] = i;
        while (l[i] > 0 && a[l[i]-1]%a[i] == 0) l[i] = l[l[i]-1];
    }
    for (int i = n-1; i >= 0; i--) {
        r[i] = i;
        while (r[i] < n-1 && a[r[i]+1]%a[i] == 0) r[i] = r[r[i]+1];
    }
    int ans = -1;
    set<int> v;
    for (int i = 0; i < n; i++)
        if (r[i]-l[i]>ans)
            ans = r[i]-l[i], v.clear(), v.insert(l[i]+1);
        else if (r[i]-l[i]==ans)
            v.insert(l[i]+1);
    cout << v.size() << " " << ans << endl;
    for (int x : v) cout << x << " "; cout << endl;

    return 0;
}
