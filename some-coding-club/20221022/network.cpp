#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;

const int maxn = 504;
int x[maxn], y[maxn];

int fd(int i, int j) { return abs(x[i]-x[j])*abs(x[i]-x[j])+abs(y[i]-y[j])*abs(y[i]-y[j]); }

int pa[maxn];
int find(int i) { return pa[i] == i ? i : (pa[i] = find(pa[i])); }
void join(int i, int j) { pa[find(i)] = find(j); }

struct edge {
	int dis, i, j;
	bool operator<(const edge &o) const { return o.dis < dis; }
};

int main() {
	// freopen("wireless.in", "r", stdin);
	// freopen("wireless.out", "w", stdout);
	int s, p; cin >> s >> p;
	for (int i = 0; i < p; i++) cin >> x[i] >> y[i];
	priority_queue<edge> pq;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
			if (i != j)
				pq.push({fd(i, j), i, j});
	for (int i = 0; i < p; i++) pa[i] = i;
	int cnt = 0, ans = 0;
	while (cnt < p-s) {
		edge e = pq.top(); pq.pop();
		if (find(e.i) == find(e.j)) continue;
		join(e.i, e.j);
		ans = e.dis;
		cnt++;
	}
	cout << fixed << setprecision(2) << sqrt(ans) << endl;
	return 0;
}
