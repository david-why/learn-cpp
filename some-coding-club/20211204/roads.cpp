#include <bits/stdc++.h>

using namespace std;

int par[1000], n;
int root(int i)
{
    return par[i] == i ? i : (par[i] = root(par[i]));
}
void merge(int i, int j)
{
    int a = root(i), b = root(j);
    if (a != b)
    {
        par[a] = b;
        n--;
    }
}

int main()
{
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        int m;
        cin >> m;
        for (int i = 1; i <= n; i++)
            par[i] = i;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        cout << n - 1 << endl;
    }
}
