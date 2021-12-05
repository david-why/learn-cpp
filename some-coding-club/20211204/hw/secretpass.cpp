// https://codeforces.com/problemset/problem/1263/D

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;
int par[maxn], gr[26], g;
int root(int i)
{
    return par[i] == i ? i : (par[i] = root(par[i]));
}
void merge(int i, int j)
{
    int a = root(i), b = root(j);
    if (a != b)
    {
        par[root(i)] = root(j);
        g--;
    }
}

int main()
{
    int n;
    cin >> n;
    g = n;
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (char c : s)
            if (gr[c - 'a'] == 0)
                gr[c - 'a'] = root(i);
            else
                merge(gr[c - 'a'], i);
    }

    cout << g << endl;
    return 0;
}
