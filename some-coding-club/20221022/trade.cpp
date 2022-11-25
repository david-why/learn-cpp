#include <iostream>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = 100005, maxm = 500005;

int p[maxn];
int dis[maxn*3];
bool vis[maxn*3];

unordered_map<int, int> con[maxn*3];

void spfa(int s, int n) {
    for (int i = 1; i <= n; i++) dis[i] = -1e8;
    dis[s] = 0;
    queue<int> q;
    q.push(s); vis[s] = true;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        vis[c] = false;
        for (auto &p:con[c]) {
            if (dis[p.first] < dis[c] + p.second) {
                dis[p.first] = dis[c] + p.second;
                if (!vis[p.first]) vis[p.first] = true, q.push(p.first);
            }
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        con[x][y] = con[x+n][y+n] = con[x+n+n][y+n+n] = 0;
        if (z == 2) con[y][x] = con[y+n][x+n] = con[y+n+n][x+n+n] = 0;
    }
    for (int i = 1; i <= n; i++) {
        con[i][i+n] = -p[i];
        con[i+n][i+n+n] = p[i];
    }
    spfa(1, n*3);
    cout << max(dis[n], dis[3*n]) << endl;
    return 0;
}
