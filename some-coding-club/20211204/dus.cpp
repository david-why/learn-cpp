#include <bits/stdc++.h>

using namespace std;

#define maxn 100000
int par[maxn];
int find_root(int a)
{
    if (par[a] == a)
        return a;
    else
        return par[a] = find_root(par[a]);
}
void join(int a, int b)
{
    par[find_root(a)] = find_root(b);
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < q; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            join(x, y);
        else
            cout << (find_root(x) == find_root(y) ? "Yes" : "No") << endl;
    }
    return 0;
}
