#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 7;

unordered_map<int, vector<int>> con[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        if (con[x].count(y))
            throw exception();
        con[x][y].push_back(c);
        con[y][x].push_back(c);
    }
    return 0;
}
