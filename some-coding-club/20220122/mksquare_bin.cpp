// https://codeforces.com/problemset/problem/962/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = INT_MAX;
    for (int i = 1; i < (1 << s.length()); i++)
    {
        string x;
        for (int j = 0; j < s.length(); j++)
            if (i & (1 << j))
                x += s[j];
        if (x[0] == '0')
            continue;
        int v = atoi(x.c_str()), q = sqrt(v);
        if (q * q == v)
            ans = min(ans, (int)s.length() - (int)x.length());
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}
