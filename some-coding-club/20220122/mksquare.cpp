// https://codeforces.com/problemset/problem/962/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    queue<string> p;
    p.push(s);
    int ans = 0;
    while (!p.empty())
    {
        size_t qs = p.size();
        while (qs--)
        {
            string x = p.front();
            p.pop();
            if (x.empty() || x[0] == '0')
                continue;
            int i = atoi(x.c_str());
            int q = sqrt(atoi(x.c_str()));
            if (q * q == i)
            {
                cout << ans << endl;
                return 0;
            }
            for (int i = 0; i < x.length(); i++)
            {
                p.push(x.substr(0, i) + x.substr(i + 1));
            }
        }
        ans++;
    }
    cout << -1 << endl;
    return 0;
}
