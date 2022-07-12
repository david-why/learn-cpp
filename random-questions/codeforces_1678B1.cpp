// https://codeforces.com/contest/1678/problem/B1
// Codeforces Contest #1678 B1. Tokitsukaze and Good 01-String (easy version)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int main()
{
    string s;
    s.reserve(maxn);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> s;
        char v = s[0] ^ 1;
        int c = 0;
        int a = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != v)
            {
                v = s[i];
                if (c % 2 && c >= 0)
                    a++, c = 1;
                else
                    c = 0;
            }
            c++;
        }
        cout << a << endl;
    }

    return 0;
}
