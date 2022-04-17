// https://codeforces.com/problemset/problem/1295/C
// Codeforces Contest #1295 C. Obtain The String
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
int nxt[maxn][26], last[26];
char s[maxn], t[maxn];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> (s + 1) >> (t + 1);
        int n = strlen(s + 1), m = strlen(t + 1);
        memset(last, 0, sizeof(last));
        memset(nxt, -1, sizeof(nxt));
        for (int i = n; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
                nxt[i][j] = nxt[i + 1][j];
            if (i)
                nxt[i][s[i] - 'a'] = i;
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j < 26; j++)
        //         cout << (nxt[i][j]) << " ";
        //     cout << endl;
        // }
        int ans = 1, pos = 0;
        for (int i = 1; i <= m; i++)
        {
            // cout << pos << " " << t[i] - 'a' << " " << nxt[pos][t[i] - 'a'] << endl;
            if (nxt[pos][t[i] - 'a'] == -1)
            {
                ans++;
                pos = nxt[0][t[i] - 'a'] + 1;
                if (pos == 0)
                {
                    ans = -1;
                    break;
                }
            }
            else
                pos = nxt[pos][t[i] - 'a'] + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
