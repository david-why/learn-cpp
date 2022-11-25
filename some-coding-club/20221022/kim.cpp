#include <iostream>

using namespace std;

const int maxn = 3e4+5, maxm = 30;

int dp[maxm][maxn];
int v[maxn], p[maxn];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> p[i] >> v[i];
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= p[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-p[i]]+v[i]*p[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) ans = max(ans, dp[m][i]);
	cout << ans << endl;
	return 0;
}
