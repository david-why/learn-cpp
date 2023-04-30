// https://www.luogu.com.cn/problem/P8435
#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e5 + 233;

vector<int> con[maxn];

int dfn[maxn], low[maxn], idx;
stack<int> st;
vector<vector<int>> ans;
void tarjan(int i)
{
    dfn[i] = low[i] = ++idx;
    st.push(i);
    for (int j : con[i])
    {
        if (!dfn[j])
        {
            tarjan(j);
            low[i] = min(low[i], low[j]);
            if (low[j] >= dfn[i])
            {
                vector<int> v;
                while (true)
                {
                    int x = st.top();
                    st.pop();
                    v.push_back(x);
                    if (x == j)
                        break;
                }
                v.push_back(i);
                ans.push_back(move(v));
            }
        }
        else
            low[i] = min(low[i], dfn[j]);
    }
    if (all_of(con[i].begin(), con[i].end(), [i](int x)
               { return x == i; }))
    {
        vector<int> v;
        v.push_back(i);
        ans.push_back(move(v));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        con[u].push_back(v);
        con[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
        {
            while (!st.empty())
                st.pop();
            tarjan(i);
        }
    cout << ans.size() << "\n";
    for (vector<int> &v : ans)
    {
        cout << v.size();
        for (int i : v)
            cout << " " << i;
        cout << "\n";
    }
    return 0;
}
