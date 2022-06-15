#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
ll a[maxn];
ll suf[maxn];

int main() {
    int p, q;
    cin >> p >> q;
    for (int i = 1; i <= p; i++) cin >> a[i];
    sort(a+1, a+p+1);
    for (int i = p; i >= 1; i--) suf[i] = suf[i+1] + a[i];
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << suf[p-x+1] - suf[p-x+y+1] << endl;
    }
}
