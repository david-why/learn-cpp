#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;
int a[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, s=0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
        cout << max(0, s-m) << endl;
    }
}
