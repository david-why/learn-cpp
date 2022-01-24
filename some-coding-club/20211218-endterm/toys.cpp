// https://www.luogu.com.cn/problem/P1563?contestId=58741

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000;

unordered_map<string, int> mp;
string ppl[maxn];
bool dir[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> dir[i] >> s;
        mp[s] = i;
        ppl[i] = s;
    }

    int now = 0;
    for (int i = 0; i < m; i++)
    {
        int a, s;
        cin >> a >> s;
        if (a == dir[now])
        {
            now = now + n - s;
        }
        else
        {
            now = now + s;
        }
        now %= n;
    }

    cout << ppl[now] << endl;
    return 0;
}
