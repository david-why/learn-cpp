#include <iostream>

using namespace std;

int a[3005];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	int s = 0;
	for (int i = 0; i < m; i++) s += a[i];
	int ans = s;
	for (int i = 1; i <= n-m; i++) ans = min(ans, s = s-a[i-1]+a[i+m-1]);
	cout << ans << endl;

	return 0;
}
