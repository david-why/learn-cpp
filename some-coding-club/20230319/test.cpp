#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;

vector<int> g[maxn];
int low[maxn], dfn[maxn], T, cnt;
stack<int> sta;
bool inStack[maxn];

void tarjan(int u) {
	dfn[u] = low[u] = ++T;
	sta.push(u);
	inStack[u] = true;

	for(int v : g[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(inStack[v]) low[u] = min(low[u], low[v]);
	}

	if(low[u] == dfn[u]) {
		int x;
		cout << ++cnt << " : ";
		do{
			x = sta.top();
			sta.pop();
			inStack[x] = false;
			cout << x << " ";
		}while(x != u);
		cout << "\n";
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	while(m--) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	tarjan(1);
	return 0;
}