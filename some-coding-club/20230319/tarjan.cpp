#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;

vector<int> con[maxn];

int low[maxn], dfn[maxn], loi;
bool ins[maxn];
stack<int> st;

int cpi[maxn], cpn;
vector<int> comps[maxn];

void tarjan(int u)
{
    dfn[u] = low[u] = ++loi;
    st.push(u);
    ins[u] = true;
    for (int v : con[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
            low[u] = min(low[u], low[v]);
    }
    if (low[u] == dfn[u])
    {
        int i = ++cpn, x;
        do
        {
            x = st.top();
            st.pop();
            ins[x] = false;
            cpi[x] = i;
            comps[i].push_back(x);
        } while (x != u);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
    }
    tarjan(1);
    for (int i = 1; i <= cpn; i++)
    {
        cout << i << ": ";
        for (int u : comps[i])
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
