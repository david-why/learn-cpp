// https://www.luogu.com.cn/problem/P4819
#include <bits/stdc++.h>

using namespace std;
const int maxn = 100007;

vector<int> con[maxn];

int dfn[maxn], low[maxn], idx;
stack<int> st;
bool inst[maxn];
int comps, comp[maxn], cnt[maxn];
void tarjan(int i)
{
    dfn[i] = low[i] = ++idx;
    inst[i] = true;
    st.push(i);
    for (int j : con[i])
    {
        if (!dfn[j])
        {
            tarjan(j);
            low[i] = min(low[i], low[j]);
        }
        else if (inst[j])
            low[i] = min(low[i], low[j]);
    }
    if (low[i] == dfn[i])
    {
        int cmp = ++comps;
        int v = 0;
        while (v != i)
        {
            v = st.top();
            st.pop();
            inst[v] = false;
            comp[v] = cmp;
            cnt[cmp]++;
        }
    }
}

vector<int> con2[maxn];
int col[maxn];
void dfs(int i, int c)
{
    if (col[i] == -1 || col[i] == c)
        return;
    if (col[i] == 0)
        col[i] = c;
    if (col[i] != c)
        col[i] = -1;
    for (int j : con2[i])
        dfs(j, c);
}

int in[maxn], out[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        for (int j : con[i])
            if (comp[i] != comp[j])
                in[comp[j]]++, out[comp[i]]++, con2[comp[i]].push_back(comp[j]);
    for (int i = 1; i <= comps; i++)
        if (in[i] == 0)
            dfs(i, i);
    bool sp = false;
    for (int i = 1; i <= comps && !sp; i++)
        if (in[i] == 0 && cnt[i] == 1)
        {
            sp = true;
            for (int j : con2[i])
                if (col[j] != -1)
                {
                    sp = false;
                    break;
                }
        }
    int k = 0;
    for (int i = 1; i <= comps; i++)
    {
        // cout<<i<<" : ";
        // for (int j = 1; j <= n; j++) if (comp[j] == i) cout << j << " ";
        // cout<<endl;
        k += in[i] == 0;
        // sp |= (in[i] == 0 || out[i] == 0) && cnt[i] == 1;
    }
    cout << setprecision(6) << fixed << 1.0 - 1.0 * (k - sp) / n << endl;
    return 0;
}
