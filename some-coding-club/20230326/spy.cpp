// https://www.luogu.com.cn/problem/P1262
#include <bits/stdc++.h>

using namespace std;

const int maxn = 3005;

int n, p, r;
int cost[maxn];
vector<int> con[maxn];

int in[maxn];

bool vis[maxn];
void dfs(int i)
{
    vis[i] = true;
    for (int j : con[i])
        if (!vis[j])
            dfs(j);
}

int dfn[maxn], low[maxn], idx, cnt, mn[maxn], comp[maxn];
stack<int> st;
bool inst[maxn];
void tarjan(int s)
{
    dfn[s] = low[s] = ++idx;
    st.push(s);
    inst[s] = true;
    for (int i : con[s])
    {
        if (!dfn[i])
            tarjan(i), low[s] = min(low[s], low[i]);
        else if (inst[i])
            low[s] = min(low[s], low[i]);
    }
    if (dfn[s] == low[s])
    {
        cnt++;
        mn[cnt] = 1e9;
        // cout << "c" << cnt;
        while (true)
        {
            int x = st.top();
            st.pop();
            inst[x] = false;
            comp[x] = cnt;
            // cout << " " << x;
            if (cost[x])
                mn[cnt] = min(mn[cnt], cost[x]);
            if (x == s)
                break;
        }
        // cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        cost[x] = y;
    }
    cin >> r;
    for (int i = 1; i <= r; i++)
    {
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
        if (cost[i] && !vis[i])
            dfs(i);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n"
                 << i << endl;
            return 0;
        }
        if (!dfn[i])
            tarjan(i);
    }

    for (int i = 1; i <= n; i++)
        for (int j : con[i])
            if (comp[i] != comp[j])
                in[comp[j]]++;

    // for (int i = 1; i <= cnt; i++)
    //     cout << in[i] << " ";
    // cout << endl;

    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        if (!in[i])
            // cout << "!" << i << " " << mn[i] << endl,
                ans += mn[i];
    cout << "YES\n"
         << ans << endl;
    return 0;
}
