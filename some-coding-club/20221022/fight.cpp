#include <iostream>
#include <string>

using namespace std;

const int maxn = 1e5, maxm = 1e9, bits = 31;

int op[maxn], t[maxn];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s >> t[i];
		if (s == "XOR") op[i] = 0;
		else if (s == "OR") op[i] = 1;
		else op[i] = 2;
	}
	int ans = 0;
	for (int b = 0; b < bits; b++) {
		int B = 1<<b;
		for (int x = 0; x <= (B<=m)?1:0; x++) {
			int y = x?B:0;
			for (int i = 0; i < n; i++) {
				int z = t[i]&B;
				if (op[i] == 0) y = y ^ z;
				else if (op[i] == 1) y = y | z;
				else y = y & z;
			}
			ans |= y;
		}
	}
	cout << ans << endl;
	return 0;
}
