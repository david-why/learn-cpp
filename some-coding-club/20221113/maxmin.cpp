#include <bits/stdc++.h>

using namespace std;

map<int, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            m[x]++;
        }
        else if (op == 2)
        {
            int x, c;
            cin >> x >> c;
            if (m[x] > c)
                m[x] -= c;
            else
                m.erase(x);
        }
        else if (op == 3)
        {
            cout << m.rbegin()->first - m.begin()->first << "\n";
        }
    }
}
